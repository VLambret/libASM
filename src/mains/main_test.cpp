#include <iostream>
#include "OPLabel.h"
#include "OPExpression.h"
#include "OPRegister.h"
#include "OPImmediate.h"

extern void programparse(void) ;

int main(){
	programparse() ;
	//asm_mipsparse() ;
/*
	OPLabel label("Loop");
	OPRegister registr("$5",5);
	OPImmediate imm("10");
	OPExpression expr("16<<Ism");


	cout<<label.getOp()<<endl;
	label.setOp("End");
	cout<<label.getOp()<<endl;
	cout<<label.toString()<<endl;

	cout<<expr.getOp()<<endl;
	expr.setOp("0($4)");
	cout<<expr.getOp()<<endl;
	cout<<expr.toString()<<endl;


	cout<<registr.getOp()<<endl;
	registr.setOp("$4");
	cout<<registr.getOp()<<endl;
	cout<<registr.toString()<<endl;
	cout<<registr.getReg()<<endl;
	registr.setReg(4);
	cout<<registr.getReg()<<endl;

	cout<<imm.getOp()<<endl;
	imm.setOp("12");
	cout<<imm.getOp()<<endl;
	cout<<imm.toString()<<endl;

*/

}