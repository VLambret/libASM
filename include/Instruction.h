#ifndef _Instruction_H
#define _Instruction_H

/**	\file	Instruction.h
	\brief	Instruction class
	\author	Hajjem
*/

#include "Operand.h"
#include <string>
#include "OPExpression.h"
#include "OPImmediate.h"
#include "OPLabel.h"
#include "Line.h"
#include "OPRegister.h"
#include "Enum_type.h"

using namespace std;

/**	\class	Instruction
	\brief	class representing an instruction which herited by Line
*/


class Instruction :public Line{

private:
	t_Operator _op;
	t_Format _format;
	t_Inst _type;
	Operand *_op1;
	Operand *_op2;
	Operand *_op3;
	int _nbrOper;

public:

/**	\brief	Constructor of the class instruction
*/
	Instruction(string, t_Operator, t_Format, t_Inst, Operand *, Operand *, Operand *, int);

/**	\brief	Destructor of the class instruction
*/
	virtual ~Instruction();

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

/**	\brief	get the string Opcode value
	accessor of the string opcode
*/
	string stringOPcode();


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
	virtual t_Inst  getType();


	/**	\brief	get the type of the line
*/
	virtual t_Line typeLine();

	/**	\brief	get the name string instruction
*/
	virtual string toString();

	/**	\brief	get the string  of the instruction
*/
	virtual string getContent();

	/**	\brief	set the string of the instruction
*/
	virtual void setContent(string);

/**	\brief	set the string format
*/
	string stringForm();

/**	\brief	set the string Type of instruction
*/
	string stringType();

/**	\brief	get the dependance between the current instruction and i2
	\return return "RAW", "WAR", "WAW" or "not dependant" in format string
*/
	string is_dependant(Instruction i2);

/**	\brief	get the dependance RAW between the current instruction and i2	\return return "RAW" or "not dependant" in format string
*/
	string RAW(Instruction i2);

/**	\brief	get the dependance between the current instruction and i2	\return return "WAR" or "not dependant" in format string
*/
	string WAR(Instruction i2);

/**	\brief	get the dependance between the current instruction and i2	\return return "WAW" or "not dependant" in format string
*/
	string WAW(Instruction i2);

/**	\brief	get the number of operand	\return return the number of operand
*/
	int getNumberOper();


/**	\brief	set the number of operand*/
	void setNumberOper(int);

	/**	\brief	return true if the directive indicate a function
*/
	virtual bool isFunction();


};

#endif
