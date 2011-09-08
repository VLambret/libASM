#include <iostream>
#include <OPLabel.h>
#include <Program.h>
#include <OPExpression.h>
#include <OPRegister.h>
#include <OPImmediate.h>


int main(){


	int size, i, j ;
	Program p("src/examples/test/test4.s") ;
	p.display() ;
	Line *l, *ligne ;
	Instruction *i1, *i2 ;
	t_Dep t ;
	
	size = p.size() ;
	std::cout << " : " ;
	for (i=0 ; i<size ; i++) {
		std::cout << i << " " ;
	}
	std::cout << std::endl ;
	for (i=0 ; i<size ; i++) {
		l = p.findLine(i) ;
	// std::cout << "Ligne " << i << " : " << l->getContent() << std::endl ;
	i1 = dynamic_cast< Instruction * > (l);
	std::cout << "Ligne " << i << " : ";
	for (j=0 ; j<size ; j++) {
		if (j != i) {
			ligne = p.findLine(j) ;
			i2 = dynamic_cast< Instruction * > (ligne);
			t = i1->is_dependant(*i2);
			if (t == RAW) {
				std::cout << "-RAW" ;
			} else if (t == WAR) {
				std::cout << "-WAR" ;
			} else if (t == WAW) {
				std::cout << "-WAW" ;
			} else {
				std::cout << "none" ;
			}
			} else {
				std::cout << "----" ;

			}
		}
		std::cout << std::endl ;
	}

	// Inversion de 2 instructions
	// dernière instruction à la première place
	p.Exchange_Line(0,size-1) ;

	size = p.size() ;
	std::cout << " : " ;
	for (i=0 ; i<size ; i++) {
		std::cout << i << " " ;
	}
	std::cout << std::endl ;
	for (i=0 ; i<size ; i++) {
		l = p.findLine(i) ;
		// std::cout << "Ligne " << i << " : " << l->getContent() << std::endl ;
		i1 = dynamic_cast< Instruction * > (l);
		std::cout << "Ligne " << i << " : ";
		for (j=0 ; j<size ; j++) {
			if (j != i) {
				ligne = p.findLine(j) ;
				i2 = dynamic_cast< Instruction * > (ligne);
				t = i1->is_dependant(*i2);
				if (t == RAW) {
					std::cout << "-RAW" ;
				} else if (t == WAR) {
					std::cout << "-WAR" ;
				} else if (t == WAW) {
					std::cout << "-WAW" ;
				} else {
					std::cout << "none" ;
				}
			} else {
				std::cout << "----" ;
			}
		}
		std::cout << std::endl ;
	}
	p.inFile("tmp/test4.s") ;
}
