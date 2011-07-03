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

void Function::comput_Label(){
	Node* element = _head;

	if(element == _end && element->getLine()->typeLine()==line_Lab)	
					_list_lab.push_back(dynamic_cast< Label *> (element->getLine()));
	while(element != _end)
	{

		if(element->getLine()->typeLine()==line_Lab)	
					_list_lab.push_back(dynamic_cast< Label * > (element->getLine()));

		if(element->getnext()==_end){
			if(element->getLine()->typeLine()==line_Lab)	
					_list_lab.push_back(dynamic_cast< Label * > (element->getLine()));
			break;
		}
		else element = element->getnext();

	}

}

int Function::nbr_Label(){
	return _list_lab.size();

}

Label* Function::get_Label(int index){

	list<Label*>::iterator it;
	it=_list_lab.begin();

  	if(index< _list_lab.size()){
  		for (int i=0; i<index;i++ ) it++;
		return *it;	
	}
	else cout<<"Error: index is bigger than the size of the list"<<endl; 
	
	return _list_lab.back();
}

Basic_block *Function::find_Label_BB(OPLabel* label){
	Basic_block *BB = new Basic_block();
	for(int i=0; i<_myBB.size(); i++){		
		if(get_BB(i)->get_head()->getLine()->typeLine()==line_Lab){
			
			if(!get_BB(i)->get_head()->getLine()->getContent().compare(0,
				(get_BB(i)->get_head()->getLine()->getContent().size()-1),label->getOp())){
				return get_BB(i);}
		}
	}
	return BB;
}

void Function::comput_basic_block(){
	Basic_block * BB = new Basic_block();	
	int i=0;
	int begin=0;

		Node* element = _head;

		//cout<<"entrÃ©"<<endl;
		/*supprime les directives precedent le premier BB*/
		while(!begin){
			if(element->getLine()->typeLine()!=line_Direct){
				//cout<<"tete1 "<<element->getLine()->getContent() <<endl;
				BB->set_head(element);
				//cout<<BB->get_head()->getLine()->getContent()<<endl;
				begin=1;
			}	
			else	element= element->getnext();

		}

		while(element != _end)
		{ 		/*si l'instruction est un branchement alors on prend le delay sot comme
				dernier element du BB et comme tete l'element qui suit*/
			if(element->getLine()->typeLine()==line_Instru && element->getnext()->getLine()->typeLine()==line_Instru){
				if(element->getLine()->getType()==BR){
					//cout<<"fin1 "<<element->getnext()->getLine()->getContent() <<endl;
					BB->set_Branch(element);
					BB->set_end(element->getnext());
					BB->set_index(i);
					i++;
					_myBB.push_back(BB);
					BB = new Basic_block();
					BB->set_Branch(NULL);
					if(element->getnext()->getnext()!=_end && element->getnext()!=_end){
						//cout<<"tÃªte2 "<<element->getnext()->getnext()->getLine()->getContent() <<endl;
						BB->set_head(element->getnext()->getnext());
						element = element->getnext();
					}
					else	break;
				}
			}
			/*si l'instruction suivante est un label alors on prend l'instruction courante comme fin
			du BB et on prens le suivant comme tete du prochain BB*/
			else if(element->getnext()->getLine()->typeLine()==line_Lab){
				//cout<<"fin3 "<<element->getLine()->getContent() <<endl;
				BB->set_end(element);
				BB->set_index(i);
				i++;
				_myBB.push_back(BB);
				//cout<<"tÃªte3 "<<element->getnext()->getLine()->getContent() <<endl;
				BB = new Basic_block();
				BB->set_head(element->getnext());

			}
			if(element->getnext()==_end){
				BB->set_end(element);
				BB->set_index(i);
				i++;
				//cout<<"fin4"<<element->getLine()->getContent() <<endl;
				_myBB.push_back(BB);
				break;
			}
			else element = element->getnext();

		}	


		
}

int Function::nbr_BB(){
	return _myBB.size();
}

Basic_block *Function::get_BB(int index){

	list<Basic_block*>::iterator it;
	it=_myBB.begin();

  	if(index< _myBB.size()){
  		for (int i=0; i<index;i++ ) it++;
		return *it;	
	}
	else cout<<"Error: index is bigger than the size of the list"<<endl; 
	
	return _myBB.back();
}


void Function::comput_succ_pred_BB(){
	list <Basic_block*> BBtmp;
	Basic_block * BB = new Basic_block();
	

	/*Calcul des successeurs*/
	for(int i=0; i<_myBB.size(); i++){
		BB = get_BB(i);
		if(get_BB(i)->get_end()->getLine()->typeLine()==line_Instru){
			//si l'instru n'est pas un br alors 1 successeur le BB suivant
			if(get_BB(i)->get_Branch()==NULL && ((i+1) < _myBB.size()) ||
				dynamic_cast< Instruction *> (get_BB(i)->get_Branch()->getLine())->getOPcode()==jal ||
				dynamic_cast< Instruction *> (get_BB(i)->get_Branch()->getLine())->getOPcode()==jalr  ){
				BB->set_successor1( get_BB(i+1)); 
				}
	
			//si l'instru est un BR inconditiennel 1 successeur le BB pointé par le label
			else if(dynamic_cast< Instruction *> (get_BB(i)->get_Branch()->getLine())->getOPcode()==j){ 
				if(find_Label_BB(dynamic_cast< Instruction *> (get_BB(i)->get_Branch()->getLine())->getOp1())->get_head()){
					//cout<<"coucou1"<<endl;
					BB->set_successor1(find_Label_BB(
					  dynamic_cast< Instruction *> (get_BB(i)->get_Branch()->getLine())->getOp1()));
				}
			}//cout<<"here too\n";}
	
			//si l'instru est un BR conditionnel 2 successeur le BB pointé et le BB suivant
			else if((dynamic_cast< Instruction *> (get_BB(i)->get_Branch()->getLine())->getOPcode()==beq ||
				dynamic_cast< Instruction *> (get_BB(i)->get_Branch()->getLine())->getOPcode()==bne)
				&& ((i+1)< _myBB.size())){
			
				if(find_Label_BB(
					dynamic_cast< Instruction *> (get_BB(i)->get_Branch()->getLine())->getOp3())->get_head()){	
					
					BB->set_successor1(find_Label_BB( dynamic_cast< Instruction *> (get_BB(i)->get_Branch()->getLine())->getOp3()));
				}
				BB->set_successor2(get_BB(i+1));
				//cout<<"here too too\n";
			}
	
			else if(dynamic_cast< Instruction *> (get_BB(i)->get_Branch()->getLine())->getOPcode()!=jr
					&& ((i+1)< _myBB.size())){

				if(find_Label_BB(
					dynamic_cast< Instruction *> (get_BB(i)->get_Branch()->getLine())->getOp2())->get_head()){
					
					BB->set_successor1(find_Label_BB(
					dynamic_cast< Instruction *> (get_BB(i)->get_Branch()->getLine())->getOp2()));
				}
				BB->set_successor2(get_BB(i+1));
				//cout<<"and finaly here too\n";
			}

			//sinon pas de successeur
			else ;
			BBtmp.push_back(BB);
			BB = new Basic_block();
		}
		

	}
	_myBB.clear();

	list<Basic_block*>::iterator it;
	it=BBtmp.begin();

	for (int i=0; i< BBtmp.size();i++ ){ 
		_myBB.push_back(*it);
		it++;
	}

	/*Calcul des predecesseur*/
	for(int i=0;i<_myBB.size(); i++){
		for(int j=0; j<_myBB.size(); j++){
			//cout<<"nbr de succ de BB"<<j<<" "<<get_BB(j)->get_nbr_succ()<<endl;
			if(get_BB(j)->get_nbr_succ()){
				if(get_BB(i)->get_index() == get_BB(j)->get_successor1()->get_index()){
					get_BB(i)->set_predecessor(get_BB(j));
				}
			}
			if(get_BB(j)->get_nbr_succ()==2){
				if(get_BB(i)->get_index() == get_BB(j)->get_successor2()->get_index()){
						get_BB(i)->set_predecessor(get_BB(j));	
				}
			}
		}		
	}	
	
}




void Function::test(){
	/*comput_successor_BB();
	Cfg graph(get_BB(0),_myBB.size());
	
	graph.display(NULL);
	graph.restitution(NULL,"./tmp/graph.dot");

	for(int i=0;i<_myBB.size(); i++){
		for(int j=0; j<get_BB(i)->get_nbr_pred();j++)
		cout<<"BB"<<get_BB(i)->get_predecessor(j)->get_index()<<" predecesseur de BB"<<i<<endl;
			}*/
}
