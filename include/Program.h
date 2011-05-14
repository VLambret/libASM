#ifndef _Program_H
#define _Program_H

/**	\file	Program.h
	\brief	Program class
	\author	Hajjem
*/


#include <Node.h>
#include <Function.h>
#include <Basic_block.h>
#include <Instruction.h>
#include <string>
#include <stdio.h>
#include <Enum_type.h>
#include <fstream>
#include <list>
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

/**	\brief	Add a line to the program with position as index
*/
	int add_Line_at(Line *newline, int position);

/** \brief display the program
*/
	void display();


/**	\brief	Delete a line in the program
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
	//t_Dep dependance(Instruction i1, Instruction i2);


/**	\brief	write the programme in file
*/
	void inFile(string const filename);

/**	\brief	return true if the program is Empty
*/
	bool isEmpty();

/**	\brief	calculate functions
*/
	void  comput_Function();

/**	\brief	get the number of functions in the program
*/
	int nbr_Func();

/**	\brief	get one fonction of the list myfunc
*/
	Function  get_Function(int );



private:
	int _length;
	Node * _head;
	list <Function> myfunc;
	

};



#endif
