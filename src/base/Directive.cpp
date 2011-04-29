#include "Directive.h"

Directive::Directive( string direct)
{
	_line= direct;
}

Directive::~Directive(){}


string Directive::toString(){
	return "Directive";

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
