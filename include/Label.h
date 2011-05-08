#ifndef _Label_H
#define _Label_H
/**	\file	Label.h
	\brief	Label class
	\author	Hajjem
*/

#include <iostream>
#include <string>
#include "Enum_type.h"
#include "Line.h"
using namespace std;

/**	\class	Label
	\brief	class representing an Label herited by Line
*/

class Label : public Line{


public	:

		/**	\brief	Constructor of the Label
*/
	Label(string);

		/**	\brief	Destructor of the Label
*/
	virtual ~Label();

		/**	\brief	get the type of the line
*/
	virtual t_Line typeLine();

	/**	\brief	get the string of Label
*/	
	virtual string toString();

	/**	\brief	get the string  of the Label
*/	
	virtual string getContent();

	/**	\brief	set the string of the Label
*/	
	virtual void setContent(string);

	/**	\brief	return true if the directive indicate a function
*/
	virtual bool isFunction();

	/**	\brief	return the type of the instruction
*/
	virtual t_Inst  getType();




};

#endif
