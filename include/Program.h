#ifndef _Program_H
#define _Program_H

/**	\file	Program.h
	\brief	Program class
	\author	Hajjem
*/


#include "Node.h"
#include <string>
#include <stdio.h>
#include "Enum_type.h"
using namespace std;

/**	\class	Program
	\brief	class representing a program 
*/

class Program{

public:
	Program();
	Program(Program * otherprogram);
	Program (FILE * sourceasm);
	~Program();
	void addLine(Line * newline);
	void delLine(int index);
	Line * findLine(int index);
	int size();

private:
	int _length;
	Node * _head;

};



#endif
