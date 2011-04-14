#include "Instruction.h"


Instruction::Instruction(string instr, t_Operator oper, t_Format form, t_Inst type, Operand *Op1, Operand *Op2, Operand *Op3){
	
	_line= instr;
	_op= oper;
	_format= form;
	_type= type;
	_op1= Op1;
	_op2= Op2;
	_op3= Op3;
	
}

Instruction::~Instruction(){}

Operand* Instruction::getOp1(){	
	return _op1;
	//return NULL;
}

void Instruction::setOp1(Operand * o){
	_op1=o;
}

Operand* Instruction::getOp2(){	
	return _op2;
	//return NULL;
}

void Instruction::setOp2(Operand * o){
	_op2=o;
}

Operand* Instruction::getOp3(){	
	return _op3;
	//return NULL;
}

void Instruction::setOp3(Operand * o){
	_op3 =o;
}	


t_Operator Instruction::getOPcode(){
	return _op;
}

	
void Instruction::setOPcode(t_Operator newop)
{
	_op = newop;
}



t_Format Instruction::getFormat(){

	if(_op1->getOptype()==Lab) return J;
	else if((_op1->getOptype()==Imm) || (_op2->getOptype()==Lab) || (_op2->getOptype()==Imm) ||(_op3->getOptype()==Lab) || (_op3->getOptype()==Imm))
				return I;
	else if ((_op1->getOptype()==Reg) && (_op2->getOptype()==Reg) && (_op3->getOptype()==Reg))	return R;
	else return O;
}


t_Inst  Instruction::getType(){
	if (_op<15) return BR;
	else if ((14<_op) && (_op<29)) return MEM;
	else if ((28<_op)&& (_op<61))  return ALU;
	else return OTHER;
	
}

string Instruction::toString(){
	return "Instruction";

}


t_Line Instruction::typeLine(){
	return line_Instru;
}

string Instruction::getContent(){

	string tmp,tmp1;
	tmp= opString[_op]+ " ";
	tmp= tmp+ _op1->getOp();
	if (_op2!=NULL){
		tmp= tmp+ ",";
		tmp =tmp+ _op2->getOp();
	}
	if(_op3!=NULL){	
		tmp= tmp+ ",";
		tmp =tmp1+ _op3->getOp();
	}
	return tmp;

}

void Instruction::setContent(string line){
	_line =line;
}
