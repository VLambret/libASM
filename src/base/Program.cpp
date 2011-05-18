#include <Program.h>
#include <asm_mipsyac.h>

extern	void programparse(string) ; 
extern	Program prog ;

Program::Program(){
	_head= NULL;
	_length=0;
}

Program::Program(Program const&  otherprogram){
	//On initialise la liste.

	_head= NULL;
	_length= 0;

    // On copie la liste.

   	Node * tmp = otherprogram._head;

    	while (tmp != NULL){

       		addLine(tmp->getLine());
       		tmp = tmp->getnext();
	}
}


Program::Program (string const file){
	_head = NULL ;
	_length = 0 ;
	 programparse(file) ;
	std::cout << "ETAPE1" << std::endl ;

	Node * tmp = prog._head;

    	while (tmp != NULL){

       		addLine(tmp->getLine());
       		tmp = tmp->getnext();
	}

}

Program::~Program(){

	delete _head;
	_head=NULL;
	_length=0;
}



void Program::addLine(Line * newline){

	Node *nod = new Node(newline);

	if(!_head){
		_head= nod;
	}

	else{
		Node *n = _head;
		while (n->getnext()){
			n= n->getnext();
		}

		n->setNext(nod);
	}

	_length++;

}


void Program::delLine(int index){
	Node * to_delete;
	Node * prec;
	
	if (index >= 0 && index < _length){

      		 if (index == 0){
			if (_length > 0){
				// On efface le maillon.
      			 	to_delete = _head;
			 	_head = _head->getnext();

				
    			}
		}else{	// On se place sur le précédent.
           		prec = _head;

			for (int i = 0; i < index-1; ++i){
				prec = prec->getnext();
			}

 			// On retire le maillon.
			to_delete = prec->getnext();
			prec->setNext( to_delete->getnext() );

       		}
		delete to_delete;
		--_length;
    	}
}

int Program::add_Line_at(Line *newline, int position)
{
    if (position <= 0){
       	Node * new_nod = new Node(newline);

    	if (new_nod == NULL)  // Y avait-il assez de mémoire ?
		return 0;

	new_nod->setNext(_head); // new_nod pointe sur le premier.
	_head = new_nod;       // new_nod est maintenant premier.


	++_length;
	return 1;
	}

    else if (position >= _length)
	addLine(newline);

    else
    {
       Node * new_nod = new Node(newline);
       Node * prec = _head;
       if (new_nod == NULL)// Y avait-il assez de mémoire?
           return 0;

       // On se place sur le précédent.
       for (int i = 0; i < position - 1; ++i){
		prec = prec->getnext();
	}

       // On ajuste les pointeurs.
       new_nod->setNext(prec->getnext());
       prec->setNext(new_nod);
       ++_length;
       return 1;
    }
	return 1;
}


void Program::display()
{
	Node* element = _head;
	while(element != NULL)
	{
		cout << element->getLine()-> getContent() <<endl;
		
		if(element->getnext()==NULL)	break;
		else element = element->getnext();

	}
	if(isEmpty())	cout<<"The program is empty"<<endl;
	cout << endl;
}
/*
t_Dep Program::dependance(Instruction i1, Instruction i2){

	string dep1= i1.is_dependant(i2);
	string dep2= i2.is_dependant(i1);
	cout<<"Depedance i1->i2: "<<dep1<<endl;
	cout<<"Depedance i2->i1: "<<dep2<<endl;
}
*/
Line* Program::findLine(int index){

    int j;
    Node *e = _head;

	for (j=0; j< _length ;j++)
	{
	    if(j==index)
	    { return e->getLine();}
	   
	    e= e->getnext();

	}
	return NULL;
}


int Program::size(){
	return _length;
}

bool Program::isEmpty(){
	if(!_head)	return true;
	return false;
}

void Program::inFile(string const filename){

	Node* element = _head;
	ofstream monflux(filename.c_str());

	if(monflux){
		while(element != NULL)
		{
			if(element->getLine()->typeLine()==line_Instru || element->getLine()->typeLine()== line_Direct) monflux<<"\t";
			monflux << element->getLine()-> getContent();
		
			if(element->getnext()==NULL)	break;
			else {
				if(element->getLine()->getContent().compare("nop")) monflux<<endl;
				element = element->getnext();
			}			
		}
		
	}

	else {
		cout<<"Error cannot open the file"<<endl;
	}

	monflux.close();	
}


void Program::comput_Function(){
	Function func;

	if (!isEmpty()){	

		Node* element = _head;
		func.set_head(_head);
		//cout<<func.get_head()->getLine()->getContent()<<endl;
		while(element != NULL)
		{
			if(!element->getLine()->getContent().compare(".end")){
				func.set_end(element);
				//cout<<func.get_end()->getLine()->getContent()<<endl;
				myfunc.push_back(func);
				func.set_head(element->getnext());
				//cout<<func.get_head()->getLine()->getContent()<<endl;
			}
			
			if(element->getnext()==NULL){
				func.set_end(element);
				//cout<<func.get_end()->getLine()->getContent()<<endl;
				myfunc.push_back(func);
				break;
			}
			else element = element->getnext();

		}		
	}
}

int Program::nbr_Func(){
	return myfunc.size();
}

Function  Program::get_Function(int index){

	list<Function>::iterator it;
	it=myfunc.begin();

  	if(index< myfunc.size()){
  		for (int i=0; i<index;i++ ) it++;
		return *it;	
	}
	
	return myfunc.back();	
}


