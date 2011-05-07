#include "Directive.h"

Directive::Directive( string direct)
{
	_line= direct;
}

Directive::~Directive(){}


string Directive::toString(){
	return _line;

}


t_Line Directive::typeLine(){
	return line_Direct;
}

string Directive::getContent(){

	return _line;

}

void Directive::setContent(string line){
	_line =line;
}


bool Directive::isFunction(){
	if(!_line.compare(".ent")){
		return true;
	}
	else return false;

}

t_Inst  Directive::getType(){
	return OTHER;
}
