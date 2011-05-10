#ifndef _Enum_type_H
#define _Enum_type_H

/**	\brief	Type enum which take the type of the operand			
*/
	enum t_OpType {Imm,Exp,Lab,Reg,};

/**	\brief	Type enum which take the format of the instructions			
*/
	enum  t_Format {J, I, R, O, B};

/**	\brief	Type enum which take the type of the instructions			
*/
	enum t_Inst {ALU, MEM, BR, OTHER,BAD2};

/**	\brief	Type enum which take the Operator of the instructions			
*/
	// !!WARNING!! :If you add new Operators, dont forget to report their caracteristics in op_profile with the same order !!
	enum t_Operator{
	b,		beqz,	bnez,	beq,	bgez,	bgezal,
	bgtz,	blez,	bltz,	bltzal,	bne,	j,
	jal,	jalr,	jr,		la,		li,		loadi,
	sb,		sh,		lb,		lbu,	lh,		lhu,
	lui,	lw,		lwl,	lwr,	sw,		add,
	addu,	addi,	addiu,	andu,	andi,	mul,
	mult,	multu,	nor,	oru,	ori,	srl,
	srlv,	sub,	subu,	sll,	sllv,	slt,
	slti,	sltiu,	sltu,	xor_,	xori,	sra,
	srav,	div_,	divu,	mfhi,	mflo,	mthi,
	mtlo,	move,	neg,	negu,	nop,	breaku,
	syscallu,mfc0,	mtc0,	clo,	clz,	ebase,
	eepc,	eret,	ll,		madd,	maddu,	mfc2,
	movn,	movz,	msub,	msubu,	mtc2,	pref,
	sc,		syncu,	tccontext,teq,	teqi,	tge,
	tgei,	tgeiu,	tgeu,	tlt,	 tlti,	tltiu,
	tltu,	tne,	tnei,	waitn,	rfe};

/**	\brief	Structure allowing to add caracteristics to an operator*/
	struct s_Profile {
		t_Operator	op ;
		t_Format	format ;
		t_Inst		type ;
	} ;

	static s_Profile op_profile[rfe+1] = {
			{b,			B,		BAD2},
			{beqz,		I,		BR},
			{bnez,		I,		BR},
			{beq,		I,		BR},
			{bgez,		I,		BR},
			{bgezal,	I,		BR},
			{bgtz,		I,		BR},
			{blez,		I,		BR},
			{bltz,		I,		BR},
			{bltzal,	I,		BR},
			{bne,		I,		BR},
			{j,			J,		BR},
			{jal,		J,		BR},
			{jalr,		R,		BR},
			{jr,		R,		BR},
			{la,		O,		OTHER},
			{li,		O,		OTHER},
			{loadi,		O,		OTHER},
			{sb,		I,		MEM},
			{sh,		I,		MEM},
			{lb,		I,		MEM},
			{lbu,		I,		MEM},
			{lh,		I,		MEM},
			{lhu,		I,		MEM},
			{lui,		I,		MEM},
			{lw,		I,		MEM},
			{lwl,		B,		BAD2},
			{lwr,		B,		BAD2},
			{sw,		I,		MEM},
			{add,		R,		ALU},
			{addu,		R,		ALU},
			{addi,		I,		ALU},
			{addiu,		I,		ALU},
			{andu,		B,		BAD2},
			{andi,		I,		ALU},
			{mul,		B,		BAD2},
			{mult,		R,		ALU},
			{multu,		R,		ALU},
			{nor,		R,		ALU},
			{oru,		B,		BAD2},
			{ori,		I,		ALU},
			{srl,		R,		ALU},
			{srlv,		R,		ALU},
			{sub,		R,		ALU},
			{subu,		R,		ALU},
			{sll,		R,		ALU},
			{sllv,		R,		ALU},
			{slt,		R,		ALU},
			{slti,		I,		ALU},
			{sltiu,		I,		ALU},
			{sltu,		R,		ALU},
			{xor_,		R,		ALU},
			{xori,		I,		ALU},
			{sra,		R,		ALU},
			{srav,		R,		ALU},
			{div_,		R,		ALU},
			{divu,		R,		ALU},
			{mfhi,		R,		OTHER},
			{mflo,		R,		OTHER},
			{mthi,		R,		OTHER},
			{mtlo,		R,		OTHER},
			{move,		B,		BAD2},
			{neg,		B,		BAD2},
			{negu,		B,		BAD2},
			{nop,		B,		BAD2},
			{breaku,	B,		BAD2},
			{syscallu,	B,		BAD2},
			{mfc0,		B,		BAD2},
			{mtc0,		B,		BAD2},
			{clo,		B,		BAD2},
			{clz,		B,		BAD2},
			{ebase,		B,		BAD2},
			{eepc,		B,		BAD2},
			{eret,		B,		BAD2},
			{ll,		B,		BAD2},
			{madd,		B,		BAD2},
			{maddu,		B,		BAD2},
			{mfc2,		B,		BAD2},
			{movn,		B,		BAD2},
			{movz,		B,		BAD2},
			{msub,		B,		BAD2},
			{msubu,		B,		BAD2},
			{mtc2,		B,		BAD2},
			{pref,		B,		BAD2},
			{sc,		B,		BAD2},
			{syncu,		B,		BAD2},
			{tccontext,	B,		BAD2},
			{teq,		B,		BAD2},
			{teqi,		B,		BAD2},
			{tge,		B,		BAD2},
			{tgei,		B,		BAD2},
			{tgeiu,		B,		BAD2},
			{tgeu,		B,		BAD2},
			{tlt,		B,		BAD2},
			{tlti,		B,		BAD2},
			{tltiu,		B,		BAD2},
			{tltu,		B,		BAD2},
			{tne,		B,		BAD2},
			{tnei,		B,		BAD2},
			{waitn,		B,		BAD2},
			{rfe,		B,		BAD2}
		};

	




/**	\brief	Type enum which take the type of the line			
*/
	enum t_Line {line_Instru,line_Lab,line_Direct};

/**	\brief	Type enum which take the type of the register			
*/
	enum t_Src_Dst {Src,Dst};


#endif

 
  

