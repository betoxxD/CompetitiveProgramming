#include <stdio.h>

int n, boxes[150];

void scanValues() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d",&boxes[i]);
	}
}

void aplyGravity() {
	int aux;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(boxes[i] < boxes[j]) {
				aux = boxes[i];
				boxes[i] = boxes[j];
				boxes[j] = aux;
			}
		}
	}
}

void printResult() {
	for (int i = 0; i < n; i++) {
		printf("%d ",boxes[i]);
	}
}

int main() {
	scanValues();
	aplyGravity();
	printResult();
	return 0;
}
