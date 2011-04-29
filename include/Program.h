#ifndef _Program_H
#define _Program_H

/**	\file	Program.h
	\brief	Program class
	\author	Hajjem
*/


#include <Node.h>
#include <Instruction.h>
#include <string>
#include <stdio.h>
#include <Enum_type.h>
#include <fstream>
using namespace std;

/**	\class	Program
	\brief	class representing a program as list
*/

class Program{

public:

/**	\brief	Empty constructor of program
*/
	Program();

/**	\brief	Copy constructor of program
*/
	Program(Program const&  otherprogram);

/**	\brief	Constructor with input file of program
*/
	Program (FILE * sourceasm);

/**	\brief	Destructor of program
*/
	~Program();

/**	\brief	Add a line at the end of the program
*/
	void addLine(Line * newline);

/**	\brief	Add a line to the program
*/
	int add_position(Line *newline, int position);

/** \brief display the program
*/
	void display();


/**	\brief	Delete a line to the program
*/
	void delLine(int index);

/**	\brief	gives the line that corresponds to the index
*/
	Line * findLine(int index);

/**	\brief	get the length of the program
*/
	int size();

/**	\brief	get the dependance betwen two instructions
*/
	string dependance(Instruction i1, Instruction i2);


/**	\brief	write the programme in file
*/
	void inFile(string const filename);

private:
	int _length;
	Node * _head;
	

};



#endif
