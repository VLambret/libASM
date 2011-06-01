#include <Function.h>

Function::Function(){
	_head = NULL;
	_end = NULL;
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
	cout<<"Begin"<<endl;
	Node* element = _head;

	if(element == _end)	cout << _head->getLine()-> getContent() <<endl;
	while(element != _end)
	{
		cout << element->getLine()-> getContent() <<endl;
		
		if(element->getnext()==_end){
			cout << element->getnext()->getLine()-> getContent() <<endl;
			break;
		}
		else element = element->getnext();

	}
	cout<<"End\n\n"<<endl;
	
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


void Function::restitution(string const filename){
	
	Node* element = _head;
	ofstream monflux(filename.c_str(), ios::app);

	if(monflux){
		monflux<<"Begin"<<endl;
		if(element == _end)	monflux << _head->getLine()-> getContent() <<endl;
		while(element != _end)
		{
			if(element->getLine()->typeLine()==line_Instru || element->getLine()->typeLine()== line_Direct) monflux<<"\t";
			monflux << element->getLine()-> getContent() ;
			if(element->getLine()->getContent().compare("nop")) monflux<<endl;
		
			if(element->getnext()==_end){
				if(element->getnext()->getLine()->typeLine()==line_Instru || 
							element->getnext()->getLine()->typeLine()==line_Direct) monflux<<"\t";
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

void Function::comput_basic_block(){
	Basic_block BB;	
	int begin=0;

		Node* element = _head;

		cout<<"entré"<<endl;
		/*supprime les directives precedent le premier BB*/
		while(!begin){
			if(element->getLine()->typeLine()!=line_Direct){
				cout<<"tête1 "<<element->getLine()->getContent() <<endl;
				BB.set_head(element);
				begin=1;
			}	
			else	element= element->getnext();

		}
		while(element != _end)
		{ 		/*si l'instruction est un branchement alors on prend le delay sot comme
				dernier element du BB et comme tete l'element qui suit*/
			if(element->getLine()->typeLine()==line_Instru && element->getnext()->getLine()->typeLine()==line_Instru){
				if(element->getLine()->getType()==BR){
					cout<<"fin1 "<<element->getnext()->getLine()->getContent() <<endl;
					BB.set_end(element->getnext());
					myBB.push_back(BB);
					if(element->getnext()->getnext()!=_end && element->getnext()!=_end){
						cout<<"tête2 "<<element->getnext()->getnext()->getLine()->getContent() <<endl;
						BB.set_head(element->getnext()->getnext());
						element = element->getnext();
					}
					else	break;
				}
			}
			/*si l'instruction suivante est un label alors on prend l'instruction courante comme fin
			du BB et on prens le suivant comme tete du prochain BB*/
			else if(element->getnext()->getLine()->typeLine()==line_Lab){
				cout<<"fin3 "<<element->getLine()->getContent() <<endl;
				BB.set_end(element);
					myBB.push_back(BB);
					cout<<"tête3 "<<element->getnext()->getLine()->getContent() <<endl;
					BB.set_head(element->getnext());

			}
			/*if(element->getnext()->getLine()->typeLine()==line_Direct){
				cout<<"fin "<<element->getLine()->getContent() <<endl;
				BB.set_end(element);
				break;
			}*/
			if(element->getnext()==_end){
				BB.set_end(element);
				cout<<"fin4"<<element->getLine()->getContent() <<endl;
				myBB.push_back(BB);
				break;
			}
			else element = element->getnext();

		}		
}

int Function::nbr_BB(){
	return myBB.size();
}

Basic_block Function::get_BB(int index){

	list<Basic_block>::iterator it;
	it=myBB.begin();

  	if(index< myBB.size()){
  		for (int i=0; i<index;i++ ) it++;
		return *it;	
	}
	else cout<<"Error: index is bigger than the size of the list"<<endl; 
	
	return myBB.back();
}

