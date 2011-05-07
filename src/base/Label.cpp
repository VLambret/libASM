#include "Label.h"

Label::Label( string lab){
	_line= lab;
}

Label::~Label(){
}

string Label::toString(){
	return _line;

}


t_Line Label::typeLine(){
	return line_Lab;
}

string Label::getContent(){

	return _line;

}

void Label::setContent(string line){
	_line =line;
}

bool Label::isFunction(){
	return false;
}

t_Inst  Label::getType(){
	return OTHER;
}
