#include <stdio.h>
#include <string.h>

char stringA[150], stringB[150];

void getData() {
	scanf("%s", stringA);
	scanf("%s", stringB);
}

void transformLowercase() {
	int diff = 'a' - 'A';
	int size = strlen(stringA);
	for (int i = 0; i < size ; i++ ) {
		if(stringA[i] < 'a'){
			stringA[i]+=diff;
		}
		if(stringB[i] < 'a'){
			stringB[i]+=diff;
		}
	}
}

int compareStrings() {
	int result = 0;
	int size = strlen(stringA);
	for(int i = 0; i < size; i++){
		if(stringA[i] < stringB[i]){
			result = -1;
			break;
		}
		if(stringA[i] > stringB[i]){
			result = 1;
			break;
		}
	}
	return result;
}

int main() {
	getData();
	transformLowercase(); 
	printf("%d",compareStrings());
	return 0;
}
