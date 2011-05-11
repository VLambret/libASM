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
string opString[]={"b", "beqz", "bnez"," beq"," bgez"," bgezal"," bgtz"," blez"," bltz"," bltzal"," bne",
		"j"," jal"," jalr"," jr",
		"la"," li"," loadi"," sb"," sh"," lb"," lbu"," lh"," lhu"," lui"," lw"," lwl"," lwr"," sw",
		"add"," addu"," addi"," addiu"," andu"," andi"," mul"," mult"," multu"," nor"," oru"," ori",
		"srl"," srlv"," sub"," subu"," sll"," sllv"," slt"," slti"," sltiu"," sltu","xoru"," xori",
		"sra"," srav","  div"," divu"," mfhi"," mflo"," mthi"," mtlo",
		"move"," neg"," negu"," nop","breaku"," syscallu","mfc0","mtc0",
		"clo"," clz"," ebase"," eepc"," eret"," ll"," madd"," maddu",
		"mfc2"," movn"," movz"," msub"," msubu"," mtc2","pref"," sc"," syncu",
		"tccontext"," teq"," teqi"," tge","tgei"," tgeiu"," tgeu"," tlt",
			"tlti"," tltiu"," tltu"," tne"," tnei"," waitn","rfe"  };

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
else if ((14<_op) && (_op<29)) _type= MEM;
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
				rt = rt+ "," + _op2->getOp();
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

string Instruction::RAW(Instruction i2){

	 if(_op1->getOptype()==Reg  && _op1->getType() == Dst){
		if((_op1->getOp().compare(i2.getOp1()->getOp())==0) && (i2.getOp1()->getOptype()==Reg) && 
					(i2.getOp1()->getType() == Src)) 
							return "RAW";
		if(i2.getNumberOper()>=2 && i2.getOp2()!=NULL){
            		if((_op1->getOp().compare(i2.getOp2()->getOp())==0) && (i2.getOp2()->getOptype()==Reg) && 
					(i2.getOp2()->getType() == Src)) 
							return "RAW";
		}
                else if(i2.getNumberOper()==3 && i2.getOp3()!=NULL){ 
			if((_op1->getOp().compare(i2.getOp3()->getOp())==0) && (i2.getOp3()->getOptype()==Reg) &&
					(i2.getOp3()->getType() == Src)) 
							return "RAW";
		}
        }
	return "not depedant";

}

string Instruction::WAR(Instruction i2){

	if(i2.getOp1()->getType() == Dst){
		if(getNumberOper()>=2 && _op2->getType() == Src && getOp2()!=NULL){
		 	if((_op2->getOptype()==Reg) && (i2.getOp1()->getOptype()==Reg)){
	            		if(_op2->getOp().compare(i2.getOp1()->getOp())==0 )    return "WAR";
	        	}
		}
		else if(getNumberOper()==3 && _op3->getType() == Dst && getOp1()!=NULL){
	        	if((_op3->getOptype()==Reg) && (i2.getOp1()->getOptype()==Reg)){
	            		if(_op3->getOp().compare(i2.getOp1()->getOp())==0)     return "WAR";
	        	}
		}	
		if( _op1->getType() == Src){
	        	if((_op1->getOptype()==Reg) && (i2.getOp1()->getOptype()==Reg)){
	            		if(_op1->getOp().compare(i2.getOp1()->getOp())==0)     return "WAR";
	        	}
		}
	}
	return "not depedant";

}

string Instruction::WAW(Instruction i2){

	
        if(_op1->getOptype()==Reg){
		if(_op1->getType() == Dst && i2.getOp1()->getType() == Dst)

            if((_op1->getOp().compare(i2.getOp1()->getOp())==0) && (i2.getOp1()->getOptype()==Reg) )   return "WAW";
          }
	return "not depedant";

}

string Instruction::is_dependant(Instruction i2){

	string dep1, dep2, dep3;

        dep1= RAW(i2);
	dep2=WAR(i2);
	dep3=WAW(i2);

	if(dep1.compare("RAW")==0) return dep1;
	if(dep2.compare("WAR")==0) return dep2;
	return dep3;

}


int Instruction::getNumberOper(){
	return _nbrOper;
}

void Instruction::setNumberOper(int nbr){
	_nbrOper=nbr;
}

bool Instruction::isFunction(){
	return false;
}
