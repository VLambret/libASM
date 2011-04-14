#ifndef _Instruction_H
#define _Instruction_H

/**	\file	Instruction.h
	\brief	Instruction class
	\author	Hajjem
*/

#include "Operand.h"
#include "OPExpression.h"
#include "OPImmediate.h"
#include "OPLabel.h"
#include "Line.h"
#include "OPRegister.h"
#include <string>
#include "Enum_type.h"

using namespace std;

/**	\class	Instruction
	\brief	class representing an instruction which herited by _line
*/

string opString[]={"b", "beqz", "bnez"," beq"," bgez"," bgezal"," bgtz"," blez"," bltz"," bltzal"," bne", 
			"j"," jal"," jalr"," jr",
			"la"," li"," loadi"," sb"," sh"," lb"," lbu"," lh"," lhu"," lui"," lw"," lwl"," lwr"," sw",
			"add"," addu"," addi"," addiu"," andu"," andi"," mul"," mult"," multu"," nor"," oru"," ori", 
			"srl"," srlv"," sub"," subu"," sll"," sllv"," slt"," slti"," sltiu"," sltu","xoru"," xori",
			"sra"," srav","  div"," divu"," mfhi"," mflo"," mthi"," mtlo", 
			"move"," neg"," negu"," nop","breaku"," syscallu","mfc0","mtc0",
 			"clo"," clz"," ebase"," eepc"," eret"," ll"," madd"," maddu", 
			"mfc2"," movn"," movz"," msub"," msubu"," mtc2","pref"," sc"," syncu",
		 	"tccontext"," teq"," teqi"," tge","tgei"," tgeiu"," tgeu"," tlt",
      			"tlti"," tltiu"," tltu"," tne"," tnei"," waitn"  };

class Instruction :public Line{

private:
	t_Operator _op;
	t_Format _format;
	t_Inst _type;
	Operand *_op1;
	Operand *_op2;
	Operand *_op3;

public:

/**	\brief	Constructor of the class instrcution
*/
	Instruction(string, t_Operator, t_Format, t_Inst, Operand *, Operand *, Operand *);

/**	\brief	Destructor of the class instruction
*/
	~Instruction();

/**	\brief	Get the first operand value
	accessor of the operand
*/
	Operand* getOp1();

/**	\brief	set the first operand value
	setter of the operand
*/
	void setOp1(Operand * o);

/**	\brief	Get the second operand value
	accessor of the operand
*/
	Operand* getOp2();

/**	\brief	set the second operand value
	setter of the operand
*/
	void setOp2(Operand * o);

/**	\brief	Get the third operand value
	accessor of the operand
*/
	Operand* getOp3();

/**	\brief	set the third operand value
	setter of the operand
*/
	void setOp3(Operand * o);

/**	\brief	get the Opcode value
	accessor of the opcode
*/
	t_Operator getOPcode();

/**	\brief	set the opcode value
	setter of the opcode
*/
	void setOPcode(t_Operator newop);

/**	\brief	get the format of the Instruction
	accessor of the format
*/
	t_Format getFormat();

/**	\brief	get the Type of the Instruction
	accessor of the Type
*/	
	t_Inst  getType();
	

	/**	\brief	get the type of the line
*/
	virtual t_Line typeLine();

	/**	\brief	get the string instruction
*/	
	virtual string toString();

	/**	\brief	get the string  of the instruction
*/	

	virtual string getContent();

	/**	\brief	set the string of the instruction
*/	

	virtual void setContent(string);





};

#endif
