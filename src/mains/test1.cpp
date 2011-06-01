#include <iostream>
#include <Program.h>
#include <Basic_block.h>
#include <Function.h>


/*
-Affichage des informations generales du programme comme le nombre de
lignes et d'instructions.
-Calcul du decoupage en blocs de base et en fonctions.
-Ecriture dans un fichier des sequences de lignes de ces blocs de base et
fonctions dans des fichiers differents.


*/

int main(){

	remove("tmp/test1.txt");
	remove("tmp/test2.txt");

	Program prog("src/examples/primes.s");
	Function functmp;
	Basic_block BBtmp;
	list <Function> myfunc; 
	list <Basic_block> myBB;

	cout<<"Le programme a "<<prog.size()<<" lignes\n"<<endl;

	cout<<"Contenu du programme:"<<endl;
	prog.display();
	prog.inFile("tmp/retit.txt");

	cout<<"\n Calcul des fonctions des block de base et restitution\n"<<endl;


	prog.comput_Function();
	
	for(int i=0; i<prog.nbr_Func(); i++)
		myfunc.push_back(prog.get_Function(i));

	list<Function>::iterator it;
	list<Basic_block>::iterator it1;
	it=myfunc.begin();

	cout<<"nbrfunc "<<prog.nbr_Func()<<endl;
   	for (int i=0; i<prog.nbr_Func();i++ ){
		functmp= *it;
		functmp.restitution("tmp/test1.txt");
		functmp.comput_basic_block();
		
		
		for(int j=0; j<functmp.nbr_BB(); j++)
			myBB.push_back(functmp.get_BB(j));

		it1=myBB.begin();

		for (int j=0; j<functmp.nbr_BB();j++ ){
			BBtmp= *it1;
			BBtmp.display();
			BBtmp.restitution("tmp/test2.txt");
			cout<<"\n\n"<<endl;
			it1++;
		}
		
		it++;
	}
}
