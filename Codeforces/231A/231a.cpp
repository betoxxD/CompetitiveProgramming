#include <stdio.h>


int main(){
	int n, input, cont, problems = 0;
	scanf("%d",&n);
	for(int i= 0; i<n; i++){
		cont = 0;
		for(int j = 0; j < 3; j++){
			scanf("%d",&input);
			cont+=input;
		}
		if(cont >1){
			problems++;
		}
	}
	printf("%d",problems);
	return 0;
}
