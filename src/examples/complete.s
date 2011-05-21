	# This file aim to test all parser cases
function1:
label1:

	j		label1
	jal		label1

	syscall
	eret
	sync
	wait
	rfe

	jalr	$1
	jalr	$2,	$3

	mfhi	$4
	mflo	$5

	lb		$2,42($8)
	lbu		$3,43($7)
	lh		$4,44($6)
	lhu		$5,45($5)
	lw		$6,46($4)
	lwl		$7,47($3)
	lwr		$8,48($2)
	ll		$9,49($1)
	
	lb		$2,42
	lbu		$3,43
	lh		$4,44
	lhu		$5,45
	lw		$6,46
	lwl		$7,47
	lwr		$8,48
	ll		$9,49
	
	lb		$2,($8)
	lbu		$3,($7)
	lh		$4,($6)
	lhu		$5,($5)
	lw		$6,($4)
	lwl		$7,($3)
	lwr		$8,($2)
	ll		$9,($1)

	lui		$10,42

	clo		$11,$12
	clz		$13,$14

	add		$1,	$2,	$3
	addu	$1,	$2,	$3
	and		$1,	$2,	$3
	mul		$1,	$2,	$3
	nor		$1,	$2,	$3
	or		$1,	$2,	$3
	slt		$1,	$2,	$3
	sltu	$1,	$2,	$3
	sub		$1,	$2,	$3
	subu	$1,	$2,	$3
	xor		$1,	$2,	$3
	movn	$1,	$2,	$3
	movz	$1,	$2,	$3

	addi	$2,	$3,	42
	addiu	$4,	$5,	43
	slti	$6,	$7,	44
	sltiu	$8,	$9,	45

	andi	$2,	$3,	42
	ori		$4,	$5,	43
	xori	$6,	$7,	44

	sllv	$1,	$2,	$3
	srav	$4,	$5,	$6
	srlv	$7,	$8,	$9
	
	sll		$1,	$2,	30
	sra		$4,	$5,	60
	srl		$7,	$8,	90

	jr		$10
	mthi	$11
	mtlo	$12

	bgez	$0,	label1
	bgezal	$1,	label2
	bgtz	$2,	label3
	blez	$3,	label4
	bltz	$4,	label5
	bltzal	$5,	label6

	mult	$0,		$3
	multu	$2,		$5
	div		$4,		$7
	divu	$6,		$9
	madd	$8,		$11
	maddu	$10,	$13
	msub	$12,	$15
	msubu	$14,	$17
	teq		$16,	$19
	tge		$18,	$21
	tgeu	$20,	$23
	tlt		$22,	$25
	tltu	$24,	$27
	tne		$26,	$29

	beq		$1,		$2,		label1
	bne		$3,		$4,		label2

	teqi	$16,	19
	tgei	$18,	21
	tgeiu	$20,	23
	tlti	$22,	25
	tltiu	$24,	27
	tnei	$26,	29

	mfc0	r20,	status
	mtc0	$zero,	status
	
	mfc2	r20,	$0
	mtc2	$zero,	$1

	sb		$0,		4($8)
	sh		$1,		5($9)
	sw		$2,		6($10)
	sc		$3,		7($11)
	sb		$0,		($8)
	sh		$1,		($9)
	sw		$2,		($10)
	sc		$3,		($11)
	sb		$0,		4
	sh		$1,		5
	sw		$2,		6
	sc		$3,		7

	break 	-10

	pref	10,		11($12)

	li		$10,	0xFFFF0000
	loadi	$11,	0x0000FFFF

	move	$5,		$4

	b		infini
	nop
	
	la		$10,		etaudela

	neg		$10,	$11
	negu	$12,	$13

	beqz	$14,	labela
	bnez	$15,	labelb

	.ent	toto
	.end	toto
	.text
	.section .mdebug.abi32

	.align	2
	.extern	toto
	.global	toto
	
	.ascii	"prim_num\000"
