#ifndef _OPRegister_H
#define _OPRegister_H

/**	\file	OPRegister.h
	\brief	OPRegister class
	\author	Hajjem
*/

#include <iostream>
#include <string>
#include "Operand.h"
#include "Enum_type.h"
using namespace std;

/**	\class	OPRegister
	\brief	class representing a Register
*/

class OPRegister: public Operand{

private :
	int _reg;

public	:

/**	\brief	Constructor of the Register class
*/
	OPRegister(string);
	OPRegister(string, int);

/**	\brief	Get the Register value
	accessor of the Register
*/
	int getReg();

/**	\brief	set the Register value
	setter of the Register
*/
	void setReg( int);

/**	\brief	Get the operand value
	accessor of the operand
*/
	virtual string getOp();

/**	\brief	get the operator type
	\return	return the Operand type as enum	
*/
	virtual t_OpType getOptype();


/**	\brief	tostring
	\return	return the Object as string
*/
	virtual string toString();

/**	\brief	set the operand value
	setter of the operand
*/
	virtual void setOp( string);

/**	\brief	Destructor of the Register class
*/
	~OPRegister();


};

#endif

