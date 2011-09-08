#ifndef _Instruction_H
#define _Instruction_H

/**	\file	Instruction.h
	\brief	Instruction class
	\author	Hajjem
*/

#include <Operand.h>
#include <string>
#include <OPExpression.h>
#include <OPImmediate.h>
#include <OPLabel.h>
#include <Line.h>
#include <OPRegister.h>
#include <Enum_type.h>
#include <list>

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
	int _index;
	int _nbr_succ;
	int _nbr_pred;
	list <Instruction *> _successor;
	list <Instruction *> _predecessor;

public:

/**	\brief	Constructor of the class instruction
*/
	Instruction(string, t_Operator, t_Format, t_Inst, Operand *, Operand *, Operand *, int);

/**	\brief	Constructor with 3 Operands of the class instruction */
	Instruction(t_Operator, Operand *, Operand *, Operand *);
/**	\brief	Constructor with 2 Operands of the class instruction */
	Instruction(t_Operator, Operand *, Operand *);
/**	\brief	Constructor with 1 Operand of the class instruction */
	Instruction(t_Operator, Operand *);
/**	\brief	Constructor without Operands of the class instruction */
	Instruction(t_Operator);

/**	\brief	Destructor of the class instruction
*/
	virtual ~Instruction();

/**	\brief	Get the first operand value
	accessor of the operand
*/
	Operand* get_op1();

/**	\brief	set the first operand value
	setter of the operand
*/
	void set_op1(Operand * o);

/**	\brief	Get the second operand value
	accessor of the operand
*/
	Operand* get_op2();

/**	\brief	set the second operand value
	setter of the operand
*/
	void set_op2(Operand * o);

/**	\brief	Get the third operand value
	accessor of the operand
*/
	Operand* get_op3();

/**	\brief	set the third operand value
	setter of the operand
*/
	void set_op3(Operand * o);

/**	\brief	get the Opcode value
	accessor of the opcode
*/
	t_Operator get_opcode();

/**	\brief	get the string Opcode value
	accessor of the string opcode
*/
	string string_opcode();


/**	\brief	set the opcode value
	setter of the opcode
*/
	void set_opcode(t_Operator newop);

/**	\brief	get the format of the Instruction
	accessor of the format
*/
	t_Format get_format();

/**	\brief	get the Type of the Instruction
	accessor of the Type
*/
	virtual t_Inst  get_type();


	/**	\brief	get the type of the line
*/
	virtual t_Line type_line();

	/**	\brief	get the name string instruction
*/
	virtual string to_string();

	/**	\brief	get the string  of the instruction
*/
	virtual string get_content();

	/**	\brief	set the string of the instruction
*/
	virtual void set_content(string);

/**	\brief	set the string format
*/
	string string_form();

/**	\brief	set the string Type of instruction
*/
	string string_type();

/**	\brief	get the dependance between the current instruction and i2
	\return return "RAW", "WAR", "WAW" or "not dependant" in format enum
*/
	t_Dep is_dependant(Instruction i2);

/**	\brief	get the information if there is dependance RAW between the current instruction and i2	
	\return return true if there is a RAW dependance
*/
	bool is_dep_RAW(Instruction i2);

/**	\brief	get the information if there is dependance WAR between the current instruction and i2	
	\return return true if there is a WAR dependance
*/
	bool is_dep_WAR(Instruction i2);

/**	\brief	get the information if there is dependance WAW between the current instruction and i2	
	\return return true if there is a WAW dependance
*/
	bool is_dep_WAW(Instruction i2);

/**	\brief	get the number of operand	
	\return return the number of operand
*/
	int get_number_oper();


/**	\brief	set the number of operand*/
	void set_number_oper(int);

	/**	\brief	get the regiter destination of the instruction
*/
	Operand * get_reg_dst();

	/**	\brief	get the first register source of the instruction
*/
	Operand * get_reg_src1();
	
	/**	\brief	get the second register source of the instruction
*/
	Operand * get_reg_src2();

/**	\brief	get the successor of the Instruction
*/
	void set_successor(Instruction*);

/**	\brief	get the successor of the Instruction
*/
	Instruction *get_successor( int);

/**	\brief	setter of the predecessor of the Instruction
*/
	void set_predecessor(Instruction *);

/**	\brief	get the predecessor of the Instruction
*/
	Instruction *get_predecessor(int );


/**	\brief	get the number of successor of the Instruction
*/
	int get_nbr_succ();

/**	\brief	get the number of predecessor of the Instruction
*/
	int get_nbr_pred();

/**	\brief	get the index of instruction
*/
	int get_index();

/**	\brief	set the index of instruction
*/
	void set_index(int);

};




#endif
