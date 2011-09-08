#ifndef _Node_H
#define _Node_H

/**	\file	Node.h
	\brief	Node class
	\author	Hajjem
*/


#include <Line.h>
#include <string>
#include <Enum_type.h>
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
	Node * get_next();

/**	\brief	set the next node
*/
	void set_next(Node * newsuccessor);

/**	\brief	get the currently line
*/
	Line * get_line();

/**	\brief	set the currently line
*/
	void set_line(Line * newline);

private:
	Node * _next;
	Line * _content;
	
};

#endif
