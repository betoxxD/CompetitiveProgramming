#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> matrix[1000005];
vector<int> positions[1000005];
int readPosition[1000005];

int globalN;

void clearData(int size) {
	for(int i = 0; i < globalN; i++) {
		matrix[i].clear();
		positions[i].clear();
		readPosition[i] = 0;
	}
}

void readInput() {
	int n, m;
	int cant,input, position = 1, size, readedPos;
	while (scanf("%d", &n) != EOF) {
		globalN = n;
		position = 1;
		scanf("%d", &m);
		printf("%d %d\n", m, n);
		while(n--) {
			scanf("%d", &cant);
			if(cant == 0) {
				getchar();
			}
	
			for(int i = 0; i < cant; i++) {
				scanf("%d", &readedPos);
				readPosition[i] = readedPos;
			}
			for(int i = 0; i < cant; i++) {
				scanf("%d", &input);
				matrix[readPosition[i]].push_back(input);
				positions[readPosition[i]].push_back(position);
			}
			position++;
			for(int i = 0; i < cant; i++) {
				readPosition[i] = 0;
			}
		}
		for (int i = 1; i <= m; i++) {
			size = positions[i].size();
			printf("%d", size);	
			for(int number : positions[i]) {
				printf(" %d", number);
			}
			printf("\n");
			for(int j = 0; j < size; j++) {
				printf("%d", matrix[i][j]);
				if(j < size - 1) {
					printf(" ");
				}
			}
			printf("\n");
		}
		clearData(m);
	}
}

int main() {
	readInput();
	 return 0;
}
