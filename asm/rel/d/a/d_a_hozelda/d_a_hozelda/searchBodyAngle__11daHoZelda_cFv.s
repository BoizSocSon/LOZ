lbl_80848774:
/* 80848774  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80848778  7C 08 02 A6 */	mflr r0
/* 8084877C  90 01 00 44 */	stw r0, 0x44(r1)
/* 80848780  39 61 00 40 */	addi r11, r1, 0x40
/* 80848784  4B B1 9A 55 */	bl _savegpr_28
/* 80848788  7C 7C 1B 78 */	mr r28, r3
/* 8084878C  3C 60 80 85 */	lis r3, l_arcName@ha /* 0x80848E3C@ha */
/* 80848790  3B E3 8E 3C */	addi r31, r3, l_arcName@l /* 0x80848E3C@l */
/* 80848794  80 9C 06 D0 */	lwz r4, 0x6d0(r28)
/* 80848798  3B C0 00 00 */	li r30, 0
/* 8084879C  3B A0 00 00 */	li r29, 0
/* 808487A0  88 1C 06 D8 */	lbz r0, 0x6d8(r28)
/* 808487A4  28 00 00 00 */	cmplwi r0, 0
/* 808487A8  41 82 01 DC */	beq lbl_80848984
/* 808487AC  28 04 00 00 */	cmplwi r4, 0
/* 808487B0  41 82 01 D4 */	beq lbl_80848984
/* 808487B4  80 7C 05 70 */	lwz r3, 0x570(r28)
/* 808487B8  80 63 00 84 */	lwz r3, 0x84(r3)
/* 808487BC  80 63 00 0C */	lwz r3, 0xc(r3)
/* 808487C0  C0 03 00 3C */	lfs f0, 0x3c(r3)
/* 808487C4  D0 01 00 24 */	stfs f0, 0x24(r1)
/* 808487C8  C0 03 00 4C */	lfs f0, 0x4c(r3)
/* 808487CC  D0 01 00 28 */	stfs f0, 0x28(r1)
/* 808487D0  C0 03 00 5C */	lfs f0, 0x5c(r3)
/* 808487D4  D0 01 00 2C */	stfs f0, 0x2c(r1)
/* 808487D8  38 61 00 0C */	addi r3, r1, 0xc
/* 808487DC  38 84 05 38 */	addi r4, r4, 0x538
/* 808487E0  38 A1 00 24 */	addi r5, r1, 0x24
/* 808487E4  4B A1 E3 51 */	bl __mi__4cXyzCFRC3Vec
/* 808487E8  C0 01 00 0C */	lfs f0, 0xc(r1)
/* 808487EC  D0 01 00 18 */	stfs f0, 0x18(r1)
/* 808487F0  C0 21 00 10 */	lfs f1, 0x10(r1)
/* 808487F4  D0 21 00 1C */	stfs f1, 0x1c(r1)
/* 808487F8  C0 01 00 14 */	lfs f0, 0x14(r1)
/* 808487FC  D0 01 00 20 */	stfs f0, 0x20(r1)
/* 80848800  C0 1F 00 AC */	lfs f0, 0xac(r31)
/* 80848804  EC 01 00 28 */	fsubs f0, f1, f0
/* 80848808  D0 01 00 1C */	stfs f0, 0x1c(r1)
/* 8084880C  38 61 00 18 */	addi r3, r1, 0x18
/* 80848810  4B AF E9 29 */	bl PSVECSquareMag
/* 80848814  C0 1F 00 18 */	lfs f0, 0x18(r31)
/* 80848818  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8084881C  40 81 00 58 */	ble lbl_80848874
/* 80848820  FC 00 08 34 */	frsqrte f0, f1
/* 80848824  C8 9F 00 B0 */	lfd f4, 0xb0(r31)
/* 80848828  FC 44 00 32 */	fmul f2, f4, f0
/* 8084882C  C8 7F 00 B8 */	lfd f3, 0xb8(r31)
/* 80848830  FC 00 00 32 */	fmul f0, f0, f0
/* 80848834  FC 01 00 32 */	fmul f0, f1, f0
/* 80848838  FC 03 00 28 */	fsub f0, f3, f0
/* 8084883C  FC 02 00 32 */	fmul f0, f2, f0
/* 80848840  FC 44 00 32 */	fmul f2, f4, f0
/* 80848844  FC 00 00 32 */	fmul f0, f0, f0
/* 80848848  FC 01 00 32 */	fmul f0, f1, f0
/* 8084884C  FC 03 00 28 */	fsub f0, f3, f0
/* 80848850  FC 02 00 32 */	fmul f0, f2, f0
/* 80848854  FC 44 00 32 */	fmul f2, f4, f0
/* 80848858  FC 00 00 32 */	fmul f0, f0, f0
/* 8084885C  FC 01 00 32 */	fmul f0, f1, f0
/* 80848860  FC 03 00 28 */	fsub f0, f3, f0
/* 80848864  FC 02 00 32 */	fmul f0, f2, f0
/* 80848868  FC 21 00 32 */	fmul f1, f1, f0
/* 8084886C  FC 20 08 18 */	frsp f1, f1
/* 80848870  48 00 00 88 */	b lbl_808488F8
lbl_80848874:
/* 80848874  C8 1F 00 C0 */	lfd f0, 0xc0(r31)
/* 80848878  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 8084887C  40 80 00 10 */	bge lbl_8084888C
/* 80848880  3C 60 80 45 */	lis r3, __float_nan@ha /* 0x80450AE0@ha */
/* 80848884  C0 23 0A E0 */	lfs f1, __float_nan@l(r3)  /* 0x80450AE0@l */
/* 80848888  48 00 00 70 */	b lbl_808488F8
lbl_8084888C:
/* 8084888C  D0 21 00 08 */	stfs f1, 8(r1)
/* 80848890  80 81 00 08 */	lwz r4, 8(r1)
/* 80848894  54 83 00 50 */	rlwinm r3, r4, 0, 1, 8
/* 80848898  3C 00 7F 80 */	lis r0, 0x7f80
/* 8084889C  7C 03 00 00 */	cmpw r3, r0
/* 808488A0  41 82 00 14 */	beq lbl_808488B4
/* 808488A4  40 80 00 40 */	bge lbl_808488E4
/* 808488A8  2C 03 00 00 */	cmpwi r3, 0
/* 808488AC  41 82 00 20 */	beq lbl_808488CC
/* 808488B0  48 00 00 34 */	b lbl_808488E4
lbl_808488B4:
/* 808488B4  54 80 02 7F */	clrlwi. r0, r4, 9
/* 808488B8  41 82 00 0C */	beq lbl_808488C4
/* 808488BC  38 00 00 01 */	li r0, 1
/* 808488C0  48 00 00 28 */	b lbl_808488E8
lbl_808488C4:
/* 808488C4  38 00 00 02 */	li r0, 2
/* 808488C8  48 00 00 20 */	b lbl_808488E8
lbl_808488CC:
/* 808488CC  54 80 02 7F */	clrlwi. r0, r4, 9
/* 808488D0  41 82 00 0C */	beq lbl_808488DC
/* 808488D4  38 00 00 05 */	li r0, 5
/* 808488D8  48 00 00 10 */	b lbl_808488E8
lbl_808488DC:
/* 808488DC  38 00 00 03 */	li r0, 3
/* 808488E0  48 00 00 08 */	b lbl_808488E8
lbl_808488E4:
/* 808488E4  38 00 00 04 */	li r0, 4
lbl_808488E8:
/* 808488E8  2C 00 00 01 */	cmpwi r0, 1
/* 808488EC  40 82 00 0C */	bne lbl_808488F8
/* 808488F0  3C 60 80 45 */	lis r3, __float_nan@ha /* 0x80450AE0@ha */
/* 808488F4  C0 23 0A E0 */	lfs f1, __float_nan@l(r3)  /* 0x80450AE0@l */
lbl_808488F8:
/* 808488F8  C0 1F 00 1C */	lfs f0, 0x1c(r31)
/* 808488FC  FC 01 00 40 */	fcmpo cr0, f1, f0
/* 80848900  4C 41 13 82 */	cror 2, 1, 2
/* 80848904  40 82 00 80 */	bne lbl_80848984
/* 80848908  38 61 00 18 */	addi r3, r1, 0x18
/* 8084890C  4B A1 E8 45 */	bl atan2sY_XZ__4cXyzCFv
/* 80848910  7C 60 07 34 */	extsh r0, r3
/* 80848914  2C 00 F8 00 */	cmpwi r0, -2048
/* 80848918  40 80 00 0C */	bge lbl_80848924
/* 8084891C  38 00 F8 00 */	li r0, -2048
/* 80848920  48 00 00 14 */	b lbl_80848934
lbl_80848924:
/* 80848924  2C 00 20 00 */	cmpwi r0, 0x2000
/* 80848928  38 00 20 00 */	li r0, 0x2000
/* 8084892C  41 81 00 08 */	bgt lbl_80848934
/* 80848930  7C 60 1B 78 */	mr r0, r3
lbl_80848934:
/* 80848934  7C 00 07 34 */	extsh r0, r0
/* 80848938  7C 1E 03 78 */	mr r30, r0
/* 8084893C  AB FF 00 08 */	lha r31, 8(r31)
/* 80848940  7C 1F 00 D0 */	neg r0, r31
/* 80848944  7C 1D 07 34 */	extsh r29, r0
/* 80848948  38 61 00 18 */	addi r3, r1, 0x18
/* 8084894C  4B A1 E7 DD */	bl atan2sX_Z__4cXyzCFv
/* 80848950  A8 1C 04 E6 */	lha r0, 0x4e6(r28)
/* 80848954  7C 00 18 50 */	subf r0, r0, r3
/* 80848958  7C 03 07 34 */	extsh r3, r0
/* 8084895C  7C 03 E8 00 */	cmpw r3, r29
/* 80848960  40 80 00 08 */	bge lbl_80848968
/* 80848964  48 00 00 18 */	b lbl_8084897C
lbl_80848968:
/* 80848968  7F E0 07 34 */	extsh r0, r31
/* 8084896C  7C 03 00 00 */	cmpw r3, r0
/* 80848970  40 81 00 08 */	ble lbl_80848978
/* 80848974  7F E3 FB 78 */	mr r3, r31
lbl_80848978:
/* 80848978  7C 7D 1B 78 */	mr r29, r3
lbl_8084897C:
/* 8084897C  7F A0 07 34 */	extsh r0, r29
/* 80848980  7C 1D 03 78 */	mr r29, r0
lbl_80848984:
/* 80848984  38 7C 06 F2 */	addi r3, r28, 0x6f2
/* 80848988  7F C4 F3 78 */	mr r4, r30
/* 8084898C  38 A0 00 04 */	li r5, 4
/* 80848990  38 C0 0C 00 */	li r6, 0xc00
/* 80848994  38 E0 01 80 */	li r7, 0x180
/* 80848998  4B A2 7B A9 */	bl cLib_addCalcAngleS__FPsssss
/* 8084899C  38 7C 06 F4 */	addi r3, r28, 0x6f4
/* 808489A0  7F A4 EB 78 */	mr r4, r29
/* 808489A4  38 A0 00 04 */	li r5, 4
/* 808489A8  38 C0 0C 00 */	li r6, 0xc00
/* 808489AC  38 E0 01 80 */	li r7, 0x180
/* 808489B0  4B A2 7B 91 */	bl cLib_addCalcAngleS__FPsssss
/* 808489B4  39 61 00 40 */	addi r11, r1, 0x40
/* 808489B8  4B B1 98 6D */	bl _restgpr_28
/* 808489BC  80 01 00 44 */	lwz r0, 0x44(r1)
/* 808489C0  7C 08 03 A6 */	mtlr r0
/* 808489C4  38 21 00 40 */	addi r1, r1, 0x40
/* 808489C8  4E 80 00 20 */	blr 