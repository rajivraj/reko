﻿#region License
/* 
 * Copyright (C) 1999-2015 John Källén.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#endregion

using Reko.Core;
using Reko.Core.Configuration;
using Reko.Core.Services;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

namespace Reko.ImageLoaders.MzExe
{
    public class NeImageLoader : ImageLoader
    {
        // Relocation address types
        const byte NE_RADDR_LOWBYTE = 0;
        const byte NE_RADDR_SELECTOR = 2;
        const byte NE_RADDR_POINTER32 = 3;
        const byte NE_RADDR_OFFSET16 = 5;
        const byte NE_RADDR_POINTER48 = 11;
        const byte NE_RADDR_OFFSET32 = 13;

        // Relocation types
        const byte NE_RELTYPE_INTERNAL = 0;
        const byte NE_RELTYPE_ORDINAL = 1;
        const byte NE_RELTYPE_NAME = 2;
        const byte NE_RELTYPE_OSFIXUP = 3;
        const byte NE_RELFLAG_ADDITIVE = 4;


        // Resource types
        const ushort NE_RSCTYPE_CURSOR            =0x8001;
        const ushort NE_RSCTYPE_BITMAP            =0x8002;
        const ushort NE_RSCTYPE_ICON              =0x8003;
        const ushort NE_RSCTYPE_MENU              =0x8004;
        const ushort NE_RSCTYPE_DIALOG            =0x8005;
        const ushort NE_RSCTYPE_STRING            =0x8006;
        const ushort NE_RSCTYPE_FONTDIR           =0x8007;
        const ushort NE_RSCTYPE_FONT              =0x8008;
        const ushort NE_RSCTYPE_ACCELERATOR       =0x8009;
        const ushort NE_RSCTYPE_RCDATA            =0x800a;
        const ushort NE_RSCTYPE_GROUP_CURSOR      =0x800c;
        const ushort NE_RSCTYPE_GROUP_ICON        =0x800e;
        const ushort NE_RSCTYPE_SCALABLE_FONTPATH = 0x80cc;

        private LoadedImage image;
        private ImageMap imageMap;
        private List<string> moduleNames;
        private NeSegment[] segments;
        private ushort cbFileAlignmentShift;
        private ushort cSeg;
        private IDiagnosticsService diags;
        private uint lfaNew;
        private ushort offImportedNamesTable;
        private ushort offEntryTable;
        private ushort offResidentNameTable;
        private ushort offRsrcTable;
        private Address addrImportStubs;
        private Dictionary<uint, Tuple<Address, ImportReference>> importStubs;
        private IProcessorArchitecture arch;
        private Address addrEntry;

        public NeImageLoader(IServiceProvider services, string filename, byte[] rawBytes, uint e_lfanew)
            : base(services, filename, rawBytes)
        {
            ImageReader rdr = new LeImageReader(RawImage, e_lfanew);
            diags = Services.RequireService<IDiagnosticsService>();
            this.lfaNew = e_lfanew;
            this.importStubs = new Dictionary<uint, Tuple<Address, ImportReference>>();
            if (!LoadNeHeader(rdr))
                throw new BadImageFormatException("Unable to read NE header.");
        }

        public override Address PreferredBaseAddress
        {
            get { return Address.ProtectedSegPtr(0xF, 0); }
            set
            {
                throw new NotImplementedException();
            }
        }

        private bool LoadNeHeader(ImageReader rdr)
        {
            ushort magic;
            if (!rdr.TryReadLeUInt16(out magic) || magic != 0x454E)
                throw new BadImageFormatException("Not a valid NE header.");
            ushort linker;
            if (!rdr.TryReadLeUInt16(out linker))
                return false;
            if (!rdr.TryReadLeUInt16(out offEntryTable))
                return false;
            ushort cbEntryTable;
            if (!rdr.TryReadLeUInt16(out cbEntryTable))
                return false;
            uint crc;
            if (!rdr.TryReadLeUInt32(out crc))
                return false;
            byte bProgramFlags;
            if (!rdr.TryReadByte(out bProgramFlags))
                return false;
            byte bAppFlags;
            if (!rdr.TryReadByte(out bAppFlags))
                return false;
            ushort iSegAutoData;
            if (!rdr.TryReadUInt16(out iSegAutoData))
                return false;
            ushort cbHeapSize;
            if (!rdr.TryReadUInt16(out cbHeapSize))
                return false;
            ushort cbStackSize;
            if (!rdr.TryReadUInt16(out cbStackSize))
                return false;
            ushort cs, ip;
            if (!rdr.TryReadUInt16(out ip) || !rdr.TryReadUInt16(out cs))
                return false;
            ushort ss, sp;
            if (!rdr.TryReadUInt16(out sp) || !rdr.TryReadUInt16(out ss))
                return false;
            if (!rdr.TryReadUInt16(out cSeg))
                return false;
            ushort cModules;
            if (!rdr.TryReadUInt16(out cModules))
                return false;
            ushort cbNonResidentNames;
            if (!rdr.TryReadUInt16(out cbNonResidentNames))
                return false;
            ushort offSegTable;
            if (!rdr.TryReadUInt16(out offSegTable))
                return false;
            if (!rdr.TryReadUInt16(out offRsrcTable))
                return false;
            if (!rdr.TryReadUInt16(out offResidentNameTable))
                return false;
            ushort offModuleReferenceTable;
            if (!rdr.TryReadUInt16(out offModuleReferenceTable))
                return false;
            if (!rdr.TryReadUInt16(out offImportedNamesTable))
                return false;
            uint offNonResidentNameTable;
            if (!rdr.TryReadUInt32(out offNonResidentNameTable))
                return false;
            ushort cMoveableEntryPoints;
            if (!rdr.TryReadUInt16(out cMoveableEntryPoints))
                return false;
            if (!rdr.TryReadUInt16(out cbFileAlignmentShift))
                return false;
            ushort cResourceTableEntries;
            if (!rdr.TryReadUInt16(out cResourceTableEntries))
                return false;
            byte bTargetOs;
            if (!rdr.TryReadByte(out bTargetOs))
                return false;
            byte bOsExeFlags;
            if (!rdr.TryReadByte(out bOsExeFlags))
                return false;
            ushort offGanglands;
            if (!rdr.TryReadUInt16(out offGanglands))
                return false;
            ushort cbGanglands;
            if (!rdr.TryReadUInt16(out cbGanglands))
                return false;
            ushort cbMinCodeSwapArea;
            if (!rdr.TryReadUInt16(out cbMinCodeSwapArea))
                return false;
            ushort wWindowsVersion;
            if (!rdr.TryReadUInt16(out wWindowsVersion))
                return false;

            LoadModuleTable(this.lfaNew + offModuleReferenceTable, cModules);
            LoadSegments(this.lfaNew + offSegTable);
            this.addrEntry = segments[cs - 1].Address + ip;
            return true;
        }


        struct NE_NAMEINFO {
    ushort  offset;
    ushort  length;
    ushort  flags;
    ushort  id;
    ushort  handle;
    ushort  usage;
}

         struct NE_TYPEINFO
        {
    ushort type_id;
        ushort count;
        uint resloader;
    };

        private void DumpResources()
        {
            var res_ptr = new LeImageReader(RawImage, this.lfaNew  + offRsrcTable);
            var rdr = res_ptr.Clone();
            //const void* res_ptr = (const char*)ne + ne->ne_rsrctab;
            ushort size_shift = rdr.ReadLeUInt16();
                //NE_TYPEINFO* info = (const NE_TYPEINFO*)((const WORD*)res_ptr + 1);

                int count;

                //printf("\nResources:\n");
            ushort type_id = rdr.ReadLeUInt16();
                while (type_id != 0) //&& (const char*)info < (const char*)ne + ne->ne_restab)
    {
                ushort typeCount = rdr.ReadLeUInt16();
                uint resLoader = rdr.ReadLeUInt32();
                Debug.Print("{0}s (loader: {1:X8})", GetResourceType(type_id), resLoader);
                for (count = typeCount; count > 0; --count)
                {
                    ushort nameOffset = rdr.ReadLeUInt16();
                    ushort nameLength = rdr.ReadLeUInt16();
                    ushort nameFlags = rdr.ReadLeUInt16();
                    ushort nameId = rdr.ReadLeUInt16();
                    ushort nameHandle = rdr.ReadLeUInt16();
                    ushort nameUsage = rdr.ReadLeUInt16();

                    if ((nameId & 0x8000) != 0)
                        Debug.Write(string.Format("  {0}", (nameId & ~0x8000)));
                    else
                    {
                        //Debug.Write(string.Format("  %.*s", *((const unsigned char*)res_ptr + name->id),
                        // (const char*)res_ptr + name->id + 1 );
                        var name = ReadByteLengthString(res_ptr, nameId);
                        Debug.Write(string.Format("  {0}", name));
                    }
                    if ((type_id & 0x8000) != 0)
                        Debug.Write(string.Format(" {0}", GetResourceType(type_id)));
                    else
                        Debug.Write(string.Format(" {0}", ReadByteLengthString(res_ptr, type_id)));
                    Debug.Print(" flags {0:X4} length {1:X4}", nameFlags, (int)nameLength << size_shift);
                    if (type_id == NE_RSCTYPE_BITMAP)
                    {
                        var offset = (uint)nameOffset << size_shift;
                        var rdrRsrc = new LeImageReader(base.RawImage, offset);
                        var rsrc =  rdrRsrc.ReadBytes((uint)nameLength << size_shift);
                        var sig = LoadedImage.ReadBeUInt16(rsrc, 0);
                    }
                    //dump_data(PRD((uint)nameOffset << size_shift, (uint)nameLength << size_shift),
                    //           nameLength << size_shift, "    ");
                }
                type_id = rdr.ReadLeUInt16();
            }

        }


        string ReadByteLengthString(ImageReader rdr, int offset)
        {
            var clone = rdr.Clone();
            clone.Offset = (ulong)((long)clone.Offset + offset);
            var len = clone.ReadByte();
            var abStr = clone.ReadBytes(len);
            return Encoding.ASCII.GetString(abStr);
        }

        string GetResourceType(ushort id)
        {
            switch (id)
            {
            case NE_RSCTYPE_CURSOR: return "CURSOR";
            case NE_RSCTYPE_BITMAP: return "BITMAP";
            case NE_RSCTYPE_ICON: return "ICON";
            case NE_RSCTYPE_MENU: return "MENU";
            case NE_RSCTYPE_DIALOG: return "DIALOG";
            case NE_RSCTYPE_STRING: return "STRING";
            case NE_RSCTYPE_FONTDIR: return "FONTDIR";
            case NE_RSCTYPE_FONT: return "FONT";
            case NE_RSCTYPE_ACCELERATOR: return "ACCELERATOR";
            case NE_RSCTYPE_RCDATA: return "RCDATA";
            case NE_RSCTYPE_GROUP_CURSOR: return "CURSOR_GROUP";
            case NE_RSCTYPE_GROUP_ICON: return "ICON_GROUP";
            default: return id.ToString("X4");
            }
        }

        public override Program Load(Address addrLoad)
        {
            var cfgSvc = Services.RequireService<IConfigurationService>();
            this.arch = cfgSvc.GetArchitecture("x86-protected-16");
            var platform = cfgSvc.GetEnvironment("win16").Load(Services, arch);
            DumpResources();

            var program = new Program(
                this.image,
                this.imageMap,
                arch,
                platform);
            foreach (var impRef in this.importStubs.Values)
            {
                program.ImportReferences.Add(impRef.Item1, impRef.Item2);
            }
            return program;
        }

        public override RelocationResults Relocate(Program program, Address addrLoad)
        {
            var entryNames = LoadEntryNames();
            var entryPoints = LoadEntryPoints(entryNames);
            entryPoints.Add(new EntryPoint(addrEntry, arch.CreateProcessorState()));
            return new RelocationResults(
                entryPoints,
                new RelocationDictionary(),
                new List<Address>());
        }

        public Dictionary<int, string> LoadEntryNames()
        {
            var rdr = new LeImageReader(RawImage, this.lfaNew + this.offResidentNameTable);
            var dict = new Dictionary<int, string>();
            for (;;)
            {
                var cChar = rdr.ReadByte();
                if (cChar == 0)
                    break;
                var abName = rdr.ReadBytes(cChar);
                var name = Encoding.ASCII.GetString(abName);
                int ordinal = rdr.ReadLeInt16();
                dict[ordinal] = name;
            }
            return dict;
        }

        public List<EntryPoint> LoadEntryPoints(Dictionary<int, string> names)
        {
            var rdr = new LeImageReader(RawImage, this.lfaNew + this.offEntryTable);
            var entries = new List<EntryPoint>();
            for (;;)
            {
                var cEntries = rdr.ReadByte();
                if (cEntries == 0)
                    break;
                var segNum = rdr.ReadByte();
                var seg = this.segments[segNum - 1];
                for (int i = 0; i < cEntries; ++i)
                {
                    var flags = rdr.ReadByte();
                    var offset = rdr.ReadUInt16();
                    string name;
                    var addr = seg.Address + offset;
                    var state = arch.CreateProcessorState();
                    EntryPoint ep;
                    if (names.TryGetValue(entries.Count, out name))
                    {
                        ep = new EntryPoint(addr, name, state);
                    }
                    else
                    {
                        ep = new EntryPoint(addr, state);
                    }
                    entries.Add(ep);
                }
            }
            return entries; 
        }

        public class NeSegment
        {
            public ushort DataOffset;
            public ushort DataLength;
            public ushort Flags;
            public ushort Alloc;

            public uint LinearAddress;
            public Address Address;
        }

        void LoadModuleTable(uint offset, int cModules)
        {
            var rdr = new LeImageReader(RawImage, offset);
            this.moduleNames = new List<string>();
            for (int i = 0; i < cModules; ++i)
            {
                uint nameOffset = rdr.ReadLeUInt16();
                if (nameOffset == 0)
                    break;
                nameOffset += lfaNew + this.offImportedNamesTable;
                var rdrName = new LeImageReader(RawImage, nameOffset);
                byte length = rdrName.ReadByte();
                byte[] abModuleName = rdrName.ReadBytes(length);
                var moduleName = Encoding.ASCII.GetString(abModuleName);
                moduleNames.Add(moduleName);
            }
        }

        void LoadSegments(uint offset)
        {
            this.segments = ReadSegmentTable(offset, cSeg);
            var segFirst = segments[0];
            var segLast = segments[segments.Length - 1];
            this.image = new LoadedImage(
                PreferredBaseAddress,
                new byte[segLast.LinearAddress + segLast.DataLength]);
            this.imageMap = image.CreateImageMap();
            foreach (var segment in segments)
            {
                LoadSegment(segment, image, imageMap);
            }
        }

        private NeSegment[] ReadSegmentTable(uint offset, int cSeg)
        {
            var segs = new List<NeSegment>(cSeg);
            var rdr = new LeImageReader(RawImage, offset);
            uint linAddress = 0x2000;
            for (int iSeg = 0; iSeg < cSeg; ++iSeg)
            {
                var seg = new NeSegment
                {
                    DataOffset = rdr.ReadLeUInt16(),
                    DataLength = rdr.ReadLeUInt16(),
                    Flags = rdr.ReadLeUInt16(),
                    Alloc = rdr.ReadLeUInt16()
                };
                uint cbSegmentPage = Math.Max(seg.Alloc, seg.DataLength);
                // We allocate segments on 4 kb boundaries for convenience,
                // but protected mode code must never assume addresses are
                // linear.
                // Align to 4kb boundary.
                cbSegmentPage = (cbSegmentPage + 0xFFFu) & ~0xFFFu;
                seg.LinearAddress = linAddress;
                seg.Address = Address.ProtectedSegPtr((ushort)((linAddress >> 9) | 7), 0);
                segs.Add(seg);
                linAddress += cbSegmentPage;
            }

            // Generate pseudo-segment for imports
            addrImportStubs = Address.ProtectedSegPtr((ushort)((linAddress >> 9) | 7), 0);

            return segs.ToArray();
        }

        bool LoadSegment(NeSegment seg, LoadedImage loadedImage, ImageMap imageMap)
        {
            Array.Copy(
                RawImage,
                (uint)seg.DataOffset << this.cbFileAlignmentShift,
                loadedImage.Bytes,
                seg.LinearAddress - (int)loadedImage.BaseAddress.ToLinear(),
                seg.DataLength);
            var x = seg.Address.ToLinear();

            AccessMode access =
                (seg.Flags & 1) != 0
                    ? AccessMode.ReadWrite
                    : AccessMode.ReadExecute;
            imageMap.AddSegment(
                seg.Address,
                seg.Address.Selector.ToString("X4"),
                access,
                seg.DataLength);

            var rdr = new LeImageReader(
                RawImage,
                seg.DataLength + ((uint)seg.DataOffset << this.cbFileAlignmentShift));
            int count = rdr.ReadLeInt16();
            return ApplyRelocations(rdr, count, seg);
        }

#if NE_
        static void NE_FixupSegmentPrologs(NE_MODULE* pModule, WORD segnum)
        {
            SEGTABLEENTRY* pSegTable = NE_SEG_TABLE(pModule);
            ET_BUNDLE* bundle;
            ET_ENTRY* entry;
            WORD dgroup, num_entries, sel = SEL(pSegTable[segnum - 1].hSeg);
            BYT* pSeg, *pFunc;


            if (pSegTable[segnum - 1].flags & NE_SEGFLAGS_DATA)
            {
                pSegTable[segnum - 1].flags |= NE_SEGFLAGS_LOADED;
                return;
            }

            if (!pModule->ne_autodata) return;


            if (!pSegTable[pModule.ne_autodata - 1].hSeg) return;
            dgroup = SEL(pSegTable[pModule.ne_autodata - 1].hSeg);


            pSeg = MapSL(MAKESEGPTR(sel, 0));


            bundle = (ET_BUNDLE*)((BYTE*)pModule + pModule.ne_enttab);


            do {
                Debug.Print("num_entries: {0}, bundle: {1}, next: {2:X4}, pSeg: {3}", bundle.last - bundle.first, bundle, bundle.next, pSeg);
                if (!(num_entries = bundle.last - bundle.first))
                    return;
                entry = (ET_ENTRY*)((BYTE*)bundle + 6);
                while (num_entries--)
                {
                    /*TRACE("entry: %p, entry.segnum: %d, entry.offs: %04x\n", entry, entry.segnum, entry.offs);*/
                    if (entry.segnum == segnum)
                    {
                        pFunc = pSeg + entry.offs;
                        TRACE("pFunc: %p, *(DWORD *)pFunc: %08x, num_entries: %d\n", pFunc, *(DWORD*)pFunc, num_entries);
                        if (*(pFunc + 2) == 0x90)
                        {
                            if (*(WORD*)pFunc == 0x581e) /* push ds, pop ax */
                            {
                                TRACE("patch %04x:%04x -> mov ax, ds\n", sel, entry.offs);
                                *(WORD*)pFunc = 0xd88c; /* mov ax, ds */
                            }


                            if (*(WORD*)pFunc == 0xd88c)
                            {
                                if ((entry.flags & 2)) /* public data ? */
                                {
                                    TRACE("patch %04x:%04x . mov ax, dgroup [%04x]\n", sel, entry.offs, dgroup);
                                    *pFunc = 0xb8; /* mov ax, */
                                    *(WORD*)(pFunc + 1) = dgroup;
                                }
                                else if ((pModule.ne_flags & NE_FFLAGS_MULTIPLEDATA)
                                         && (entry.flags & 1)) /* exported ? */
                                {
                                    TRACE("patch %04x:%04x -> nop, nop\n", sel, entry.offs);
                                    *(WORD*)pFunc = 0x9090; /* nop, nop */
                                }
                            }
                        }
                    }
                    entry++;
                }
            } while ((bundle.next) && (bundle = ((ET_BUNDLE*)((BYTE*)pModule + bundle.next))));
        }
#endif

        public class NeRelocationEntry
        {
            public byte address_type;    // Relocation address type
            public byte relocation_type; // Relocation type
            public ushort offset;          // Offset in segment to fixup
            public ushort target1;         // Target specification
            public ushort target2;         // Target specification/
        }

        // Apply relocations to a segment.
        bool ApplyRelocations(ImageReader rdr, int cRelocations, NeSegment seg)
        {
            string module = "";
            Address address = null;
            NeRelocationEntry rep = null;
            for (int i = 0; i < cRelocations; i++)
            {
                rep = new NeRelocationEntry
                {
                    address_type = rdr.ReadByte(),
                    relocation_type = rdr.ReadByte(),
                    offset = rdr.ReadLeUInt16(),
                    target1 = rdr.ReadLeUInt16(),
                    target2 = rdr.ReadLeUInt16(),
                };

                // Get the target address corresponding to this entry.

                // If additive, there is no target chain list. Instead, add source
                //  and target.
                bool additive = (rep.relocation_type & NE_RELFLAG_ADDITIVE) != 0;
                Tuple<Address, ImportReference> impRef;
                uint lp;
                switch (rep.relocation_type & 3)
                {
                case NE_RELTYPE_ORDINAL:
                    module = moduleNames[rep.target1 - 1];
                    // Synthesize an import 
                    lp = ((uint)rep.target1 << 16) | rep.target2;
                    if (importStubs.TryGetValue(lp, out impRef))
                    {
                        address = impRef.Item1;
                    }
                    else
                    {
                        address = addrImportStubs;
                        importStubs.Add(lp, new Tuple<Address, ImportReference>(
                            address,
                            new OrdinalImportReference(address, module, rep.target2)));
                        addrImportStubs += 8;
                    }
                    break;

                case NE_RELTYPE_NAME:
                    module = moduleNames[rep.target1 - 1];
                    uint offName = lfaNew + this.offImportedNamesTable + rep.target2;
                    var nameRdr = new LeImageReader(RawImage, offName);
                    byte fnNameLength = nameRdr.ReadByte();
                    var abFnName = nameRdr.ReadBytes(fnNameLength);
                    lp = ((uint)rep.target1 << 16) | rep.target2;
                    if (importStubs.TryGetValue(lp, out impRef))
                    {
                        address = impRef.Item1;
                    }
                    else
                    {
                        address = addrImportStubs;
                        string fnName = Encoding.ASCII.GetString(abFnName);
                        importStubs.Add(lp, new Tuple<Address, ImportReference>(
                            address,
                            new NamedImportReference(address, module, fnName)));
                    }
                    break;
                case NE_RELTYPE_INTERNAL:
                    if ((rep.target1 & 0xff) == 0xff)
                    {
                        throw new NotImplementedException();
                    }
                    else
                    {
                        address = segments[rep.target1 - 1].Address + rep.target2;
                    }
                    Debug.Print("{0}: {1:X4}:{2:X4} {3}",
                          i + 1, address.Selector, address.Selector,
                          "");
                    break;
                case NE_RELTYPE_OSFIXUP:
                    /* Relocation type 7:
                     *
                     *    These appear to be used as fixups for the Windows
                     * floating point emulator.  Let's just ignore them and
                     * try to use the hardware floating point.  Linux should
                     * successfully emulate the coprocessor if it doesn't
                     * exist.
                     */
                    /*
                   TRACE("%d: TYPE %d, OFFSET %04x, TARGET %04x %04x %s\n",
                         i + 1, rep->relocation_type, rep->offset,
                         rep->target1, rep->target2,
                         NE_GetRelocAddrName( rep->address_type, additive ) );
                   */
                    continue;
                }
                ushort offset = rep.offset;

                // Apparently, high bit of address_type is sometimes set;
                // we ignore it for now.
                if (rep.address_type > NE_RADDR_OFFSET32)
                {
                    diags.Error(
                        string.Format(
                            "Module {0}: unknown relocation address type {1:X2}. Please report",
                            module, rep.address_type));
                    return false;
                }

                if (additive)
                {
                    var sp = seg.Address + offset;
                    Debug.Print("    {0:X4}:{0:X4}", offset, offset);
                    byte b;
                    ushort w;
                    switch (rep.address_type & 0x7f)
                    {
                    case NE_RADDR_LOWBYTE:
                        b = image.ReadByte(sp);
                        image.WriteByte(sp, (byte)(b + address.Offset));
                        break;
                    case NE_RADDR_OFFSET16:
                        w = image.ReadLeUInt16(sp);
                        image.WriteLeUInt16(sp, (ushort)(w + address.Offset));
                        break;
                    case NE_RADDR_POINTER32:
                        w = image.ReadLeUInt16(sp);
                        image.WriteLeUInt16(sp, (ushort)(w + address.Offset));
                        image.WriteLeUInt16(sp + 2, address.Selector);
                        break;
                    case NE_RADDR_SELECTOR:
                        // Borland creates additive records with offset zero. Strange, but OK.
                        w = image.ReadLeUInt16(sp);
                        if (w != 0)
                            diags.Error(string.Format("Additive selector to {0:X4}. Please report.", w));
                        else
                            image.WriteLeUInt16(sp, address.Selector);
                        break;
                    default:
                        goto unknown;
                    }
                }
                else
                {
                    // Non-additive fixup.
                    do
                    {
                        var sp = seg.Address + offset;
                        ushort next_offset = image.ReadLeUInt16(sp);
                        Debug.Print("    {0:X4}:{0:X4}", offset, next_offset);
                        switch (rep.address_type & 0x7f)
                        {
                        case NE_RADDR_LOWBYTE:
                            image.WriteByte(sp, (byte)address.Offset);
                            break;
                        case NE_RADDR_OFFSET16:
                            image.WriteLeUInt16(sp, (ushort)address.Offset);
                            break;
                        case NE_RADDR_POINTER32:
                            image.WriteLeUInt16(sp, (ushort)address.Offset);
                            image.WriteLeUInt16(sp + 2, address.Selector);
                            break;
                        case NE_RADDR_SELECTOR:
                            image.WriteLeUInt16(sp, address.Selector);
                            break;
                        default:
                            goto unknown;
                        }
                        if (next_offset == offset) break;  // avoid infinite loop 
                        if (next_offset >= seg.Alloc)
                            break;
                        offset = next_offset;
                    } while (offset != 0xffff);
                }
            }
            return true;

            unknown:
            var svc = Services.RequireService<IDiagnosticsService>();
            svc.Warn(string.Format("{0}: unknown ADDR TYPE {1},  " +
                "TYPE {2},  OFFSET {3:X4},  TARGET {4:X4} {5:X4}",
                seg.Address.Selector, rep.address_type, rep.relocation_type,
                rep.offset, rep.target1, rep.target2));
            return false;
        }

    }
}
