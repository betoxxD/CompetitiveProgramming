#include <stdio.h>
#include <string.h>

char name[200];

void readValues() {
	scanf("%s", name);
}

int rotateLeft(char current, char next) {
	if(next > current){
		return 'z' - 'a' + 1 - next + current;
	} else {
		return current - next;
	}
}

int rotateRight(char current, char next) {
	if(next > current){
		return next - current;
	} else {
		return 'z' - 'a' + 1 - current + next;
	}
}

int correctTurn(char current, char next){
	current = current - 'a' + 1;
	next = next - 'a' + 1;
	int left = rotateLeft(current, next);
	int right = rotateRight(current, next); 
	if(left < right) {
		return left;
	} else {
		return right;
	}
}

int calculateRotation() {
	int rotations = 0;
	char current = 'a';
	int size = strlen(name);
	for (int i = 0; i < size; i++){
		rotations += correctTurn(current, name[i]);
		current = name[i];
	}
	return rotations;
}

int main() {
	readValues();
	printf("%d\n", calculateRotation());
	return 0;
}
