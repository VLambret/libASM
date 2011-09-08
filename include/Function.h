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
#include <Label.h>
#include <Enum_type.h>
#include <list>
#include <Cfg.h>
#include <fstream>
using namespace std;

/**	\class	Function
	\brief	class representing a Function on a program
*/

class Function{

public:
/**	\brief	Constructor of a function
*/
	Function();

/**	\brief	Destructor of a function
*/
	~Function();

/**	\brief	setter of the head of the function
*/
	void set_head(Node *);

/**	\brief	setter of the end of the function
*/
	void set_end(Node *);

/**	\brief	get the head of the function
*/
	Node* get_head();

/**	\brief	get the end of the function
*/
	Node* get_end();

/**	\brief	display the function
*/
	void display();

/**	\brief	get the size of the function
*/
	int size();	

/**	\brief	restitute the function in a file
*/
	void restitution(string const);

/**	\brief	Calculate the basics bolck of the function
*/
	void comput_basic_block();

/**	\brief	get the number of Basic block in the function
*/
	int nbr_BB();

/**	\brief	get the Basic Block in the list
*/
	Basic_block *get_BB(int);

/**	\brief	comput labels of the function in list
*/
	void comput_label();

/**	\brief	get all labels of the function
*/
	Label* get_label(int);

/**	\brief	get the size of the list label
*/
	int nbr_label();

/**	\brief	Get the basic block corresponding to the label
*/
	Basic_block *find_label_BB(OPLabel*);

/**	\brief	Associate for each Basic block its successors
*/
	void comput_succ_pred_BB();

/**	\brief	method to test other methods
*/
	void test();

private:

	Node *_head;
	Node *_end;
	list <Basic_block*> _myBB;
	list <Label*> _list_lab;
};

#endif
