#include <stdio.h>

int n;
char stones[100];

void readData(){
	scanf("%d", &n);
	scanf("%s", stones);
}

int countStones() {
	char current = stones[0];
	int cont = 0;
	for(int i = 1; i < n; i++){
		if(current == stones[i]){
			cont++;
		}
		current = stones[i];
	}
	return cont;
}

int main(){
	readData();
	printf("%d\n",countStones());
	return 0;
}
