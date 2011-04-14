#ifndef _OPImmediate_H
#define _OPImmediate_H

/**	\file	OPImmediate.h
	\brief	OPImmediate class
	\author	Hajjem
*/

#include <iostream>
#include <string>
#include "Operand.h"
#include "Enum_type.h"
using namespace std;


/**	\class	OPImmediate
	\brief	class representing an Immediate
*/
class OPImmediate: public Operand{

public	:

/**	\brief	Constructor of the Immediate Class
*/
	OPImmediate(string);

/**	\brief	Destructor of the Immediate Class
*/
	~OPImmediate();

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

