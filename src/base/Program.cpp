#include "Program.h"

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

Program::Program (FILE * sourceasm){
	cout<<"on donne au constructeur un fichier à parser"<<endl;
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

int Program::add_position(Line *newline, int position)
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
	cout << endl;
}

string Program::dependance(Instruction i1, Instruction i2){


	if(i1.getOp1()->getOptype()==Reg){

            if((i1.getOp1()->getOp().compare(i2.getOp1()->getOp())==0) && (i2.getOp1()->getOptype()==Reg) )   return "WAW";
            else if((i1.getOp1()->getOp().compare(i2.getOp2()->getOp())==0) && (i2.getOp2()->getOptype()==Reg)) return "RAW";
            else if((i1.getOp1()->getOp().compare(i2.getOp3()->getOp())==0) && (i2.getOp3()->getOptype()==Reg)) return "RAW";
        }

        if((i1.getOp2()->getOptype()==Reg) && (i2.getOp1()->getOptype()==Reg)){
            if(i1.getOp2()->getOp().compare(i2.getOp1()->getOp())==0 )    return "WAR";
        }

        if((i1.getOp3()->getOptype()==Reg) && (i2.getOp1()->getOptype()==Reg)){
            if(i1.getOp3()->getOp().compare(i2.getOp1()->getOp())==0)     return "WAR";
        }

        return "not dependant";

}

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

void Program::inFile(string const filename){

	Node* element = _head;
	ofstream monflux(filename.c_str());

	monflux<<"###--------------------------------------------------------------------------------------------###"<<endl;
	monflux<<"#file : "<<filename<<endl;
	monflux<<"#date :   "<<endl;
	monflux<<"###--------------------------------------------------------------------------------------------###\n"<<endl;
	

	

	if(monflux){
		while(element != NULL)
		{
			if(element->getLine()->typeLine()==line_Instru || element->getLine()->typeLine()== line_Direct) monflux<<"\t";
			monflux << element->getLine()-> getContent() <<endl;
		
			if(element->getnext()==NULL)	break;
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


