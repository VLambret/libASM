#include "Label.h"

Label::Label( string lab){
	_line= lab;
}

Label::~Label(){
}

string Label::toString(){
	return "Label";

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
