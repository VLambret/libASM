#include <Dfg.h>

Dfg::Dfg(int size){
	//_head = new Node_dfg(inst);
	_arc_lu=0;
	_nbr_arc=0;
	_length = size;
	_read = new int[size];
	for(int i=0; i<size; i++)	_read[i]=0;
}

Dfg::~Dfg(){}


//Pas encore modifiée
void Dfg::build_dfg(Node_dfg * node, bool first){
	Arc* edge = new Arc();
	list<Node_dfg*>::iterator it;
	list <Node_dfg*> list_tmp;
	Node_dfg* test;
	int end=0;
	
	//si le noeud n'a pas encore été lu
	if(!_read[node->get_instruction()->get_index()]){

		//si on est au premier appel (et nn dans un appel recurssif)
		if(first)	{ _head.push_back(node);
				 list_node_dfg.push_back(node);
				}

		//marquer comme lu
		_read[node->get_instruction()->get_index()]=1;

		//On l'affecte de ses successeurs
		for(int i=0;i<node->get_instruction()->get_nbr_succ();i++){
			list_tmp = list_node_dfg;
			_nbr_arc++;
			edge = new Arc();
			edge->dep=node->get_instruction()->is_dependant(* node->get_instruction()->get_successor(i));
			//calcul le delay en fonction de la dep
			switch (edge->dep){
				case RAW : edge->delai= t_delay[node->get_instruction()->get_type()][node->get_instruction()->get_successor(i)->get_type()]; break;
				case WAW :  edge->delai=1; break;
				case WAR : edge->delai= 1; break;
			}
			
			
			it=list_tmp.begin();
			for(int k=0;k<list_tmp.size();k++){
				test=*it++;
				/*cout<<"la liste des nodes déjà créé "<<test->get_instruction()->get_index()<<endl;
				cout<<"succ de i  "<<node->get_instruction()->get_successor(i)->get_index()<<endl;
*/
				if(test->get_instruction()->get_index()==node->get_instruction()->get_successor(i)->get_index()){
				//cout<<"erreur"<<endl;
				end= 1;
				edge->next=test;
				}
				
			}
			
			if(!end){
					//cout<<"coucou"<<endl;
					edge->next= new Node_dfg(node->get_instruction()->get_successor(i));
					list_node_dfg.push_back(edge->next);
				}
			else	end=0;			
			
			node->set_succ(edge);
			
			//on appel le successeur
			build_dfg(edge->next,false);


			//on compte le nombre de descendant
			node->set_desc(node->get_instruction()->get_successor(i)->get_index());
			for(int j=0; j<edge->next->get_nb_desc();j++){
				node->set_desc(edge->next->get_desc(j));
			}
			
		}
	}
		
}

void Dfg::display(Node_dfg * node, bool first){
	
	list<Node_dfg*>::iterator it;
	it=_head.begin();

	if(first)	for(int i=0; i<_length; i++)	_read[i]=0;  	

  	for (int j=0; j<_head.size();j++ ){ 
		if(first) node = *it;	
			

		if(!_read[node->get_instruction()->get_index()]){
				_read[node->get_instruction()->get_index()]=1;
			cout<<"pour i"<<node->get_instruction()->get_index()<<endl;
			cout<<"l'instruction "<<node->get_instruction()->get_content()<<endl;
			
			//On affiche ses successeurs s'il en a
			for(int i=0;i<node->get_instruction()->get_nbr_succ();i++){
				cout<<" -> succ "<<node->get_succ(i)->next->get_instruction()->get_content()<<endl;
				cout<<"= i"<<node->get_succ(i)->next->get_instruction()->get_index()<<endl;
			}
			for(int i=0;i<node->get_instruction()->get_nbr_succ();i++){	
				display(node->get_succ(i)->next, false);
			}

			
		}
		it++;

	}
}


//Pour générer le fichier .dot: dot -Tps graph.dot -o graph.ps
void Dfg::restitute(Node_dfg * node, string const filename, bool first){

	ofstream monflux(filename.c_str(), ios::app);
	list<Node_dfg*>::iterator it;
	it=_head.begin();
	int test=0, end=0;
	
	if(first && _length){
		for(int i=0; i<_length; i++)	_read[i]=0;
		monflux<<"digraph G1 {"<<endl;
		
	}	

	for (int j=0; j<_head.size();j++ ){ 		

		if(first) node = *it;
		
		if(monflux){			
			//monflux.open(filename.c_str(), ios::app);
			if(!_read[node->get_instruction()->get_index()]){
				_read[node->get_instruction()->get_index()]=1;
					
				//On affiche ses successeurs s'il en a
				for(int i=0;i<node->get_instruction()->get_nbr_succ();i++){
					_arc_lu++;
					monflux<<"i"<<node->get_instruction()->get_index();
					monflux<<" ->  i"<<node->get_succ(i)->next->get_instruction()->get_index();
					monflux<<" [label= \""<<node->get_succ(i)->delai<<"\"];"<<endl;
				}
				monflux.close();
				for(int i=0;i<node->get_instruction()->get_nbr_succ();i++){
					restitute(node->get_succ(i)->next,filename.c_str(),false);	
				}
			}
		}
		if((j+1) < _head.size())	monflux.open(filename.c_str(), ios::app);
		it++;
	}

	//lecture du fichier pour savoir s'il y a déjà un parenthese de fin
	ifstream fichier(filename.c_str());
	if(fichier){
	
		string ligne;     //Une variable pour stocker les lignes lues
		while(getline(fichier, ligne))    //Tant qu'on n'est pas a la fin, on lit
		{	end=0;
			if(!ligne.compare("}"))	end=1;
		}
	}
	else{
		cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
	}
					
	//si pas de parenthese la rajouter
	if(!end){
		monflux.open(filename.c_str(), ios::app);
		if(_arc_lu == _nbr_arc || _arc_lu==0)	monflux<<"}"<<endl;
		monflux.close();
	}
}

bool Dfg::read_test(){
	for(int i=0; i<_length; i++)	if(_read[i]==0)	return true;
	return false;
}

void Dfg::comput_critical_path(Node_dfg * node, bool first){

	list<Node_dfg*>::iterator it;
	it=_head.begin();
	int cmpt =0, end =0;

	if(first)	for(int i=0; i<_length; i++)	_read[i]=0;  	

  	for (int j=0; j<_head.size();j++ ){ 
		if(first) node = *it;	
			
		//s'il n'a pas encore été lu
		if(!_read[node->get_instruction()->get_index()]){
			_read[node->get_instruction()->get_index()]=1;

			//on passe aux successeur d'abord
			for(int i=0;i<node->get_instruction()->get_nbr_succ();i++){	
				comput_critical_path(node->get_succ(i)->next, false);
			}

			//pour calculer le poids il faut que tous les successeur ai été lu avant
			for(int i=0;i<node->get_instruction()->get_nbr_succ();i++){	
				if(!_read[node->get_succ(i)->next->get_instruction()->get_index()]) end=1;
			}
			
			//si le noeud à été lu ou qu'il n'a pas de successeur on peut compter son poids
			if(!end || node->get_instruction()->get_nbr_succ()==0){				
				for(int i=0;i<node->get_instruction()->get_nbr_succ();i++){
					
					cmpt = node->get_succ(i)->next->get_weight() + node->get_succ(i)->delai;
					if(node->get_weight() < cmpt)
						node->set_weight(cmpt);
				}
			}
			
		}
		it++;

	}
}

list <Node_dfg*> Dfg::no_freezing_cycle(list <Node_dfg*> tmp){
	list <Node_dfg*> tmp1=tmp;
	list<Node_dfg*>::iterator it;
	list<Node_dfg*>::iterator it1;
	Node_dfg* inst, *inst_new_order;
	t_Dep dep;
	int cycle = 0;

	it=tmp1.begin();
	

  	for (int i=0; i<tmp1.size();i++ ){
		inst = *it++;
		it1=new_order.begin();

		//On parcours la nouvelle liste pour calculer s'il y a un cycle de gel entre l'instruction et 
		//les instructions déjà réordonnancé
		for (int j=0; j<new_order.size();j++ ){			
			inst_new_order = *it1++;
			cycle=0;
			dep=inst_new_order->get_instruction()->is_dependant( *inst->get_instruction());

			switch (dep){
				case RAW : cycle= t_delay[inst_new_order->get_instruction()->get_type()][inst->get_instruction()->get_type()]; break;
				case WAW :  cycle=1; break;
				case WAR :  cycle= 1; break;
			}
			cycle= cycle - (new_order.size()-j);
			if(cycle<0)	cycle=0;
// 			cout<<" i"<<inst->get_instruction()->get_index()<<endl;
//  			cout<<" cycle = "<<cycle<<endl;
			
			
			if(cycle != 0) tmp.remove(inst);
		} 
	}

	//si toutes les instructions ont des cycles de gel alors on retourne la liste d'origine
	if(tmp.empty())	return tmp1;
	return tmp;

}

list <Node_dfg*> Dfg::greater_weight(list <Node_dfg*> tmp){

	list <Node_dfg*> tmp1= tmp;
	list<Node_dfg*>::iterator it;
	Node_dfg* inst;
	int biggest = 0;
	it=tmp.begin();
	
	//on parcours la liste pour récupérer le plus gros poids
  	for (int i=0; i<tmp.size();i++ ){
		inst = *it++;
		if(inst->get_weight()> biggest)
			biggest = inst->get_weight();

	} 

			
	it=tmp1.begin();
	
	//on supprime les instructions qui n'ont pas le plus gros poids
// 	cout<<"biggest poids= "<<biggest<<endl;
  	for (int i=0; i<tmp1.size();i++ ){
		inst = *it++;
// 		cout<<" i"<<inst->get_instruction()->get_index()<<endl;
// 		cout<<"poids inst "<<inst->get_weight()<<endl;
		if(inst->get_weight()!= biggest)
			tmp.remove(inst);
		
	} 	
	
	return tmp;
}

list <Node_dfg*> Dfg::more_sucessor(list <Node_dfg*> tmp){
	list<Node_dfg*>::iterator it;
	list <Node_dfg*> tmp1= tmp;
	Node_dfg* inst;
	int biggest = 0;
	it=tmp.begin();

	//on parcours la liste pour récupérer le plus grand nombre de successeur
  	for (int i=0; i<tmp.size();i++ ){
		inst = *it++;
		if(inst->get_nbr_succ()> biggest)
			biggest = inst->get_nbr_succ();

	} 
			
	it=tmp1.begin();

	//on supprime de la liste les instructions qui n'ont pas le plus grand nombre de successeur
// 	cout<<"biggest successor= "<<biggest<<endl;
  	for (int i=0; i<tmp1.size();i++ ){
		inst = *it++;
// 		cout<<" i"<<inst->get_instruction()->get_index()<<endl;
// 		cout<<"succ inst "<<inst->get_nbr_succ()<<endl;
		if(inst->get_nbr_succ()!= biggest)
			tmp.remove(inst);

	} 
	
	
	return tmp;

}

list <Node_dfg*> Dfg::more_descendant(list <Node_dfg*> tmp ){
	list<Node_dfg*>::iterator it;
	list <Node_dfg*> tmp1= tmp;
	Node_dfg* inst;
	int biggest = 0;
	it=tmp.begin();

	//on parcours la liste pour récupérer le plus grand nombre de descendants
  	for (int i=0; i<tmp.size();i++ ){
		inst = *it++;
		if(inst->get_nb_desc()> biggest)
			biggest = inst->get_nb_desc();

	} 
			
	it=tmp1.begin();

	//on supprime de la liste toutes les instructions qui n'ont pas le plus de descendants
// 	cout<<"biggest descendant= "<<biggest<<endl;
  	for (int i=0; i<tmp1.size();i++ ){
		inst = *it++;
// 		cout<<" i"<<inst->get_instruction()->get_index()<<endl;
// 		cout<<"desc inst "<<inst->get_nb_desc()<<endl;
		if(inst->get_nb_desc()!= biggest)
			tmp.remove(inst);

	} 
	
	
	return tmp;
}

list <Node_dfg*> Dfg::longer_latency(list <Node_dfg*> tmp){
	list <Node_dfg*> tmp1=tmp;
	list<Node_dfg*>::iterator it;
	list<Node_dfg*>::iterator it1, it2;
	Node_dfg* inst, *inst_new_order;
	t_Dep dep;
	int cycle = 0, biggest =0;
	int tab[_length];

	//on parcous la nouvelle liste pour calculer la latence entre les instructions déjà réordonnancé
	//et celle de la liste, on récupère celle qui a la plus grosse latence
	it1=new_order.begin();
	for (int j=0; j<new_order.size();j++ ){
		inst_new_order = *it1++;
		biggest=0;
		for(int i=0; i<_length; i++)	tab[i]=0;
		tmp1 = tmp;
		it=tmp1.begin();	
		//cout<<"new order size "<<new_order.size()<<endl;
		for (int i=0; i<tmp1.size();i++ ){
			inst = *it++;
			cycle=0;
			dep=inst_new_order->get_instruction()->is_dependant( *inst->get_instruction());

			switch (dep){
				case RAW : cycle= t_delay[inst_new_order->get_instruction()->get_type()][inst->get_instruction()->get_type()]; break;
				case WAW :  cycle=1; break;
				case WAR :  cycle= 1; break;
			}
			cycle= cycle + ((new_order.size()-j)-1);
			//cout<<" i"<<inst->get_instruction()->get_index()<<endl;
			//cout<<"latency inst "<<cycle<<endl;
			
			if(biggest<=cycle){	
				biggest=cycle;
				tab[inst->get_instruction()->get_index()]=cycle;
			}
		} 

		//cout<<"biggest: "<<biggest<<endl;
		it2=tmp1.begin();
		for(int i=0; i<tmp1.size(); i++){
			inst = *it2++;
			if(tab[inst->get_instruction()->get_index()] != biggest){
				tmp.remove(inst);
			}
		}
	}

	return tmp;
}

list <Node_dfg*> Dfg::original_order(list <Node_dfg*> tmp){

	list <Node_dfg*> tmp1=tmp;
	list<Node_dfg*>::iterator it;
	Node_dfg* inst;
	Node_dfg* first_instr;
	
	/*it=tmp1.begin();
	for (int i=0; i<tmp1.size();i++ ){
		inst = *it++;
		cout<<"instr "<<inst->get_instruction()->get_index()<<"taille de tmp "<<tmp1.size()<<endl;
	} */

	//on récupère l'instruction qui a le plus petit id de la liste
	it=tmp1.begin();
	first_instr = tmp1.front();
	it++;
  	for (int i=1; i<tmp1.size();i++ ){
		inst = *it++;
		
		if(inst->get_instruction()->get_index()<first_instr->get_instruction()->get_index()){
			tmp.remove(first_instr);
			first_instr=inst;
		}
		else	tmp.remove(inst);
	} 

	it=tmp.begin();

  	for (int i=0; i<tmp.size();i++ ){
		inst = *it++;
		//cout<<"instruction: "<<inst->get_instruction()->get_index()<<endl;
	} 
	
	return tmp;
}

//reordonnancement
void Dfg::scheduling(){

	_inst_ready = _head;

	Node_dfg* winner;
	list<Node_dfg*>::iterator it;
	list <Node_dfg*> chosen;


	for(int i=0; i<_length; i++)	_read[i]=0;

	//tant que le liste des instruction prète n'est pas vide
	while(! _inst_ready.empty()){
		chosen = _inst_ready;
		
		//on calcule l'instruction la plus optimal suivant cet ordre de priorité
		chosen = no_freezing_cycle(chosen);
 		chosen = greater_weight(chosen);
 		chosen = more_sucessor(chosen);
 		chosen = more_descendant(chosen);
 		chosen = longer_latency(chosen);
 		chosen = original_order(chosen);

		cout<<"le winner "<<chosen.back()->get_instruction()->get_index()<<endl;
		winner = chosen.back();
		new_order.push_back(winner);
		_inst_ready.remove(winner);

		_read[winner->get_instruction()->get_index()]=1;

		cout<<"nbr de succ de win "<<winner->get_instruction()->get_nbr_succ()<<endl;
		
		//on récupère les successeur de l'instrucion choisi
		for(int i=0;i<winner->get_instruction()->get_nbr_succ();i++){	
			if(!_read[winner->get_succ(i)->next->get_instruction()->get_index()]){
				_read[winner->get_succ(i)->next->get_instruction()->get_index()]=1;
				_inst_ready.push_back(winner->get_succ(i)->next);
			}
		}

		
	}

	it=new_order.begin();
	cout<<"voici le nouvel ordre"<<endl;
  	for (int i=0; i<new_order.size();i++ ){
		winner = *it++;
		cout<<" i"<<winner->get_instruction()->get_index()<<endl;
	} 
	
	cout<<"\n############end#############\n"<<cout;

}


void Dfg::scheduling_BB( Basic_block * BB){

	Node_dfg* winner;
	list<Node_dfg*>::iterator it;
	Node *element= BB->get_head();

	scheduling();

	it=new_order.begin();
	while(element != BB->get_end()->get_next())
	{
		winner = *it;
		
		if(element->get_line()->type_line() == line_Instru){
			element->set_line(winner->get_instruction());
			it++;
		}
		
		if(element->get_next()==BB->get_end()->get_next()){
			break;
		}
		else element = element->get_next();

	}

}