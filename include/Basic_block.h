#ifndef _Basic_block_H
#define _Basic_block_H

/**	\file	Basic_block.h
	\brief	Basic_block class
	\author	Hajjem
*/


#include <Node.h>
#include <Instruction.h>
#include <string>
#include <stdio.h>
#include <Enum_type.h>
#include <fstream>

using namespace std;

/**	\class	Basic_block
	\brief	class representing a Basic_block of a fonction
*/

class Basic_block{

public:
	Basic_block();
	~Basic_block();
	void set_head(Node *);
	void set_end(Node *);
	Node* get_head();
	Node* get_end();
	void display();
	int size();	
	string toString();
	void restitution(string const);
	bool isLabelised();

private:

	Node *_head;
	Node *_end;
};

#endif
