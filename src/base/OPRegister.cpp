#include <OPRegister.h>
#include <sstream>


OPRegister::OPRegister(string op, t_Src_Dst ty){

    _oper = op;
    _type = ty;
}

OPRegister::OPRegister(string op, int reg, t_Src_Dst ty){

    _oper = op;
    _reg = reg;
    _type = ty;

    }

OPRegister::OPRegister(int reg, t_Src_Dst ty){
	std::ostringstream oss ;
	oss << "$" << reg ;
    _oper = oss.str() ;
    _reg = reg;
    _type = ty;

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
   return _oper;
}

void OPRegister::setOp( string op){
    _oper=op;
}

t_Src_Dst OPRegister::getType( ){
	return _type;
}

void OPRegister::setType(t_Src_Dst ty){
	_type=ty;
}

