#include <Basic_block.h>

Basic_block::Basic_block(){
	_head = NULL;
	_end = NULL;
	_branch = NULL;
	_index = 0;
	_nbr_succ=0;
}


Basic_block::~Basic_block(){}

void Basic_block::set_index(int i){
	_index = i;
}

int Basic_block::get_index(){
	return _index;
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

void Basic_block::set_successor1(Basic_block *BB){
	_nbr_succ++;
	_successor.push_front(BB);
}

Basic_block *Basic_block::get_successor1(){
	return _successor.front();
}

void Basic_block::set_successor2(Basic_block *BB){
	_nbr_succ++;
	_successor.push_back(BB);
}

Basic_block *Basic_block::get_successor2(){
	return _successor.back();
}

int Basic_block::get_nbr_succ(){
	return _nbr_succ;
}

void Basic_block::set_Branch(Node * br){
	_branch=br;
}

Node* Basic_block::get_Branch(){
	return _branch;
}

void Basic_block::display(){

	cout<<"Begin"<<endl;
	Node* element = _head;
	
	if(element == _end)	cout << _head->getLine()-> getContent() <<endl;
	while(element != _end)
	{
		if(element->getLine()->typeLine()!=line_Direct)
			cout << element->getLine()-> getContent() <<endl;
		
		if(element->getnext()==_end){
			if(element->getLine()->typeLine()!=line_Direct)
				cout << element->getnext()->getLine()-> getContent() <<endl;
			break;
		}
		else element = element->getnext();

	}

	cout<<"End\n\n"<<endl;
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


void Basic_block::restitution(string const filename){
	
	Node* element = _head;
	ofstream monflux(filename.c_str(), ios::app);

	if(monflux){
		monflux<<"Begin"<<endl;
		if(element == _end)	monflux << _head->getLine()-> getContent() <<endl;
		while(element != _end)
		{
			if(element->getLine()->typeLine()==line_Instru ) monflux<<"\t";
				if(element->getLine()->typeLine()!=line_Direct)
					monflux << element->getLine()-> getContent()<<endl ;
		
			if(element->getnext()==_end){
				if(element->getnext()->getLine()->typeLine()==line_Instru ) monflux<<"\t";
					if(element->getLine()->typeLine()!=line_Direct)
						monflux << element->getnext()->getLine()-> getContent()<<endl;
				break;
			}
			else element = element->getnext();

		}
		monflux<<"End\n\n"<<endl;
		
	}

	else {
		cout<<"Error cannot open the file"<<endl;
	}

	monflux.close();

}

bool Basic_block::isLabeled(){
	if (_head->getLine()->typeLine()==line_Lab){
		return true;
	}
	else return false;
}
