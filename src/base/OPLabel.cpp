#include <OPLabel.h>

OPLabel::OPLabel(string op){

    _oper = op;

    }

OPLabel::~OPLabel(){}

 string OPLabel::getOp(){

    return _oper;
    }

t_OpType OPLabel::getOptype(){
   return Lab;
    }


 string OPLabel::toString(){
   return _oper;
    }

 void OPLabel::setOp( string op){
    _oper=op;
    }

