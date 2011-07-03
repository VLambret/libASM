#ifndef _Node_cfg_H
#define _Node_cfg_H

/**	\file	Node_cfg.h
	\brief	Node_cfg class
	\author	Hajjem
*/



#include <Basic_block.h>
#include <string>
#include <stdio.h>
#include <Label.h>
#include <Enum_type.h>

using namespace std;

/**	\class	Node_cfg
	\brief	class representing a node in control flot graph
*/

class Node_cfg{

public:

/**	\brief	Constructor of Node_cfg
*/
	Node_cfg(Basic_block* );

/**	\brief	Destructor of Node_cfg
*/
	~Node_cfg();

/**	\brief	get the first successor
*/
	Node_cfg *get_succ1();

/**	\brief	get the second successor
*/
	Node_cfg *get_succ2();

/**	\brief	get the number of successor 
*/
	int get_nbr_succ();

/**	\brief	get the Basic Block
*/
	Basic_block *get_BB();

/**	\brief	set the first successor
*/
	void set_succ1(Node_cfg*);

/**	\brief	set the second successor
*/
	void set_succ2(Node_cfg*);

/**	\brief	set the Basic block
*/
	void set_BB(Basic_block* );



private:
	Node_cfg *_succ1;
	Node_cfg *_succ2;
	int _nbr_succ;
	Basic_block *_BB;

	
};

#endif
