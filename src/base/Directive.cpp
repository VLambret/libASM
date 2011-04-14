#include "Directive.h"

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
