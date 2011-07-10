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



void Basic_block::set_index_instruction(){
	
	Node* element = _head;
	int i=0;
	
	if(element == _end)	dynamic_cast< Instruction *>(element->getLine())->set_index(0);
	while(element != _end)
	{
		if(element->getLine()->typeLine()==line_Instru)
			dynamic_cast< Instruction *>(element->getLine())->set_index(i++);
		
		if(element->getnext()==_end){
			if(element->getLine()->typeLine()==line_Instru)
				dynamic_cast< Instruction *>(element->getLine())->set_index(i++);
			break;
		}
		else element = element->getnext();

	}
	_nbr_instru = i;

}

void Basic_block::comput_pred_succ(){

	Node* element = _head;
	set_index_instruction();
	
	//Calcul des successeurs
	while(element != _end->getnext())
	{
		Node* elem_suiv = element->getnext();
		
		while(elem_suiv != _end->getnext())
		{
		
			if(element->getLine()->typeLine() == line_Instru && elem_suiv->getLine()->typeLine() == line_Instru){

				Instruction *inst = dynamic_cast< Instruction *> (elem_suiv->getLine());
				//cout<<"element : "<<element->getLine()->getContent()<<endl;

				if(dynamic_cast< Instruction *> (element->getLine())->is_dependant(* inst) != NONE){

					dynamic_cast< Instruction *> (element->getLine())->set_successor(dynamic_cast< Instruction *> (elem_suiv->getLine()));

				}
				else if(get_Branch() && elem_suiv->getnext()==_end){
	
					dynamic_cast< Instruction *> (element->getLine())->set_successor(dynamic_cast< Instruction *> (get_Branch()->getLine()));		
				}
				else ;

			}

			if(elem_suiv->getnext()==_end->getnext()){
				break;
			}
			else elem_suiv = elem_suiv->getnext();

		}
		
		if(element->getnext()==_end->getnext()){
			break;
		}
		else element = element->getnext();

	}

	//Calcul des predecesseurs
	element= _head;
	while(element != _end->getnext())
	{
		Node* elem_suiv = _head;
		
		while(elem_suiv != element)
		{

			if(element->getLine()->typeLine() == line_Instru && elem_suiv->getLine()->typeLine() == line_Instru){
				Instruction *inst = dynamic_cast< Instruction *> (elem_suiv->getLine());
				
				for(int i=0; i<inst->get_nbr_succ(); i++){

					if(! dynamic_cast< Instruction *> (element->getLine())->getContent().compare(inst->get_successor(i)->getContent()))
						dynamic_cast< Instruction *> (element->getLine())->set_predecessor(inst);
			
				}
			}

			if(elem_suiv->getnext()==_end->getnext()){
				break;
			}
			else elem_suiv = elem_suiv->getnext();

		}
		
		if(element->getnext()==_end->getnext()){
			break;
		}
		else element = element->getnext();

	}

}


void Basic_block::test(){
	comput_pred_succ();

	Node* element = _head;
	
	Dfg graph(_nbr_instru);

	while(element != _end->getnext())
	{
		Node_dfg *node = new Node_dfg(dynamic_cast< Instruction *> (element->getLine()));
		if(element->getLine()->typeLine()==line_Instru){
			graph.build_dfg(node,true);			
		}
		 element= element->getnext();
		
	}

	graph.display(NULL, true);
	graph.restitute(NULL,"./tmp/graph_dfg.dot", true);
	graph.comput_critical_path(NULL, true);
	/*element = _head;
	while(element != _end)
	{
		Node_dfg *node = new Node_dfg(dynamic_cast< Instruction *> (element->getLine()));
		if(element->getLine()->typeLine()==line_Instru){
			graph.display(node);			
		}
		 element= element->getnext();
		
	}

	element = _head;
	while(element != _end)
	{
		Node_dfg *node = new Node_dfg(dynamic_cast< Instruction *> (element->getLine()));
		if(element->getLine()->typeLine()==line_Instru){
			graph.restitute(node,"./tmp/graph_dfg.dot");		
		}
		 element= element->getnext();
		
	}*/

			
	
	/*while(element != _end->getnext())
	{
		if(element->getLine()->typeLine() == line_Instru ){
			cout<<"\nVoici les succ de l'inst :"<<endl;
			cout<<element->getLine()->getContent()<<endl;
			for(int i=0;i<dynamic_cast< Instruction *>(element->getLine())->get_nbr_succ();i++){
			cout<<dynamic_cast< Instruction *>(element->getLine())->get_successor(i)->getContent()<<endl;
			}
		}
		
		if(element->getnext()==_end->getnext()){
			break;
		}
		else element = element->getnext();

	}

	element = _head;
	while(element != _end->getnext())
	{
		if(element->getLine()->typeLine() == line_Instru ){
			cout<<"\nVoici les pred de l'inst :"<<endl;
			cout<<element->getLine()->getContent()<<endl;
			for(int i=0;i<dynamic_cast< Instruction *>(element->getLine())->get_nbr_pred();i++){
			cout<<dynamic_cast< Instruction *>(element->getLine())->get_predecessor(i)->getContent()<<endl;
			}
		}
		
		if(element->getnext()==_end->getnext()){
			break;
		}
		else element = element->getnext();

	}*/
	
}