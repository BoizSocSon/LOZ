lbl_8007FF1C:
/* 8007FF1C  94 21 FF 10 */	stwu r1, -0xf0(r1)
/* 8007FF20  7C 08 02 A6 */	mflr r0
/* 8007FF24  90 01 00 F4 */	stw r0, 0xf4(r1)
/* 8007FF28  DB E1 00 E0 */	stfd f31, 0xe0(r1)
/* 8007FF2C  F3 E1 00 E8 */	psq_st f31, 232(r1), 0, 0 /* qr0 */
/* 8007FF30  39 61 00 E0 */	addi r11, r1, 0xe0
/* 8007FF34  48 2E 22 6D */	bl _savegpr_14
/* 8007FF38  7C 6F 1B 78 */	mr r15, r3
/* 8007FF3C  7C 90 23 78 */	mr r16, r4
/* 8007FF40  C0 24 00 2C */	lfs f1, 0x2c(r4)
/* 8007FF44  D0 21 00 44 */	stfs f1, 0x44(r1)
/* 8007FF48  C0 04 00 30 */	lfs f0, 0x30(r4)
/* 8007FF4C  D0 01 00 48 */	stfs f0, 0x48(r1)
/* 8007FF50  C0 C4 00 34 */	lfs f6, 0x34(r4)
/* 8007FF54  D0 C1 00 4C */	stfs f6, 0x4c(r1)
/* 8007FF58  C0 A4 00 38 */	lfs f5, 0x38(r4)
/* 8007FF5C  D0 A1 00 38 */	stfs f5, 0x38(r1)
/* 8007FF60  C0 84 00 3C */	lfs f4, 0x3c(r4)
/* 8007FF64  D0 81 00 3C */	stfs f4, 0x3c(r1)
/* 8007FF68  C0 64 00 40 */	lfs f3, 0x40(r4)
/* 8007FF6C  D0 61 00 40 */	stfs f3, 0x40(r1)
/* 8007FF70  C0 42 8D 20 */	lfs f2, lit_4189(r2)
/* 8007FF74  EC 21 10 28 */	fsubs f1, f1, f2
/* 8007FF78  D0 21 00 44 */	stfs f1, 0x44(r1)
/* 8007FF7C  EC 00 10 28 */	fsubs f0, f0, f2
/* 8007FF80  D0 01 00 48 */	stfs f0, 0x48(r1)
/* 8007FF84  EC 06 10 28 */	fsubs f0, f6, f2
/* 8007FF88  D0 01 00 4C */	stfs f0, 0x4c(r1)
/* 8007FF8C  EC 05 10 2A */	fadds f0, f5, f2
/* 8007FF90  D0 01 00 38 */	stfs f0, 0x38(r1)
/* 8007FF94  EC 04 10 2A */	fadds f0, f4, f2
/* 8007FF98  D0 01 00 3C */	stfs f0, 0x3c(r1)
/* 8007FF9C  EC 03 10 2A */	fadds f0, f3, f2
/* 8007FFA0  D0 01 00 40 */	stfs f0, 0x40(r1)
/* 8007FFA4  81 C3 00 18 */	lwz r14, 0x18(r3)
/* 8007FFA8  C3 EE 00 14 */	lfs f31, 0x14(r14)
/* 8007FFAC  EC 21 F8 28 */	fsubs f1, f1, f31
/* 8007FFB0  48 2E 20 FD */	bl __cvt_fp2unsigned
/* 8007FFB4  7C 7E 1B 79 */	or. r30, r3, r3
/* 8007FFB8  40 80 00 08 */	bge lbl_8007FFC0
/* 8007FFBC  3B C0 00 00 */	li r30, 0
lbl_8007FFC0:
/* 8007FFC0  C0 01 00 38 */	lfs f0, 0x38(r1)
/* 8007FFC4  EC 20 F8 28 */	fsubs f1, f0, f31
/* 8007FFC8  48 2E 20 E5 */	bl __cvt_fp2unsigned
/* 8007FFCC  7C 7D 1B 78 */	mr r29, r3
/* 8007FFD0  80 0E 00 20 */	lwz r0, 0x20(r14)
/* 8007FFD4  7C 00 00 F8 */	nor r0, r0, r0
/* 8007FFD8  7C 1D 00 00 */	cmpw r29, r0
/* 8007FFDC  40 81 00 08 */	ble lbl_8007FFE4
/* 8007FFE0  7C 1D 03 78 */	mr r29, r0
lbl_8007FFE4:
/* 8007FFE4  7C 1E E8 00 */	cmpw r30, r29
/* 8007FFE8  40 80 03 28 */	bge lbl_80080310
/* 8007FFEC  C0 01 00 48 */	lfs f0, 0x48(r1)
/* 8007FFF0  C3 EE 00 18 */	lfs f31, 0x18(r14)
/* 8007FFF4  EC 20 F8 28 */	fsubs f1, f0, f31
/* 8007FFF8  48 2E 20 B5 */	bl __cvt_fp2unsigned
/* 8007FFFC  7C 7C 1B 79 */	or. r28, r3, r3
/* 80080000  40 80 00 08 */	bge lbl_80080008
/* 80080004  3B 80 00 00 */	li r28, 0
lbl_80080008:
/* 80080008  C0 01 00 3C */	lfs f0, 0x3c(r1)
/* 8008000C  EC 20 F8 28 */	fsubs f1, f0, f31
/* 80080010  48 2E 20 9D */	bl __cvt_fp2unsigned
/* 80080014  7C 7B 1B 78 */	mr r27, r3
/* 80080018  80 0E 00 24 */	lwz r0, 0x24(r14)
/* 8008001C  7C 00 00 F8 */	nor r0, r0, r0
/* 80080020  7C 1B 00 00 */	cmpw r27, r0
/* 80080024  40 81 00 08 */	ble lbl_8008002C
/* 80080028  7C 1B 03 78 */	mr r27, r0
lbl_8008002C:
/* 8008002C  7C 1C D8 00 */	cmpw r28, r27
/* 80080030  40 80 02 E0 */	bge lbl_80080310
/* 80080034  C0 01 00 4C */	lfs f0, 0x4c(r1)
/* 80080038  C3 EE 00 1C */	lfs f31, 0x1c(r14)
/* 8008003C  EC 20 F8 28 */	fsubs f1, f0, f31
/* 80080040  48 2E 20 6D */	bl __cvt_fp2unsigned
/* 80080044  7C 71 1B 79 */	or. r17, r3, r3
/* 80080048  40 80 00 08 */	bge lbl_80080050
/* 8008004C  3A 20 00 00 */	li r17, 0
lbl_80080050:
/* 80080050  C0 01 00 40 */	lfs f0, 0x40(r1)
/* 80080054  EC 20 F8 28 */	fsubs f1, f0, f31
/* 80080058  48 2E 20 55 */	bl __cvt_fp2unsigned
/* 8008005C  7C 7A 1B 78 */	mr r26, r3
/* 80080060  80 0E 00 28 */	lwz r0, 0x28(r14)
/* 80080064  7C 00 00 F8 */	nor r0, r0, r0
/* 80080068  7C 1A 00 00 */	cmpw r26, r0
/* 8008006C  40 81 00 08 */	ble lbl_80080074
/* 80080070  7C 1A 03 78 */	mr r26, r0
lbl_80080074:
/* 80080074  7C 11 D0 00 */	cmpw r17, r26
/* 80080078  40 80 02 98 */	bge lbl_80080310
/* 8008007C  3A E0 00 00 */	li r23, 0
/* 80080080  3A C0 00 00 */	li r22, 0
/* 80080084  7E 35 8B 78 */	mr r21, r17
/* 80080088  3C 60 80 42 */	lis r3, vtx_tbl_4582@ha /* 0x80424F70@ha */
/* 8008008C  3B E3 4F 70 */	addi r31, r3, vtx_tbl_4582@l /* 0x80424F70@l */
lbl_80080090:
/* 80080090  3C 60 00 0F */	lis r3, 0x000F /* 0x000F4240@ha */
/* 80080094  3B 03 42 40 */	addi r24, r3, 0x4240 /* 0x000F4240@l */
/* 80080098  7F 94 E3 78 */	mr r20, r28
lbl_8008009C:
/* 8008009C  3C 60 00 0F */	lis r3, 0x000F /* 0x000F4240@ha */
/* 800800A0  3B 23 42 40 */	addi r25, r3, 0x4240 /* 0x000F4240@l */
/* 800800A4  39 C0 00 00 */	li r14, 0
/* 800800A8  7F D3 F3 78 */	mr r19, r30
lbl_800800AC:
/* 800800AC  81 0F 00 18 */	lwz r8, 0x18(r15)
/* 800800B0  80 68 00 0C */	lwz r3, 0xc(r8)
/* 800800B4  80 88 00 2C */	lwz r4, 0x2c(r8)
/* 800800B8  7E 67 24 30 */	srw r7, r19, r4
/* 800800BC  7E A5 24 30 */	srw r5, r21, r4
/* 800800C0  80 08 00 34 */	lwz r0, 0x34(r8)
/* 800800C4  7C A6 00 30 */	slw r6, r5, r0
/* 800800C8  7E 85 24 30 */	srw r5, r20, r4
/* 800800CC  80 08 00 30 */	lwz r0, 0x30(r8)
/* 800800D0  7C A0 00 30 */	slw r0, r5, r0
/* 800800D4  7C C0 03 78 */	or r0, r6, r0
/* 800800D8  7C E0 03 78 */	or r0, r7, r0
/* 800800DC  54 05 10 3A */	slwi r5, r0, 2
/* 800800E0  48 00 00 28 */	b lbl_80080108
lbl_800800E4:
/* 800800E4  7C 60 2A 14 */	add r3, r0, r5
/* 800800E8  38 84 FF FF */	addi r4, r4, -1
/* 800800EC  7E 66 24 30 */	srw r6, r19, r4
/* 800800F0  7E A5 24 30 */	srw r5, r21, r4
/* 800800F4  7E 80 24 30 */	srw r0, r20, r4
/* 800800F8  54 00 0F BC */	rlwinm r0, r0, 1, 0x1e, 0x1e
/* 800800FC  50 A0 17 7A */	rlwimi r0, r5, 2, 0x1d, 0x1d
/* 80080100  50 C0 07 FE */	rlwimi r0, r6, 0, 0x1f, 0x1f
/* 80080104  54 05 10 3A */	slwi r5, r0, 2
lbl_80080108:
/* 80080108  7C 60 1B 78 */	mr r0, r3
/* 8008010C  7C A3 28 2E */	lwzx r5, r3, r5
/* 80080110  2C 05 00 00 */	cmpwi r5, 0
/* 80080114  40 80 FF D0 */	bge lbl_800800E4
/* 80080118  54 A0 00 7E */	clrlwi r0, r5, 1
/* 8008011C  7E 43 02 14 */	add r18, r3, r0
/* 80080120  38 00 00 01 */	li r0, 1
/* 80080124  7C 03 20 30 */	slw r3, r0, r4
/* 80080128  38 A3 FF FF */	addi r5, r3, -1
/* 8008012C  7E 60 28 38 */	and r0, r19, r5
/* 80080130  7C 00 18 50 */	subf r0, r0, r3
/* 80080134  90 01 00 8C */	stw r0, 0x8c(r1)
/* 80080138  7E 80 28 38 */	and r0, r20, r5
/* 8008013C  7C 80 18 50 */	subf r4, r0, r3
/* 80080140  7E A0 28 38 */	and r0, r21, r5
/* 80080144  7C 00 18 50 */	subf r0, r0, r3
/* 80080148  7C 00 C0 00 */	cmpw r0, r24
/* 8008014C  40 80 00 08 */	bge lbl_80080154
/* 80080150  7C 18 03 78 */	mr r24, r0
lbl_80080154:
/* 80080154  7C 04 C8 00 */	cmpw r4, r25
/* 80080158  40 80 00 08 */	bge lbl_80080160
/* 8008015C  7C 99 23 78 */	mr r25, r4
lbl_80080160:
/* 80080160  7C 04 70 00 */	cmpw r4, r14
/* 80080164  40 81 00 18 */	ble lbl_8008017C
/* 80080168  A0 12 00 02 */	lhz r0, 2(r18)
/* 8008016C  28 00 00 00 */	cmplwi r0, 0
/* 80080170  41 82 00 0C */	beq lbl_8008017C
/* 80080174  7C 8E 23 78 */	mr r14, r4
/* 80080178  7E 57 93 78 */	mr r23, r18
lbl_8008017C:
/* 8008017C  7C 12 B0 40 */	cmplw r18, r22
/* 80080180  41 82 01 64 */	beq lbl_800802E4
/* 80080184  48 00 01 54 */	b lbl_800802D8
lbl_80080188:
/* 80080188  80 CF 00 18 */	lwz r6, 0x18(r15)
/* 8008018C  80 66 00 08 */	lwz r3, 8(r6)
/* 80080190  A0 92 00 00 */	lhz r4, 0(r18)
/* 80080194  54 80 20 36 */	slwi r0, r4, 4
/* 80080198  7C A3 02 14 */	add r5, r3, r0
/* 8008019C  80 66 00 04 */	lwz r3, 4(r6)
/* 800801A0  A0 05 00 06 */	lhz r0, 6(r5)
/* 800801A4  1C 00 00 0C */	mulli r0, r0, 0xc
/* 800801A8  7E 23 02 14 */	add r17, r3, r0
/* 800801AC  7D E3 7B 78 */	mr r3, r15
/* 800801B0  38 A1 00 78 */	addi r5, r1, 0x78
/* 800801B4  4B FF E9 BD */	bl getPolyCode__8dBgWKColCFiP5dBgPc
/* 800801B8  C0 11 00 00 */	lfs f0, 0(r17)
/* 800801BC  D0 01 00 2C */	stfs f0, 0x2c(r1)
/* 800801C0  C0 11 00 04 */	lfs f0, 4(r17)
/* 800801C4  D0 01 00 30 */	stfs f0, 0x30(r1)
/* 800801C8  C0 11 00 08 */	lfs f0, 8(r17)
/* 800801CC  D0 01 00 34 */	stfs f0, 0x34(r1)
/* 800801D0  7D E3 7B 78 */	mr r3, r15
/* 800801D4  38 81 00 78 */	addi r4, r1, 0x78
/* 800801D8  80 B0 00 00 */	lwz r5, 0(r16)
/* 800801DC  80 D0 00 04 */	lwz r6, 4(r16)
/* 800801E0  38 E1 00 2C */	addi r7, r1, 0x2c
/* 800801E4  4B FF E9 E1 */	bl chkPolyThrough__8dBgWKColCFP5dBgPcP16cBgS_PolyPassChkP15cBgS_GrpPassChkR4cXyz
/* 800801E8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 800801EC  40 82 00 EC */	bne lbl_800802D8
/* 800801F0  7D E3 7B 78 */	mr r3, r15
/* 800801F4  A0 92 00 00 */	lhz r4, 0(r18)
/* 800801F8  38 A1 00 20 */	addi r5, r1, 0x20
/* 800801FC  38 C1 00 14 */	addi r6, r1, 0x14
/* 80080200  38 E1 00 08 */	addi r7, r1, 8
/* 80080204  4B FF E7 A1 */	bl GetTriPnt__8dBgWKColCFiP3VecP3VecP3Vec
/* 80080208  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8008020C  41 82 00 CC */	beq lbl_800802D8
/* 80080210  C0 01 00 20 */	lfs f0, 0x20(r1)
/* 80080214  3C 60 80 42 */	lis r3, vtx_tbl_4582@ha /* 0x80424F70@ha */
/* 80080218  D0 03 4F 70 */	stfs f0, vtx_tbl_4582@l(r3)  /* 0x80424F70@l */
/* 8008021C  C0 01 00 24 */	lfs f0, 0x24(r1)
/* 80080220  D0 1F 00 04 */	stfs f0, 4(r31)
/* 80080224  C0 01 00 28 */	lfs f0, 0x28(r1)
/* 80080228  D0 1F 00 08 */	stfs f0, 8(r31)
/* 8008022C  C0 01 00 14 */	lfs f0, 0x14(r1)
/* 80080230  D0 1F 00 0C */	stfs f0, 0xc(r31)
/* 80080234  C0 01 00 18 */	lfs f0, 0x18(r1)
/* 80080238  D0 1F 00 10 */	stfs f0, 0x10(r31)
/* 8008023C  C0 01 00 1C */	lfs f0, 0x1c(r1)
/* 80080240  D0 1F 00 14 */	stfs f0, 0x14(r31)
/* 80080244  C0 01 00 08 */	lfs f0, 8(r1)
/* 80080248  D0 1F 00 18 */	stfs f0, 0x18(r31)
/* 8008024C  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 80080250  D0 1F 00 1C */	stfs f0, 0x1c(r31)
/* 80080254  C0 01 00 10 */	lfs f0, 0x10(r1)
/* 80080258  D0 1F 00 20 */	stfs f0, 0x20(r31)
/* 8008025C  3C 60 80 3A */	lis r3, __vt__8cM3dGPla@ha /* 0x803A37C0@ha */
/* 80080260  38 03 37 C0 */	addi r0, r3, __vt__8cM3dGPla@l /* 0x803A37C0@l */
/* 80080264  90 01 00 74 */	stw r0, 0x74(r1)
/* 80080268  38 61 00 50 */	addi r3, r1, 0x50
/* 8008026C  7D E4 7B 78 */	mr r4, r15
/* 80080270  A0 B2 00 00 */	lhz r5, 0(r18)
/* 80080274  4B FF E6 4D */	bl GetTriPla__8dBgWKColCFi
/* 80080278  C0 01 00 50 */	lfs f0, 0x50(r1)
/* 8008027C  D0 01 00 64 */	stfs f0, 0x64(r1)
/* 80080280  C0 01 00 54 */	lfs f0, 0x54(r1)
/* 80080284  D0 01 00 68 */	stfs f0, 0x68(r1)
/* 80080288  C0 01 00 58 */	lfs f0, 0x58(r1)
/* 8008028C  D0 01 00 6C */	stfs f0, 0x6c(r1)
/* 80080290  C0 01 00 5C */	lfs f0, 0x5c(r1)
/* 80080294  D0 01 00 70 */	stfs f0, 0x70(r1)
/* 80080298  3C 60 80 3A */	lis r3, __vt__8cM3dGPla@ha /* 0x803A37C0@ha */
/* 8008029C  38 03 37 C0 */	addi r0, r3, __vt__8cM3dGPla@l /* 0x803A37C0@l */
/* 800802A0  90 01 00 60 */	stw r0, 0x60(r1)
/* 800802A4  7E 03 83 78 */	mr r3, r16
/* 800802A8  3C 80 80 42 */	lis r4, vtx_tbl_4582@ha /* 0x80424F70@ha */
/* 800802AC  38 84 4F 70 */	addi r4, r4, vtx_tbl_4582@l /* 0x80424F70@l */
/* 800802B0  38 A0 00 00 */	li r5, 0
/* 800802B4  38 C0 00 01 */	li r6, 1
/* 800802B8  38 E0 00 02 */	li r7, 2
/* 800802BC  39 01 00 64 */	addi r8, r1, 0x64
/* 800802C0  81 90 00 48 */	lwz r12, 0x48(r16)
/* 800802C4  7D 89 03 A6 */	mtctr r12
/* 800802C8  4E 80 04 21 */	bctrl 
/* 800802CC  3C 60 80 3A */	lis r3, __vt__8cM3dGPla@ha /* 0x803A37C0@ha */
/* 800802D0  38 03 37 C0 */	addi r0, r3, __vt__8cM3dGPla@l /* 0x803A37C0@l */
/* 800802D4  90 01 00 74 */	stw r0, 0x74(r1)
lbl_800802D8:
/* 800802D8  A4 12 00 02 */	lhzu r0, 2(r18)
/* 800802DC  28 00 00 00 */	cmplwi r0, 0
/* 800802E0  40 82 FE A8 */	bne lbl_80080188
lbl_800802E4:
/* 800802E4  80 01 00 8C */	lwz r0, 0x8c(r1)
/* 800802E8  7E 73 02 14 */	add r19, r19, r0
/* 800802EC  7C 13 E8 40 */	cmplw r19, r29
/* 800802F0  40 81 FD BC */	ble lbl_800800AC
/* 800802F4  7E F6 BB 78 */	mr r22, r23
/* 800802F8  7E 94 CA 14 */	add r20, r20, r25
/* 800802FC  7C 14 D8 40 */	cmplw r20, r27
/* 80080300  40 81 FD 9C */	ble lbl_8008009C
/* 80080304  7E B5 C2 14 */	add r21, r21, r24
/* 80080308  7C 15 D0 40 */	cmplw r21, r26
/* 8008030C  40 81 FD 84 */	ble lbl_80080090
lbl_80080310:
/* 80080310  E3 E1 00 E8 */	psq_l f31, 232(r1), 0, 0 /* qr0 */
/* 80080314  CB E1 00 E0 */	lfd f31, 0xe0(r1)
/* 80080318  39 61 00 E0 */	addi r11, r1, 0xe0
/* 8008031C  48 2E 1E D1 */	bl _restgpr_14
/* 80080320  80 01 00 F4 */	lwz r0, 0xf4(r1)
/* 80080324  7C 08 03 A6 */	mtlr r0
/* 80080328  38 21 00 F0 */	addi r1, r1, 0xf0
/* 8008032C  4E 80 00 20 */	blr 