#include <iostream>
#include <OPLabel.h>
#include <Program.h>
#include <OPExpression.h>
#include <OPRegister.h>
#include <OPImmediate.h>


int main(){
	//Program p("src/examples/complete.s") ;
	//p.display() ;
	Program p2("src/examples/complete.s") ;
//	p2.display() ;
	//Program p(f) ;
	//Program p() ;
	// programparse("src/examples/complete.s") ;
	//asm_mipsparse() ;
/*
	OPLabel label("Loop");
	OPRegister registr("$5",5);
	OPImmediate imm("10");
	OPExpression expr("16<<Ism");


	cout<<label.get_op()<<endl;
	label.set_op("End");
	cout<<label.get_op()<<endl;
	cout<<label.to_string()<<endl;

	cout<<expr.get_op()<<endl;
	expr.set_op("0($4)");
	cout<<expr.get_op()<<endl;
	cout<<expr.to_string()<<endl;


	cout<<registr.get_op()<<endl;
	registr.set_op("$4");
	cout<<registr.get_op()<<endl;
	cout<<registr.to_string()<<endl;
	cout<<registr.get_reg()<<endl;
	registr.set_reg(4);
	cout<<registr.get_reg()<<endl;

	cout<<imm.get_op()<<endl;
	imm.set_op("12");
	cout<<imm.get_op()<<endl;
	cout<<imm.to_string()<<endl;

*/

}
