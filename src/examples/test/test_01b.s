	.file	1 "test_01b.c"
	.section .mdebug.abi32
	.previous
	.gnu_attribute 4, 1
	.abicalls
	.text
	.align	2
	.globl	is_prim_num
	.set	nomips16
	.ent	is_prim_num
	.type	is_prim_num, @function
is_prim_num:
	.frame	$fp,24,$31		# vars= 8, regs= 1/0, args= 0, gp= 8
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-24
	sw	$fp,20($sp)
	move	$fp,$sp
	sw	$4,24($fp)
	sw	$5,28($fp)
	li	$2,2			# 0x2
	sw	$2,8($fp)
	.option	pic0
	j	$L2
	nop

	.option	pic2
$L5:
	lw	$2,28($fp)
	nop
	addiu	$2,$2,4
	sw	$2,28($fp)
	lw	$3,24($fp)
	lw	$2,8($fp)
	nop
	bne	$2,$0,1f
	div	$0,$3,$2
	break	7
1:
	mfhi	$2
	bne	$2,$0,$L3
	nop

	move	$2,$0
	.option	pic0
	j	$L4
	nop

	.option	pic2
$L3:
	lw	$2,8($fp)
	nop
	addiu	$2,$2,1
	sw	$2,8($fp)
$L2:
	lw	$2,24($fp)
	nop
	srl	$3,$2,31
	addu	$2,$3,$2
	sra	$2,$2,1
	addiu	$3,$2,1
	lw	$2,8($fp)
	nop
	slt	$2,$2,$3
	bne	$2,$0,$L5
	nop

	li	$2,1			# 0x1
$L4:
	move	$sp,$fp
	lw	$fp,20($sp)
	addiu	$sp,$sp,24
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	is_prim_num
	.size	is_prim_num, .-is_prim_num
	.align	2
	.globl	main
	.set	nomips16
	.ent	main
	.type	main, @function
main:
	.frame	$fp,48,$31		# vars= 16, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-48
	sw	$31,44($sp)
	sw	$fp,40($sp)
	move	$fp,$sp
	sw	$0,28($fp)
	lw	$2,32($fp)
	li	$3,1			# 0x1
	sw	$3,0($2)
	sw	$0,24($fp)
	.option	pic0
	j	$L7
	nop

	.option	pic2
$L9:
	lw	$4,24($fp)
	lw	$5,32($fp)
	.option	pic0
	jal	is_prim_num
	nop

	.option	pic2
	beq	$2,$0,$L8
	nop

	lw	$2,28($fp)
	nop
	addiu	$2,$2,1
	sw	$2,28($fp)
$L8:
	lw	$2,24($fp)
	nop
	addiu	$2,$2,1
	sw	$2,24($fp)
$L7:
	lw	$2,24($fp)
	nop
	slt	$2,$2,20
	bne	$2,$0,$L9
	nop

	lw	$2,28($fp)
	move	$sp,$fp
	lw	$31,44($sp)
	lw	$fp,40($sp)
	addiu	$sp,$sp,48
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (GNU) 4.5.2"
