lbl_8048561C:
/* 8048561C  80 C3 00 B0 */	lwz r6, 0xb0(r3)
/* 80485620  38 00 00 01 */	li r0, 1
/* 80485624  7C 03 20 30 */	slw r3, r0, r4
/* 80485628  38 63 FF FF */	addi r3, r3, -1
/* 8048562C  7C C0 2C 30 */	srw r0, r6, r5
/* 80485630  7C 63 00 38 */	and r3, r3, r0
/* 80485634  4E 80 00 20 */	blr 