#include <OPImmediate.h>
#include <sstream>

OPImmediate::OPImmediate(string op){
    _oper = op;
}

OPImmediate::OPImmediate(int imm){
	std::ostringstream oss ;
	oss << imm ;
    _oper = oss.str() ;
}

OPImmediate::~OPImmediate(){}

string OPImmediate::getOp(){

    return _oper;
}


t_OpType OPImmediate::getOptype(){
    return Imm;
}


string OPImmediate::toString(){
    return _oper;
}

void OPImmediate::setOp( string op){
    _oper=op;
   }
t_Src_Dst OPImmediate::getType( ){
	return Src;
}
