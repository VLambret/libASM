#include <iostream>
#include "Instruction.h"
#include "Program.h"
#include "Directive.h"
#include "Label.h"


int main(){

	Program prog;
	Operand *Op1,*Op2, *Op3;
	Line *lg1,*lg2,*lg3;
	OPLabel label("Loop");
	OPRegister registr("$5",5);
	OPRegister registr1("$6",6);
	OPRegister registr2("$7",7);
	OPImmediate imm("10");
	OPExpression expr("16<<Ism");
	Op1= &registr;
	Op2= &registr1;
	Op3= &registr2;
	Directive dir(".ent");
	Label lab("Loop");
	Instruction ins("add $6,$5,$5",add,R, ALU,Op3,Op2,Op1);
	Instruction ins1("add $7,$6,$7",add,R, ALU,Op2,Op3,Op3);
	string tlin[]={"line_Instru","line_Lab","line_Direct"};
	lg1= &dir;
	lg2= &lab;
	lg3= &ins;

	cout<<label.getOp()<<endl;
	label.setOp("End");
	cout<<label.getOp()<<endl;
	cout<<label.toString()<<endl;

	cout<<expr.getOp()<<endl;
	expr.setOp("0($4)");
	cout<<expr.getOp()<<endl;
	cout<<expr.toString()<<endl;


	/*cout<<registr.getOp()<<endl;
	registr.setOp("$4");
	cout<<registr.getOp()<<endl;
	cout<<registr.toString()<<endl;
	cout<<registr.getReg()<<endl;
	registr.setReg(4);
	cout<<registr.getReg()<<endl;*/

	cout<<imm.getOp()<<endl;
	imm.setOp("12");
	cout<<imm.getOp()<<endl;
	cout<<imm.toString()<<endl;

	cout<<"TEST INSTRU"<<endl;
	cout<<ins.getOp1()->getOp()<<endl;
	//ins.setOp1(Op2);
	//cout<<ins.getOp1()->getOp()<<endl;
	cout<<ins.stringOPcode()<<endl;
	ins.setOPcode(sub);
	cout<<ins.stringOPcode()<<endl;
	cout<<ins.stringForm()<<endl;
	cout<<ins.stringType()<<endl;
	cout<<ins.toString()<<endl;
	cout<<ins.getContent()<<endl;
	cout<<tlin[ins.typeLine()]<<endl;
	ins.setContent("j loop");
	cout<<ins.getContent()<<endl;

	cout<<ins.is_dependant(ins1)<<endl;


	cout<<"TEST PROG"<<endl;
	prog.add_position(lg1,0);
	prog.display();
	prog.add_position(lg3,1);
	prog.addLine(lg2);
	prog.display();
	prog.addLine(lg3);
	prog.display();
	cout<<prog.findLine(1)-> getContent()<<"\n"<<endl;

	cout<<"\n\n"<<prog.dependance(ins,ins1)<<"\n"<<endl;
	prog.delLine(3);
	cout<<prog.findLine(2)-> getContent()<<"\n"<<endl;
	prog.display();

	Program prog1 (prog);
	prog1.display();
	prog1.addLine(lg1);
	prog1.display();
	cout<<prog.size()<<endl;

	prog1.inFile("tmp/file.txt");
}
