#include <Node.h>

Node::Node(Line * content){
	_content= content;
	_next=NULL;
}

Node::~Node(){
}

Node* Node::get_next()
{
	return _next;
}

void Node::set_next(Node * newsuccessor){
	_next=newsuccessor;
}
	
	
Line * Node::get_line(){
	return _content;
}
	
void Node::set_line(Line * newline){
	_content=newline;
}
