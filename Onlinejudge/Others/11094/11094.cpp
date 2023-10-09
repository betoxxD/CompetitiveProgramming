#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<string> localMap;
int x, y;
int n, m;
char continentChar;
int maxi;
int steps;
bool marks[40][40];
bool memo[40][40];

void clearData() {
	localMap.clear();
	maxi = 0;
	steps = 0;
	for(int i = 0; i < 40; i++) {
		for(int j = 0; j < 40; j++){
			marks[i][j] = 0;
			memo[i][j] = 0;
		}
	}
}

void printMap(int lx, int ly) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++){
			if(i == lx && j == ly){
				printf("[%c]", localMap[i][j]);
			} else {
				printf(" %c ", localMap[i][j]);
			}
		}
		printf("\n");
	}
}

void countContinent(int lx, int ly) {
	if(ly >= m) {
		if(localMap[lx][0] == continentChar){
			countContinent(lx, 0);
		}	
		return;
	}
	if(ly < 0) {
		if(localMap[lx][m - 1] == continentChar){
			countContinent(lx, m - 1);
		}
		return;
		
	}
	if(lx >= n) {
		return;
	}
	if(lx < 0) {
		return;
	}
	if(marks[lx][ly]){
		return;
	}
	// printf("x: %d y: %d %c\n",lx, ly, localMap[lx][ly]);
	if(localMap[lx][ly] != continentChar) {
		maxi = max(maxi, steps);
		return;
	}
	if(!memo[lx][ly]){
		steps++;
	}else {
		return;
	}
	// printMap(lx, ly); 
	// printf("%d\n", steps);
	// getchar();

	marks[lx][ly] = 1;
	memo[lx][ly] = 1;
	countContinent(lx + 1, ly);
	countContinent(lx - 1, ly);
	countContinent(lx, ly + 1);
	countContinent(lx, ly - 1);
	marks[lx][ly] = 0;
}

void deleteCurrentContinent(int lx, int ly) {
	if(ly >= m) {
		deleteCurrentContinent(lx, 0);
	}
	if(ly < 0) {
		deleteCurrentContinent(lx, m - 1);
	}
	if(lx >= n) {
		return;
	}
	if(lx < 0) {
		return;
	}
	if(localMap[lx][ly] != continentChar) {
		return;
	}
	localMap[lx][ly]++;
		//printMap(x, y);
		//getchar();

	deleteCurrentContinent(lx + 1, ly);
	deleteCurrentContinent(lx - 1, ly);
	deleteCurrentContinent(lx, ly + 1);
	deleteCurrentContinent(lx, ly - 1);
}

void getContinentChar() {
	continentChar = localMap[x][y];
}

void readInput() {
	char line[200];
	while(scanf("%d%d",&n, &m) != EOF) {
		for(int i = 0; i < n; i++) {
			scanf("%s",line);
			localMap.push_back(line);
		}
		scanf("%d%d",&x, &y);
		getContinentChar();
		
		deleteCurrentContinent(x,y);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(!memo[i][j]){
					if(localMap[i][j] == continentChar){
						steps = 0;
						countContinent(i, j);
					}
				}
			}
		}
		printf("%d\n",maxi);
		clearData();
		scanf("\n");
	}

}

int main() {
	readInput();
	return 0;
}
