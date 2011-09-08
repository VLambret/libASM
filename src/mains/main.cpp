#include <iostream>
#include <Instruction.h>
#include <Program.h>
#include <Directive.h>
#include <Label.h>
#include <fstream>


int main(){

	Program prog;
	Operand *Op1,*Op2, *Op3, *Op4, *Op5;
	Line *lg1,*lg2,*lg3,*lg4,*lg5,*lg6;
	OPLabel label("Loop");
	OPRegister registr("$5",5,Src);
	OPRegister registr1("$6",6,Dst);
	OPRegister registr2("$7",7,Src);
	OPRegister registr3("$6",6,Src);
	OPImmediate imm("43");
	OPExpression expr("16<<Ism");
	Op1= &registr;
	Op2= &registr1;
	Op3= &registr2;
	Op4= &registr3;
	Op5= &label;
	Directive dir(".ent");
	Directive dir1(".end");
	Label lab("Loop");
	Instruction ins("sw $5,43($6)",sw,I, MEM,Op2,NULL,Op2,3);
	Instruction ins1("add $8,$6,$7",add,R, ALU,Op4,Op3,Op3,3);
	Instruction ins5("j Loop",j,J, BR,&label,NULL,NULL,1);
	string tlin[]={"line_Instru","line_Lab","line_Direct"};
	lg1= &dir;
	lg2= &lab;
	lg3= &ins;
	lg4= &dir1;
	lg5= &ins5;
	lg6= &ins1;

	cout<<label.get_op()<<endl;
	//label.set_op("End");
	cout<<label.get_op()<<endl;
	cout<<label.to_string()<<endl;

	cout<<expr.get_op()<<endl;
	expr.set_op("0($4)");
	cout<<expr.get_op()<<endl;
	cout<<expr.to_string()<<endl;


	/*cout<<registr.get_op()<<endl;
	registr.set_op("$4");
	cout<<registr.get_op()<<endl;
	cout<<registr.to_string()<<endl;
	cout<<registr.get_reg()<<endl;
	registr.set_reg(4);
	cout<<registr.get_reg()<<endl;*/

	cout<<imm.get_op()<<endl;
	imm.set_op("12");
	cout<<imm.get_op()<<endl;
	cout<<imm.to_string()<<endl;

	cout<<"TEST INSTRU"<<endl;
	cout<<ins.get_op1()->get_op()<<endl;
	//ins.set_op1(Op2);
	//cout<<ins.get_op1()->get_op()<<endl;
	cout<<ins.string_opcode()<<endl;
	//ins.set_opcode(sub);
	cout<<ins.string_opcode()<<endl;
	cout<<ins.string_form()<<endl;
	cout<<ins.string_type()<<endl;
	cout<<ins.to_string()<<endl;
	cout<<ins.get_content()<<endl;
	cout<<tlin[ins.type_line()]<<endl;
	//ins.set_content("j loop");
	cout<<ins.get_content()<<endl;

	cout<<ins.is_dependant(ins1)<<endl;


	cout<<"TEST PROG"<<endl;
	prog.display();
	prog.add_line_at(lg1,0);
	prog.display();
	prog.add_line_at(lg2,1);
	prog.add_line(lg3);
	prog.display();
	prog.add_line(lg6);
	prog.add_line(lg5);
	prog.add_line(lg3);
	prog.add_line(lg4);	
	prog.display();
	cout<<prog.find_line(1)-> get_content()<<"\n"<<endl;

	prog.dependance(ins,ins1);
	//prog.del_line(3);
	//cout<<prog.find_line(2)-> get_content()<<"\n"<<endl;
	prog.display();

	/*cout<<"\n TEST Copie"<<endl;
	Program prog1 (prog);
	prog1.display();
	prog1.add_line(lg1);
	prog1.display();
	cout<<prog.size()<<endl;

	prog1.inFile("src/examples/file.txt");*/

	Function unc;
	Basic_block bb;
	cout<<"\n TEST OPTION"<<endl;
	prog.comput_function();
	prog.get_function(0).display();
	cout<<prog.nbr_func()<<endl;
	cout<<"\n";
	/*cout<<*/
	unc=prog.get_function(0);
	unc.display();
	cout<<unc.size()<<endl;
	unc.restitution("./tmp/ex1.txt");
	unc.comput_basic_block();
	bb=*unc.get_BB(0);
	cout<<endl;
	bb.get_head();
	bb.display();
	bb.restitution("./tmp/ex12.txt");
	cout<<endl;

	prog.flush();
	cout<<"affichage du prog après vidage"<<endl;
	prog.display();

}
