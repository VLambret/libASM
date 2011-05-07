#include <Basic_block.h>

Basic_block::Basic_block(){
	_head = NULL;
	_end = NULL;
}

void Basic_block::set_head(Node *head){
	_head = head;
}

void Basic_block::set_end(Node *end){
	_end = end;
}

Node* Basic_block::get_head(){
	return _head;
}

Node* Basic_block::get_end(){
	return _end;
}

Basic_block::~Basic_block(){}

void Basic_block::display(){

	Node* element = _head;
	while(element != _end)
	{
		cout << element->getLine()-> getContent() <<endl;
		
		if(element->getnext()==_end){
			cout << element->getnext()->getLine()-> getContent() <<endl;
			break;
		}
		else element = element->getnext();

	}
}

int Basic_block::size(){

	Node* element = _head;
	int lenght=0;
	while(element != _end)
	{
		lenght++;
		
		if(element->getnext()==_end)	break;
		else element = element->getnext();

	}
	return lenght;
}	

string Basic_block::toString(){
	return "ok";
}

void Basic_block::restitution(string const filename){
	
	Node* element = _head;
	ofstream monflux(filename.c_str());

	if(monflux){
		while(element != _end)
		{
			if(element->getLine()->typeLine()==line_Instru || element->getLine()->typeLine()== line_Direct) monflux<<"\t";
			monflux << element->getLine()-> getContent() <<endl;
		
			if(element->getnext()==_end)	break;
			else {
				if(element->getLine()->typeLine()!= element->getnext()->getLine()->typeLine()) monflux<<endl;
				element = element->getnext();
			}			
		}
		cout << endl;
	}

	else {
		cout<<"Error cannot open the file"<<endl;
	}

	monflux.close();

}

bool Basic_block::isLabelised(){
	if (_head->getLine()->typeLine()==line_Lab){
		return true;
	}
	else return false;
}
