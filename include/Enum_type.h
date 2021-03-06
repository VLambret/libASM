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
	enum t_Inst {ALU, MEM, BR, OTHER,BAD};

/**	\brief	Type enum which take the Operator of the instructions			
*/
	// !!WARNING!! :If you add new Operators, dont forget to report their caracteristics in op_profile with the same order !!
	enum t_Operator{
	b,	beqz,	bnez,	beq,	bgez,	bgezal,
	bgtz,	blez,	bltz,	bltzal,	bne,	j,
	jal,	jalr,	jr,	la,	li,	loadi,	
	sb,	sh,	lb,	lbu,	lh,	lhu,	
	lui,	lw,	lwl,	lwr,	ll,	pref,
	sw,	add,
	addu,	addi,	addiu,	and_,	andi,	mul,
	mult,	multu,	nor,	or_,	ori,	srl,
	srlv,	sub,	subu,	sll,	sllv,	slt,
	slti,	sltiu,	sltu,	xor_,	xori,	sra,
	srav,	div_,	divu,	mfhi,	mflo,	mthi,
	mtlo,	move,	neg,	negu,	nop,	break_,
	syscallu,mfc0,	mtc0,	clo,	clz,	ebase,
	eepc,	eret,	madd,	maddu,	mfc2,
	movn,	movz,	msub,	msubu,	mtc2,	
	sc,		sync_,	tccontext,teq,	teqi,	tge,
	tgei,	tgeiu,	tgeu,	tlt,	 tlti,	tltiu,
	tltu,	tne,	tnei,	waitn,	rfe,	maxop};

/**	\brief	Type enum which take the type of dependance			
*/
	enum t_Dep {NONE,RAW,WAR,WAW};

/**	\brief	Structure allowing to add caracteristics to an operator*/
	struct s_Profile {
		t_Operator	op ;
		t_Format	format ;
		t_Inst		type ;
	} ;

	static s_Profile op_profile[maxop] = {
			{b,		B,		BAD},
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
			{j,		J,		BR},
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
			{lwl,		B,		BAD},
			{lwr,		B,		BAD},
			{ll,		B,		BAD},
			{pref,		O,		MEM},
			{sw,		I,		MEM},
			{add,		R,		ALU},
			{addu,		R,		ALU},
			{addi,		I,		ALU},
			{addiu,		I,		ALU},
			{and_,		R,		ALU},
			{andi,		I,		ALU},
			{mul,		B,		BAD},
			{mult,		R,		ALU},
			{multu,		R,		ALU},
			{nor,		R,		ALU},
			{or_,		R,		ALU},
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
			{move,		B,		BAD},
			{neg,		B,		BAD},
			{negu,		B,		BAD},
			{nop,		B,		BAD},
			{break_,	B,		BAD},
			{syscallu,	B,		BAD},
			{mfc0,		B,		BAD},
			{mtc0,		B,		BAD},
			{clo,		B,		BAD},
			{clz,		B,		BAD},
			{ebase,		B,		BAD},
			{eepc,		B,		BAD},
			{eret,		B,		BAD},
			{madd,		B,		BAD},
			{maddu,		B,		BAD},
			{mfc2,		B,		BAD},
			{movn,		B,		BAD},
			{movz,		B,		BAD},
			{msub,		B,		BAD},
			{msubu,		B,		BAD},
			{mtc2,		B,		BAD},
			{sc,		B,		BAD},
			{sync_,		B,		BAD},
			{tccontext,	B,		BAD},
			{teq,		B,		BAD},
			{teqi,		B,		BAD},
			{tge,		B,		BAD},
			{tgei,		B,		BAD},
			{tgeiu,		B,		BAD},
			{tgeu,		B,		BAD},
			{tlt,		B,		BAD},
			{tlti,		B,		BAD},
			{tltiu,		B,		BAD},
			{tltu,		B,		BAD},
			{tne,		B,		BAD},
			{tnei,		B,		BAD},
			{waitn,		B,		BAD},
			{rfe,		B,		BAD}
		};


	static int t_delay[5][5]={{1,1,2,-1,-1},
			 {2,2,3,-1,-1},
			 {1,1,2,-1,-1},
			 {-1,-1,-1,-1,-1},
			 {-1,-1,-1,-1,-1}};

/**	\brief	Type enum which take the type of the line			
*/
	enum t_Line {line_Instru,line_Lab,line_Direct};

/**	\brief	Type enum which take the type of the register			
*/
	enum t_Src_Dst {Src,Dst,CopSrc,CopDst} ;


#endif

 
  

