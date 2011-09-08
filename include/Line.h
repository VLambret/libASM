#ifndef _Line_H
#define _Line_H
/**	\file	Line.h
	\brief	Line class
	\author	Hajjem
*/

#include <iostream>
#include <string>
#include <Enum_type.h>
using namespace std;

/**	\class	Line
	\brief	Abstract class representing an Line
*/

class Line{


public	:
	
	/**	\brief	Virtual destructor
*/
	virtual ~Line(){}; 

	/**	\brief	get the string  of the line
		virtual getter
*/
	virtual string get_content()=0;

	/**	\brief	set the string of the line
		virtual setter
*/
	virtual void set_content(string)=0;

	/**	\brief	get the type of the line
		virtual accessor of the type
*/
	virtual t_Line type_line()=0;

/**	\brief	get the name string 
		accessor of the type line
		
*/
	virtual string to_string()=0;


	/**	\brief	return the type of the instruction
*/
	virtual t_Inst  get_type()=0;


protected:

	string _line;
};

#endif	
