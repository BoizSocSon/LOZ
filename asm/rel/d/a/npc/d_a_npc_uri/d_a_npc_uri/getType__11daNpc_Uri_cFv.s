lbl_80B271EC:
/* 80B271EC  80 03 00 B0 */	lwz r0, 0xb0(r3)
/* 80B271F0  54 00 06 3E */	clrlwi r0, r0, 0x18
/* 80B271F4  2C 00 00 03 */	cmpwi r0, 3
/* 80B271F8  41 82 00 48 */	beq lbl_80B27240
/* 80B271FC  40 80 00 1C */	bge lbl_80B27218
/* 80B27200  2C 00 00 01 */	cmpwi r0, 1
/* 80B27204  41 82 00 2C */	beq lbl_80B27230
/* 80B27208  40 80 00 30 */	bge lbl_80B27238
/* 80B2720C  2C 00 00 00 */	cmpwi r0, 0
/* 80B27210  40 80 00 18 */	bge lbl_80B27228
/* 80B27214  48 00 00 44 */	b lbl_80B27258
lbl_80B27218:
/* 80B27218  2C 00 00 05 */	cmpwi r0, 5
/* 80B2721C  41 82 00 34 */	beq lbl_80B27250
/* 80B27220  40 80 00 38 */	bge lbl_80B27258
/* 80B27224  48 00 00 24 */	b lbl_80B27248
lbl_80B27228:
/* 80B27228  38 60 00 00 */	li r3, 0
/* 80B2722C  4E 80 00 20 */	blr 
lbl_80B27230:
/* 80B27230  38 60 00 01 */	li r3, 1
/* 80B27234  4E 80 00 20 */	blr 
lbl_80B27238:
/* 80B27238  38 60 00 02 */	li r3, 2
/* 80B2723C  4E 80 00 20 */	blr 
lbl_80B27240:
/* 80B27240  38 60 00 03 */	li r3, 3
/* 80B27244  4E 80 00 20 */	blr 
lbl_80B27248:
/* 80B27248  38 60 00 04 */	li r3, 4
/* 80B2724C  4E 80 00 20 */	blr 
lbl_80B27250:
/* 80B27250  38 60 00 05 */	li r3, 5
/* 80B27254  4E 80 00 20 */	blr 
lbl_80B27258:
/* 80B27258  38 60 00 06 */	li r3, 6
/* 80B2725C  4E 80 00 20 */	blr 