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
