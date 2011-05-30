
primes.o:     file format elf32-tradlittlemips


Disassembly of section .text:

00000000 <is_prim_num>:
   0:	27bdffe8 	addiu	sp,sp,-24
   4:	afbe0010 	sw	s8,16(sp)
   8:	03a0f021 	move	s8,sp
   c:	afc40018 	sw	a0,24(s8)
  10:	afc5001c 	sw	a1,28(s8)
  14:	24020002 	li	v0,2
  18:	afc20000 	sw	v0,0(s8)
  1c:	10000015 	b	74 <is_prim_num+0x74>
  20:	00000000 	nop
  24:	8fc2001c 	lw	v0,28(s8)
  28:	00000000 	nop
  2c:	24420004 	addiu	v0,v0,4
  30:	afc2001c 	sw	v0,28(s8)
  34:	8fc30018 	lw	v1,24(s8)
  38:	8fc20000 	lw	v0,0(s8)
  3c:	00000000 	nop
  40:	14400002 	bnez	v0,4c <is_prim_num+0x4c>
  44:	0062001a 	div	zero,v1,v0
  48:	0007000d 	break	0x7
  4c:	00001010 	mfhi	v0
  50:	14400004 	bnez	v0,64 <is_prim_num+0x64>
  54:	00000000 	nop
  58:	afc00008 	sw	zero,8(s8)
  5c:	10000012 	b	a8 <is_prim_num+0xa8>
  60:	00000000 	nop
  64:	8fc20000 	lw	v0,0(s8)
  68:	00000000 	nop
  6c:	24420001 	addiu	v0,v0,1
  70:	afc20000 	sw	v0,0(s8)
  74:	8fc30018 	lw	v1,24(s8)
  78:	00000000 	nop
  7c:	000317c2 	srl	v0,v1,0x1f
  80:	00431021 	addu	v0,v0,v1
  84:	00021043 	sra	v0,v0,0x1
  88:	24430001 	addiu	v1,v0,1
  8c:	8fc20000 	lw	v0,0(s8)
  90:	00000000 	nop
  94:	0043102a 	slt	v0,v0,v1
  98:	1440ffe2 	bnez	v0,24 <is_prim_num+0x24>
  9c:	00000000 	nop
  a0:	24020001 	li	v0,1
  a4:	afc20008 	sw	v0,8(s8)
  a8:	8fc20008 	lw	v0,8(s8)
  ac:	03c0e821 	move	sp,s8
  b0:	8fbe0010 	lw	s8,16(sp)
  b4:	27bd0018 	addiu	sp,sp,24
  b8:	03e00008 	jr	ra
  bc:	00000000 	nop

000000c0 <main>:
  c0:	27bdffc8 	addiu	sp,sp,-56
  c4:	afbf0034 	sw	ra,52(sp)
  c8:	afbe0030 	sw	s8,48(sp)
  cc:	03a0f021 	move	s8,sp
  d0:	3c020000 	lui	v0,0x0
  d4:	24440000 	addiu	a0,v0,0
  d8:	3c020000 	lui	v0,0x0
  dc:	24450014 	addiu	a1,v0,20
  e0:	8f990000 	lw	t9,0(gp)
  e4:	00000000 	nop
  e8:	0320f809 	jalr	t9
  ec:	00000000 	nop
  f0:	afc20018 	sw	v0,24(s8)
  f4:	8fc20018 	lw	v0,24(s8)
  f8:	00000000 	nop
  fc:	14400011 	bnez	v0,144 <main+0x84>
 100:	00000000 	nop
 104:	8f820000 	lw	v0,0(gp)
 108:	00000000 	nop
 10c:	8c43000c 	lw	v1,12(v0)
 110:	3c020000 	lui	v0,0x0
 114:	24440018 	addiu	a0,v0,24
 118:	24050001 	li	a1,1
 11c:	2406005a 	li	a2,90
 120:	00603821 	move	a3,v1
 124:	8f990000 	lw	t9,0(gp)
 128:	00000000 	nop
 12c:	0320f809 	jalr	t9
 130:	00000000 	nop
 134:	24020001 	li	v0,1
 138:	afc20028 	sw	v0,40(s8)
 13c:	100000e0 	b	4c0 <main+0x400>
 140:	00000000 	nop
 144:	24040004 	li	a0,4
 148:	8f990000 	lw	t9,0(gp)
 14c:	00000000 	nop
 150:	0320f809 	jalr	t9
 154:	00000000 	nop
 158:	afc20020 	sw	v0,32(s8)
 15c:	8fc20020 	lw	v0,32(s8)
 160:	00000000 	nop
 164:	14400011 	bnez	v0,1ac <main+0xec>
 168:	00000000 	nop
 16c:	8f820000 	lw	v0,0(gp)
 170:	00000000 	nop
 174:	8c43000c 	lw	v1,12(v0)
 178:	3c020000 	lui	v0,0x0
 17c:	24440074 	addiu	a0,v0,116
 180:	24050001 	li	a1,1
 184:	24060017 	li	a2,23
 188:	00603821 	move	a3,v1
 18c:	8f990000 	lw	t9,0(gp)
 190:	00000000 	nop
 194:	0320f809 	jalr	t9
 198:	00000000 	nop
 19c:	24020001 	li	v0,1
 1a0:	afc20028 	sw	v0,40(s8)
 1a4:	100000c6 	b	4c0 <main+0x400>
 1a8:	00000000 	nop
 1ac:	8fc40018 	lw	a0,24(s8)
 1b0:	3c020000 	lui	v0,0x0
 1b4:	2445008c 	addiu	a1,v0,140
 1b8:	8fc60020 	lw	a2,32(s8)
 1bc:	8f990000 	lw	t9,0(gp)
 1c0:	00000000 	nop
 1c4:	0320f809 	jalr	t9
 1c8:	00000000 	nop
 1cc:	8fc40018 	lw	a0,24(s8)
 1d0:	8f990000 	lw	t9,0(gp)
 1d4:	00000000 	nop
 1d8:	0320f809 	jalr	t9
 1dc:	00000000 	nop
 1e0:	8f820000 	lw	v0,0(gp)
 1e4:	00000000 	nop
 1e8:	8c43000c 	lw	v1,12(v0)
 1ec:	8fc20020 	lw	v0,32(s8)
 1f0:	00000000 	nop
 1f4:	8c460000 	lw	a2,0(v0)
 1f8:	00602021 	move	a0,v1
 1fc:	3c020000 	lui	v0,0x0
 200:	24450090 	addiu	a1,v0,144
 204:	8f990000 	lw	t9,0(gp)
 208:	00000000 	nop
 20c:	0320f809 	jalr	t9
 210:	00000000 	nop
 214:	8fc20020 	lw	v0,32(s8)
 218:	00000000 	nop
 21c:	8c420000 	lw	v0,0(v0)
 220:	00000000 	nop
 224:	00021080 	sll	v0,v0,0x2
 228:	00402021 	move	a0,v0
 22c:	8f990000 	lw	t9,0(gp)
 230:	00000000 	nop
 234:	0320f809 	jalr	t9
 238:	00000000 	nop
 23c:	afc2001c 	sw	v0,28(s8)
 240:	8fc20020 	lw	v0,32(s8)
 244:	00000000 	nop
 248:	14400012 	bnez	v0,294 <main+0x1d4>
 24c:	00000000 	nop
 250:	8f820000 	lw	v0,0(gp)
 254:	00000000 	nop
 258:	8c43000c 	lw	v1,12(v0)
 25c:	8fc20020 	lw	v0,32(s8)
 260:	00000000 	nop
 264:	8c460000 	lw	a2,0(v0)
 268:	00602021 	move	a0,v1
 26c:	3c020000 	lui	v0,0x0
 270:	244500a4 	addiu	a1,v0,164
 274:	8f990000 	lw	t9,0(gp)
 278:	00000000 	nop
 27c:	0320f809 	jalr	t9
 280:	00000000 	nop
 284:	24020001 	li	v0,1
 288:	afc20028 	sw	v0,40(s8)
 28c:	1000008c 	b	4c0 <main+0x400>
 290:	00000000 	nop
 294:	8fc3001c 	lw	v1,28(s8)
 298:	24020001 	li	v0,1
 29c:	ac620000 	sw	v0,0(v1)
 2a0:	8fc2001c 	lw	v0,28(s8)
 2a4:	00000000 	nop
 2a8:	afc20014 	sw	v0,20(s8)
 2ac:	24020002 	li	v0,2
 2b0:	afc20010 	sw	v0,16(s8)
 2b4:	10000031 	b	37c <main+0x2bc>
 2b8:	00000000 	nop
 2bc:	8fc20014 	lw	v0,20(s8)
 2c0:	00000000 	nop
 2c4:	24420004 	addiu	v0,v0,4
 2c8:	afc20014 	sw	v0,20(s8)
 2cc:	8fc40010 	lw	a0,16(s8)
 2d0:	8fc5001c 	lw	a1,28(s8)
 2d4:	8f990000 	lw	t9,0(gp)
 2d8:	00000000 	nop
 2dc:	0320f809 	jalr	t9
 2e0:	00000000 	nop
 2e4:	10400012 	beqz	v0,330 <main+0x270>
 2e8:	00000000 	nop
 2ec:	8fc30014 	lw	v1,20(s8)
 2f0:	24020001 	li	v0,1
 2f4:	ac620000 	sw	v0,0(v1)
 2f8:	8f820000 	lw	v0,0(gp)
 2fc:	00000000 	nop
 300:	8c42000c 	lw	v0,12(v0)
 304:	00000000 	nop
 308:	00402021 	move	a0,v0
 30c:	3c020000 	lui	v0,0x0
 310:	244500c0 	addiu	a1,v0,192
 314:	8fc60010 	lw	a2,16(s8)
 318:	8f990000 	lw	t9,0(gp)
 31c:	00000000 	nop
 320:	0320f809 	jalr	t9
 324:	00000000 	nop
 328:	10000010 	b	36c <main+0x2ac>
 32c:	00000000 	nop
 330:	8fc20014 	lw	v0,20(s8)
 334:	00000000 	nop
 338:	ac400000 	sw	zero,0(v0)
 33c:	8f820000 	lw	v0,0(gp)
 340:	00000000 	nop
 344:	8c42000c 	lw	v0,12(v0)
 348:	00000000 	nop
 34c:	00402021 	move	a0,v0
 350:	3c020000 	lui	v0,0x0
 354:	244500e0 	addiu	a1,v0,224
 358:	8fc60010 	lw	a2,16(s8)
 35c:	8f990000 	lw	t9,0(gp)
 360:	00000000 	nop
 364:	0320f809 	jalr	t9
 368:	00000000 	nop
 36c:	8fc20010 	lw	v0,16(s8)
 370:	00000000 	nop
 374:	24420001 	addiu	v0,v0,1
 378:	afc20010 	sw	v0,16(s8)
 37c:	8fc20020 	lw	v0,32(s8)
 380:	00000000 	nop
 384:	8c430000 	lw	v1,0(v0)
 388:	8fc20010 	lw	v0,16(s8)
 38c:	00000000 	nop
 390:	0062102a 	slt	v0,v1,v0
 394:	1040ffc9 	beqz	v0,2bc <main+0x1fc>
 398:	00000000 	nop
 39c:	8f820000 	lw	v0,0(gp)
 3a0:	00000000 	nop
 3a4:	8c43000c 	lw	v1,12(v0)
 3a8:	8fc20020 	lw	v0,32(s8)
 3ac:	00000000 	nop
 3b0:	8c420000 	lw	v0,0(v0)
 3b4:	00000000 	nop
 3b8:	24460001 	addiu	a2,v0,1
 3bc:	00602021 	move	a0,v1
 3c0:	3c020000 	lui	v0,0x0
 3c4:	24450104 	addiu	a1,v0,260
 3c8:	8f990000 	lw	t9,0(gp)
 3cc:	00000000 	nop
 3d0:	0320f809 	jalr	t9
 3d4:	00000000 	nop
 3d8:	8fc2001c 	lw	v0,28(s8)
 3dc:	00000000 	nop
 3e0:	afc20014 	sw	v0,20(s8)
 3e4:	24020001 	li	v0,1
 3e8:	afc20010 	sw	v0,16(s8)
 3ec:	10000022 	b	478 <main+0x3b8>
 3f0:	00000000 	nop
 3f4:	8fc20014 	lw	v0,20(s8)
 3f8:	00000000 	nop
 3fc:	8c430000 	lw	v1,0(v0)
 400:	24020001 	li	v0,1
 404:	1462000d 	bne	v1,v0,43c <main+0x37c>
 408:	00000000 	nop
 40c:	8f820000 	lw	v0,0(gp)
 410:	00000000 	nop
 414:	8c42000c 	lw	v0,12(v0)
 418:	00000000 	nop
 41c:	00402021 	move	a0,v0
 420:	3c020000 	lui	v0,0x0
 424:	24450134 	addiu	a1,v0,308
 428:	8fc60010 	lw	a2,16(s8)
 42c:	8f990000 	lw	t9,0(gp)
 430:	00000000 	nop
 434:	0320f809 	jalr	t9
 438:	00000000 	nop
 43c:	8fc20020 	lw	v0,32(s8)
 440:	00000000 	nop
 444:	8c430000 	lw	v1,0(v0)
 448:	8fc20010 	lw	v0,16(s8)
 44c:	00000000 	nop
 450:	10620005 	beq	v1,v0,468 <main+0x3a8>
 454:	00000000 	nop
 458:	8fc20014 	lw	v0,20(s8)
 45c:	00000000 	nop
 460:	24420004 	addiu	v0,v0,4
 464:	afc20014 	sw	v0,20(s8)
 468:	8fc20010 	lw	v0,16(s8)
 46c:	00000000 	nop
 470:	24420001 	addiu	v0,v0,1
 474:	afc20010 	sw	v0,16(s8)
 478:	8fc20020 	lw	v0,32(s8)
 47c:	00000000 	nop
 480:	8c430000 	lw	v1,0(v0)
 484:	8fc20010 	lw	v0,16(s8)
 488:	00000000 	nop
 48c:	0062102a 	slt	v0,v1,v0
 490:	1040ffd8 	beqz	v0,3f4 <main+0x334>
 494:	00000000 	nop
 498:	8f820000 	lw	v0,0(gp)
 49c:	00000000 	nop
 4a0:	8c42000c 	lw	v0,12(v0)
 4a4:	2404000a 	li	a0,10
 4a8:	00402821 	move	a1,v0
 4ac:	8f990000 	lw	t9,0(gp)
 4b0:	00000000 	nop
 4b4:	0320f809 	jalr	t9
 4b8:	00000000 	nop
 4bc:	afc00028 	sw	zero,40(s8)
 4c0:	8fc20028 	lw	v0,40(s8)
 4c4:	03c0e821 	move	sp,s8
 4c8:	8fbf0034 	lw	ra,52(sp)
 4cc:	8fbe0030 	lw	s8,48(sp)
 4d0:	27bd0038 	addiu	sp,sp,56
 4d4:	03e00008 	jr	ra
 4d8:	00000000 	nop
 4dc:	00000000 	nop

Disassembly of section .reginfo:

00000000 <.reginfo>:
   0:	f20000fc 	0xf20000fc
	...

Disassembly of section .pdr:

00000000 <.pdr>:
   0:	00000000 	nop
   4:	40000000 	mfc0	zero,c0_index
   8:	fffffff8 	0xfffffff8
	...
  14:	00000018 	mult	zero,zero
  18:	0000001e 	0x1e
  1c:	0000001f 	0x1f
  20:	00000000 	nop
  24:	c0000000 	lwc0	$0,0(zero)
  28:	fffffffc 	0xfffffffc
	...
  34:	00000038 	0x38
  38:	0000001e 	0x1e
  3c:	0000001f 	0x1f

Disassembly of section .rodata:

00000000 <.rodata>:
   0:	6d697270 	0x6d697270
   4:	6d756e5f 	0x6d756e5f
   8:	69727000 	0x69727000
   c:	756e5f6d 	jalx	5b97db4 <main+0x5b97cf4>
  10:	0000006d 	0x6d
  14:	00000072 	0x72
  18:	6e6e6143 	0x6e6e6143
  1c:	6f20746f 	0x6f20746f
  20:	206e6570 	addi	t6,v1,25968
  24:	69727027 	0x69727027
  28:	756e5f6d 	jalx	5b97db4 <main+0x5b97cf4>
  2c:	202c606d 	addi	t4,at,24685
  30:	61656c70 	0x61656c70
  34:	63206573 	0x63206573
  38:	74616572 	jalx	18595c8 <main+0x1859508>
  3c:	6e6f2065 	0x6e6f2065
  40:	69772065 	0x69772065
  44:	3a206874 	xori	zero,s1,0x6874
  48:	73755b0a 	0x73755b0a
  4c:	68407265 	0x68407265
  50:	2074736f 	addi	s4,v1,29551
  54:	756d6973 	jalx	5b5a5cc <main+0x5b5a50c>
  58:	203e5d6c 	addi	s8,at,23916
  5c:	6f686365 	0x6f686365
  60:	30303120 	andi	s0,at,0x3120
  64:	203e2030 	addi	s8,at,8240
  68:	6d697270 	0x6d697270
  6c:	6d756e5f 	0x6d756e5f
  70:	00000a20 	0xa20
  74:	6e6e6143 	0x6e6e6143
  78:	6120746f 	0x6120746f
  7c:	61636f6c 	0x61636f6c
  80:	6d206574 	0x6d206574
  84:	726f6d65 	0x726f6d65
  88:	000a2079 	0xa2079
  8c:	00006425 	0x6425
  90:	6978616d 	0x6978616d
  94:	206d756d 	addi	t5,v1,30061
  98:	756c6176 	jalx	5b185d8 <main+0x5b18518>
  9c:	25203a65 	addiu	zero,t1,14949
  a0:	00000a64 	0xa64
  a4:	6e6e6143 	0x6e6e6143
  a8:	6120746f 	0x6120746f
  ac:	61636f6c 	0x61636f6c
  b0:	6d206574 	0x6d206574
  b4:	726f6d65 	0x726f6d65
  b8:	25282079 	addiu	t0,t1,8313
  bc:	000a2964 	0xa2964
  c0:	202b2b2b 	addi	t3,at,11051
  c4:	2b206425 	slti	zero,t9,25637
  c8:	69202b2b 	0x69202b2b
  cc:	20612073 	addi	at,v1,8307
  d0:	6d697270 	0x6d697270
  d4:	756e2065 	jalx	5b88194 <main+0x5b880d4>
  d8:	7265626d 	0x7265626d
  dc:	0000000a 	0xa
  e0:	202d2d2d 	addi	t5,at,11565
  e4:	2d206425 	sltiu	zero,t1,25637
  e8:	69202d2d 	0x69202d2d
  ec:	6f6e2073 	0x6f6e2073
  f0:	20612074 	addi	at,v1,8308
  f4:	6d697270 	0x6d697270
  f8:	756e2065 	jalx	5b88194 <main+0x5b880d4>
  fc:	7265626d 	0x7265626d
 100:	0000000a 	0xa
 104:	6e697270 	0x6e697270
 108:	676e6974 	0x676e6974
 10c:	65687420 	0x65687420
 110:	69727020 	0x69727020
 114:	6e20656d 	0x6e20656d
 118:	65626d75 	0x65626d75
 11c:	62207372 	0x62207372
 120:	65777465 	0x65777465
 124:	30206e65 	andi	zero,at,0x6e65
 128:	646e6120 	0x646e6120
 12c:	3a642520 	xori	a0,s3,0x2520
 130:	0000000a 	0xa
 134:	00206425 	0x206425
	...

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	c0	0x1434700
   4:	4728203a 	c1	0x128203a
   8:	2029554e 	addi	t1,at,21838
   c:	2e322e34 	sltiu	s2,s1,11828
  10:	Address 0x0000000000000010 is out of bounds.

