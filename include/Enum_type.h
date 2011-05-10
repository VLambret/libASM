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
	// !!WARNING!! :If you add new Operators, dont forget to report their caracteristics in op_profile !!
	enum t_Operator{
	b,		beqz,	bnez,	beq,	bgez,	bgezal,
	bgtz,	blez,	bltz,	bltzal,	bne,	j,
	jal,	jalr,	jr,		la,		li,		loadi,
	sb,		sh,		lb,		lbu,	lh,		lhu,
	lui,	lw,		lwl,	lwr,	sw,		add,
	addu,	addi,	addiu,	andu,	andi,	mul,
	mult,	multu,	nor,	oru,	ori,	srl,
	srlv,	sub,	subu,	sll,	sllv,	slt,
	slti,	sltiu,	sltu,	xoru,	xori,	sra,
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
			{beqz,		B,		BAD2},
			{bnez,		B,		BAD2},
			{beq,		B,		BAD2},
			{bgez,		B,		BAD2},
			{bgezal,	B,		BAD2},
			{bgtz,		B,		BAD2},
			{blez,		B,		BAD2},
			{bltz,		B,		BAD2},
			{bltzal,	B,		BAD2},
			{bne,		B,		BAD2},
			{j,			B,		BAD2},
			{jal,		B,		BAD2},
			{jalr,		B,		BAD2},
			{jr,		B,		BAD2},
			{la,		B,		BAD2},
			{li,		B,		BAD2},
			{loadi,		B,		BAD2},
			{sb,		B,		BAD2},
			{sh,		B,		BAD2},
			{lb,		B,		BAD2},
			{lbu,		B,		BAD2},
			{lh,		B,		BAD2},
			{lhu,		B,		BAD2},
			{lui,		B,		BAD2},
			{lw,		B,		BAD2},
			{lwl,		B,		BAD2},
			{lwr,		B,		BAD2},
			{sw,		B,		BAD2},
			{add,		B,		BAD2},
			{addu,		B,		BAD2},
			{addi,		B,		BAD2},
			{addiu,		B,		BAD2},
			{andu,		B,		BAD2},
			{andi,		B,		BAD2},
			{mul,		B,		BAD2},
			{mult,		B,		BAD2},
			{multu,		B,		BAD2},
			{nor,		B,		BAD2},
			{oru,		B,		BAD2},
			{ori,		B,		BAD2},
			{srl,		B,		BAD2},
			{srlv,		B,		BAD2},
			{sub,		B,		BAD2},
			{subu,		B,		BAD2},
			{sll,		B,		BAD2},
			{sllv,		B,		BAD2},
			{slt,		B,		BAD2},
			{slti,		B,		BAD2},
			{sltiu,		B,		BAD2},
			{sltu,		B,		BAD2},
			{xoru,		B,		BAD2},
			{xori,		B,		BAD2},
			{sra,		B,		BAD2},
			{srav,		B,		BAD2},
			{div_,		B,		BAD2},
			{divu,		B,		BAD2},
			{mfhi,		B,		BAD2},
			{mflo,		B,		BAD2},
			{mthi,		B,		BAD2},
			{mtlo,		B,		BAD2},
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

 
  

