// VCExeSample.c
// Generated by decompiling VCExeSample.exe
// using Reko decompiler version 0.6.2.0.

#include "VCExeSample.h"

int32 main(int32 argc, char * * argv)
{
	test1(*argv, argc, "test123", 1.0F);
	return 0x00;
}

void test1(char * arg1, int32 arg2, char * arg3, real32 arg4)
{
	printf("%s %d %s %f", arg1, arg2, arg3, (real64) arg4);
	return;
}

void test2(word32 dwArg04)
{
	test1("1", 0x02, "3", globals->r4020E8);
	if (dwArg04 == 0x00)
		test1("5", 0x06, "7", globals->r4020E4);
	return;
}

void indirect_call_test3(cdecl_class * c)
{
	c->vtbl->method04(c, 1000);
	return;
}

void test4()
{
	globals->gbl_c->vtbl->method00(globals->gbl_c);
	return;
}

void test5()
{
	globals->gbl_c->vtbl->method04(globals->gbl_c, 999, globals->r4020EC);
	return;
}

void test6(Eq_63 c, int32 a, int32 b)
{
	c->vtbl->method04(c, c->vtbl->sum(c, a, b));
	return;
}

void test7(real64 rArg04)
{
	if (1.0 < rArg04)
		globals->gbl_thiscall->vtbl->set_double(globals->gbl_thiscall, rArg04);
	globals->gbl_thiscall->vtbl->modify_double(globals->gbl_thiscall, 0x0D, rArg04);
	return;
}

word32 nested_if_blocks_test8(real64 rArg04, real64 rArg0)
{
	globals->gbl_thiscall->vtbl->modify_double(globals->gbl_thiscall, ~0x00, rArg04);
	if (globals->r4020F8 != rArg04 && globals->r4020F0 > rArg04)
		globals->gbl_thiscall->vtbl->set_double(globals->gbl_thiscall, rArg04);
	test6(globals->gbl_c, 0x06, 0x07);
	return ebp;
}

void loop_test9(real32 rArg04, real64 rArg0)
{
	word32 dwLoc08_12 = 0x00;
	while (true)
	{
		globals->gbl_thiscall->vtbl->modify_double(globals->gbl_thiscall, dwLoc08_12, (real64) rArg04);
		if (rArg0 <= (real64) dwLoc08_12)
			break;
		rArg0 = (real64) rArg04;
		globals->gbl_thiscall->vtbl->set_double(globals->gbl_thiscall, rArg0);
		dwLoc08_12 = dwLoc08_12 + 0x01;
	}
	return;
}

void const_div_test10(word32 dwArg04)
{
	uint32 eax_16 = 0x0A;
	uint32 ecx_19 = 0x03;
	if (dwArg04 != 0x00)
	{
		eax_16 = 0x03;
		ecx_19 = 0x01;
	}
	globals->dw40301C = ecx_19;
	globals->dw403020 = eax_16;
	return;
}

void loop_test11(word32 ecx, word32 ebp)
{
	struct Eq_223 * ebp_19 = fp - 0x04;
	while (*(ebp_19 - 0x04) > 0x00)
	{
		ui32 eax_26 = *(ebp_19 - 0x04);
		ui32 eax_27 = eax_26 & 0x80000001;
		if ((eax_26 & 0x80000001) < 0x00)
			eax_27 = ((eax_26 & 0x80000001) - 0x01 | ~0x01) + 0x01;
		if (eax_27 == 0x00)
		{
			*(ebp_19 - 0x08) = (real32) ebp_19->r0008;
			real64 rLoc1_44 = (real64) *(ebp_19 - 0x08);
			*(fp - 0x10) = ecx;
			*(fp - 0x10) = (real32) rLoc1_44;
			loop_test9(rArg00, rArg0);
		}
		else
		{
			*(fp - 0x14) = ebp_19->r0008;
			ebp_19 = nested_if_blocks_test8(rArg00, rArg0);
		}
		word32 ecx_38 = *(ebp_19 - 0x04);
		*(ebp_19 - 0x04) = ecx_38 - 0x01;
		ecx = ecx_38 - 0x01;
	}
	return;
}

