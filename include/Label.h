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
	\brief	Virtual class representing an Label
*/

class Label : Line{


public	:
	 
		/**	\brief	get the type of the line
*/
	virtual t_Line typeLine();

	/**	\brief	get the string Label
*/	
	virtual string toString();

	/**	\brief	get the string  of the Label
*/	

	virtual string getContent();

	/**	\brief	set the string of the Label
*/	

	virtual void setContent(string);



};

#endif
