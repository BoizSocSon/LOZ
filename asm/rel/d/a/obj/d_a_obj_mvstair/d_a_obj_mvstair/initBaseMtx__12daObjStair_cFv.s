lbl_80C9D098:
/* 80C9D098  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80C9D09C  7C 08 02 A6 */	mflr r0
/* 80C9D0A0  90 01 00 14 */	stw r0, 0x14(r1)
/* 80C9D0A4  80 83 05 A8 */	lwz r4, 0x5a8(r3)
/* 80C9D0A8  C0 03 04 EC */	lfs f0, 0x4ec(r3)
/* 80C9D0AC  D0 04 00 18 */	stfs f0, 0x18(r4)
/* 80C9D0B0  C0 03 04 F0 */	lfs f0, 0x4f0(r3)
/* 80C9D0B4  D0 04 00 1C */	stfs f0, 0x1c(r4)
/* 80C9D0B8  C0 03 04 F4 */	lfs f0, 0x4f4(r3)
/* 80C9D0BC  D0 04 00 20 */	stfs f0, 0x20(r4)
/* 80C9D0C0  48 00 00 15 */	bl setBaseMtx__12daObjStair_cFv
/* 80C9D0C4  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80C9D0C8  7C 08 03 A6 */	mtlr r0
/* 80C9D0CC  38 21 00 10 */	addi r1, r1, 0x10
/* 80C9D0D0  4E 80 00 20 */	blr 