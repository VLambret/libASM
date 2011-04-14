#ifndef _Line_H
#define _Line_H
/**	\file	Line.h
	\brief	Line class
	\author	Hajjem
*/

#include <iostream>
#include <string>
#include "Enum_type.h"
using namespace std;

/**	\class	Line
	\brief	Virtual class representing an Line
*/

class Line{


public	:
	 
	virtual string getContent()=0;
	virtual void setContent(string)=0;
	virtual t_Line typeLine()=0;
	virtual string toString()=0;

protected:

	string _line;
};

#endif	
