lbl_803228B0:
/* 803228B0  80 A5 00 00 */	lwz r5, 0(r5)
/* 803228B4  54 80 10 3A */	slwi r0, r4, 2
/* 803228B8  7C 63 02 14 */	add r3, r3, r0
/* 803228BC  90 A3 00 18 */	stw r5, 0x18(r3)
/* 803228C0  4E 80 00 20 */	blr 