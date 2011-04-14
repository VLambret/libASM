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
	\brief	class representing a Node 
*/

class Node{

public:
	Node(Line * content);
	~Node();
	Node * getnext();
	void setNext(Node * newsuccessor);
	Line * getLine();
	void setLine(Line * newline);

private:
	Node * _next;
	Line * _content;
	
};

#endif
