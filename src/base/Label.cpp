#include "Label.h"

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
