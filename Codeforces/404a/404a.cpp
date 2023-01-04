#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

char board[1000][1000];
bool isX;
char xChar, notXChar;
int n;

void printMatrix() {
	printf("Matrix:\n");
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	getchar();
}

void getNotXChar() {
	bool founded = false;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(board[i][j] != xChar) {
				founded = true;
				notXChar = board[i][j];
				break;
			}
		}
	}
	if(!founded) {
		isX = false;
	}
}

void checkOther() {
	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(board[i][j] != notXChar && board[i][j] != '0'){
				isX = false;
				return;
			}
		}
	}
}

void checkDiagonal() {
	xChar = board[0][0];
	getNotXChar();
	if(!isX) {
		return;
	}
	for(int i = 0; i < n; i++) {
		if(board[i][i] != xChar) {
			isX = false;
			return;
		}
		board[i][i] = '0';
	}
	int cont = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(board[cont][i] != xChar && board[cont][i] != '0') {
			isX = false;
			return;
		}
		board[cont][i] = '0';
		cont++;
	}
}

void readData() {
	isX = true;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", board[i]);
	}
	checkDiagonal();
	if(!isX) {
		printf("NO\n");
		return;
	}
	checkOther();
	if(!isX) {
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main() {
	readData();
	return 0;
}
