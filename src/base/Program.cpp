#include <Program.h>
#include <asm_mipsyac.h>

extern	void programparse(string) ; 
extern	Program prog ;

Program::Program(){
	_head= NULL;
	_length=0;
}


//constructeur de copie
Program::Program(Program const&  otherprogram){
	//On initialise la liste.

	_head= NULL;
	_length= 0;

    // On copie la liste.

   	Node * tmp = otherprogram._head;

    	while (tmp != NULL){

       		add_line(tmp->get_line());
       		tmp = tmp->get_next();
	}
}

//constructeur qui vas permettre de parser un fichier
Program::Program (string const file){
	_head = NULL ;
	_length = 0 ;
	 programparse(file) ;

	Node * tmp = prog._head;

    	while (tmp != NULL){

       		add_line(tmp->get_line());
       		tmp = tmp->get_next();
	}

}

Program::~Program(){

	delete _head;
	_head=NULL;
	_length=0;
}



void Program::add_line(Line * newline){

	Node *nod = new Node(newline);

	if(!_head){
		_head= nod;
	}

	else{
		Node *n = _head;
		while (n->get_next()){
			n= n->get_next();
		}

		n->set_next(nod);
	}

	_length++;

}


void Program::del_line(int index){
	Node * to_delete;
	Node * prec;
	
	if (index >= 0 && index < _length){

      		 if (index == 0){
			if (_length > 0){
				// On efface le maillon.
      			 	to_delete = _head;
			 	_head = _head->get_next();

				
    			}
		}else{	// On se place sur le pr√©c√©dent.
           		prec = _head;

			for (int i = 0; i < index-1; ++i){
				prec = prec->get_next();
			}

 			// On retire le maillon.
			to_delete = prec->get_next();
			prec->set_next( to_delete->get_next() );

       		}
		delete to_delete;
		--_length;
    	}
}

int Program::add_line_at(Line *newline, int position)
{
    if (position <= 0){
       	Node * new_nod = new Node(newline);

    	if (new_nod == NULL)  // Y avait-il assez de m√©moire ?
		return 0;

	new_nod->set_next(_head); // new_nod pointe sur le premier.
	_head = new_nod;       // new_nod est maintenant premier.


	++_length;
	return 1;
	}

    else if (position >= _length)
	add_line(newline);

    else
    {
       Node * new_nod = new Node(newline);
       Node * prec = _head;
       if (new_nod == NULL)// Y avait-il assez de m√©moire?
           return 0;

       // On se place sur le pr√©c√©dent.
       for (int i = 0; i < position - 1; ++i){
		prec = prec->get_next();
	}

       // On ajuste les pointeurs.
       new_nod->set_next(prec->get_next());
       prec->set_next(new_nod);
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
		cout << element->get_line()-> get_content() <<endl;
		
		if(element->get_next()==NULL)	break;
		else element = element->get_next();

	}
	if(is_empty())	cout<<"The program is empty"<<endl;
	cout << endl;
}

void Program::flush()
{
	Node* element = _head;
	int i=0;

	while(!is_empty())
	{
		del_line(0);		
	
	}
}


t_Dep Program::dependance(Instruction i1, Instruction i2){
	
	//Calcul des depandance dans les deux sens
	string dep[]={"NONE","RAW","WAR","WAW"};
	t_Dep dep1= i1.is_dependant(i2);
	t_Dep dep2= i2.is_dependant(i1);
	cout<<"Depedance i1->i2: "<<dep[dep1]<<endl;
	cout<<"Depedance i2->i1: "<<dep[dep2]<<endl;

	return dep1;
}

void Program::exchange_line(int line1, int line2){
	Line * lg1,*lg2;
	
	lg1=find_line(line1);
	lg2=find_line(line2);

	del_line(line1);
	add_line_at(lg2,line1);
	del_line(line2);
	add_line_at(lg1,line2);
	

}

Line* Program::find_line(int index){

    int j;
    Node *e = _head;

	for (j=0; j< _length ;j++)
	{
	    if(j==index)
	    { return e->get_line();}
	   
	    e= e->get_next();

	}
	return NULL;
}


int Program::size(){
	return _length;
}

bool Program::is_empty(){
	if(!_head)	return true;
	return false;
}

void Program::in_file(string const filename){

	Node* element = _head;
	ofstream monflux(filename.c_str());

	if(monflux){
		while(element != NULL)
		{
			if(element->get_line()->type_line()==line_Instru || element->get_line()->type_line()== line_Direct) monflux<<"\t";
			monflux << element->get_line()-> get_content();
		
			if(element->get_next()==NULL)	break;
			else {
				if(element->get_line()->get_content().compare("nop")) monflux<<endl;
				element = element->get_next();
			}			
		}
		
	}

	else {
		cout<<"Error cannot open the file"<<endl;
	}

	monflux.close();	
}


void Program::comput_function(){
	Function func;
	
	if (!is_empty()){	

		Node* element = _head;
		
		
		while(element != NULL)
		{
			//Si la ligne correspond ‡ la directive d'entrÈe
			//Alors la ligne sera affectÈe ‡ la tÍte de la fonction
			if(!element->get_line()->get_content().compare(0,4,".ent")){
				func.set_head(element->get_next());
				//cout<<func.get_head()->get_line()->get_content()<<endl;
			}

			//Si la ligne correspond ‡ la directive de sortie
			//Alors la ligne sera affectÈe ‡ la fin de la fonction
			if(!element->get_line()->get_content().compare(0,4,".end")){
				func.set_end(element);
				//cout<<func.get_end()->get_line()->get_content()<<endl;
				myfunc.push_back(func);
			}
			
			if(element->get_next()==NULL){
				//cout<<func.get_end()->get_line()->get_content()<<endl;
				break;
			}
			else element = element->get_next();

		}		
	}
}

int Program::nbr_func(){
	return myfunc.size();
}

Function  Program::get_function(int index){

	list<Function>::iterator it;
	it=myfunc.begin();

  	if(index< myfunc.size()){
  		for (int i=0; i<index;i++ ) it++;
		return *it;	
	}
	
	return myfunc.back();	
}


