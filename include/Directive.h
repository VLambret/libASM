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
	\brief	class representing an Directive herited by Line
*/

class Directive : public Line{


public	:

		/**	\brief	Constructor of the Directive
*/	
	Directive(string);

		/**	\brief	Destructor of the Directive
*/
	virtual ~Directive();

	 
		/**	\brief	get the type of the line
*/
	virtual t_Line typeLine();

	/**	\brief	get the string name of the Directive
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
