#ifndef _Node_dfg_H
#define _Node_dfg_H

/**	\file	Node_dfg.h
	\brief	Node_dfg class
	\author	Hajjem
*/



#include <Basic_block.h>
#include <string>
#include <stdio.h>
#include <Label.h>
#include <Enum_type.h>

class Node_dfg;

using namespace std;

/**	\class	Node_dfg
	\brief	class representing a node of data flow graph
*/

struct Arc {
	int delai;
	t_Dep dep;
	Node_dfg *next;
};

class Node_dfg{

public:

/**	\brief	Constructor of Node_dfg
*/
	Node_dfg(Instruction* );

/**	\brief	Destructor of Node_dfg
*/
	~Node_dfg();

/**	\brief	get the first successor
*/
	Arc *get_succ(int);

/**	\brief	get the number of successor 
*/
	int get_nbr_succ();

/**	\brief	get the Instruction
*/
	Instruction *get_instruction();

/**	\brief	set the first successor
*/
	void set_succ(Arc*);

/**	\brief	set the Instruction
*/
	void set_instruction( Instruction* );


/**	\brief	set the weight
*/
	void set_weight( int );

/**	\brief	get the weight
*/
	int get_weight( );

/**	\brief	set the number of descendant
*/
	void set_descendant(int);

/**	\brief	get the number of descendant
*/
	int get_nb_desc();

/**	\brief	set one descendant
*/
	void set_desc(int);

/**	\brief	get one descendant
*/
	int get_desc(int);


private:
	list <Arc *> _arc;
	list <int> _desc;
	Instruction * _inst;
	int _nbr_descendant;
	int _poids;

	
};



#endif
