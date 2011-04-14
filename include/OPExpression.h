#ifndef _OPExpression_H
#define _OPExpression_H

/**	\file	OPExpression.h
	\brief	OPExpression class
	\author	Hajjem
*/
#include <iostream>
#include <string>
#include "Operand.h"
#include "Enum_type.h"
using namespace std;

/**	\class	OPExpression
	\brief	class representing an expression
*/

class OPExpression: public Operand{

public	:

/**	\brief	Constructor of the Expression class
*/
	OPExpression(string);

/**	\brief	Destructor of the Expression class
*/
	~OPExpression();

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


};

#endif

