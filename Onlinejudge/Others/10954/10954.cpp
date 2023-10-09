#include <bits/stdc++.h>
#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int> colita;
int cost;

void clearData() {
	while (!colita.empty()) {
		colita.pop();
	}
	cost = 0;
}

void makeSums() {
	int n1,n2, sum;
	while(!colita.empty()) {
		n1 = -colita.top();
		colita.pop();
		n2 = -colita.top();
		colita.pop();
		sum = n1 + n2;
		cost+=sum;
		colita.push(-sum);
		if(colita.size() == 1) {
			break;
		}
	}
}

void readInput() {
	int n  = 1; 
	int in;
	while (n != 0) {
		scanf("%d", &n);
		if(n == 0) {
			break;
		}
		while(n--) {
			scanf("%d", &in);
			colita.push(-in);
			getchar();
		}
		makeSums();
		printf("%d\n", cost);
		clearData();
	}
}

int main() {
	readInput();
	return 0;
}
