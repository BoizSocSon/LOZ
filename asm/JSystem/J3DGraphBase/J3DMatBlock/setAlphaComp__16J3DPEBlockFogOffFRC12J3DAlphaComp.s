lbl_80321B0C:
/* 80321B0C  A0 04 00 00 */	lhz r0, 0(r4)
/* 80321B10  B0 03 00 04 */	sth r0, 4(r3)
/* 80321B14  88 04 00 02 */	lbz r0, 2(r4)
/* 80321B18  98 03 00 06 */	stb r0, 6(r3)
/* 80321B1C  88 04 00 03 */	lbz r0, 3(r4)
/* 80321B20  98 03 00 07 */	stb r0, 7(r3)
/* 80321B24  4E 80 00 20 */	blr 