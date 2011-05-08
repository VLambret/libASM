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
/**	\brief	Constructor of a Basic Block
*/
	Basic_block();

/**	\brief	Destructor of a basic block
*/
	~Basic_block();

/**	\brief	setter of the head of the basic block
*/
	void set_head(Node *);

/**	\brief	setter of the end of the basic block
*/
	void set_end(Node *);

/**	\brief	get the head of the basic block
*/
	Node* get_head();

/**	\brief	get the end of the basic block
*/
	Node* get_end();

/**	\brief	display the basic block
*/
	void display();

/**	\brief	get the size of the basic block
*/
	int size();	

/**	\brief	restitute the basic block in a file
*/
	void restitution(string const);	

/**	\brief	Return true if the first line of the block is a label
*/
	bool isLabelised();

private:

	Node *_head;
	Node *_end;
};

#endif
