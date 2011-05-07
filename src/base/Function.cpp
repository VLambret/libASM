#include <Function.h>

Function::Function(){
	_head = NULL;
	_end = NULL;
	_nbr_BB=0;
}

Function::~Function(){}

void Function::set_head(Node *head){
	_head = head;
}

void Function::set_end(Node *end){
	_end = end;
}

Node* Function::get_head(){
	return _head;
}

Node* Function::get_end(){
	return _end;
}
void Function::display(){
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

int Function::size(){
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

string Function::toString(){
	return "ok";
}

void Function::restitution(string const filename){
	
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

void Function::calculate_basic_block(){
	Basic_block BB;	

		Node* element = _head;
		BB.set_head(_head);
		cout<<BB.get_head()->getLine()->getContent()<<endl;
		while(element != NULL)
		{
			if(element->getLine()->typeLine()==line_Instru){
				if(element->getLine()->getType()==BR){
					BB.set_end(element->getnext());
					cout<<BB.get_end()->getLine()->getContent()<<endl;
					myBB.push_back(BB);
					_nbr_BB++;
					if(element->getnext()->getnext()!=NULL){
						BB.set_head(element->getnext()->getnext());
						cout<<BB.get_head()->getLine()->getContent()<<endl;
					}
					else	break;
				}
			}
			if(element->getLine()->typeLine()==line_Lab){
				BB.set_end(element->getnext());
					cout<<BB.get_end()->getLine()->getContent()<<endl;
					myBB.push_back(BB);
					_nbr_BB++;
					if(element->getnext()->getnext()!=NULL){
						BB.set_head(element->getnext()->getnext());
						cout<<BB.get_head()->getLine()->getContent()<<endl;
					}
					else	break;

			}
			if(element->getnext()==NULL){
				BB.set_end(element);
				cout<<BB.get_end()->getLine()->getContent()<<endl;
				myBB.push_back(BB);
				_nbr_BB++;
				break;
			}
			else element = element->getnext();

		}		
}

int Function::nbr_BB(){
	return _nbr_BB;
}

Basic_block Function::get_BB(int index){

	list<Basic_block>::iterator it;
	it=myBB.begin();

  	if(index<= _nbr_BB){
  		for (int i=0; i<index;i++ ) it++;
		return *it;	
	}
	
	return myBB.back();
}

