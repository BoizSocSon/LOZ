lbl_80648544:
/* 80648544  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80648548  7C 08 02 A6 */	mflr r0
/* 8064854C  90 01 00 24 */	stw r0, 0x24(r1)
/* 80648550  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 80648554  93 C1 00 18 */	stw r30, 0x18(r1)
/* 80648558  7C 7E 1B 78 */	mr r30, r3
/* 8064855C  3C 80 80 65 */	lis r4, lit_3757@ha /* 0x8064EB1C@ha */
/* 80648560  3B E4 EB 1C */	addi r31, r4, lit_3757@l /* 0x8064EB1C@l */
/* 80648564  80 03 06 DC */	lwz r0, 0x6dc(r3)
/* 80648568  2C 00 00 05 */	cmpwi r0, 5
/* 8064856C  40 80 00 1C */	bge lbl_80648588
/* 80648570  2C 00 00 01 */	cmpwi r0, 1
/* 80648574  41 82 00 9C */	beq lbl_80648610
/* 80648578  40 80 01 E8 */	bge lbl_80648760
/* 8064857C  2C 00 00 00 */	cmpwi r0, 0
/* 80648580  40 80 00 20 */	bge lbl_806485A0
/* 80648584  48 00 01 DC */	b lbl_80648760
lbl_80648588:
/* 80648588  2C 00 00 0A */	cmpwi r0, 0xa
/* 8064858C  41 82 01 48 */	beq lbl_806486D4
/* 80648590  40 80 01 D0 */	bge lbl_80648760
/* 80648594  2C 00 00 07 */	cmpwi r0, 7
/* 80648598  40 80 01 C8 */	bge lbl_80648760
/* 8064859C  48 00 00 E0 */	b lbl_8064867C
lbl_806485A0:
/* 806485A0  38 80 00 00 */	li r4, 0
/* 806485A4  4B FF 72 A9 */	bl setNextDamageMode__10daB_ZANT_cFi
/* 806485A8  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 806485AC  41 82 00 14 */	beq lbl_806485C0
/* 806485B0  7F C3 F3 78 */	mr r3, r30
/* 806485B4  38 80 00 00 */	li r4, 0
/* 806485B8  4B FF 79 B5 */	bl setTgHitBit__10daB_ZANT_cFi
/* 806485BC  48 00 01 A4 */	b lbl_80648760
lbl_806485C0:
/* 806485C0  7F C3 F3 78 */	mr r3, r30
/* 806485C4  38 80 00 1D */	li r4, 0x1d
/* 806485C8  38 A0 00 00 */	li r5, 0
/* 806485CC  C0 3F 00 5C */	lfs f1, 0x5c(r31)
/* 806485D0  C0 5F 00 0C */	lfs f2, 0xc(r31)
/* 806485D4  4B FF 5F F1 */	bl setBck__10daB_ZANT_cFiUcff
/* 806485D8  3C 60 00 07 */	lis r3, 0x0007 /* 0x0007040C@ha */
/* 806485DC  38 03 04 0C */	addi r0, r3, 0x040C /* 0x0007040C@l */
/* 806485E0  90 01 00 0C */	stw r0, 0xc(r1)
/* 806485E4  38 7E 05 F0 */	addi r3, r30, 0x5f0
/* 806485E8  38 81 00 0C */	addi r4, r1, 0xc
/* 806485EC  38 A0 FF FF */	li r5, -1
/* 806485F0  81 9E 05 F0 */	lwz r12, 0x5f0(r30)
/* 806485F4  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 806485F8  7D 89 03 A6 */	mtctr r12
/* 806485FC  4E 80 04 21 */	bctrl 
/* 80648600  38 00 00 01 */	li r0, 1
/* 80648604  90 1E 06 DC */	stw r0, 0x6dc(r30)
/* 80648608  38 00 00 00 */	li r0, 0
/* 8064860C  98 1E 07 02 */	stb r0, 0x702(r30)
lbl_80648610:
/* 80648610  80 1E 06 F0 */	lwz r0, 0x6f0(r30)
/* 80648614  2C 00 00 00 */	cmpwi r0, 0
/* 80648618  40 82 00 10 */	bne lbl_80648628
/* 8064861C  7F C3 F3 78 */	mr r3, r30
/* 80648620  38 80 00 00 */	li r4, 0
/* 80648624  4B FF 79 49 */	bl setTgHitBit__10daB_ZANT_cFi
lbl_80648628:
/* 80648628  80 7E 05 B4 */	lwz r3, 0x5b4(r30)
/* 8064862C  38 80 00 01 */	li r4, 1
/* 80648630  88 03 00 11 */	lbz r0, 0x11(r3)
/* 80648634  54 00 07 FF */	clrlwi. r0, r0, 0x1f
/* 80648638  40 82 00 18 */	bne lbl_80648650
/* 8064863C  C0 3F 00 28 */	lfs f1, 0x28(r31)
/* 80648640  C0 03 00 18 */	lfs f0, 0x18(r3)
/* 80648644  FC 01 00 00 */	fcmpu cr0, f1, f0
/* 80648648  41 82 00 08 */	beq lbl_80648650
/* 8064864C  38 80 00 00 */	li r4, 0
lbl_80648650:
/* 80648650  54 80 06 3F */	clrlwi. r0, r4, 0x18
/* 80648654  41 82 01 0C */	beq lbl_80648760
/* 80648658  7F C3 F3 78 */	mr r3, r30
/* 8064865C  38 80 00 1E */	li r4, 0x1e
/* 80648660  38 A0 00 02 */	li r5, 2
/* 80648664  C0 3F 00 5C */	lfs f1, 0x5c(r31)
/* 80648668  C0 5F 00 0C */	lfs f2, 0xc(r31)
/* 8064866C  4B FF 5F 59 */	bl setBck__10daB_ZANT_cFiUcff
/* 80648670  38 00 00 0A */	li r0, 0xa
/* 80648674  90 1E 06 DC */	stw r0, 0x6dc(r30)
/* 80648678  48 00 00 E8 */	b lbl_80648760
lbl_8064867C:
/* 8064867C  2C 00 00 05 */	cmpwi r0, 5
/* 80648680  40 82 00 18 */	bne lbl_80648698
/* 80648684  38 00 00 64 */	li r0, 0x64
/* 80648688  90 1E 06 F0 */	stw r0, 0x6f0(r30)
/* 8064868C  38 00 00 00 */	li r0, 0
/* 80648690  98 1E 06 FF */	stb r0, 0x6ff(r30)
/* 80648694  48 00 00 18 */	b lbl_806486AC
lbl_80648698:
/* 80648698  80 1E 06 F0 */	lwz r0, 0x6f0(r30)
/* 8064869C  2C 00 00 1E */	cmpwi r0, 0x1e
/* 806486A0  40 80 00 0C */	bge lbl_806486AC
/* 806486A4  38 00 00 1E */	li r0, 0x1e
/* 806486A8  90 1E 06 F0 */	stw r0, 0x6f0(r30)
lbl_806486AC:
/* 806486AC  7F C3 F3 78 */	mr r3, r30
/* 806486B0  38 80 00 1E */	li r4, 0x1e
/* 806486B4  38 A0 00 02 */	li r5, 2
/* 806486B8  C0 3F 00 5C */	lfs f1, 0x5c(r31)
/* 806486BC  C0 5F 00 0C */	lfs f2, 0xc(r31)
/* 806486C0  4B FF 5F 05 */	bl setBck__10daB_ZANT_cFiUcff
/* 806486C4  38 00 00 0A */	li r0, 0xa
/* 806486C8  90 1E 06 DC */	stw r0, 0x6dc(r30)
/* 806486CC  38 00 00 00 */	li r0, 0
/* 806486D0  98 1E 07 02 */	stb r0, 0x702(r30)
lbl_806486D4:
/* 806486D4  80 7E 05 B4 */	lwz r3, 0x5b4(r30)
/* 806486D8  38 63 00 0C */	addi r3, r3, 0xc
/* 806486DC  C0 3F 00 0C */	lfs f1, 0xc(r31)
/* 806486E0  4B CD FD 4D */	bl checkPass__12J3DFrameCtrlFf
/* 806486E4  2C 03 00 00 */	cmpwi r3, 0
/* 806486E8  41 82 00 2C */	beq lbl_80648714
/* 806486EC  3C 60 00 07 */	lis r3, 0x0007 /* 0x0007042D@ha */
/* 806486F0  38 03 04 2D */	addi r0, r3, 0x042D /* 0x0007042D@l */
/* 806486F4  90 01 00 08 */	stw r0, 8(r1)
/* 806486F8  38 7E 05 F0 */	addi r3, r30, 0x5f0
/* 806486FC  38 81 00 08 */	addi r4, r1, 8
/* 80648700  38 A0 FF FF */	li r5, -1
/* 80648704  81 9E 05 F0 */	lwz r12, 0x5f0(r30)
/* 80648708  81 8C 00 1C */	lwz r12, 0x1c(r12)
/* 8064870C  7D 89 03 A6 */	mtctr r12
/* 80648710  4E 80 04 21 */	bctrl 
lbl_80648714:
/* 80648714  80 1E 06 F0 */	lwz r0, 0x6f0(r30)
/* 80648718  2C 00 00 00 */	cmpwi r0, 0
/* 8064871C  40 82 00 44 */	bne lbl_80648760
/* 80648720  7F C3 F3 78 */	mr r3, r30
/* 80648724  38 80 00 00 */	li r4, 0
/* 80648728  4B FF 78 45 */	bl setTgHitBit__10daB_ZANT_cFi
/* 8064872C  7F C3 F3 78 */	mr r3, r30
/* 80648730  38 80 00 01 */	li r4, 1
/* 80648734  4B FF 71 19 */	bl setNextDamageMode__10daB_ZANT_cFi
/* 80648738  54 60 06 3F */	clrlwi. r0, r3, 0x18
/* 8064873C  40 82 00 24 */	bne lbl_80648760
/* 80648740  7F C3 F3 78 */	mr r3, r30
/* 80648744  4B FF EC A1 */	bl setNearPillarPos__10daB_ZANT_cFv
/* 80648748  38 00 00 00 */	li r0, 0
/* 8064874C  98 1E 07 11 */	stb r0, 0x711(r30)
/* 80648750  7F C3 F3 78 */	mr r3, r30
/* 80648754  38 80 00 01 */	li r4, 1
/* 80648758  38 A0 00 01 */	li r5, 1
/* 8064875C  4B FF 5F 69 */	bl setActionMode__10daB_ZANT_cFii
lbl_80648760:
/* 80648760  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80648764  83 C1 00 18 */	lwz r30, 0x18(r1)
/* 80648768  80 01 00 24 */	lwz r0, 0x24(r1)
/* 8064876C  7C 08 03 A6 */	mtlr r0
/* 80648770  38 21 00 20 */	addi r1, r1, 0x20
/* 80648774  4E 80 00 20 */	blr 