#ifndef _Dfg_H
#define _Dfg_H

/**	\file	Dfg.h
	\brief	Dfg class
	\author	Hajjem
*/


#include <Basic_block.h>
#include <Node_dfg.h>
#include <Instruction.h>
#include <string>
#include <stdio.h>
#include <Enum_type.h>
#include <fstream>
#include <list>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/astar_search.hpp>

class Basic_block;
class Node_dfg;

/**	\class	Dfg
	\brief	class representing a Dfg of a Basic block, a data flow graph
	which will be used to calculate the critical path and schedule code
*/


class Dfg{

public:

	/**	\brief	Constructor of Dfg
*/
	Dfg(int);

	/**	\brief	Destructor of Dfg
*/
	~Dfg();

	/**	\brief	Build the Dfg, 
		when you call this method you have to affect the fisrt parameter to NULL and the 
		second to true
*/
	void build_dfg(Node_dfg*,bool);

	/**	\brief	Display the Dfg, 
		when you call this method you have to affect the fisrt parameter to NULL and the 
		second to true
*/
	void display(Node_dfg * ,bool);

	/**	\brief	restitute the Dfg, 
		when you call this method you have to affect the fisrt parameter to NULL and the 
		third to true
*/
	void restitute(Node_dfg * ,string const, bool );

	/**	\brief	test if all node have been read
*/
	bool read_test();

	/**	\brief	comput the critical path of the Dfg, 
		when you call this method you have to affect the fisrt parameter to NULL and the 
		second to true
*/
	void comput_critical_path(Node_dfg * , bool );


	/**	\brief	order the instructions in the basic block according to an algorithm list
*/
	void scheduling();

/**	\brief	get the instructions without freezing cycle
*/
	list <Node_dfg*> no_freezing_cycle(list <Node_dfg*> );

/**	\brief	get the instructions with the biggest weight
*/
	list <Node_dfg*> greater_weight(list <Node_dfg*>);

/**	\brief	get the instructions with the biggest number of successor
*/
	list <Node_dfg*> more_sucessor(list <Node_dfg*>);

/**	\brief	get the instructions with the biggest number of descedant
*/
	list <Node_dfg*> more_descendant(list <Node_dfg*>);

/**	\brief	get the instructions with the biggest latency
*/
	list <Node_dfg*> longer_latency(list <Node_dfg*> );

/**	\brief	get the first instruction in the original order
*/
	list <Node_dfg*> original_order(list <Node_dfg*> );

/**	\brief	modify the Basic block with the new scheduling
*/
	void scheduling_BB(Basic_block *);


private:
	list <Node_dfg*> _head;
	list <Node_dfg*> _inst_ready;
	list <Node_dfg*> new_order;
	list <Node_dfg*> list_node_dfg;
	int _nbr_arc;
	int _arc_lu;
	int _length;
	int *_read;
	
};

#endif

