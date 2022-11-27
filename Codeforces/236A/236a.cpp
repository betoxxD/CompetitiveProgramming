#include <stdio.h>
#include <string.h>

char cad[150];
int bucket[300];

void readValues() {
	scanf("%s", cad);
}

int countCharacters() {
	int size = strlen(cad);
	int cont = 0;
	for(int i = 0; i < size; i++){
		bucket[cad[i]]++;
	}
	for(int i = 0; i < 150; i++){
		if(bucket[i] != 0){
			cont++;
		}
	}
	return cont;
}

void getResult(int characters) {
	if(characters % 2 == 0){
		printf("CHAT WITH HER!");
	} else {
		printf("IGNORE HIM!");
	}
}

int main() {
	readValues();
	int diferent = countCharacters();
	getResult(diferent);
	return 0;
}
