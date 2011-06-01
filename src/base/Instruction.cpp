#include <Instruction.h>
#include <Enum_type.h>

Instruction::Instruction(string instr, t_Operator oper, t_Format form, t_Inst type, Operand *Op1, Operand *Op2, Operand *Op3, int nbr){

	_line= instr;
	_op= oper;
	_format= form;
	_type= type;
	_op1= Op1;
	_op2= Op2;
	_op3= Op3;
	_nbrOper=nbr;

}

Instruction::Instruction(t_Operator oper, Operand *Op1, Operand *Op2, Operand *Op3){
	_op= oper;
	_op1= Op1;
	_op2= Op2;
	_op3= Op3;
}

Instruction::Instruction(t_Operator oper, Operand *Op1, Operand *Op2){
	_op= oper;
	_op1= Op1;
	_op2= Op2;
	_op3= (Operand*)0;
}

Instruction::Instruction(t_Operator oper, Operand *Op1){
	_op= oper;
	_op1= Op1;
	_op2= (Operand*)0;
	_op3= (Operand*)0;
}

Instruction::Instruction(t_Operator oper){
	_op= oper;
	_op1= (Operand*)0;
	_op2= (Operand*)0;
	_op3= (Operand*)0;
}
Instruction::~Instruction(){}

Operand* Instruction::getOp1(){
return _op1;
}

void Instruction::setOp1(Operand * o){
_op1=o;
}

Operand* Instruction::getOp2(){
return _op2;
}

void Instruction::setOp2(Operand * o){
_op2=o;
}

Operand* Instruction::getOp3(){
return _op3;
}

void Instruction::setOp3(Operand * o){
_op3 =o;
}


t_Operator Instruction::getOPcode(){
return _op;
}

string Instruction::stringOPcode(){
string opString[]={"b","beqz","bnez","beq","bgez","bgezal",
	"bgtz","blez","bltz","bltzal","bne","j",
	"jal","jalr","jr","la","li","loadi",
	"sb","sh","lb","lbu","lh","lhu",
	"lui","lw","lwl","lwr","ll","pref","sw","add",
	"addu","addi","addiu","and","andi","mul",
	"mult","multu","nor","or","ori","srl",
	"srlv","sub","subu","sll","sllv","slt",
	"slti","sltiu","sltu","xor","xori","sra",
	"srav","div","divu","mfhi","mflo","mthi",
	"mtlo","move","neg","negu","nop","break",
	"syscall","mfc0","mtc0","clo","clz","ebase",
	"eepc","eret","madd","maddu","mfc2",
	"movn","movz","msub","msubu","mtc2",
	"sc","sync","tccontext","teq","teqi","tge",
	"tgei","tgeiu","tgeu","tlt","tlti","tltiu",
	"tltu","tne","tnei","wait","rfe"};

return opString[_op];
}


void Instruction::setOPcode(t_Operator newop)
{
	_op = newop;
}



t_Format Instruction::getFormat(){

if(_op1->getOptype()==Lab) _format=J;
else if((_op1->getOptype()==Imm) || (_op2->getOptype()==Lab) || (_op2->getOptype()==Imm) ||(_op3->getOptype()==Lab) || (_op3->getOptype()==Imm))
			_format=I;
else if ((_op1->getOptype()==Reg) && (_op2->getOptype()==Reg) && (_op3->getOptype()==Reg))	_format=R;
else return _format=O;

return _format;
}


string Instruction::stringForm(){
string form[]={"J", "I", "R", "O"};

return form[_format];
}

t_Inst  Instruction::getType(){
if (_op<15) _type= BR;
else if ((14<_op) && (_op<31)) _type= MEM;
else if ((28<_op)&& (_op<61))  _type= ALU;
else _type= OTHER;

return _type;

}

string Instruction::toString(){
return getContent();

}


t_Line Instruction::typeLine(){
return line_Instru;
}

string Instruction::getContent(){


	string rt ;

	rt= stringOPcode()+ " ";

	if(getType()==MEM){
		if (_op1!=NULL){
			rt = rt+ _op1->getOp();
			if (_op2!=NULL){
				if(_op2->getOptype()!=Reg)
					rt = rt+ "," + _op2->getOp();
				else	rt = rt+ ",(" + _op2->getOp()+")";
			}
			
			if(_op3!=NULL && _op2==NULL){
				rt =rt+",("+ _op3->getOp()+")";	
			}
			else if(_op3!=NULL && _op2!=NULL){
				rt =rt+"("+ _op3->getOp()+")";	
			}		
		}
	}
	else{
		if (_op1!=NULL){
			rt = rt+ _op1->getOp();
			if (_op2!=NULL){
				rt = rt+ "," + _op2->getOp();
				if(_op3!=NULL){
					rt =rt+","+ _op3->getOp();
				}
			}
		}
	}	
	return rt;
}

void Instruction::setContent(string line){
_line =line;

}

string Instruction::stringType(){
	string typ[]={"ALU", "MEM", "BR", "OTHER"};
	return typ[_type];
}


bool Instruction::is_dep_RAW(Instruction i2){

	if(getRegDst()!=NULL){
		if(i2.getRegSrc2()!=NULL)
			 if(getRegDst()->getOp().compare(i2.getRegSrc2()->getOp())==0)    return true;		        	
		
		if(i2.getRegSrc1()!=NULL)
		 	if(getRegDst()->getOp().compare(i2.getRegSrc1()->getOp())==0)    return true;
		       	
				

	}
	 
	return false;

}

bool Instruction::is_dep_WAR(Instruction i2){

	if(i2.getRegDst()!=NULL ){

			if(getRegSrc2()!=NULL){
			 	if(getRegSrc2()->getOp().compare(i2.getRegDst()->getOp())==0)    return true;		        	
			}
			if(getRegSrc1()!=NULL){
			 	if(getRegSrc1()->getOp().compare(i2.getRegDst()->getOp())==0)    return true;
		        	
			}			
	}
	
	return false;

}

bool Instruction::is_dep_WAW(Instruction i2){

        if(getRegDst()!=NULL && i2.getRegDst()!=NULL){	
	
            if(getRegDst()->getOp().compare(i2.getRegDst()->getOp())==0)   return true;

          }

	return false;

}

t_Dep Instruction::is_dependant(Instruction i2){


	if(is_dep_RAW(i2)) return RAW;
	if(is_dep_WAR(i2)) return WAR;
	if(is_dep_WAW(i2)) return WAW;
	return NONE;

}

int Instruction::getNumberOper(){
	return _nbrOper;
}

void Instruction::setNumberOper(int nbr){
	_nbrOper=nbr;
}



Operand * Instruction::getRegDst(){
	OPRegister *op1 = dynamic_cast< OPRegister * > (_op1);
	
	if(_op1->getOptype()==Reg && op1->getType() == Dst && _op1!=NULL && _op1->getOp().compare("$0"))
		return _op1;

	return NULL;
}

Operand * Instruction::getRegSrc1(){
	OPRegister *op1 = dynamic_cast< OPRegister * > (_op1);
	OPRegister *op2 = dynamic_cast< OPRegister * > (_op2);
	if(_op1->getOptype()==Reg && op1->getType() == Src && _op1!=NULL && _op1->getOp().compare("$0"))
		return _op1;
	if(_op2->getOptype()==Reg && op2->getType() == Src && _op2!=NULL && _op2->getOp().compare("$0"))
		return _op2;

	return NULL;
}

Operand * Instruction::getRegSrc2(){
	OPRegister *op3 = dynamic_cast< OPRegister * > (_op3);
	OPRegister *op2 = dynamic_cast< OPRegister * > (_op2);
	if(_op2->getOptype()==Reg && op2->getType() == Src && _op2!=NULL && _op2->getOp().compare("$0"))
		return _op2;
	if(_op3->getOptype()==Reg && op3->getType() == Src && _op3!=NULL && _op3->getOp().compare("$0"))
		return _op3;

	return NULL;
}
