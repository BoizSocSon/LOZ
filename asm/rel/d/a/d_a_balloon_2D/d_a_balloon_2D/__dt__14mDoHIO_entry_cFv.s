lbl_80655404:
/* 80655404  94 21 FF F0 */	stwu r1, -0x10(r1)
/* 80655408  7C 08 02 A6 */	mflr r0
/* 8065540C  90 01 00 14 */	stw r0, 0x14(r1)
/* 80655410  93 E1 00 0C */	stw r31, 0xc(r1)
/* 80655414  7C 7F 1B 79 */	or. r31, r3, r3
/* 80655418  41 82 00 1C */	beq lbl_80655434
/* 8065541C  3C A0 80 65 */	lis r5, __vt__14mDoHIO_entry_c@ha /* 0x8065575C@ha */
/* 80655420  38 05 57 5C */	addi r0, r5, __vt__14mDoHIO_entry_c@l /* 0x8065575C@l */
/* 80655424  90 1F 00 00 */	stw r0, 0(r31)
/* 80655428  7C 80 07 35 */	extsh. r0, r4
/* 8065542C  40 81 00 08 */	ble lbl_80655434
/* 80655430  4B C7 99 0D */	bl __dl__FPv
lbl_80655434:
/* 80655434  7F E3 FB 78 */	mr r3, r31
/* 80655438  83 E1 00 0C */	lwz r31, 0xc(r1)
/* 8065543C  80 01 00 14 */	lwz r0, 0x14(r1)
/* 80655440  7C 08 03 A6 */	mtlr r0
/* 80655444  38 21 00 10 */	addi r1, r1, 0x10
/* 80655448  4E 80 00 20 */	blr 