#include <stdio.h>
#include <string.h>

char input[150];

void readInput() {
	scanf("%s", input);
}

bool checkUpperAndLower() {
	int upper = 0;
	int lower = 0;
	int size = strlen(input);
	bool mostUpper = false;

	for(int i = 0; i < size; i++) {
		if(input[i] < 'a'){
			upper++;
		} else {
			lower++;
		}
	}
	mostUpper = upper > lower;
	return mostUpper;
}

void transformString( bool upper ) {
	int difference = 'a' - 'A';
	int size = strlen(input);
	if(!upper) {
		for(int i = 0; i < size; i++) {
			if ( input[i] < 'a' ) {
				input[i]+= difference;
			}
		}
	} else {
		for(int i = 0; i < size; i++) {
			if ( input[i] > 'Z' ) {
				input[i]-= difference;
			}
		}
	}
}

int main() {
	readInput();
	bool upper = checkUpperAndLower();
	transformString(upper);
	printf("%s\n", input);
	return 0;
}
