lbl_809675E8:
/* 809675E8  94 21 FF A0 */	stwu r1, -0x60(r1)
/* 809675EC  7C 08 02 A6 */	mflr r0
/* 809675F0  90 01 00 64 */	stw r0, 0x64(r1)
/* 809675F4  DB E1 00 50 */	stfd f31, 0x50(r1)
/* 809675F8  F3 E1 00 58 */	psq_st f31, 88(r1), 0, 0 /* qr0 */
/* 809675FC  39 61 00 50 */	addi r11, r1, 0x50
/* 80967600  4B 9F AB D9 */	bl _savegpr_28
/* 80967604  7C 7F 1B 78 */	mr r31, r3
/* 80967608  7C 80 23 78 */	mr r0, r4
/* 8096760C  7C BC 2B 78 */	mr r28, r5
/* 80967610  7C DD 33 78 */	mr r29, r6
/* 80967614  FF E0 08 90 */	fmr f31, f1
/* 80967618  7C FE 3B 78 */	mr r30, r7
/* 8096761C  38 A0 00 00 */	li r5, 0
/* 80967620  80 83 00 20 */	lwz r4, 0x20(r3)
/* 80967624  28 04 00 00 */	cmplwi r4, 0
/* 80967628  41 82 00 44 */	beq lbl_8096766C
/* 8096762C  38 61 00 08 */	addi r3, r1, 8
/* 80967630  7C 05 03 78 */	mr r5, r0
/* 80967634  4B 8F F5 01 */	bl __mi__4cXyzCFRC3Vec
/* 80967638  C0 21 00 08 */	lfs f1, 8(r1)
/* 8096763C  D0 21 00 14 */	stfs f1, 0x14(r1)
/* 80967640  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 80967644  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 80967648  C0 41 00 10 */	lfs f2, 0x10(r1)
/* 8096764C  D0 41 00 1C */	stfs f2, 0x1c(r1)
/* 80967650  4B 90 00 25 */	bl cM_atan2s__Fff
/* 80967654  7C BC 18 50 */	subf r5, r28, r3
/* 80967658  A8 1F 01 52 */	lha r0, 0x152(r31)
/* 8096765C  7C 1C 00 50 */	subf r0, r28, r0
/* 80967660  7C 00 07 34 */	extsh r0, r0
/* 80967664  7C A0 28 50 */	subf r5, r0, r5
/* 80967668  7C A5 F2 14 */	add r5, r5, r30
lbl_8096766C:
/* 8096766C  2C 1D 00 00 */	cmpwi r29, 0
/* 80967670  41 82 00 0C */	beq lbl_8096767C
/* 80967674  7C 05 00 D0 */	neg r0, r5
/* 80967678  7C 05 07 34 */	extsh r5, r0
lbl_8096767C:
/* 8096767C  3C 60 80 96 */	lis r3, lit_4514@ha /* 0x80967EFC@ha */
/* 80967680  C0 63 7E FC */	lfs f3, lit_4514@l(r3)  /* 0x80967EFC@l */
/* 80967684  EC 83 F8 24 */	fdivs f4, f3, f31
/* 80967688  A8 1F 01 34 */	lha r0, 0x134(r31)
/* 8096768C  3C 60 80 96 */	lis r3, lit_5042@ha /* 0x80967F28@ha */
/* 80967690  C8 43 7F 28 */	lfd f2, lit_5042@l(r3)  /* 0x80967F28@l */
/* 80967694  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 80967698  90 01 00 24 */	stw r0, 0x24(r1)
/* 8096769C  3C 60 43 30 */	lis r3, 0x4330
/* 809676A0  90 61 00 20 */	stw r3, 0x20(r1)
/* 809676A4  C8 01 00 20 */	lfd f0, 0x20(r1)
/* 809676A8  EC 20 10 28 */	fsubs f1, f0, f2
/* 809676AC  EC 03 20 28 */	fsubs f0, f3, f4
/* 809676B0  EC 21 00 32 */	fmuls f1, f1, f0
/* 809676B4  7C A0 07 34 */	extsh r0, r5
/* 809676B8  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 809676BC  90 01 00 2C */	stw r0, 0x2c(r1)
/* 809676C0  90 61 00 28 */	stw r3, 0x28(r1)
/* 809676C4  C8 01 00 28 */	lfd f0, 0x28(r1)
/* 809676C8  EC 00 10 28 */	fsubs f0, f0, f2
/* 809676CC  EC 00 01 32 */	fmuls f0, f0, f4
/* 809676D0  EC 01 00 2A */	fadds f0, f1, f0
/* 809676D4  FC 00 00 1E */	fctiwz f0, f0
/* 809676D8  D8 01 00 30 */	stfd f0, 0x30(r1)
/* 809676DC  80 01 00 34 */	lwz r0, 0x34(r1)
/* 809676E0  B0 1F 01 2E */	sth r0, 0x12e(r31)
/* 809676E4  E3 E1 00 58 */	psq_l f31, 88(r1), 0, 0 /* qr0 */
/* 809676E8  CB E1 00 50 */	lfd f31, 0x50(r1)
/* 809676EC  39 61 00 50 */	addi r11, r1, 0x50
/* 809676F0  4B 9F AB 35 */	bl _restgpr_28
/* 809676F4  80 01 00 64 */	lwz r0, 0x64(r1)
/* 809676F8  7C 08 03 A6 */	mtlr r0
/* 809676FC  38 21 00 60 */	addi r1, r1, 0x60
/* 80967700  4E 80 00 20 */	blr 