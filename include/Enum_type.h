#ifndef _Enum_type_H
#define _Enum_type_H

/**	\brief	Type enum which take the type of the operand			
*/
	enum t_OpType {Imm,Exp,Lab,Reg};

/**	\brief	Type enum which take the format of the instructions			
*/
	enum  t_Format {J, I, R, O};

/**	\brief	Type enum which take the type of the instructions			
*/
	enum t_Inst {ALU, MEM, BR, OTHER};

/**	\brief	Type enum which take the Operator of the instructions			
*/
	enum t_Operator {b, beqz, bnez, beq, bgez, bgezal, bgtz, blez, bltz, bltzal, bne, 
			j, jal, jalr, jr,
			la, li, loadi, sb, sh, lb, lbu, lh, lhu, lui, lw, lwl, lwr, sw,
			add, addu, addi, addiu, andu, andi, mul, mult, multu, nor, oru, ori, 
			srl, srlv, sub, subu, sll, sllv, slt, slti, sltiu, sltu,xoru, xori,
			sra, srav,  div_, divu, mfhi, mflo, mthi, mtlo, 
			move, neg, negu, nop,breaku, syscallu,mfc0,mtc0,
 			clo, clz, ebase, eepc, eret, ll, madd, maddu, 
			mfc2, movn, movz, msub, msubu, mtc2,pref, sc, syncu,
		 	tccontext, teq, teqi, tge,tgei, tgeiu, tgeu, tlt,
      			tlti, tltiu, tltu, tne, tnei, waitn,
			rfe  };

/**	\brief	Type enum which take the type of the line			
*/
	enum t_Line {line_Instru,line_Lab,line_Direct};

/**	\brief	Type enum which take the type of the register			
*/
	enum t_Src_Dst {Src,Dst};


#endif

 
  

