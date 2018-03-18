﻿#region License
/* 
 * Copyright (C) 2017-2018 Christian Hostelet.
 * inspired by work of:
 * Copyright (C) 1999-2017 John Källén.
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
using Reko.Core.Expressions;
using Reko.Libraries.Microchip;

namespace Reko.Arch.Microchip.PIC16
{
    using Common;

    internal class PIC16BasicMode : PICProcessorMode
    {
        public override string ArchitectureID => "pic16";

        public override PICArchitecture CreateArchitecture()
            => new PIC16Architecture(ArchitectureID, this);

        public override PICDisassemblerBase CreateDisassembler(PICArchitecture arch, EndianImageReader rdr)
            => PIC16BasicDisasm.Create(arch, rdr);

        public override void CreateRegisters()
            => PIC16BasicRegisters.Create(PICDescriptor);

        public override PICRewriter CreateRewriter(PICArchitecture arch, PICDisassemblerBase dasm, PICProcessorState state, IStorageBinder binder, IRewriterHost host)
            => PIC16BasicRewriter.Create(arch, dasm, state, binder, host);

        public override Address MakeAddressFromConstant(Constant c)
            => Address.Ptr32(c.ToUInt32());

        public override PICProcessorState CreateProcessorState(PICArchitecture arch)
            => new PIC16State(arch);
    }

    internal class PIC16EnhancedMode : PICProcessorMode
    {
        public override string ArchitectureID => "pic16";

        public override PICArchitecture CreateArchitecture()
            => new PIC16Architecture(ArchitectureID, this);

        public override PICDisassemblerBase CreateDisassembler(PICArchitecture arch, EndianImageReader rdr)
            => PIC16EnhancedDisasm.Create(arch, rdr);

        public override void CreateRegisters()
            => PIC16EnhancedRegisters.Create(PICDescriptor);

        public override PICRewriter CreateRewriter(PICArchitecture arch, PICDisassemblerBase dasm, PICProcessorState state, IStorageBinder binder, IRewriterHost host)
            => PIC16EnhancedRewriter.Create(arch, dasm, state, binder, host);

        public override Address MakeAddressFromConstant(Constant c)
            => Address.Ptr32(c.ToUInt32());

        public override PICProcessorState CreateProcessorState(PICArchitecture arch)
            => new PIC16State(arch);

    }

    internal class PIC16FullMode : PICProcessorMode
    {
        public override string ArchitectureID => "pic16";

        public override PICArchitecture CreateArchitecture()
            => new PIC16Architecture(ArchitectureID, this);

        public override PICDisassemblerBase CreateDisassembler(PICArchitecture arch, EndianImageReader rdr)
            => PIC16FullDisasm.Create(arch, rdr);

        public override void CreateRegisters()
            => PIC16FullRegisters.Create(PICDescriptor);

        public override PICRewriter CreateRewriter(PICArchitecture arch, PICDisassemblerBase dasm, PICProcessorState state, IStorageBinder binder, IRewriterHost host)
            => PIC16FullRewriter.Create(arch, dasm, state, binder, host);

        public override Address MakeAddressFromConstant(Constant c)
            => Address.Ptr32(c.ToUInt32());

        public override PICProcessorState CreateProcessorState(PICArchitecture arch)
            => new PIC16State(arch);

    }

}
