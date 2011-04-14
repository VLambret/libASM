#include "Program.h"

Program::Program(){
	_head= NULL;
	_length=0;
}

Program::Program(Program * otherprogram){
	cout<<"constructeur de copie"<<endl;
}

Program::Program (FILE * sourceasm){
	cout<<"on donne au constructeur un fichier à parser"<<endl;
}

Program::~Program(){

}

void Program::addLine(Line * newline){
	cout<<"ajout d'une nouvelle ligne"<<endl;
}

void Program::delLine(int index){
	cout<<"suppression d'une ligne"<<endl;
}

Line* Program::findLine(int index){
	cout<<"recherche d'une ligne"<<endl;	
}

int Program::size(){
	return _length;
}


