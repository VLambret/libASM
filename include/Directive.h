#ifndef _Directive_H
#define _Directive_H
/**	\file	Directive.h
	\brief	Directive class
	\author	Hajjem
*/

#include <iostream>
#include <string>
#include "Enum_type.h"
#include "Line.h"
using namespace std;

/**	\class	Directive
	\brief	Virtual class representing an Directive
*/

class Directive : Line{


public	:
	 
		/**	\brief	get the type of the line
*/
	virtual t_Line typeLine();

	/**	\brief	get the string Directive
*/	
	virtual string toString();

	/**	\brief	get the string  of the Directive
*/	

	virtual string getContent();

	/**	\brief	set the string of the Directive
*/	

	virtual void setContent(string);



};

#endif
