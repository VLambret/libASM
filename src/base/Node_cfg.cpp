#include <Node_cfg.h>

Node_cfg::Node_cfg(Basic_block* Block){
	_succ1 = NULL;
	_succ2 = NULL;
	_nbr_succ = 0;
	_BB = Block;
}

Node_cfg::~Node_cfg(){}

Node_cfg* Node_cfg::get_succ1(){
	return _succ1;
}

Node_cfg* Node_cfg::get_succ2(){
	return _succ2;
}

int Node_cfg::get_nbr_succ(){
	return _nbr_succ;
}

Basic_block* Node_cfg::get_BB(){
	return _BB;
}

void Node_cfg::set_succ1(Node_cfg *nd){
	_nbr_succ=1;
	_succ1 = nd;
}

void Node_cfg::set_succ2(Node_cfg *nd){
	_nbr_succ = 2;
	_succ2 = nd;
}

void Node_cfg::set_BB(Basic_block* Block){
	_BB = Block;
}

