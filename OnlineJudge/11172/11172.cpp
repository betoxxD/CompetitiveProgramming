#include <stdio.h>

int n;

char analiceAlgorithm(int a, int b) {
	return a < b? '<' : a > b ? '>' : '=';
}

void readValues() {
	int a, b;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		printf("%c\n", analiceAlgorithm(a, b));
	}
}

int main() {
	readValues();
	return 0;
}
