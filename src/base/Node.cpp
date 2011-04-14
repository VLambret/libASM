#include "Node.h"

Node::Node(Line * content){
	_content= content;
	_next=NULL;
}

Node::~Node(){
	if(_next)	delete _next;	
}

Node* Node::getnext()
{
	return _next;
}

void Node::setNext(Node * newsuccessor){
	_next=newsuccessor;
}
	
	
Line * Node::getLine(){
	return _content;
}
	
void Node::setLine(Line * newline){
	_content=newline;
}
