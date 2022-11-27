#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

char tablero[10][10];
bool marcas[10][10];
int cantWords;
char word[20];
int wordSize;
int points;
bool isInTablero;
bool wordFound;

void checkIsOnTablero(int x, int y, int wordPos){
	if(x < 0 || x >= 4){
		return;
	}
	if(y < 0 || y >= 4){
		return;
	}
	if(marcas[x][y]){
		return;
	}
	if(word[wordPos] == tablero[x][y]) {
		isInTablero = true;
	} else {
		isInTablero = false;
		return;
	}
	if(wordPos >= wordSize - 1){
		wordFound = true;
		return;
	}
	if(wordFound) {
		return;
	}
	if(isInTablero){
		marcas[x][y] = 1;
		checkIsOnTablero(x - 1, y, wordPos + 1);
		checkIsOnTablero(x - 1, y + 1, wordPos + 1);
		checkIsOnTablero(x, y + 1, wordPos + 1);
		checkIsOnTablero(x + 1, y + 1, wordPos + 1);
		checkIsOnTablero(x + 1, y, wordPos + 1);
		checkIsOnTablero(x + 1, y - 1, wordPos + 1);
		checkIsOnTablero(x, y - 1, wordPos + 1);
		checkIsOnTablero(x - 1, y - 1, wordPos + 1);
		marcas[x][y] = 0;
	}
}

void searchFirstLetter(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(word[0] == tablero[i][j]){
				checkIsOnTablero(i, j, 0);
				if(wordFound){
					break;
				}
			}
			if(wordFound){
				break;
			}
		}
	}
}

int calculatePoints(){
	int points = 0;
	if(wordSize == 3 || wordSize == 4){
		points = 1;
	} else if(wordSize == 5){
		points = 2;
	} else if(wordSize == 6){
		points = 3;
	} else if(wordSize == 7){
		points = 5;
	} else if(wordSize > 7){
		points = 11;
	}
	return points;
}

void initialiceData() {
	for(int i = 0; i < 4; i++){
		scanf("%s", tablero[i]);
	}
	scanf("%d", &cantWords);
}

void countPoints() {
	for(int i = 0; i < cantWords; i++){
		scanf("%s",word);
		wordSize = strlen(word);
		isInTablero = false;
		wordFound = false;
		searchFirstLetter();
		if(wordFound){
			points+= calculatePoints();
		}	
	}
}

int main() {
	initialiceData();
	countPoints();
	printf("%d\n", points);
	return 0;
}
