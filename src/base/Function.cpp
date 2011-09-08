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

	if(element == _end)	cout << _head->get_line()-> get_content() <<endl;
	while(element != _end)
	{
		cout << element->get_line()-> get_content() <<endl;
		
		if(element->get_next()==_end){
			cout << element->get_next()->get_line()-> get_content() <<endl;
			break;
		}
		else element = element->get_next();

	}
	cout<<"End\n\n"<<endl;
	
}

int Function::size(){
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


void Function::restitution(string const filename){
	
	Node* element = _head;
	ofstream monflux(filename.c_str(), ios::app);

	if(monflux){
		monflux<<"Begin"<<endl;
		if(element == _end)	monflux << _head->get_line()-> get_content() <<endl;
		while(element != _end)
		{
			if(element->get_line()->type_line()==line_Instru || element->get_line()->type_line()== line_Direct) monflux<<"\t";
			monflux << element->get_line()-> get_content() ;
			if(element->get_line()->get_content().compare("nop")) monflux<<endl;
		
			if(element->get_next()==_end){
				if(element->get_next()->get_line()->type_line()==line_Instru || 
							element->get_next()->get_line()->type_line()==line_Direct) monflux<<"\t";
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

void Function::comput_label(){
	Node* element = _head;

	if(element == _end && element->get_line()->type_line()==line_Lab)	
					_list_lab.push_back(dynamic_cast< Label *> (element->get_line()));
	while(element != _end)
	{

		if(element->get_line()->type_line()==line_Lab)	
					_list_lab.push_back(dynamic_cast< Label * > (element->get_line()));

		if(element->get_next()==_end){
			if(element->get_line()->type_line()==line_Lab)	
					_list_lab.push_back(dynamic_cast< Label * > (element->get_line()));
			break;
		}
		else element = element->get_next();

	}

}

int Function::nbr_label(){
	return _list_lab.size();

}

Label* Function::get_label(int index){

	list<Label*>::iterator it;
	it=_list_lab.begin();

  	if(index< _list_lab.size()){
  		for (int i=0; i<index;i++ ) it++;
		return *it;	
	}
	else cout<<"Error: index is bigger than the size of the list"<<endl; 
	
	return _list_lab.back();
}

Basic_block *Function::find_label_BB(OPLabel* label){
	Basic_block *BB = new Basic_block();
	for(int i=0; i<_myBB.size(); i++){		
		if(get_BB(i)->get_head()->get_line()->type_line()==line_Lab){
			
			if(!get_BB(i)->get_head()->get_line()->get_content().compare(0,
				(get_BB(i)->get_head()->get_line()->get_content().size()-1),label->get_op())){
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
			if(element->get_line()->type_line()!=line_Direct){
				//cout<<"tete1 "<<element->get_line()->get_content() <<endl;
				BB->set_head(element);
				//cout<<BB->get_head()->get_line()->get_content()<<endl;
				begin=1;
			}	
			else	element= element->get_next();

		}

		while(element != _end)
		{ 		/*si l'instruction est un branchement alors on prend le delay sot comme
				dernier element du BB et comme tete l'element qui suit*/
			if(element->get_line()->type_line()==line_Instru && element->get_next()->get_line()->type_line()==line_Instru){
				if(element->get_line()->get_type()==BR){
					//cout<<"fin1 "<<element->get_next()->get_line()->get_content() <<endl;
					BB->set_branch(element);
					BB->set_end(element->get_next());
					BB->set_index(i);
					i++;
					_myBB.push_back(BB);
					BB = new Basic_block();
					BB->set_branch(NULL);
					if(element->get_next()->get_next()!=_end && element->get_next()!=_end){
						//cout<<"tÃªte2 "<<element->get_next()->get_next()->get_line()->get_content() <<endl;
						BB->set_head(element->get_next()->get_next());
						element = element->get_next();
					}
					else	break;
				}
			}
			/*si l'instruction suivante est un label alors on prend l'instruction courante comme fin
			du BB et on prens le suivant comme tete du prochain BB*/
			else if(element->get_next()->get_line()->type_line()==line_Lab){
				//cout<<"fin3 "<<element->get_line()->get_content() <<endl;
				BB->set_end(element);
				BB->set_index(i);
				i++;
				_myBB.push_back(BB);
				//cout<<"tÃªte3 "<<element->get_next()->get_line()->get_content() <<endl;
				BB = new Basic_block();
				BB->set_head(element->get_next());

			}
			if(element->get_next()==_end){
				BB->set_end(element);
				BB->set_index(i);
				i++;
				//cout<<"fin4"<<element->get_line()->get_content() <<endl;
				_myBB.push_back(BB);
				break;
			}
			else element = element->get_next();

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
		if(get_BB(i)->get_end()->get_line()->type_line()==line_Instru){
			//si l'instru n'est pas un br alors 1 successeur le BB suivant
			if(get_BB(i)->get_branch()==NULL && ((i+1) < _myBB.size()) ||
				dynamic_cast< Instruction *> (get_BB(i)->get_branch()->get_line())->get_opcode()==jal ||
				dynamic_cast< Instruction *> (get_BB(i)->get_branch()->get_line())->get_opcode()==jalr  ){
				BB->set_successor1( get_BB(i+1)); 
				}
	
			//si l'instru est un BR inconditiennel 1 successeur le BB pointé par le label
			else if(dynamic_cast< Instruction *> (get_BB(i)->get_branch()->get_line())->get_opcode()==j){ 
				if(find_label_BB(dynamic_cast< Instruction *> (get_BB(i)->get_branch()->get_line())->get_op1())->get_head()){
					//cout<<"coucou1"<<endl;
					BB->set_successor1(find_label_BB(
					  dynamic_cast< Instruction *> (get_BB(i)->get_branch()->get_line())->get_op1()));
				}
			}//cout<<"here too\n";}
	
			//si l'instru est un BR conditionnel 2 successeur le BB pointé et le BB suivant
			else if((dynamic_cast< Instruction *> (get_BB(i)->get_branch()->get_line())->get_opcode()==beq ||
				dynamic_cast< Instruction *> (get_BB(i)->get_branch()->get_line())->get_opcode()==bne)
				&& ((i+1)< _myBB.size())){
			
				if(find_label_BB(
					dynamic_cast< Instruction *> (get_BB(i)->get_branch()->get_line())->get_op3())->get_head()){	
					
					BB->set_successor1(find_label_BB( dynamic_cast< Instruction *> (get_BB(i)->get_branch()->get_line())->get_op3()));
				}
				BB->set_successor2(get_BB(i+1));
				//cout<<"here too too\n";
			}
	
			else if(dynamic_cast< Instruction *> (get_BB(i)->get_branch()->get_line())->get_opcode()!=jr
					&& ((i+1)< _myBB.size())){

				if(find_label_BB(
					dynamic_cast< Instruction *> (get_BB(i)->get_branch()->get_line())->get_op2())->get_head()){
					
					BB->set_successor1(find_label_BB(
					dynamic_cast< Instruction *> (get_BB(i)->get_branch()->get_line())->get_op2()));
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
	
	for(int i=0;i<_myBB.size(); i++){
		get_BB(i)->test();
	}
}
