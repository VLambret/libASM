#include <iostream>
#include <OPLabel.h>
#include <Program.h>
#include <OPExpression.h>
#include <OPRegister.h>
#include <OPImmediate.h>


int main(){
	Program p2("src/examples/primes.s") ;
	p2.in_file("tmp/primes.s") ;
}
