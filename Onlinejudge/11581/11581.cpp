#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int grid[10][10];
int gridCopy[10][10];
int result;

bool checkFinal() {
	for(int i = 0; i < 3; i++) {
		for( int j = 0; j < 3; j++ ) {
			if(grid[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void transform() {
	int sum = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++){
			sum = 0;
			if(i - 1 >= 0) {
				sum+= grid[i - 1][j];
			}
			if(i + 1 < 3) {
				sum+= grid[i + 1][j];
			}
			if(j - 1 >= 0) {
				sum+= grid[i][j - 1];
			}
			if(j + 1 < 3) {
				sum+= grid[i][j + 1];
			}
			gridCopy[i][j] = sum % 2;
		}
	}
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			grid[i][j] = gridCopy[i][j];
		}
	}
}

void printGrid() {
	for(int i = 0; i < 3; i++) {
		for( int j = 0; j < 3; j ++ ) {
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	getchar();
}

void readInput() {
	int n; scanf("%d", &n);
	char in[10];
	getchar();
	while (n--) {
		result = 0;
		for(int i = 0; i < 3; i++){
			scanf("%s", in);
			for(int j = 0; j < 3; j++) {
				grid[i][j] = in[j] - '0';
			}
		}

		while (!checkFinal()) {
			transform();
			//printGrid();
			result++;
		}
		result--;
		printf("%d\n", result);
		getchar();
	}
}

int main() {
	readInput();
	return 0;
}
