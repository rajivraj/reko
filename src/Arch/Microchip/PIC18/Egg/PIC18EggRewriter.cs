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
using Reko.Core.Machine;
using Reko.Core.Rtl;
using Reko.Core.Types;
using Reko.Libraries.Microchip;
using System;

namespace Reko.Arch.Microchip.PIC18
{
    using Common;

    public class PIC18EggRewriter : PIC18RewriterBase
    {
        private PIC18EggRewriter(PICArchitecture arch, PICDisassemblerBase dasm, PICProcessorState state, IStorageBinder binder, IRewriterHost host)
            : base(arch, dasm, state, binder, host)
        {
        }

        public static PICRewriter Create(PICArchitecture arch, PICDisassemblerBase dasm, PICProcessorState state, IStorageBinder binder, IRewriterHost host)
        {
            return new PIC18EggRewriter(
                arch ?? throw new ArgumentNullException(nameof(arch)),
                dasm ?? throw new ArgumentNullException(nameof(dasm)),
                state ?? throw new ArgumentNullException(nameof(state)),
                binder ?? throw new ArgumentNullException(nameof(binder)),
                host ?? throw new ArgumentNullException(nameof(host))
              );
        }

        protected override void RewriteInstr()
        {
            switch (instrCurr.Opcode)
            {
                default:
                    base.RewriteInstr();
                    break;

                case Opcode.ADDFSR:
                    RewriteADDFSR();
                    break;
                case Opcode.ADDULNK:
                    RewriteADDULNK();
                    break;
                case Opcode.CALLW:
                    RewriteCALLW();
                    break;
                case Opcode.MOVSF:
                    RewriteMOVSF();
                    break;
                case Opcode.MOVSS:
                    RewriteMOVSS();
                    break;
                case Opcode.PUSHL:
                    RewritePUSHL();
                    break;
                case Opcode.SUBFSR:
                    RewriteSUBFSR();
                    break;
                case Opcode.SUBULNK:
                    RewriteSUBULNK();
                    break;
            }

        }

        private void RewriteADDFSR()
        {
            var fsr = GetFSRRegister(instrCurr.op1);
            var k = GetImmediateValue(instrCurr.op2);
            m.Assign(fsr, m.IAdd(fsr, k));
        }

        private void RewriteADDULNK()
        {
            var k = GetImmediateValue(instrCurr.op1);
            m.Assign(Fsr2, m.IAdd(Fsr2, k));
            SetStatusFlags(Fsr2);
            rtlc = RtlClass.Transfer;
            m.Return(0, 0);
        }

        private void RewriteCALLW()
        {

            rtlc = RtlClass.Transfer | RtlClass.Call;

            var pclat = binder.EnsureRegister(PIC18Registers.PCLAT);
            var target = m.Fn(host.PseudoProcedure("__callw", VoidType.Instance, Wreg, pclat));
            var retaddr = instrCurr.Address + instrCurr.Length;
            var tos = binder.EnsureRegister(PIC18Registers.TOS);

            var dst = PushToHWStackAccess();
            m.Assign(dst, retaddr);
            m.Assign(tos, retaddr);
            m.Call(target, 0);
        }

        private void RewriteMOVSF()
        {
            var zs = GetFSR2IdxAddress(instrCurr.op1);
            var (indMode, memPtr) = GetUnaryAbsPtrs(instrCurr.op2, out Expression memExpr);
            ArithAssignIndirect(memExpr, zs, indMode, memPtr);
        }

        private void RewriteMOVSS()
        {
            var zs = GetFSR2IdxAddress(instrCurr.op1);
            var zd = GetFSR2IdxAddress(instrCurr.op2);
            m.Assign(zd, zs);
        }

        private void RewritePUSHL()
        {
            var k = GetImmediateValue(instrCurr.op1);
            m.Assign(DataMem8(Fsr2), k);
            m.Assign(Fsr2, m.IAdd(Fsr2, 1));
        }

        private void RewriteSUBFSR()
        {
            var fsr = GetFSRRegister(instrCurr.op1);
            var k = GetImmediateValue(instrCurr.op2);
            m.Assign(fsr, m.ISub(fsr, k));
        }

        private void RewriteSUBULNK()
        {
            rtlc = RtlClass.Transfer;

            var k = GetImmediateValue(instrCurr.op1);
            var tos = binder.EnsureRegister(PIC18Registers.TOS);

            m.Assign(Fsr2, m.ISub(Fsr2, k));
            var src = PopFromHWStackAccess();
            m.Assign(tos, src);
            m.Return(0, 0);
        }


        private Expression GetFSR2IdxAddress(MachineOperand op)
        {
            switch (op)
            {
                case PIC18FSR2IdxOperand fsr2idx:
                    return DataMem8(m.IAdd(Fsr2, fsr2idx.Offset));

                default:
                    throw new InvalidOperationException($"Invalid FSR2 indexed address operand.");
            }
        }

    }

}
