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
	#test
