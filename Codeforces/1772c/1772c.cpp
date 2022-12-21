#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int k, maxSize; 
int maxArray[100000];
int maxi = 0;

void searchMax(int cant, int number, int increment) {
	if(cant >= k) {
		return;
	}
	if(number > maxSize) {
		return;
	}
	if(increment <= 0) {
		return;
	}
	printf("pos: %d number: %d increment: %d\n", cant, number, increment);
	getchar();
	if(number <= maxSize && number > maxArray[cant - 1] && number > maxArray[cant]) {
		maxArray[cant] = number;
	}
	searchMax(cant + 1, number + increment, increment + 1);
	searchMax(cant + 1, number + increment, increment - 1);
}

void readInput() {
	int n; scanf("%d",&n);
	while (n--) {
		scanf("%d%d", &k, &maxSize);
		searchMax(0, 1, 1);
		for( int i = 0; i < k; i++) {
			printf("%d ", maxArray[i]);
		}
		printf("\n");
		maxi = 0;
		for(int i = 0; i < k; i++) {
			maxArray[i] = 0;
		}
	}
}

int main() {
	readInput();
	return 0;
}
