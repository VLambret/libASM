
int is_prim_num(int num, int *list_prim) {
	int i;

	for(i=2;i<(num/2)+1;i++) {
		list_prim++;
		if(num%i==0) {
			return 0;
		}
	}
	return 1;
}

int main (void) {
	int *prim_num ;
	int i ;
	int found ;

	found = 0 ; 
	*prim_num = 1 ;
	for (i = 0 ; i < 20 ; i++) {
		if(is_prim_num(i,prim_num)) {
			found ++ ;
		}
	}
	return found ;
}
