lbl_80B152AC:
/* 80B152AC  38 80 00 00 */	li r4, 0
/* 80B152B0  B0 83 00 00 */	sth r4, 0(r3)
/* 80B152B4  38 00 00 01 */	li r0, 1
/* 80B152B8  B0 03 00 02 */	sth r0, 2(r3)
/* 80B152BC  90 83 00 04 */	stw r4, 4(r3)
/* 80B152C0  4E 80 00 20 */	blr 