lbl_800105C8:
/* 800105C8  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 800105CC  7C 08 02 A6 */	mflr r0
/* 800105D0  90 01 00 24 */	stw r0, 0x24(r1)
/* 800105D4  39 61 00 20 */	addi r11, r1, 0x20
/* 800105D8  48 35 1C 01 */	bl _savegpr_28
/* 800105DC  7C 7C 1B 78 */	mr r28, r3
/* 800105E0  7C 9D 23 78 */	mr r29, r4
/* 800105E4  7C BE 2B 78 */	mr r30, r5
/* 800105E8  7C DF 33 78 */	mr r31, r6
/* 800105EC  4B FF F5 D5 */	bl frameUpdate__13mDoExt_morf_cFv
/* 800105F0  80 7C 00 4C */	lwz r3, 0x4c(r28)
/* 800105F4  28 03 00 00 */	cmplwi r3, 0
/* 800105F8  41 82 00 48 */	beq lbl_80010640
/* 800105FC  80 03 00 48 */	lwz r0, 0x48(r3)
/* 80010600  28 00 00 00 */	cmplwi r0, 0
/* 80010604  41 82 00 3C */	beq lbl_80010640
/* 80010608  28 1D 00 00 */	cmplwi r29, 0
/* 8001060C  41 82 00 34 */	beq lbl_80010640
/* 80010610  C0 3C 00 1C */	lfs f1, 0x1c(r28)
/* 80010614  C0 5C 00 18 */	lfs f2, 0x18(r28)
/* 80010618  48 2A E8 BD */	bl updateAnime__15Z2SoundObjAnimeFff
/* 8001061C  80 7C 00 4C */	lwz r3, 0x4c(r28)
/* 80010620  7F C4 F3 78 */	mr r4, r30
/* 80010624  7F E5 FB 78 */	mr r5, r31
/* 80010628  81 83 00 10 */	lwz r12, 0x10(r3)
/* 8001062C  81 8C 00 08 */	lwz r12, 8(r12)
/* 80010630  7D 89 03 A6 */	mtctr r12
/* 80010634  4E 80 04 21 */	bctrl 
/* 80010638  38 00 00 01 */	li r0, 1
/* 8001063C  98 1C 00 50 */	stb r0, 0x50(r28)
lbl_80010640:
/* 80010640  38 60 00 01 */	li r3, 1
/* 80010644  88 1C 00 11 */	lbz r0, 0x11(r28)
/* 80010648  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 8001064C  40 82 00 18 */	bne lbl_80010664
/* 80010650  C0 22 81 1C */	lfs f1, lit_3876(r2)
/* 80010654  C0 1C 00 18 */	lfs f0, 0x18(r28)
/* 80010658  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 8001065C  41 82 00 08 */	beq lbl_80010664
/* 80010660  38 60 00 00 */	li r3, 0
lbl_80010664:
/* 80010664  54 63 06 3E */	clrlwi r3, r3, 0x18
/* 80010668  39 61 00 20 */	addi r11, r1, 0x20
/* 8001066C  48 35 1B B9 */	bl _restgpr_28
/* 80010670  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80010674  7C 08 03 A6 */	mtlr r0
/* 80010678  38 21 00 20 */	addi r1, r1, 0x20
/* 8001067C  4E 80 00 20 */	blr 