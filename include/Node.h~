#ifndef _Node_H
#define _Node_H

/**	\file	Node.h
	\brief	Node class
	\author	Hajjem
*/


#include "Line.h"
#include <string>
#include "Enum_type.h"
using namespace std;

/**	\class	Node
	\brief	class representing a Node in list
*/

class Node{

public:

/**	\brief	Node constructor
*/
	Node(Line * content);

/**	\brief	Node destructor
*/
	~Node();

/**	\brief	get the next node
*/
	Node * getnext();

/**	\brief	set the next node
*/
	void setNext(Node * newsuccessor);

/**	\brief	get the currently line
*/
	Line * getLine();

/**	\brief	set the currently line
*/
	void setLine(Line * newline);

private:
	Node * _next;
	Line * _content;
	
};

#endif
