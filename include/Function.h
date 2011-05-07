#ifndef _Function_H
#define _Function_H

/**	\file	Function.h
	\brief	Function class
	\author	Hajjem
*/


#include <Node.h>
#include <Basic_block.h>
#include <Instruction.h>
#include <string>
#include <stdio.h>
#include <Enum_type.h>
#include <list>
#include <fstream>
using namespace std;

/**	\class	Function
	\brief	class representing a Function on a program
*/

class Function{

public:
	Function();
	~Function();
	void set_head(Node *);
	void set_end(Node *);
	Node* get_head();
	Node* get_end();
	void display();
	int size();	
	string toString();
	void restitution(string const);
	void calculate_basic_block();
	int nbr_BB();
	Basic_block get_BB(int);

private:

	Node *_head;
	Node *_end;
	list <Basic_block> myBB;
	int _nbr_BB;
};

#endif
