// STRLEN.c
// Generated by decompiling STRLEN
// using Reko decompiler version 0.6.2.0.

#include "STRLEN.h"

void fn00001000(int32 d0, byte * a0)
{
	struct Eq_4 * a6_8 = *(struct Eq_4 **) 0x04;
	int32 d2_235 = d0;
	byte * a2_247 = a0;
	if (a6_8->w0014 < 0x24)
	{
		word32 * a0_502 = &globals->ptr13C8;
		word32 d0_505 = 0x0C;
		do
		{
			*a0_502 = 0x00;
			a0_502 = a0_502 + 0x01;
			d0_505 = d0_505 - 0x01;
		} while (d0_505 != 0x00);
	}
	globals->ptr13C8 = fp;
	globals->ptr13CC = a6_8;
	struct Eq_25 * d0_19 = FindTask(0x00);
	struct Eq_31 * d0_112 = OpenLibrary(0x12BC, 0x00);
	if (d0_112 != null)
	{
		int32 d4_457;
		globals->ptr13D0 = d0_112;
		if (d0_19->ptr00AC == null)
		{
			d4_457 = 0x02;
			d2_235 = 0x08;
		}
		else
		{
			byte * a0_460 = a0;
			d4_457 = 0x03;
			do
			{
				if (*a0_514 == 0x20)
					d4_457 = DPB(d4_457, (word16) d4_457 + 0x01, 0);
				a0_460 = a0_514 + 0x01;
				byte * a0_514 = a0_460;
			} while (*a0_514 != 0x00);
		}
		int32 d0_105 = d4_457 << 0x02;
		int32 d0_107 = d0_105 + d2_235;
		int32 d1_111 = 0x00010001;
		d0_112 = AllocMem(d0_107 + 0x11, 0x00010001);
		if (d0_112 != null)
		{
			struct Eq_67 * dwLoc14_159;
			word32 a0_164;
			d0_112->dw0000 = d0_107 + 0x11;
			int32 d4_123 = d4_457 - 0x01;
			d0_112->dw000C = d4_123;
			d0_112->ptr0008 = d0_112->dw000C + 0x01 + d0_105 / 0x0010;
			Mem131[0x00:word32] = 0x00;
			struct Eq_67 * d0_132 = d0_19->ptr00AC;
			d0_132->ptr0000 = d0_107 + 0x11;
			d0_132->dw000C = d4_123 - 0x01;
			d0_132->ptr0008 = (byte *) (&d0_132->ptr0010 + d0_105 / 0x0028);
			Mem150[0x00:word32] = 0x00;
			struct Eq_67 * d0_151 = d0_19->ptr00AC;
			if (d0_151 == null)
			{
				fn00001214(d0_19);
				globals->ptr13D4 = d0_151;
				globals->ptr13D8 = d0_151;
				Mem401[0x00:word32] = 0x00;
				dwLoc14_159 = d0_151;
				ui32 d0_404 = d0_151->dw0024;
				if (d0_404 != 0x00)
					Enable();
				Supervisor(d0_132);
				d0_132->dw0004 = d0_404;
				if (d0_404 == 0x00)
				{
					fn0000127C(0x0014);
					return;
				}
				globals->dw13DC = d0_404;
				*(ui32 *) 5088 = d0_404;
				*(ui32 *) 0x13E4 = d0_404;
				d0_19->dw009C = d0_404;
				d0_19->dw00A0 = d0_404;
				word32 d0_429 = ((word32[]) 0x08)[d0_404];
				if (d0_429 != 0x00)
					d0_19->dw00A4 = d0_429;
l000011F8:
				a0_164 = d0_19->dw003A;
				goto l00001202;
			}
			ui32 d0_202 = ((ui32[]) 0x0010)[d0_151];
			Eq_202 (* a0_209)[] = (d0_202 << 0x02) + 0x01;
			int32 d0_210 = (int32) null[d0_202].b0000;
			Mem211[a0_209 + d0_210:byte] = 0x00;
			d0_132->ptr0010 = a0_209;
			ui32 d0_217 = ((ui32[]) 0x0010)[d0_210];
			byte * a1_220 = d0_132->ptr0008;
			Eq_202 (* a0_225)[] = (d0_217 << 0x02) + 0x01;
			int32 d0_226 = (int32) null[d0_217].b0000;
			Mem227[a0_225 + d0_226:byte] = 0x00;
			d0_132->ptr0010 = a0_225;
			word32 * a6_230 = &((char *) d0_132->ptr0010 + 0x04);
			int32 d3_231 = 0x01;
			struct Eq_239 * a0_233 = a0 + d2_235;
l000010DA:
			a0_233 = a0_233 - 0x01;
			if (a0_233->b0000 > 0x20)
			{
				d2_235 = d2_235 - 0x01;
				if (d2_235 != ~0x00)
					goto l000010DA;
			}
			a0_233[0x01] = (struct Eq_239) 0x00;
			do
			{
l000010E6:
				byte v37_256 = *a2_247;
				a2_247 = a2_247 + 0x01;
				d1_111 = DPB(d1_111, v37_256, 0);
				if (v37_256 == 0x00)
					goto l00001148;
			} while (v37_256 == 0x20 || v37_256 == 0x09);
			if (d3_231 - d0_132->dw000C != 0x00)
			{
				*a6_230 = a1_220;
				a6_230 = a6_230 + 0x01;
				d3_231 = DPB(d3_231, (word16) d3_231 + 0x01, 0);
				if (v37_256 != 0x22)
				{
					*a1_220 = v37_256;
					a1_220 = a1_220 + 0x01;
					while (true)
					{
						byte v45_338 = *a2_247;
						a2_247 = a2_247 + 0x01;
						d1_111 = DPB(d1_111, v45_338, 0);
						if (v45_338 == 0x00)
							break;
						if (v45_338 == 0x20)
							goto l00001116;
						*a1_220 = v45_338;
						a1_220 = a1_220 + 0x01;
					}
				}
				else
				{
					while (true)
					{
						byte v70_354 = *a2_247;
						a2_247 = a2_247 + 0x01;
						d1_111 = DPB(d1_111, v70_354, 0);
						if (v70_354 == 0x00)
							break;
						if (v70_354 == 0x22)
						{
l00001116:
							*a1_220 = 0x00;
							a1_220 = a1_220 + 0x01;
							goto l000010E6;
						}
						if (v70_354 == 0x2A)
						{
							byte v73_373 = *a2_247;
							a2_247 = a2_247 + 0x01;
							d1_111 = DPB(d1_111, v73_373, 0);
							if ((v73_373 & 223) == 0x4E)
								d1_111 = 0x0A;
							else if ((v73_373 & 223) == 0x45)
								d1_111 = 0x001B;
						}
						*a1_220 = (byte) d1_111;
						a1_220 = a1_220 + 0x01;
					}
				}
			}
l00001148:
			*a1_220 = 0x00;
			*a6_230 = 0x00;
			execPrivate4();
			globals->dw13DC = d0_226;
			execPrivate5();
			*(int32 *) 5088 = d0_226;
			dwLoc14_159 = &d0_132->ptr0010;
			dwLoc18 = d3_231;
			if (globals->ptr13CC->w0014 >= 0x24)
			{
				word32 v87_298 = d0_19->dw00E0;
				*(word32 *) 0x13E4 = v87_298;
				if (v87_298 != 0x00)
				{
l0000117E:
					if (d0_19->b0008 == 0x0D)
					{
						word32 * a0_288 = d0_19->ptr00B0;
						a0_164 = a0_288 + 0x01 - *a0_288;
l00001202:
						*(word32 *) 0x13F0 = a0_164;
						*(ptr32 *) 0x13F4 = fp - 0x18;
						fn00001354(dwLoc18, dwLoc14_159);
						fn0000127C(0x00);
						return;
					}
					goto l000011F8;
				}
			}
			*(int32 *) 0x13E4 = d0_226;
			goto l0000117E;
		}
		CloseLibrary(globals->ptr13D0);
		Alert(0x00010000);
	}
	else
		Alert(0x00038007);
	if (d0_19->ptr00AC == null)
	{
		fn00001214(d0_19);
		fn0000126C(d0_112);
	}
	return;
}

void fn00001214(Eq_25 * a3)
{
	WaitPort(&((char *) a3->dw003A + 0x0022));
	GetMsg(&((char *) a3->dw003A + 0x0022));
	return;
}

void fn0000126C(Eq_31 * a2)
{
	Forbid();
	ReplyMsg(a2);
	return;
}

void fn00001278(word32 dwArg04)
{
	fn0000127C(dwArg04);
	return;
}

void fn0000127C(int32 d2)
{
	ptr32 a7_3 = globals->ptr13C8;
	struct Eq_528 * v8_8 = *(a7_3 - 0x04);
	struct Eq_31 * v6_5 = *(a7_3 - 0x08);
	if (v8_8->dw0004 != 0x00)
		execPrivate1();
	CloseLibrary(globals->ptr13D0);
	if (v6_5 != null)
		fn0000126C(v6_5);
	FreeMem(v8_8, v8_8->dw0000);
	return;
}

void fn000012D0(word32 dwArg04)
{
	Eq_600 a3_11[] = (Eq_600 (*)[]) 0x1404;
	if (0x1404 != 0x00)
	{
		int32 d2_39 = 0x01;
		if (*(word32 *) 0x1408 != 0x00)
		{
			do
				d2_39 = d2_39 + 0x01;
			while (((word32[]) 0x1404)[d2_39] != 0x00);
		}
		int32 d2_49 = d2_39 - 0x01;
		if (d2_49 != 0x00)
		{
			do
			{
				int32 d0_55 = d2_49 << 0x02;
				Eq_600 a2_57 = a3_11[d0_55].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00].a0000[0x00];
				word32 a7_59;
				word32 a2_61;
				word32 d2_62;
				word32 d0_63;
				byte CVZN_64;
				byte Z_65;
				byte ZN_66;
				byte C_67;
				byte V_68;
				byte CVZNX_69;
				a2_57();
				d2_49 = d2_62 - 0x01;
			} while (d2_62 != 0x01);
		}
	}
	fn00001278(dwArg04);
	return;
}

void fn0000131C(word32 dwArg04)
{
	if (*(word32 *) 5112 == 0x00)
	{
		struct Eq_624 * a3_28 = *(struct Eq_624 **) 0x140C;
		*(int32 *) 5112 = 0x01;
		if (a3_28 != null)
		{
			do
			{
				<anonymous> * a2_50 = a3_28->ptr0004;
				word32 a7_51;
				struct Eq_624 ** a3_52;
				word32 a2_53;
				byte ZN_54;
				byte C_55;
				byte V_56;
				byte Z_57;
				word32 d0_58;
				byte CVZN_59;
				a2_50();
				a3_28 = (struct Eq_624 *) *a3_52;
			} while (a3_28 != null);
		}
		fn000012D0(dwArg04);
	}
	return;
}

void fn00001354(int32 dwArg04, Eq_67 * dwArg08)
{
	<anonymous> ** a3_45 = (<anonymous> **) 0x1400;
	if (5116 != 0x00 && *((word32 *) 0x1400) != 0x00)
	{
		do
		{
			word32 a7_52;
			word32 a2_54;
			word32 d0_55;
			byte CVZN_56;
			byte Z_57;
			byte ZN_58;
			byte C_59;
			byte V_60;
			(*a3_45)();
		} while (*a3_45 != null);
	}
	fn0000131C(fn00001390());
	return;
}

word32 fn00001390()
{
	return fn000013AC(0x13A4);
}

int32 fn000013AC(ptr32 dwArg04)
{
	byte * a1_11 = dwArg04;
	int32 d0_17 = 0x00;
	while (true)
	{
		a1_11 = a1_11 + 0x01;
		if (*a1_11 == 0x00)
			break;
		d0_17 = d0_17 + 0x01;
	}
	return d0_17;
}

