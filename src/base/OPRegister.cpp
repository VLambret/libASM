#include "OPRegister.h"


OPRegister::OPRegister(string op){

    _oper = op;
}

OPRegister::OPRegister(string op, int reg){

    _oper = op;
    _reg = reg;

    }

OPRegister::~OPRegister(){}


int OPRegister::getReg(){
    return _reg;
    }


void OPRegister::setReg( int reg){
    _reg= reg;
    }

string OPRegister::getOp(){
    return _oper;
}

t_OpType OPRegister::getOptype(){
    return Reg;
}

string OPRegister::toString(){
   return "Register";
}

void OPRegister::setOp( string op){
    _oper=op;
}
