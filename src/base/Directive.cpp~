#include "Directive.h"

Directive::Directive( string direct)
{
	_dir= direct;
	_value = "" ;
	_isfunction = false ;
}

Directive::Directive(string direct, string value)
{
	_dir= direct ;
	_value= value ;
	_isfunction= false ;

}

Directive::Directive(string direct, string value, bool isfunction)
{
	_dir= direct ;
	_value= value ;
	_isfunction= isfunction ;

}

Directive::~Directive(){}


string Directive::toString(){
	return _line;

}


t_Line Directive::typeLine(){
	return line_Direct;
}

string Directive::getContent(){
	return _dir + "	" + _value ;
}

void Directive::setContent(string line){
	_line =line;
}


bool Directive::isFunction(){
	return _isfunction ;
}

t_Inst  Directive::getType(){
	return OTHER;
}
