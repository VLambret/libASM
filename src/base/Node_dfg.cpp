#include <Node_dfg.h>

Node_dfg::Node_dfg(Instruction* i1 ){
	_inst =i1;
	_nbr_descendant=0;
	_poids = 0;
}

Node_dfg::~Node_dfg(){
}

Arc *Node_dfg::get_succ(int index){

	list<Arc*>::iterator it;
	it=_arc.begin();

  	if(index< _arc.size()){
  		for (int i=0; i<index;i++ ) it++;
		return *it;	
	}
	else cout<<"Error: index is bigger than the size of the list"<<endl; 
	
	return _arc.back();

}

int Node_dfg::get_nbr_succ(){
	//_arc.size();
	_inst->get_nbr_succ();
}

Instruction *Node_dfg::get_instruction(){
	return _inst;
}

void Node_dfg::set_succ(Arc* u){
	_arc.push_back( u);
}

void Node_dfg::set_instruction( Instruction* i1){
	_inst = i1;
}

void Node_dfg::set_weight( int w ){
	_poids = w;
}

int Node_dfg::get_weight( ){
	return _poids;
}

void Node_dfg::set_descendant(int descent){
	_nbr_descendant=descent;
}

int Node_dfg::get_nb_desc(){
	//return _nbr_descendant;
	return _desc.size();
}

void Node_dfg::set_desc(int d){
	_desc.push_back(d);
	_desc.sort();
	_desc.unique();
}

int Node_dfg::get_desc(int index){

	list<int>::iterator it;
	it=_desc.begin();

  	if(index< _desc.size()){
  		for (int i=0; i<index;i++ ) it++;
		return *it;	
	}
	else cout<<"Error: index is bigger than the size of the list"<<endl; 
	
	return _desc.back();
}