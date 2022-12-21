#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int matrix[10][10];

bool checkIfBeauty() {
	if(matrix[0][0] < matrix[0][1] && matrix[0][0] < matrix[1][0] && matrix[1][0] < matrix[1][1] && matrix[0][1] < matrix[1][1]){
		return true;
	}else {
		return false;
	}
}

void permute() {
	int aux;
	for(int i = 0; i < 5; i++) {
		if(checkIfBeauty()) {
			printf("YES\n");
			return;
		}
		aux = matrix[0][0];
		matrix[0][0] = matrix[1][0];
		matrix[1][0] = matrix[1][1];
		matrix[1][1] = matrix[0][1];
		matrix[0][1] = aux;
	}
	printf("NO\n");
}

void readInput() {
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &matrix[0][0], &matrix[0][1]);
		scanf("%d%d", &matrix[1][0], &matrix[1][1]);
		permute();
	}
}

int main() {
	readInput();
	return 0;
}
