	.file	1 "primes.c"
	.section .mdebug.abi32
	.previous
	.text
	.align	2
	.globl	is_prim_num
	.ent	is_prim_num
is_prim_num:
	.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-8
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-24
	sw	$fp,16($sp)
	move	$fp,$sp
	sw	$4,24($fp)
	sw	$5,28($fp)
	li	$2,2			# 0x2
	sw	$2,0($fp)
	j	$L2
	nop

$L3:
	lw	$2,28($fp)
	nop
	addiu	$2,$2,4
	sw	$2,28($fp)
	lw	$3,24($fp)
	lw	$2,0($fp)
	nop
	bne	$2,$0,1f
	div	$0,$3,$2
	break	7
1:
	mfhi	$2
	bne	$2,$0,$L4
	nop

	sw	$0,8($fp)
	j	$L6
	nop

$L4:
	lw	$2,0($fp)
	nop
	addiu	$2,$2,1
	sw	$2,0($fp)
$L2:
	lw	$3,24($fp)
	nop
	srl	$2,$3,31
	addu	$2,$2,$3
	sra	$2,$2,1
	addiu	$3,$2,1
	lw	$2,0($fp)
	nop
	slt	$2,$2,$3
	bne	$2,$0,$L3
	nop

	li	$2,1			# 0x1
	sw	$2,8($fp)
$L6:
	lw	$2,8($fp)
	move	$sp,$fp
	lw	$fp,16($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	is_prim_num
	.size	is_prim_num, .-is_prim_num
	.rdata
	.align	2
$LC0:
	.ascii	"prim_num\000"
	.asciiz	"prim_num\000"
	.align	2
$LC1:
	.ascii	"r\000"
	.align	2
$LC2:
	.ascii	"Cannot open 'prim_num`, please create one with :\012[use"
	.ascii	"r@host simul]> echo 1000 > prim_num \012\000"
	.align	2
$LC3:
	.ascii	"Cannot alocate memory \012\000"
	.align	2
$LC4:
	.ascii	"%d\000"
	.align	2
$LC5:
	.ascii	"maximum value: %d\012\000"
	.align	2
$LC6:
	.ascii	"Cannot alocate memory (%d)\012\000"
	.align	2
$LC7:
	.ascii	"+++ %d +++ is a prime number\012\000"
	.align	2
$LC8:
	.ascii	"--- %d --- is not a prime number\012\000"
	.align	2
$LC9:
	.ascii	"printing the prime numbers between 0 and %d:\012\000"
	.align	2
$LC10:
	.ascii	"%d \000"
	.text
	.align	2
	.globl	main
	.ent	main
main:
	.frame	$fp,56,$31		# vars= 32, regs= 2/0, args= 16, gp= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	
	addiu	$sp,$sp,-56
	sw	$31,52($sp)
	sw	$fp,48($sp)
	move	$fp,$sp
	lui	$2,%hi($LC0)
	addiu	$4,$2,%lo($LC0)
	lui	$2,%hi($LC1)
	addiu	$5,$2,%lo($LC1)
	jal	fopen
	nop

	sw	$2,24($fp)
	lw	$2,24($fp)
	nop
	bne	$2,$0,$L10
	nop

	lw	$2,%gp_rel(_impure_ptr)($28)
	nop
	lw	$3,12($2)
	lui	$2,%hi($LC2)
	addiu	$4,$2,%lo($LC2)
	li	$5,1			# 0x1
	li	$6,90			# 0x5a
	move	$7,$3
	jal	fwrite
	nop

	li	$2,1			# 0x1
	sw	$2,40($fp)
	j	$L12
	nop

$L10:
	li	$4,4			# 0x4
	jal	malloc
	nop

	sw	$2,32($fp)
	lw	$2,32($fp)
	nop
	bne	$2,$0,$L13
	nop

	lw	$2,%gp_rel(_impure_ptr)($28)
	nop
	lw	$3,12($2)
	lui	$2,%hi($LC3)
	addiu	$4,$2,%lo($LC3)
	li	$5,1			# 0x1
	li	$6,23			# 0x17
	move	$7,$3
	jal	fwrite
	nop

	li	$2,1			# 0x1
	sw	$2,40($fp)
	j	$L12
	nop

$L13:
	lw	$4,24($fp)
	lui	$2,%hi($LC4)
	addiu	$5,$2,%lo($LC4)
	lw	$6,32($fp)
	jal	fscanf
	nop

	lw	$4,24($fp)
	jal	fclose
	nop

	lw	$2,%gp_rel(_impure_ptr)($28)
	nop
	lw	$3,12($2)
	lw	$2,32($fp)
	nop
	lw	$6,0($2)
	move	$4,$3
	lui	$2,%hi($LC5)
	addiu	$5,$2,%lo($LC5)
	jal	fprintf
	nop

	lw	$2,32($fp)
	nop
	lw	$2,0($2)
	nop
	sll	$2,$2,2
	move	$4,$2
	jal	malloc
	nop

	sw	$2,28($fp)
	lw	$2,32($fp)
	nop
	bne	$2,$0,$L15
	nop

	lw	$2,%gp_rel(_impure_ptr)($28)
	nop
	lw	$3,12($2)
	lw	$2,32($fp)
	nop
	lw	$6,0($2)
	move	$4,$3
	lui	$2,%hi($LC6)
	addiu	$5,$2,%lo($LC6)
	jal	fprintf
	nop

	li	$2,1			# 0x1
	sw	$2,40($fp)
	j	$L12
	nop

$L15:
	lw	$3,28($fp)
	li	$2,1			# 0x1
	sw	$2,0($3)
	lw	$2,28($fp)
	nop
	sw	$2,20($fp)
	li	$2,2			# 0x2
	sw	$2,16($fp)
	j	$L17
	nop

$L18:
	lw	$2,20($fp)
	nop
	addiu	$2,$2,4
	sw	$2,20($fp)
	lw	$4,16($fp)
	lw	$5,28($fp)
	jal	is_prim_num
	nop

	beq	$2,$0,$L19
	nop

	lw	$3,20($fp)
	li	$2,1			# 0x1
	sw	$2,0($3)
	lw	$2,%gp_rel(_impure_ptr)($28)
	nop
	lw	$2,12($2)
	nop
	move	$4,$2
	lui	$2,%hi($LC7)
	addiu	$5,$2,%lo($LC7)
	lw	$6,16($fp)
	jal	fprintf
	nop

	j	$L21
	nop

$L19:
	lw	$2,20($fp)
	nop
	sw	$0,0($2)
	lw	$2,%gp_rel(_impure_ptr)($28)
	nop
	lw	$2,12($2)
	nop
	move	$4,$2
	lui	$2,%hi($LC8)
	addiu	$5,$2,%lo($LC8)
	lw	$6,16($fp)
	jal	fprintf
	nop

$L21:
	lw	$2,16($fp)
	nop
	addiu	$2,$2,1
	sw	$2,16($fp)
$L17:
	lw	$2,32($fp)
	nop
	lw	$3,0($2)
	lw	$2,16($fp)
	nop
	slt	$2,$3,$2
	beq	$2,$0,$L18
	nop

	lw	$2,%gp_rel(_impure_ptr)($28)
	nop
	lw	$3,12($2)
	lw	$2,32($fp)
	nop
	lw	$2,0($2)
	nop
	addiu	$6,$2,1
	move	$4,$3
	lui	$2,%hi($LC9)
	addiu	$5,$2,%lo($LC9)
	jal	fprintf
	nop

	lw	$2,28($fp)
	nop
	sw	$2,20($fp)
	li	$2,1			# 0x1
	sw	$2,16($fp)
	j	$L23
	nop

$L24:
	lw	$2,20($fp)
	nop
	lw	$3,0($2)
	li	$2,1			# 0x1
	bne	$3,$2,$L25
	nop

	lw	$2,%gp_rel(_impure_ptr)($28)
	nop
	lw	$2,12($2)
	nop
	move	$4,$2
	lui	$2,%hi($LC10)
	addiu	$5,$2,%lo($LC10)
	lw	$6,16($fp)
	jal	fprintf
	nop

$L25:
	lw	$2,32($fp)
	nop
	lw	$3,0($2)
	lw	$2,16($fp)
	nop
	beq	$3,$2,$L27
	nop

	lw	$2,20($fp)
	nop
	addiu	$2,$2,4
	sw	$2,20($fp)
$L27:
	lw	$2,16($fp)
	nop
	addiu	$2,$2,1
	sw	$2,16($fp)
$L23:
	lw	$2,32($fp)
	nop
	lw	$3,0($2)
	lw	$2,16($fp)
	nop
	slt	$2,$3,$2
	beq	$2,$0,$L24
	nop

	lw	$2,%gp_rel(_impure_ptr)($28)
	nop
	lw	$2,12($2)
	li	$4,10			# 0xa
	move	$5,$2
	jal	fputc
	nop

	sw	$0,40($fp)
$L12:
	lw	$2,40($fp)
	move	$sp,$fp
	lw	$31,52($sp)
	lw	$fp,48($sp)
	addiu	$sp,$sp,56
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (GNU) 4.2.4"
