#ifndef _Operand_H
#define _Operand_H

/**	\file	Operand.h
	\brief	Operand class
	\author	Hajjem
*/

#include <iostream>
#include <string>
#include "Enum_type.h"
using namespace std;

/**	\class	Operand
	\brief	Virtual class representing an operand
*/

class Operand{


public	:


/**	\brief	Get the operand value
	accessor of the operand
*/
	virtual string getOp()=0;

/**	\brief	set the operand value
	setter of the operand
*/
	virtual void setOp(string)=0;

/**	\brief	get the operator type
	\return	return the Operand type as enum	
*/

	virtual  t_OpType getOptype()=0;


/**	\brief	tostring
	\return	return the Object as string
*/
	virtual string toString()=0;

protected :
	string _oper;
};


#endif	
