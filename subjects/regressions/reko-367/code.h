// code.h
// Generated by decompiling code.bin
// using Reko decompiler version 0.8.0.0.

/*
// Equivalence classes ////////////
Eq_1: (struct "Globals")
	globals_t (in globals : (ptr (struct "Globals")))
Eq_3: (fn void (word32))
	T_3 (in fn800003CC : ptr32)
	T_4 (in signature of fn800003CC : void)
Eq_40: (fn real80 (word32, real96, real96))
	T_40 (in fn80000132 : ptr32)
	T_41 (in signature of fn80000132 : void)
	T_71 (in fn80000132 : ptr32)
	T_109 (in fn80000132 : ptr32)
Eq_47: (fn real80 (word32, real96))
	T_47 (in fn8000018E : ptr32)
	T_48 (in signature of fn8000018E : void)
	T_80 (in fn8000018E : ptr32)
	T_115 (in fn8000018E : ptr32)
Eq_61: (union "Eq_61" (real80 u0) (ptr32 u1))
	T_61 (in fp2Out : Eq_61)
	T_100 (in out fp2_28 : ptr32)
	T_127 (in out fp2_41 : ptr32)
Eq_90: (fn void (word32, real96))
	T_90 (in fn800001F2 : ptr32)
	T_91 (in signature of fn800001F2 : void)
	T_119 (in fn800001F2 : ptr32)
Eq_96: (fn real80 (word32, real96, Eq_61))
	T_96 (in fn800002AE : ptr32)
	T_97 (in signature of fn800002AE : void)
	T_124 (in fn800002AE : ptr32)
Eq_129: (fn void (word32, real96))
	T_129 (in fn8000036C : ptr32)
	T_130 (in signature of fn8000036C : void)
// Type Variables ////////////
globals_t: (in globals : (ptr (struct "Globals")))
  Class: Eq_1
  DataType: (ptr Eq_1)
  OrigDataType: (ptr (struct "Globals"))
T_2: (in d2 : word32)
  Class: Eq_2
  DataType: word32
  OrigDataType: word32
T_3: (in fn800003CC : ptr32)
  Class: Eq_3
  DataType: (ptr Eq_3)
  OrigDataType: (ptr (fn T_6 (T_2)))
T_4: (in signature of fn800003CC : void)
  Class: Eq_3
  DataType: (ptr Eq_3)
  OrigDataType: 
T_5: (in d2 : word32)
  Class: Eq_2
  DataType: word32
  OrigDataType: word32
T_6: (in fn800003CC(d2) : void)
  Class: Eq_6
  DataType: void
  OrigDataType: void
T_7: (in fp0 : real80)
  Class: Eq_7
  DataType: real80
  OrigDataType: real80
T_8: (in d2 : word32)
  Class: Eq_2
  DataType: word32
  OrigDataType: word32
T_9: (in rArg04 : real96)
  Class: Eq_9
  DataType: real96
  OrigDataType: real96
T_10: (in rArg10 : real96)
  Class: Eq_10
  DataType: real96
  OrigDataType: real96
T_11: (in dwLoc14_16 : word32)
  Class: Eq_11
  DataType: word32
  OrigDataType: word32
T_12: (in 0x00000000 : word32)
  Class: Eq_11
  DataType: word32
  OrigDataType: word32
T_13: (in rLoc24 : real96)
  Class: Eq_13
  DataType: real96
  OrigDataType: real96
T_14: (in dwLoc10 : word32)
  Class: Eq_14
  DataType: word32
  OrigDataType: word32
T_15: (in DPB(rLoc24, dwLoc10, 0) : real96)
  Class: Eq_15
  DataType: real96
  OrigDataType: real96
T_16: (in (real80) DPB(rLoc24, dwLoc10, 0) : real80)
  Class: Eq_7
  DataType: real80
  OrigDataType: real80
T_17: (in 0x00000001 : word32)
  Class: Eq_17
  DataType: word32
  OrigDataType: word32
T_18: (in dwLoc14_16 + 0x00000001 : word32)
  Class: Eq_11
  DataType: word32
  OrigDataType: word32
T_19: (in (real80) dwLoc14_16 : real80)
  Class: Eq_19
  DataType: real80
  OrigDataType: real80
T_20: (in (real96) (real80) dwLoc14_16 : real96)
  Class: Eq_10
  DataType: real96
  OrigDataType: real96
T_21: (in (real96) (real80) dwLoc14_16 >= rArg10 : bool)
  Class: Eq_21
  DataType: bool
  OrigDataType: bool
T_22: (in fp0 : real80)
  Class: Eq_22
  DataType: real80
  OrigDataType: real80
T_23: (in d2 : word32)
  Class: Eq_2
  DataType: word32
  OrigDataType: word32
T_24: (in rArg04 : real96)
  Class: Eq_24
  DataType: real96
  OrigDataType: real96
T_25: (in dwLoc14_18 : int32)
  Class: Eq_25
  DataType: int32
  OrigDataType: int32
T_26: (in 1 : int32)
  Class: Eq_25
  DataType: int32
  OrigDataType: int32
T_27: (in rLoc24 : real96)
  Class: Eq_27
  DataType: real96
  OrigDataType: real96
T_28: (in dwLoc10 : word32)
  Class: Eq_28
  DataType: word32
  OrigDataType: word32
T_29: (in DPB(rLoc24, dwLoc10, 0) : real96)
  Class: Eq_29
  DataType: real96
  OrigDataType: real96
T_30: (in (real80) DPB(rLoc24, dwLoc10, 0) : real80)
  Class: Eq_22
  DataType: real80
  OrigDataType: real80
T_31: (in 0x00000001 : word32)
  Class: Eq_31
  DataType: word32
  OrigDataType: word32
T_32: (in dwLoc14_18 + 0x00000001 : word32)
  Class: Eq_25
  DataType: int32
  OrigDataType: int32
T_33: (in (real80) dwLoc14_18 : real80)
  Class: Eq_33
  DataType: real80
  OrigDataType: real80
T_34: (in (real96) (real80) dwLoc14_18 : real96)
  Class: Eq_24
  DataType: real96
  OrigDataType: real96
T_35: (in (real96) (real80) dwLoc14_18 > rArg04 : bool)
  Class: Eq_35
  DataType: bool
  OrigDataType: bool
T_36: (in d2 : word32)
  Class: Eq_2
  DataType: word32
  OrigDataType: word32
T_37: (in rArg04 : real96)
  Class: Eq_37
  DataType: real96
  OrigDataType: real96
T_38: (in dwLoc20_25 : int32)
  Class: Eq_38
  DataType: int32
  OrigDataType: int32
T_39: (in 3 : int32)
  Class: Eq_38
  DataType: int32
  OrigDataType: int32
T_40: (in fn80000132 : ptr32)
  Class: Eq_40
  DataType: (ptr Eq_40)
  OrigDataType: (ptr (fn T_46 (T_36, T_43, T_45)))
T_41: (in signature of fn80000132 : void)
  Class: Eq_40
  DataType: (ptr Eq_40)
  OrigDataType: 
T_42: (in (real80) rArg04 : real80)
  Class: Eq_42
  DataType: real80
  OrigDataType: real80
T_43: (in (real96) (real80) rArg04 : real96)
  Class: Eq_9
  DataType: real96
  OrigDataType: real96
T_44: (in (real80) dwLoc20_25 : real80)
  Class: Eq_44
  DataType: real80
  OrigDataType: real80
T_45: (in (real96) (real80) dwLoc20_25 : real96)
  Class: Eq_10
  DataType: real96
  OrigDataType: real96
T_46: (in fn80000132(d2, (real96) (real80) rArg04, (real96) (real80) dwLoc20_25) : real80)
  Class: Eq_46
  DataType: real80
  OrigDataType: real80
T_47: (in fn8000018E : ptr32)
  Class: Eq_47
  DataType: (ptr Eq_47)
  OrigDataType: (ptr (fn T_51 (T_36, T_50)))
T_48: (in signature of fn8000018E : void)
  Class: Eq_47
  DataType: (ptr Eq_47)
  OrigDataType: 
T_49: (in (real80) dwLoc20_25 : real80)
  Class: Eq_49
  DataType: real80
  OrigDataType: real80
T_50: (in (real96) (real80) dwLoc20_25 : real96)
  Class: Eq_24
  DataType: real96
  OrigDataType: real96
T_51: (in fn8000018E(d2, (real96) (real80) dwLoc20_25) : real80)
  Class: Eq_51
  DataType: real80
  OrigDataType: real80
T_52: (in 0x00000002 : word32)
  Class: Eq_52
  DataType: word32
  OrigDataType: word32
T_53: (in dwLoc20_25 + 0x00000002 : word32)
  Class: Eq_38
  DataType: int32
  OrigDataType: int32
T_54: (in 100 : int32)
  Class: Eq_54
  DataType: int32
  OrigDataType: int32
T_55: (in 100 - dwLoc20_25 : word32)
  Class: Eq_55
  DataType: int32
  OrigDataType: int32
T_56: (in 0x00000000 : word32)
  Class: Eq_55
  DataType: int32
  OrigDataType: int32
T_57: (in 100 - dwLoc20_25 < 0x00000000 : bool)
  Class: Eq_57
  DataType: bool
  OrigDataType: bool
T_58: (in fp0 : real80)
  Class: Eq_58
  DataType: real80
  OrigDataType: real80
T_59: (in d2 : word32)
  Class: Eq_2
  DataType: word32
  OrigDataType: word32
T_60: (in rArg04 : real96)
  Class: Eq_60
  DataType: real96
  OrigDataType: real96
T_61: (in fp2Out : Eq_61)
  Class: Eq_61
  DataType: Eq_61
  OrigDataType: ptr32
T_62: (in dwLoc20_24 : int32)
  Class: Eq_62
  DataType: int32
  OrigDataType: int32
T_63: (in 2 : int32)
  Class: Eq_62
  DataType: int32
  OrigDataType: int32
T_64: (in fp2_102 : real80)
  Class: Eq_64
  DataType: real80
  OrigDataType: real80
T_65: (in fp2 : real80)
  Class: Eq_65
  DataType: real80
  OrigDataType: real80
T_66: (in *fp2Out : real80)
  Class: Eq_65
  DataType: real80
  OrigDataType: real80
T_67: (in rLoc3C : real96)
  Class: Eq_24
  DataType: real96
  OrigDataType: real96
T_68: (in dwLoc10 : word32)
  Class: Eq_68
  DataType: word32
  OrigDataType: word32
T_69: (in DPB(rLoc3C, dwLoc10, 0) : real96)
  Class: Eq_69
  DataType: real96
  OrigDataType: real96
T_70: (in (real80) DPB(rLoc3C, dwLoc10, 0) : real80)
  Class: Eq_58
  DataType: real80
  OrigDataType: real80
T_71: (in fn80000132 : ptr32)
  Class: Eq_40
  DataType: (ptr Eq_40)
  OrigDataType: (ptr (fn T_76 (T_59, T_73, T_75)))
T_72: (in (real80) rArg04 : real80)
  Class: Eq_72
  DataType: real80
  OrigDataType: real80
T_73: (in (real96) (real80) rArg04 : real96)
  Class: Eq_9
  DataType: real96
  OrigDataType: real96
T_74: (in (real80) dwLoc20_24 : real80)
  Class: Eq_74
  DataType: real80
  OrigDataType: real80
T_75: (in (real96) (real80) dwLoc20_24 : real96)
  Class: Eq_10
  DataType: real96
  OrigDataType: real96
T_76: (in fn80000132(d2, (real96) (real80) rArg04, (real96) (real80) dwLoc20_24) : real80)
  Class: Eq_46
  DataType: real80
  OrigDataType: real80
T_77: (in v19_59 : real96)
  Class: Eq_24
  DataType: real96
  OrigDataType: real96
T_78: (in (real80) dwLoc20_24 : real80)
  Class: Eq_78
  DataType: real80
  OrigDataType: real80
T_79: (in (real96) (real80) dwLoc20_24 : real96)
  Class: Eq_24
  DataType: real96
  OrigDataType: real96
T_80: (in fn8000018E : ptr32)
  Class: Eq_47
  DataType: (ptr Eq_47)
  OrigDataType: (ptr (fn T_81 (T_59, T_77)))
T_81: (in fn8000018E(d2, v19_59) : real80)
  Class: Eq_51
  DataType: real80
  OrigDataType: real80
T_82: (in 0x00000002 : word32)
  Class: Eq_82
  DataType: word32
  OrigDataType: word32
T_83: (in dwLoc20_24 + 0x00000002 : word32)
  Class: Eq_62
  DataType: int32
  OrigDataType: int32
T_84: (in 100 : int32)
  Class: Eq_84
  DataType: int32
  OrigDataType: int32
T_85: (in 100 - dwLoc20_24 : word32)
  Class: Eq_85
  DataType: int32
  OrigDataType: int32
T_86: (in 0x00000000 : word32)
  Class: Eq_85
  DataType: int32
  OrigDataType: int32
T_87: (in 100 - dwLoc20_24 < 0x00000000 : bool)
  Class: Eq_87
  DataType: bool
  OrigDataType: bool
T_88: (in d2 : word32)
  Class: Eq_2
  DataType: word32
  OrigDataType: word32
T_89: (in rArg04 : real96)
  Class: Eq_89
  DataType: real96
  OrigDataType: real96
T_90: (in fn800001F2 : ptr32)
  Class: Eq_90
  DataType: (ptr Eq_90)
  OrigDataType: (ptr (fn T_94 (T_88, T_93)))
T_91: (in signature of fn800001F2 : void)
  Class: Eq_90
  DataType: (ptr Eq_90)
  OrigDataType: 
T_92: (in (real80) rArg04 : real80)
  Class: Eq_92
  DataType: real80
  OrigDataType: real80
T_93: (in (real96) (real80) rArg04 : real96)
  Class: Eq_37
  DataType: real96
  OrigDataType: real96
T_94: (in fn800001F2(d2, (real96) (real80) rArg04) : void)
  Class: Eq_94
  DataType: void
  OrigDataType: void
T_95: (in fp2_28 : real80)
  Class: Eq_95
  DataType: real80
  OrigDataType: real80
T_96: (in fn800002AE : ptr32)
  Class: Eq_96
  DataType: (ptr Eq_96)
  OrigDataType: (ptr (fn T_101 (T_88, T_99, T_100)))
T_97: (in signature of fn800002AE : void)
  Class: Eq_96
  DataType: (ptr Eq_96)
  OrigDataType: 
T_98: (in (real80) rArg04 : real80)
  Class: Eq_98
  DataType: real80
  OrigDataType: real80
T_99: (in (real96) (real80) rArg04 : real96)
  Class: Eq_60
  DataType: real96
  OrigDataType: real96
T_100: (in out fp2_28 : ptr32)
  Class: Eq_61
  DataType: Eq_61
  OrigDataType: (union (real80 u0) (ptr32 u1))
T_101: (in fn800002AE(d2, (real96) (real80) rArg04, out fp2_28) : real80)
  Class: Eq_101
  DataType: real80
  OrigDataType: real80
T_102: (in v6_9 : real96)
  Class: Eq_102
  DataType: real96
  OrigDataType: real96
T_103: (in 80000538 : ptr32)
  Class: Eq_103
  DataType: (ptr real96)
  OrigDataType: (ptr (struct (0 T_106 t0000)))
T_104: (in 0x00000000 : word32)
  Class: Eq_104
  DataType: word32
  OrigDataType: word32
T_105: (in 0x80000538 + 0x00000000 : word32)
  Class: Eq_105
  DataType: ptr32
  OrigDataType: ptr32
T_106: (in Mem0[0x80000538 + 0x00000000:real96] : real96)
  Class: Eq_106
  DataType: real96
  OrigDataType: real96
T_107: (in (real80) *(real96 *) 0x80000538 : real80)
  Class: Eq_107
  DataType: real80
  OrigDataType: real80
T_108: (in (real96) (real80) *(real96 *) 0x80000538 : real96)
  Class: Eq_102
  DataType: real96
  OrigDataType: real96
T_109: (in fn80000132 : ptr32)
  Class: Eq_40
  DataType: (ptr Eq_40)
  OrigDataType: (ptr (fn T_114 (T_5, T_111, T_113)))
T_110: (in (real80) v6_9 : real80)
  Class: Eq_110
  DataType: real80
  OrigDataType: real80
T_111: (in (real96) (real80) v6_9 : real96)
  Class: Eq_9
  DataType: real96
  OrigDataType: real96
T_112: (in (real80) v6_9 : real80)
  Class: Eq_112
  DataType: real80
  OrigDataType: real80
T_113: (in (real96) (real80) v6_9 : real96)
  Class: Eq_10
  DataType: real96
  OrigDataType: real96
T_114: (in fn80000132(d2, (real96) (real80) v6_9, (real96) (real80) v6_9) : real80)
  Class: Eq_46
  DataType: real80
  OrigDataType: real80
T_115: (in fn8000018E : ptr32)
  Class: Eq_47
  DataType: (ptr Eq_47)
  OrigDataType: (ptr (fn T_118 (T_5, T_117)))
T_116: (in (real80) v6_9 : real80)
  Class: Eq_116
  DataType: real80
  OrigDataType: real80
T_117: (in (real96) (real80) v6_9 : real96)
  Class: Eq_24
  DataType: real96
  OrigDataType: real96
T_118: (in fn8000018E(d2, (real96) (real80) v6_9) : real80)
  Class: Eq_51
  DataType: real80
  OrigDataType: real80
T_119: (in fn800001F2 : ptr32)
  Class: Eq_90
  DataType: (ptr Eq_90)
  OrigDataType: (ptr (fn T_122 (T_5, T_121)))
T_120: (in (real80) v6_9 : real80)
  Class: Eq_120
  DataType: real80
  OrigDataType: real80
T_121: (in (real96) (real80) v6_9 : real96)
  Class: Eq_37
  DataType: real96
  OrigDataType: real96
T_122: (in fn800001F2(d2, (real96) (real80) v6_9) : void)
  Class: Eq_94
  DataType: void
  OrigDataType: void
T_123: (in fp2_41 : real80)
  Class: Eq_123
  DataType: real80
  OrigDataType: real80
T_124: (in fn800002AE : ptr32)
  Class: Eq_96
  DataType: (ptr Eq_96)
  OrigDataType: (ptr (fn T_128 (T_5, T_126, T_127)))
T_125: (in (real80) v6_9 : real80)
  Class: Eq_125
  DataType: real80
  OrigDataType: real80
T_126: (in (real96) (real80) v6_9 : real96)
  Class: Eq_60
  DataType: real96
  OrigDataType: real96
T_127: (in out fp2_41 : ptr32)
  Class: Eq_61
  DataType: Eq_61
  OrigDataType: (union (real80 u0) (ptr32 u1))
T_128: (in fn800002AE(d2, (real96) (real80) v6_9, out fp2_41) : real80)
  Class: Eq_101
  DataType: real80
  OrigDataType: real80
T_129: (in fn8000036C : ptr32)
  Class: Eq_129
  DataType: (ptr Eq_129)
  OrigDataType: (ptr (fn T_133 (T_5, T_132)))
T_130: (in signature of fn8000036C : void)
  Class: Eq_129
  DataType: (ptr Eq_129)
  OrigDataType: 
T_131: (in (real80) v6_9 : real80)
  Class: Eq_131
  DataType: real80
  OrigDataType: real80
T_132: (in (real96) (real80) v6_9 : real96)
  Class: Eq_89
  DataType: real96
  OrigDataType: real96
T_133: (in fn8000036C(d2, (real96) (real80) v6_9) : void)
  Class: Eq_133
  DataType: void
  OrigDataType: void
*/
typedef struct Globals {
} Eq_1;

typedef void (Eq_3)(word32);

typedef real80 (Eq_40)(word32, real96, real96);

typedef real80 (Eq_47)(word32, real96);

typedef union Eq_61 {
	real80 u0;
	ptr32 u1;
} Eq_61;

typedef void (Eq_90)(word32, real96);

typedef real80 (Eq_96)(word32, real96, Eq_61);

typedef void (Eq_129)(word32, real96);

