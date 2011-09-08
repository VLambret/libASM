#include <Label.h>

Label::Label( string lab){
	_line= lab;
}

Label::~Label(){
}

string Label::to_string(){
	return _line;

}


t_Line Label::type_line(){
	return line_Lab;
}

string Label::get_content(){

	return _line + ":";

}

void Label::set_content(string line){
	_line =line;
}


t_Inst  Label::get_type(){
	return OTHER;
}
