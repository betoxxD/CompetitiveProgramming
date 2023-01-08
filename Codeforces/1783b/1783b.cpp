#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int matrix[100][100];

void createMatrix(int n) {
	int max = n - 1;
	int min = 1;
	for(int i = 1; i < n; i++) {
		matrix[i - 1][min] = i;
		min += i;
	}
}

void readInput() {
	int n; scanf("%d" ,&n);
	int in;
	while(n--){
		scanf("%d", &in);
	}
}

int main() {
	return 0;
}
