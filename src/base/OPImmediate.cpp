#include "OPImmediate.h"

OPImmediate::OPImmediate(string op){

    _oper = op;

    }

OPImmediate::~OPImmediate(){}

string OPImmediate::getOp(){

    return _oper;
}


t_OpType OPImmediate::getOptype(){
    return Imm;
}


string OPImmediate::toString(){
    return "Immediate";
}

void OPImmediate::setOp( string op){
    _oper=op;
   }

