#include <Cfg.h>

Cfg::Cfg(Basic_block * BB, int size){
	_head = BB;
	_length = size;
	_read = new int[size];
	
}

Cfg::~Cfg(){}

Basic_block *Cfg::get_head(){
	return _head;
}

//Donner Null en parametre de la fonction lors de son appel
void Cfg::display(Basic_block *BB){

	//Si on entre dans la fonction pour la première fois le bloc de base  sera la tete du cfg  
	if(BB == NULL)	{
		BB = _head;
		for(int i=0; i<_length; i++)	_read[i]=0;		
	}

	//Si le bloc b'as pas encore été lu (pour eviter les boucle infini)
	if(!_read[BB->get_index()]){
		//On le marque comme lu
		_read[BB->get_index()]=1;
		cout<<"BB"<<BB->get_index()<<endl;
		cout<<"nbr succ"<<BB->get_nbr_succ()<<endl;
		//On affiche ses successeurs s'il en a
		if(BB->get_nbr_succ()){
			cout<<" -> BB"<<BB->get_successor1()->get_index()<<endl;
			
			if(BB->get_nbr_succ()==2){
				cout<<" -> BB"<<BB->get_successor2()->get_index()<<endl;				
			}
			cout<<endl;
			display(BB->get_successor1());
			if(BB->get_nbr_succ()==2)	display(BB->get_successor2());
		}
	}			
}

//Donner Null pour le BB en parametre de la fonction lors de son appel
void Cfg::restitution(Basic_block *BB, string const filename){

	
	ofstream monflux(filename.c_str(), ios::app);
	int test=0, end=0;

	if(monflux){

		if(BB == NULL)	{
			BB = _head;
			for(int i=0; i<_length; i++)	_read[i]=0;
			monflux<<"digraph G1 {"<<endl;		
		}

		if(!_read[BB->get_index()]){
			_read[BB->get_index()]=1;

			//ecriture des successeurs dans le fichier
			if(BB->get_nbr_succ()){
				monflux<<"BB"<<BB->get_index()<<" -> BB"<<BB->get_successor1()->get_index()<<";"<<endl;
				
				if(BB->get_nbr_succ()==2){
					monflux<<"BB"<<BB->get_index()<<" -> BB"<<BB->get_successor2()->get_index()<<";"<<endl;				
				}
				
				monflux.close();
				restitution(BB->get_successor1(), filename);
				if(BB->get_nbr_succ()==2)	restitution(BB->get_successor2(), filename);
			}

			//lecture du fichier pour savoir s'il y a déjà un parenthese de fin
			ifstream fichier(filename.c_str());
    			if(fichier){
       
       				 string ligne;     //Une variable pour stocker les lignes lues
				 while(getline(fichier, ligne))    //Tant qu'on n'est pas a la fin, on lit
        			{	end=0;
					if(!ligne.compare("}"))	end=1;
			        }
    			}
			else
			{
				cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
			}
			
			//si pas de parenthese la rajouter
			if(!end){
				monflux.open(filename.c_str(), ios::app);
				for(int i=0; i<_length; i++)	if(_read[i]==0)	test=1;
					if(!test)	monflux<<"}"<<endl;
				monflux.close();
			}
		}
	}
}
