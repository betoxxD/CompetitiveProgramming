#include <stdio.h>
#include <string.h>

char cad[100005];

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s",cad);
	int cadSize = strlen(cad);
	int wins=0;
	for(int i = 0; i < cadSize; i++){
		if(cad[i] == 'A'){
			wins++;
		} else {
			wins--;
		}
	}
	if(wins>0){
		printf("Anton");
	} else if(wins < 0){
		printf("Danik");
	} else {
		printf("Friendship");
	}
	return 0;
}
