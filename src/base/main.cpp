#include <iostream>
#include "Instruction.h"
#include "Program.h"
#include "Directive.h"
#include "Label.h"


int main(){

	Program prog;
	Operand *Op1,*Op2, *Op3, *Op4, *Op5;
	Line *lg1,*lg2,*lg3,*lg4,*lg5;
	OPLabel label("Loop");
	OPRegister registr("$5",5,Src);
	OPRegister registr1("$6",6,Dst);
	OPRegister registr2("$7",7,Src);
	OPRegister registr3("$6",6,Src);
	OPImmediate imm("10");
	OPExpression expr("16<<Ism");
	Op1= &registr;
	Op2= &registr1;
	Op3= &registr2;
	Op4= &registr3;
	Op5= &label;
	Directive dir(".ent");
	Directive dir1(".end");
	Label lab("Loop");
	Instruction ins("add $6,$5,$5",add,R, ALU,Op2,Op1,Op1,3);
	Instruction ins1("add $8,$6,$7",add,R, ALU,Op4,Op3,Op3,3);
	Instruction ins5("j Loop",j,J, BR,&label,NULL,NULL,1);
	string tlin[]={"line_Instru","line_Lab","line_Direct"};
	lg1= &dir;
	lg2= &lab;
	lg3= &ins;
	lg4= &dir1;
	lg5= &ins5;

	cout<<label.getOp()<<endl;
	//label.setOp("End");
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
	//ins.setContent("j loop");
	cout<<ins.getContent()<<endl;

	cout<<ins.is_dependant(ins1)<<endl;


	cout<<"TEST PROG"<<endl;
	prog.display();
	prog.add_position(lg1,0);
	prog.display();
	prog.add_position(lg3,1);
	prog.addLine(lg2);
	prog.display();
	prog.addLine(lg3);
	prog.addLine(lg5);
	prog.addLine(lg3);
	prog.addLine(lg4);	
	prog.display();
	cout<<prog.findLine(1)-> getContent()<<"\n"<<endl;

	prog.dependance(ins,ins1);
	//prog.delLine(3);
	//cout<<prog.findLine(2)-> getContent()<<"\n"<<endl;
	prog.display();

	/*cout<<"\n TEST Copie"<<endl;
	Program prog1 (prog);
	prog1.display();
	prog1.addLine(lg1);
	prog1.display();
	cout<<prog.size()<<endl;

	prog1.inFile("file.txt");*/


	cout<<"\n TEST OPTION"<<endl;
	prog.calculate_Function();
	prog.get_Function(0).display();
	cout<<"\n";
	/*cout<<*/prog.get_Function(0).calculate_basic_block();//<<endl;
	//prog.get_Function(0).get_BB(0).display();
	






}
