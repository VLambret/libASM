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
#include <list>
#include <Dfg.h>



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

/**	\brief	setter of Node corresponding to the branch
*/
	void set_branch(Node *);

/**	\brief	get the Node corresponding to the branch
*/
	Node* get_branch();


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
	bool is_labeled();

/**	\brief	setter of the successor of the basic block
*/
	void set_successor1(Basic_block *BB);

/**	\brief	get the successor of the basic block
*/
	Basic_block *get_successor1();

/**	\brief	setter of the successor of the basic block
*/
	void set_successor2(Basic_block *BB);

/**	\brief	get the successor of the basic block
*/
	Basic_block *get_successor2();

/**	\brief	setter of the predecessor of the basic block
*/
	void set_predecessor(Basic_block *BB);

/**	\brief	get the predecessor of the basic block
*/
	Basic_block *get_predecessor(int );


/**	\brief	get the number of successor of the basic block
*/
	int get_nbr_succ();

/**	\brief	get the number of predecessor of the basic block
*/
	int get_nbr_pred();

/**	\brief	set the index of the basic block
*/
	void set_index(int i);

/**	\brief	get the index of the basic block
*/
	int get_index();

/**	\brief	comput predecessors and successors of each instructions in the BB
*/
	void comput_pred_succ();

/**	\brief	set index of instruction
*/
	void set_index_instruction();

/**	\brief	method to test other methods
*/
	void test();

private:

	Node *_head;
	Node *_end;
	Node *_branch;
	int _index;
	int _nbr_succ;
	int _nbr_pred;
	int _nbr_instru;
	list <Basic_block *> _successor;
	list <Basic_block *> _predecessor;
};

#endif
