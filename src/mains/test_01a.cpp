#include <iostream>
#include <OPLabel.h>
#include <Program.h>
#include <OPExpression.h>
#include <OPRegister.h>
#include <OPImmediate.h>


int main(){
	Program p2("src/examples/test/test_01a.s") ;
	p2.in_file("tmp/test_01a.s") ;
}
