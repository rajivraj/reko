// pngpixel.c
// Generated by decompiling pngpixel
// using Reko decompiler version 0.7.2.0.

#include "pngpixel.h"

// 0000000000400AE8: void _init()
void _init()
{
	word64 rax_4 = globals->qw601FF8;
	if (rax_4 != 0x00)
	{
		word64 rsp_15;
		byte SCZO_16;
		word64 rax_17;
		byte SZO_18;
		byte C_19;
		byte Z_20;
		png_get_PLTE();
	}
}

// 0000000000400CD0: void _start(Register (ptr Eq_16) rdx, Stack Eq_17 qwArg00)
void _start( * rdx, Eq_17 qwArg00)
{
	__align((char *) fp + 0x08);
	__libc_start_main(&globals->t4012F9, qwArg00, (char *) fp + 0x08, &globals->t401780, &globals->t4017F0, rdx, fp);
	__hlt();
}

// 0000000000400D00: void deregister_tm_clones(Register word64 r8)
void deregister_tm_clones(word64 r8)
{
	if (false || 0x00 == 0x00)
		;
	else
	{
		word64 rsp_42;
		word32 eax_43;
		word64 rax_44;
		word64 rbp_45;
		word64 r8_46;
		byte SCZO_47;
		byte CZ_48;
		byte SZO_49;
		byte C_50;
		byte Z_51;
		word32 edi_52;
		word64 rdi_53;
		eax();
	}
}

// 0000000000400D40: void register_tm_clones()
void register_tm_clones()
{
	if (0x00 == 0x00 || 0x00 == 0x00)
		;
	else
	{
		word64 rsp_42;
		word64 rsi_43;
		word64 rbp_44;
		byte SCZO_45;
		word64 rax_46;
		byte Z_47;
		byte SZO_48;
		byte C_49;
		word64 rdi_50;
		word32 eax_51;
		eax();
	}
}

// 0000000000400D80: void __do_global_dtors_aux(Register word64 r8)
void __do_global_dtors_aux(word64 r8)
{
	if (globals->b602108 == 0x00)
	{
		deregister_tm_clones(r8);
		globals->b602108 = 0x01;
	}
}

// 0000000000400DA0: void frame_dummy()
void frame_dummy()
{
	if (globals->qw601E10 != 0x00 && 0x00 != 0x00)
	{
		word64 rsp_39;
		word32 edi_40;
		word64 rdi_41;
		byte SCZO_42;
		byte Z_43;
		word32 eax_44;
		word64 rax_45;
		byte SZO_46;
		byte C_47;
		word64 rbp_48;
		word32 esi_49;
		word64 rsi_50;
		eax();
		register_tm_clones();
	}
	else
		register_tm_clones();
}

// 0000000000400DC6: void component(Register uint32 ecx, Register word32 edx, Register word32 esi, Register word32 edi, Register word32 r8d, Register ptr64 r13)
void component(uint32 ecx, word32 edx, word32 esi, word32 edi, word32 r8d, ptr64 r13)
{
	*(r13 - 0x28) = r8d;
	if (ecx > 0x10)
	{
		fprintf(globals->ptr602100, "pngpixel: invalid bit depth %u\n", (uint64) ecx);
		exit(0x01);
	}
	else
	{
		word64 rax_60 = globals->a401828[(uint64) ecx * 0x08];
		Eq_153 eax_61 = (word32) rax_60;
		word64 rsp_62;
		word64 rbp_63;
		byte SCZO_64;
		word64 rdi_65;
		word32 esi_66;
		word32 edx_67;
		word32 ecx_68;
		word64 r13_69;
		word32 r8d_70;
		word32 eax_71;
		word64 rax_72;
		byte SZO_73;
		byte C_74;
		word64 rdx_75;
		byte CZ_76;
		word64 rsi_77;
		word32 edi_78;
		eax_61();
	}
}

// 0000000000400EE9: Register word64 print_pixel(Register byte dil, Register (ptr Eq_174) fs)
word64 print_pixel(byte dil, Eq_174 * fs)
{
	word64 rsp_37;
	word64 rbp_38;
	word64 r13_39;
	word64 r12_40;
	word64 rbx_41;
	byte SCZO_42;
	word64 rdi_43;
	word64 rsi_44;
	word64 rdx_45;
	word32 ecx_46;
	word64 rax_47;
	struct Eq_186 * fs_48;
	word32 eax_49;
	byte SZO_50;
	byte C_51;
	byte al_52;
	byte CZ_53;
	word32 esi_54;
	byte Z_55;
	byte dil_56;
	png_get_bit_depth();
	word64 rsp_64;
	word64 rbp_65;
	word64 r13_66;
	word64 r12_67;
	word64 rbx_68;
	byte SCZO_69;
	word64 rdi_70;
	word64 rsi_71;
	word64 rdx_72;
	word32 ecx_73;
	word64 rax_74;
	struct Eq_207 * fs_75;
	word32 eax_76;
	byte SZO_77;
	byte C_78;
	byte al_79;
	byte CZ_80;
	word32 esi_81;
	byte Z_82;
	byte dil_83;
	png_get_color_type();
	word64 rax_26 = fs->qw0028;
	uint32 eax_84 = (word32) al_79;
	if (eax_84 > 0x06)
	{
		word64 rsp_135;
		word64 rbp_136;
		word64 r13_137;
		word64 r12_138;
		word64 rbx_139;
		byte SCZO_140;
		word64 rdi_141;
		word64 rsi_142;
		word64 rdx_143;
		word32 ecx_144;
		word64 rax_145;
		struct Eq_235 * fs_146;
		word32 eax_147;
		byte SZO_148;
		byte C_149;
		byte al_150;
		byte CZ_151;
		word32 esi_152;
		byte Z_153;
		byte dil_154;
		png_error();
		if ((rax_26 ^ fs_146->qw0028) != 0x00)
			__stack_chk_fail();
		return rbp;
	}
	else
	{
		word64 rax_110 = globals->a401958[(uint64) eax_84 * 0x08];
		Eq_256 eax_111 = (word32) rax_110;
		word64 rsp_112;
		word64 rbp_113;
		word64 r13_114;
		word64 r12_115;
		word64 rbx_116;
		byte SCZO_117;
		word64 rdi_118;
		word64 rsi_119;
		word64 rdx_120;
		word32 ecx_121;
		word64 rax_122;
		struct Eq_269 * fs_123;
		word32 eax_124;
		byte SZO_125;
		byte C_126;
		byte al_127;
		byte CZ_128;
		word32 esi_129;
		byte Z_130;
		byte dil_131;
		eax_111();
		return rbp_113;
	}
}

// 00000000004012F9: void main(Register (ptr Eq_281) rsi, Register word32 edi, Register word64 r13, Register (ptr Eq_284) fs)
void main(Eq_281 * rsi, word32 edi, word64 r13, Eq_284 * fs)
{
	ptr64 rbp_123 = fp - 0x08;
	if (edi != 0x04)
	{
		fwrite(&globals->v401A70, 0x01, 0x27, globals->ptr602100);
		goto l000000000040175D;
	}
	char * rax_68 = rsi->ptr0008;
	uint64 rax_71 = DPB(rax_68, atol(rax_68), 0);
	char * rax_75 = rsi->ptr0010;
	uint64 rax_78 = DPB(rax_75, atol(rax_75), 0);
	FILE * rax_85 = fopen(rsi->ptr0018, "rb");
	if (rax_85 == null)
	{
		fprintf(globals->ptr602100, "pngpixel: %s: could not open file\n", rsi->ptr0018);
		goto l000000000040175D;
	}
	word64 rsp_122;
	byte SCZO_124;
	word32 edi_125;
	word64 rsi_126;
	word64 rax_127;
	word32 eax_129;
	byte SZO_130;
	byte C_131;
	byte Z_132;
	word64 rdi_133;
	word32 esi_134;
	word32 ecx_135;
	word64 rcx_136;
	word32 edx_137;
	word64 rdx_138;
	word64 r13_139;
	word64 r9_140;
	word64 r8_141;
	byte SO_142;
	byte cl_143;
	byte al_144;
	byte dil_145;
	png_create_read_struct();
	if (rax_127 == 0x00)
	{
		fwrite(&globals->v401A18, 0x01, 0x2E, globals->ptr602100);
		goto l000000000040175D;
	}
	word64 rsp_153;
	word64 rbp_154;
	byte SCZO_155;
	word32 edi_156;
	word64 rsi_157;
	word64 rax_158;
	struct Eq_387 * fs_159;
	word32 eax_160;
	byte SZO_161;
	byte C_162;
	byte Z_163;
	word64 rdi_164;
	word32 esi_165;
	word32 ecx_166;
	word64 rcx_167;
	word32 edx_168;
	word64 rdx_169;
	word64 r13_170;
	word64 r9_171;
	word64 r8_172;
	byte SO_173;
	byte cl_174;
	byte al_175;
	byte dil_176;
	png_create_info_struct();
	if (rax_158 != 0x00)
	{
		word64 rsp_258;
		word64 rbp_259;
		byte SCZO_260;
		word32 edi_261;
		word64 rsi_262;
		word64 rax_263;
		struct Eq_423 * fs_264;
		word32 eax_265;
		byte SZO_266;
		byte C_267;
		byte Z_268;
		word64 rdi_269;
		word32 esi_270;
		word32 ecx_271;
		word64 rcx_272;
		word32 edx_273;
		word64 rdx_274;
		word64 r13_275;
		word64 r9_276;
		word64 r8_277;
		byte SO_278;
		byte cl_279;
		byte al_280;
		byte dil_281;
		png_init_io();
		word64 rsp_286;
		word64 rbp_287;
		byte SCZO_288;
		word32 edi_289;
		word64 rsi_290;
		word64 rax_291;
		struct Eq_448 * fs_292;
		word32 eax_293;
		byte SZO_294;
		byte C_295;
		byte Z_296;
		word64 rdi_297;
		word32 esi_298;
		word32 ecx_299;
		word64 rcx_300;
		word32 edx_301;
		word64 rdx_302;
		word64 r13_303;
		word64 r9_304;
		word64 r8_305;
		byte SO_306;
		byte cl_307;
		byte al_308;
		byte dil_309;
		png_read_info();
		word64 rsp_314;
		word64 rbp_315;
		byte SCZO_316;
		word32 edi_317;
		word64 rsi_318;
		word64 rax_319;
		struct Eq_473 * fs_320;
		word32 eax_321;
		byte SZO_322;
		byte C_323;
		byte Z_324;
		word64 rdi_325;
		word32 esi_326;
		word32 ecx_327;
		word64 rcx_328;
		word32 edx_329;
		word64 rdx_330;
		word64 r13_331;
		word64 r9_332;
		word64 r8_333;
		byte SO_334;
		byte cl_335;
		byte al_336;
		byte dil_337;
		png_get_rowbytes();
		word64 rsp_342;
		word64 rbp_343;
		byte SCZO_344;
		word32 edi_345;
		word64 rsi_346;
		word64 rax_347;
		struct Eq_498 * fs_348;
		word32 eax_349;
		byte SZO_350;
		byte C_351;
		byte Z_352;
		word64 rdi_353;
		word32 esi_354;
		word32 ecx_355;
		word64 rcx_356;
		word32 edx_357;
		word64 rdx_358;
		word64 r13_359;
		word64 r9_360;
		word64 r8_361;
		byte SO_362;
		byte cl_363;
		byte al_364;
		byte dil_365;
		png_malloc();
		word64 rsp_388;
		word64 rbp_389;
		byte SCZO_390;
		word32 edi_391;
		word64 rsi_392;
		word64 rax_393;
		struct Eq_523 * fs_394;
		word32 eax_395;
		byte SZO_396;
		byte C_397;
		byte Z_398;
		word64 rdi_399;
		word32 esi_400;
		word32 ecx_401;
		word64 rcx_402;
		word32 edx_403;
		word64 rdx_404;
		word64 r13_405;
		word64 r9_406;
		word64 r8_407;
		byte SO_408;
		byte cl_409;
		byte al_410;
		byte dil_411;
		png_get_IHDR();
		if (eax_395 != 0x00)
		{
			word32 eax_418 = (word32) (uint64) dwLoc78;
			if (eax_418 != 0x00)
			{
				if (eax_418 != 0x01)
				{
					word64 rsp_892;
					word64 rbp_893;
					byte SCZO_894;
					word32 edi_895;
					word64 rsi_896;
					word64 rax_897;
					struct Eq_586 * fs_898;
					word32 eax_899;
					byte SZO_900;
					byte C_901;
					byte Z_902;
					word64 rdi_903;
					word32 esi_904;
					word32 ecx_905;
					word64 rcx_906;
					word32 edx_907;
					word64 rdx_908;
					word64 r13_909;
					word64 r9_910;
					word64 r8_911;
					byte SO_912;
					byte cl_913;
					byte al_914;
					byte dil_915;
					png_error();
				}
				else
					dwLoc6C = 0x07;
			}
			else
				dwLoc6C = 0x01;
			word64 rsp_426;
			byte SCZO_428;
			word32 edi_429;
			word64 rsi_430;
			word64 rax_431;
			struct Eq_617 * fs_432;
			word32 eax_433;
			byte SZO_434;
			byte C_435;
			byte Z_436;
			word64 rdi_437;
			word32 esi_438;
			word32 ecx_439;
			word64 rcx_440;
			word32 edx_441;
			word64 rdx_442;
			word64 r13_443;
			word64 r9_444;
			word64 r8_445;
			byte SO_446;
			byte cl_447;
			byte al_448;
			byte dil_449;
			ptr64 rbp_427;
			png_start_read_image();
			int32 dwLoc68_450 = 0x00;
			while (true)
			{
				int32 eax_480 = (word32) (uint64) dwLoc68_450;
				if (eax_480 >= dwLoc6C)
					break;
				word32 dwLoc5C_588;
				word32 dwLoc58_587;
				word32 dwLoc64_586;
				word32 dwLoc60_585;
				if ((word32) (uint64) dwLoc78 == 0x01)
				{
					word32 eax_707;
					if (dwLoc68_450 > 0x01)
						eax_707 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) (0x01 << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x07 - dwLoc68_450)) >> 0x01))))) - 0x01);
					else
						eax_707 = 0x07;
					word32 eax_745;
					uint32 edx_741 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) (eax_707 - (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc68_450))) & 0x01)) << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x03 - (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc68_450) + 0x01)) >> 0x01)))))))))))) & 0x07))) + (word32) ((uint64) dwLoc88));
					if (dwLoc68_450 > 0x01)
						eax_745 = (word32) (uint64) ((word32) (uint64) (0x07 - dwLoc68_450) >> 0x01);
					else
						eax_745 = 0x03;
					if ((word32) (uint64) (word32) (uint64) (edx_741 >> (byte) ((uint64) eax_745)) == 0x00)
						goto l000000000040166F;
					word32 eax_830;
					dwLoc60_585 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) (uint64) dwLoc68_450 & 0x01) << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x03 - (word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc68_450) + 0x01)) >> 0x01))))))))) & 0x07);
					dwLoc64_586 = (word32) (uint64) ((word32) (uint64) (word32) (uint64) ((word32) ((word32) (uint64) ((word32) (uint64) dwLoc68_450 & 0x01) == 0x00) << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x03 - (word32) ((uint64) ((word32) ((uint64) dwLoc68_450) >> 0x01))))))))) & 0x07);
					dwLoc58_587 = (word32) (uint64) (word32) (uint64) (0x01 << (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) (0x07 - dwLoc68_450)) >> 0x01)))));
					if (dwLoc68_450 > 0x02)
						eax_830 = (word32) (uint64) (word32) (uint64) (0x08 >> (byte) ((uint64) ((word32) ((uint64) ((word32) ((uint64) ((word32) ((uint64) dwLoc68_450) - 0x01)) >> 0x01)))));
					else
						eax_830 = 0x08;
					dwLoc5C_588 = eax_830;
				}
				else
				{
					dwLoc60_585 = 0x00;
					dwLoc64_586 = 0x00;
					dwLoc58_587 = 0x01;
					dwLoc5C_588 = 0x01;
				}
				uint32 dwLoc54_603 = (word32) (uint64) dwLoc64_586;
				while (dwLoc54_603 < (word32) ((uint64) dwLoc84))
				{
					int32 eax_633 = puts("png_read_row");
					word64 rsp_639;
					byte SCZO_641;
					word32 edi_642;
					word64 rsi_643;
					word64 rax_644;
					struct Eq_174 * fs_645;
					word32 eax_646;
					byte SZO_647;
					byte C_648;
					byte Z_649;
					word64 rdi_650;
					word32 esi_651;
					word32 ecx_652;
					word64 rcx_653;
					word32 edx_654;
					word64 rdx_655;
					word64 r13_656;
					word64 r9_657;
					word64 r8_658;
					byte SO_659;
					byte cl_660;
					byte al_661;
					byte dil_662;
					png_read_row();
					if ((uint64) dwLoc54_603 == rax_78)
					{
						uint32 dwLoc50_677 = (word32) (uint64) dwLoc60_585;
						while (dwLoc50_677 < (word32) ((uint64) dwLoc88))
						{
							if ((uint64) dwLoc50_677 == rax_71)
							{
								rbp_427 = print_pixel((byte) rax_127, fs_645);
								goto l000000000040167F;
							}
							dwLoc50_677 = dwLoc50_677 + (word32) ((uint64) dwLoc58_587);
						}
					}
					dwLoc54_603 = dwLoc54_603 + (word32) ((uint64) dwLoc5C_588);
				}
l000000000040166F:
				dwLoc68_450 = dwLoc68_450 + 0x01;
			}
l000000000040167F:
			*(rbp_427 - 0x40) = 0x00;
			word64 rsp_496;
			word64 rbp_497;
			byte SCZO_498;
			word32 edi_499;
			word64 rsi_500;
			word64 rax_501;
			struct Eq_658 * fs_502;
			word32 eax_503;
			byte SZO_504;
			byte C_505;
			byte Z_506;
			word64 rdi_507;
			word32 esi_508;
			word32 ecx_509;
			word64 rcx_510;
			word32 edx_511;
			word64 rdx_512;
			word64 r13_513;
			word64 r9_514;
			word64 r8_515;
			byte SO_516;
			byte cl_517;
			byte al_518;
			byte dil_519;
			png_free();
			word64 rsp_524;
			word64 rbp_525;
			byte SCZO_526;
			word32 edi_527;
			word64 rsi_528;
			word64 rax_529;
			struct Eq_683 * fs_530;
			word32 eax_531;
			byte SZO_532;
			byte C_533;
			byte Z_534;
			word64 rdi_535;
			word32 esi_536;
			word32 ecx_537;
			word64 rcx_538;
			word32 edx_539;
			word64 rdx_540;
			word64 r13_541;
			word64 r9_542;
			word64 r8_543;
			byte SO_544;
			byte cl_545;
			byte al_546;
			byte dil_547;
			png_destroy_info_struct();
l00000000004016DE:
			word64 rsp_201;
			byte SCZO_203;
			word32 edi_204;
			word64 rsi_205;
			word64 rax_206;
			word32 eax_208;
			byte SZO_209;
			byte C_210;
			byte Z_211;
			word64 rdi_212;
			word32 esi_213;
			word32 ecx_214;
			word64 rcx_215;
			word32 edx_216;
			word64 rdx_217;
			word64 r13_218;
			word64 r9_219;
			word64 r8_220;
			byte SO_221;
			byte cl_222;
			byte al_223;
			byte dil_224;
			png_destroy_read_struct();
l000000000040175D:
			if ((*(rbp_123 - 0x08) ^ fs->qw0028) != 0x00)
				__stack_chk_fail();
			return;
		}
		word64 rsp_921;
		word64 rbp_922;
		byte SCZO_923;
		word32 edi_924;
		word64 rsi_925;
		word64 rax_926;
		struct Eq_550 * fs_927;
		word32 eax_928;
		byte SZO_929;
		byte C_930;
		byte Z_931;
		word64 rdi_932;
		word32 esi_933;
		word32 ecx_934;
		word64 rcx_935;
		word32 edx_936;
		word64 rdx_937;
		word64 r13_938;
		word64 r9_939;
		word64 r8_940;
		byte SO_941;
		byte cl_942;
		byte al_943;
		byte dil_944;
		png_error();
	}
	fwrite(&globals->v4019E8, 0x01, 44, globals->ptr602100);
	goto l00000000004016DE;
}

// 0000000000401780: void __libc_csu_init(Register word32 edi)
void __libc_csu_init(word32 edi)
{
	_init();
	if (0x0000000000601E08 - 0x0000000000601E00 >> 0x03 != 0x00)
	{
		do
		{
			word64 rsp_72;
			word64 r15_73;
			word64 r14_74;
			word32 r15d_75;
			word32 edi_76;
			word64 r13_77;
			word64 r12_78;
			word64 rbp_79;
			word64 rbx_80;
			word64 rsi_81;
			word64 rdx_82;
			byte SCZO_83;
			byte SZO_84;
			byte C_85;
			byte Z_86;
			word32 ebx_87;
			word64 rdi_88;
			globals->u601E00();
		} while (rbx_80 + 0x01 != rbp_79);
	}
}

// 00000000004017F0: void __libc_csu_fini()
void __libc_csu_fini()
{
}

// 00000000004017F4: void _fini()
void _fini()
{
}

