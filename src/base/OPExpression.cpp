#include <OPExpression.h>

OPExpression::OPExpression(string op){

    _oper = op;

    }

OPExpression::~OPExpression(){}

string OPExpression::getOp(){

    return _oper;
    }

t_OpType OPExpression::getOptype(){
   return Exp;
    }

string OPExpression::toString(){
    return _oper;
    }

void OPExpression::setOp( string op){
    _oper=op;
    }

