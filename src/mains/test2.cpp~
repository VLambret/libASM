#include <iostream>
#include <Instruction.h>
#include <Program.h>
#include <Directive.h>
#include <Label.h>
#include <fstream>


int main(){

	Program prog("src/examples/recette.s");
	Operand *Op1,*Op2, *Op3, *Op4, *Op5,*Op6;
	Line *lg1,*lg2,*lg3,*lg4,*lg5,*lg6;
	OPRegister registr("$5",5,Src);
	OPRegister registr0("$5",5,Dst);
	OPRegister registr1("$6",6,Dst);
	OPRegister registr2("$0",0,Src);
	OPRegister registr3("$6",6,Src);
	OPRegister registr4("$4",4,Dst);
	OPRegister registr5("$4",4,Src);
	OPImmediate imm("0xFFFF");

	Directive dir("# Code avec des Nor");

	Op1= &registr;
	Op2= &registr0;
	Op3= &registr1;
	Op4= &registr2;
	Op5= &registr3;
	Op6= &registr4;



	Line *ligne;
	prog.display();
	
	
	prog.delLine(0);
	ligne = prog.findLine(0);

	Instruction *inst = dynamic_cast< Instruction * > (ligne);
	inst->setOPcode(lui);
	inst->setOp1(Op6);
	inst->setOp2(&imm);
	inst->setOp3(NULL);
	inst->setNumberOper(2);
	
	ligne=prog.findLine(1);
	
	Instruction *ins2 = dynamic_cast< Instruction * > (ligne);
	ins2->setOPcode(and_);

	Instruction ins3("ori $4,$4,0xFFFF",ori,R, ALU,Op6,&registr5,&imm,3);
	Instruction ins4("xor $5,$4,$0",xor_,R, ALU,Op1,&registr5,Op4,3);
	Instruction ins5("xor $4,$5,$6",xor_,R, ALU,Op3,&registr5,Op4,3);

	prog.add_Line_at(&ins3,1);
	prog.add_Line_at(&ins4,2);
	prog.add_Line_at(&ins5,3);
	prog.display();


}

