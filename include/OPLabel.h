#ifndef _OPLabel_H
#define _OPLabel_H
/**	\file	OPLabel.h
	\brief	OPLabel class
	\author	Hajjem
*/

#include <iostream>
#include "Operand.h"
#include "Enum_type.h"
#include <string>
using namespace std;

/**	\class	OPLabel
	\brief	class representing a Label herited by Operand
*/

class OPLabel: public Operand{

public	:

/**	\brief	Constructor of the Label Class
*/
	OPLabel(string);

/**	\brief	Destructor of the Label Class
*/
	virtual ~OPLabel();

/**	\brief	Get the string of the operand
	accessor of the operand
*/
	virtual string getOp();

/**	\brief	get the operator type
	\return	return the Operand type as enum	
*/
	virtual t_OpType getOptype();


/**	\brief	tostring
	\return	return the name of the Object as string
*/
	virtual string toString();

/**	\brief	set the operand value
	setter of the operand
*/
	virtual void setOp( string);

/**	\brief	get the Dst/Src type of the Operand
	getter of the type
*/
	 virtual t_Src_Dst getType( );



};

#endif

