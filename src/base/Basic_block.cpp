#include <Basic_block.h>



Basic_block::Basic_block(){
	_head = NULL;
	_end = NULL;
	_branch = NULL;
	_index = 0;
	_nbr_succ = 0;
	_nbr_pred = 0;
	_nbr_instru = 0;
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

void Basic_block::set_predecessor(Basic_block *BB){
	_nbr_pred++;
	_predecessor.push_back(BB);
}

Basic_block *Basic_block::get_predecessor(int index){

	list<Basic_block*>::iterator it;
	it=_predecessor.begin();

  	if(index< _predecessor.size()){
  		for (int i=0; i<index;i++ ) it++;
		return *it;	
	}
	else cout<<"Error: index is bigger than the size of the list"<<endl; 
	
	return _predecessor.back();
	
}

int Basic_block::get_nbr_succ(){
	return _nbr_succ;
}

int Basic_block::get_nbr_pred(){
	return _nbr_pred;
}

void Basic_block::set_branch(Node * br){
	_branch=br;
}

Node* Basic_block::get_branch(){
	return _branch;
}

void Basic_block::display(){

	cout<<"Begin"<<endl;
	Node* element = _head;
	
	if(element == _end)	cout << _head->get_line()-> get_content() <<endl;
	while(element != _end)
	{
		if(element->get_line()->type_line()!=line_Direct)
			cout << element->get_line()-> get_content() <<endl;
		
		if(element->get_next()==_end){
			if(element->get_line()->type_line()!=line_Direct)
				cout << element->get_next()->get_line()-> get_content() <<endl;
			break;
		}
		else element = element->get_next();

	}

	cout<<"End\n\n"<<endl;
}

int Basic_block::size(){

	Node* element = _head;
	int lenght=0;
	while(element != _end)
	{
		lenght++;
		
		if(element->get_next()==_end)	break;
		else element = element->get_next();

	}
	return lenght;
}	


void Basic_block::restitution(string const filename){
	
	Node* element = _head;
	ofstream monflux(filename.c_str(), ios::app);

	if(monflux){
		monflux<<"Begin"<<endl;
		if(element == _end)	monflux << _head->get_line()-> get_content() <<endl;
		while(element != _end)
		{
			if(element->get_line()->type_line()==line_Instru ) monflux<<"\t";
				if(element->get_line()->type_line()!=line_Direct)
					monflux << element->get_line()-> get_content()<<endl ;
		
			if(element->get_next()==_end){
				if(element->get_next()->get_line()->type_line()==line_Instru ) monflux<<"\t";
					if(element->get_line()->type_line()!=line_Direct)
						monflux << element->get_next()->get_line()-> get_content()<<endl;
				break;
			}
			else element = element->get_next();

		}
		monflux<<"End\n\n"<<endl;
		
	}

	else {
		cout<<"Error cannot open the file"<<endl;
	}

	monflux.close();

}

bool Basic_block::is_labeled(){
	if (_head->get_line()->type_line()==line_Lab){
		return true;
	}
	else return false;
}



void Basic_block::set_index_instruction(){
	
	Node* element = _head;
	int i=0;
	
	
	while(element != _end->get_next())
	{
		if(element->get_line()->type_line()==line_Instru){
			dynamic_cast< Instruction *>(element->get_line())->set_index(i);
			i++;
		}
		
		if(element->get_next()==_end->get_next()){
			break;
		}
		else {
			element = element->get_next();			
		}
		

	}
	_nbr_instru = i;

}

void Basic_block::comput_pred_succ(){

	Node* element = _head;
	set_index_instruction();
	int test_dep;
	
	//Calcul des successeurs
	while(element != _end->get_next())
	{
		Node* elem_suiv = element->get_next();
		test_dep=0;
		//tant qu'on est pas à la fin
		while(elem_suiv != _end->get_next())
		{
		
			//si les element sont des instructions
			if(element->get_line()->type_line() == line_Instru && elem_suiv->get_line()->type_line() == line_Instru){

				Instruction *inst = dynamic_cast< Instruction *> (elem_suiv->get_line());
				//cout<<"element : "<<element->get_line()->get_content()<<endl;

				//on regarde s'il y a une dependance
				if(dynamic_cast< Instruction *> (element->get_line())->is_dependant(* inst) != NONE){

					dynamic_cast< Instruction *> (element->get_line())->set_successor(dynamic_cast< Instruction *> (elem_suiv->get_line()));
					test_dep=1;

				}
				else if(get_branch() && elem_suiv->get_next()==_end && test_dep==0){
					dynamic_cast< Instruction *> (element->get_line())->set_successor(dynamic_cast< Instruction *> (get_branch()->get_line()));		
				}
				else ;

			}

			if(elem_suiv->get_next()==_end->get_next()){
				break;
			}
			else elem_suiv = elem_suiv->get_next();

		}
		
		if(element->get_next()==_end->get_next()){
			break;
		}
		else element = element->get_next();

	}

	//Calcul des predecesseurs
	element= _head;
	while(element != _end->get_next())
	{
		Node* elem_suiv = _head;
		
		while(elem_suiv != element)
		{

			if(element->get_line()->type_line() == line_Instru && elem_suiv->get_line()->type_line() == line_Instru){
				Instruction *inst = dynamic_cast< Instruction *> (elem_suiv->get_line());
				
				for(int i=0; i<inst->get_nbr_succ(); i++){

					if(! dynamic_cast< Instruction *> (element->get_line())->get_content().compare(inst->get_successor(i)->get_content()))
						dynamic_cast< Instruction *> (element->get_line())->set_predecessor(inst);
			
				}
			}

			if(elem_suiv->get_next()==_end->get_next()){
				break;
			}
			else elem_suiv = elem_suiv->get_next();

		}
		
		if(element->get_next()==_end->get_next()){
			break;
		}
		else element = element->get_next();

	}

}


void Basic_block::test(){
	comput_pred_succ();

	Node* element = _head;
	
	Dfg graph(_nbr_instru);

	while(element != _end->get_next())
	{
		Node_dfg *node = new Node_dfg(dynamic_cast< Instruction *> (element->get_line()));
		if(element->get_line()->type_line()==line_Instru){
			graph.build_dfg(node,true);			
		}
		 element= element->get_next();
		
	}

	//graph.display(NULL, true);
	graph.restitute(NULL,"./tmp/graph_dfg.dot", true);
	graph.comput_critical_path(NULL, true);
	
	graph.scheduling_BB(this);
	
	display();
}