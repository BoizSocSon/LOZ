lbl_80072DD8:
/* 80072DD8  94 21 FF D0 */	stwu r1, -0x30(r1)
/* 80072DDC  98 83 01 70 */	stb r4, 0x170(r3)
/* 80072DE0  88 03 01 70 */	lbz r0, 0x170(r3)
/* 80072DE4  1C 80 00 1C */	mulli r4, r0, 0x1c
/* 80072DE8  38 A4 00 08 */	addi r5, r4, 8
/* 80072DEC  7C A3 2A 14 */	add r5, r3, r5
/* 80072DF0  A8 05 00 06 */	lha r0, 6(r5)
/* 80072DF4  C8 62 8C 70 */	lfd f3, lit_4450(r2)
/* 80072DF8  6C 00 80 00 */	xoris r0, r0, 0x8000
/* 80072DFC  90 01 00 0C */	stw r0, 0xc(r1)
/* 80072E00  3C 80 43 30 */	lis r4, 0x4330
/* 80072E04  90 81 00 08 */	stw r4, 8(r1)
/* 80072E08  C8 01 00 08 */	lfd f0, 8(r1)
/* 80072E0C  EC 00 18 28 */	fsubs f0, f0, f3
/* 80072E10  D0 05 00 10 */	stfs f0, 0x10(r5)
/* 80072E14  C0 42 8C 58 */	lfs f2, lit_4073(r2)
/* 80072E18  D0 45 00 0C */	stfs f2, 0xc(r5)
/* 80072E1C  38 00 00 00 */	li r0, 0
/* 80072E20  98 05 00 05 */	stb r0, 5(r5)
/* 80072E24  88 A3 01 70 */	lbz r5, 0x170(r3)
/* 80072E28  1C A5 00 1C */	mulli r5, r5, 0x1c
/* 80072E2C  38 A5 00 14 */	addi r5, r5, 0x14
/* 80072E30  7C 23 2D 2E */	stfsx f1, r3, r5
/* 80072E34  88 A3 01 70 */	lbz r5, 0x170(r3)
/* 80072E38  1C A5 00 18 */	mulli r5, r5, 0x18
/* 80072E3C  38 C5 00 40 */	addi r6, r5, 0x40
/* 80072E40  7C C3 32 14 */	add r6, r3, r6
/* 80072E44  A8 A6 00 06 */	lha r5, 6(r6)
/* 80072E48  6C A5 80 00 */	xoris r5, r5, 0x8000
/* 80072E4C  90 A1 00 14 */	stw r5, 0x14(r1)
/* 80072E50  90 81 00 10 */	stw r4, 0x10(r1)
/* 80072E54  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 80072E58  EC 00 18 28 */	fsubs f0, f0, f3
/* 80072E5C  D0 06 00 10 */	stfs f0, 0x10(r6)
/* 80072E60  D0 46 00 0C */	stfs f2, 0xc(r6)
/* 80072E64  98 06 00 05 */	stb r0, 5(r6)
/* 80072E68  88 A3 01 70 */	lbz r5, 0x170(r3)
/* 80072E6C  1C A5 00 18 */	mulli r5, r5, 0x18
/* 80072E70  38 A5 00 4C */	addi r5, r5, 0x4c
/* 80072E74  7C 23 2D 2E */	stfsx f1, r3, r5
/* 80072E78  88 A3 01 70 */	lbz r5, 0x170(r3)
/* 80072E7C  1C A5 00 18 */	mulli r5, r5, 0x18
/* 80072E80  38 C5 00 70 */	addi r6, r5, 0x70
/* 80072E84  7C C3 32 14 */	add r6, r3, r6
/* 80072E88  A8 A6 00 06 */	lha r5, 6(r6)
/* 80072E8C  6C A5 80 00 */	xoris r5, r5, 0x8000
/* 80072E90  90 A1 00 1C */	stw r5, 0x1c(r1)
/* 80072E94  90 81 00 18 */	stw r4, 0x18(r1)
/* 80072E98  C8 01 00 18 */	lfd f0, 0x18(r1)
/* 80072E9C  EC 00 18 28 */	fsubs f0, f0, f3
/* 80072EA0  D0 06 00 10 */	stfs f0, 0x10(r6)
/* 80072EA4  D0 46 00 0C */	stfs f2, 0xc(r6)
/* 80072EA8  98 06 00 05 */	stb r0, 5(r6)
/* 80072EAC  88 A3 01 70 */	lbz r5, 0x170(r3)
/* 80072EB0  1C A5 00 18 */	mulli r5, r5, 0x18
/* 80072EB4  38 A5 00 7C */	addi r5, r5, 0x7c
/* 80072EB8  7C 23 2D 2E */	stfsx f1, r3, r5
/* 80072EBC  88 A3 01 70 */	lbz r5, 0x170(r3)
/* 80072EC0  1C A5 00 18 */	mulli r5, r5, 0x18
/* 80072EC4  38 C5 00 A0 */	addi r6, r5, 0xa0
/* 80072EC8  7C C3 32 14 */	add r6, r3, r6
/* 80072ECC  A8 A6 00 06 */	lha r5, 6(r6)
/* 80072ED0  6C A5 80 00 */	xoris r5, r5, 0x8000
/* 80072ED4  90 A1 00 24 */	stw r5, 0x24(r1)
/* 80072ED8  90 81 00 20 */	stw r4, 0x20(r1)
/* 80072EDC  C8 01 00 20 */	lfd f0, 0x20(r1)
/* 80072EE0  EC 00 18 28 */	fsubs f0, f0, f3
/* 80072EE4  D0 06 00 10 */	stfs f0, 0x10(r6)
/* 80072EE8  D0 46 00 0C */	stfs f2, 0xc(r6)
/* 80072EEC  98 06 00 05 */	stb r0, 5(r6)
/* 80072EF0  88 A3 01 70 */	lbz r5, 0x170(r3)
/* 80072EF4  1C A5 00 18 */	mulli r5, r5, 0x18
/* 80072EF8  38 A5 00 AC */	addi r5, r5, 0xac
/* 80072EFC  7C 23 2D 2E */	stfsx f1, r3, r5
/* 80072F00  88 A3 01 70 */	lbz r5, 0x170(r3)
/* 80072F04  1C A5 00 18 */	mulli r5, r5, 0x18
/* 80072F08  38 C5 00 D0 */	addi r6, r5, 0xd0
/* 80072F0C  7C C3 32 14 */	add r6, r3, r6
/* 80072F10  A8 A6 00 06 */	lha r5, 6(r6)
/* 80072F14  6C A5 80 00 */	xoris r5, r5, 0x8000
/* 80072F18  90 A1 00 2C */	stw r5, 0x2c(r1)
/* 80072F1C  90 81 00 28 */	stw r4, 0x28(r1)
/* 80072F20  C8 01 00 28 */	lfd f0, 0x28(r1)
/* 80072F24  EC 00 18 28 */	fsubs f0, f0, f3
/* 80072F28  D0 06 00 10 */	stfs f0, 0x10(r6)
/* 80072F2C  D0 46 00 0C */	stfs f2, 0xc(r6)
/* 80072F30  98 06 00 05 */	stb r0, 5(r6)
/* 80072F34  88 A3 01 70 */	lbz r5, 0x170(r3)
/* 80072F38  1C A5 00 18 */	mulli r5, r5, 0x18
/* 80072F3C  38 A5 00 DC */	addi r5, r5, 0xdc
/* 80072F40  7C 23 2D 2E */	stfsx f1, r3, r5
/* 80072F44  88 A3 01 70 */	lbz r5, 0x170(r3)
/* 80072F48  28 05 00 01 */	cmplwi r5, 1
/* 80072F4C  40 82 00 94 */	bne lbl_80072FE0
/* 80072F50  A8 A3 01 06 */	lha r5, 0x106(r3)
/* 80072F54  6C A5 80 00 */	xoris r5, r5, 0x8000
/* 80072F58  90 A1 00 2C */	stw r5, 0x2c(r1)
/* 80072F5C  90 81 00 28 */	stw r4, 0x28(r1)
/* 80072F60  C8 01 00 28 */	lfd f0, 0x28(r1)
/* 80072F64  EC 00 18 28 */	fsubs f0, f0, f3
/* 80072F68  D0 03 01 10 */	stfs f0, 0x110(r3)
/* 80072F6C  D0 43 01 0C */	stfs f2, 0x10c(r3)
/* 80072F70  98 03 01 05 */	stb r0, 0x105(r3)
/* 80072F74  A8 A3 01 22 */	lha r5, 0x122(r3)
/* 80072F78  6C A5 80 00 */	xoris r5, r5, 0x8000
/* 80072F7C  90 A1 00 24 */	stw r5, 0x24(r1)
/* 80072F80  90 81 00 20 */	stw r4, 0x20(r1)
/* 80072F84  C8 01 00 20 */	lfd f0, 0x20(r1)
/* 80072F88  EC 00 18 28 */	fsubs f0, f0, f3
/* 80072F8C  D0 03 01 2C */	stfs f0, 0x12c(r3)
/* 80072F90  D0 43 01 28 */	stfs f2, 0x128(r3)
/* 80072F94  98 03 01 21 */	stb r0, 0x121(r3)
/* 80072F98  A8 A3 01 3A */	lha r5, 0x13a(r3)
/* 80072F9C  6C A5 80 00 */	xoris r5, r5, 0x8000
/* 80072FA0  90 A1 00 1C */	stw r5, 0x1c(r1)
/* 80072FA4  90 81 00 18 */	stw r4, 0x18(r1)
/* 80072FA8  C8 01 00 18 */	lfd f0, 0x18(r1)
/* 80072FAC  EC 00 18 28 */	fsubs f0, f0, f3
/* 80072FB0  D0 03 01 44 */	stfs f0, 0x144(r3)
/* 80072FB4  D0 43 01 40 */	stfs f2, 0x140(r3)
/* 80072FB8  98 03 01 39 */	stb r0, 0x139(r3)
/* 80072FBC  A8 A3 01 52 */	lha r5, 0x152(r3)
/* 80072FC0  6C A5 80 00 */	xoris r5, r5, 0x8000
/* 80072FC4  90 A1 00 14 */	stw r5, 0x14(r1)
/* 80072FC8  90 81 00 10 */	stw r4, 0x10(r1)
/* 80072FCC  C8 01 00 10 */	lfd f0, 0x10(r1)
/* 80072FD0  EC 00 18 28 */	fsubs f0, f0, f3
/* 80072FD4  D0 03 01 5C */	stfs f0, 0x15c(r3)
/* 80072FD8  D0 43 01 58 */	stfs f2, 0x158(r3)
/* 80072FDC  98 03 01 51 */	stb r0, 0x151(r3)
lbl_80072FE0:
/* 80072FE0  38 21 00 30 */	addi r1, r1, 0x30
/* 80072FE4  4E 80 00 20 */	blr 