#include<stdio.h>

void fonct1(){
	int t[10];
	int i;

	for(i=0;i<10;i++){
	t[i]=i;
	}
}


void fonct2(){
	fonct1();
	printf("Bonjour\n");
}

void fonct3(int a){
	fonct2();
	c= a+ fonct4(a);
}

int fonct4(int a){
	return a*100;
}

void fonct5(){
	fonct3(5);

}


void fonct6(){
	fonct5();
}




int main () {
	int i;
	fonct6();
	i = 1 + 1 ;
	return i ;
}
