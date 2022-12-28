#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

priority_queue<int> queueueue;
int sizeTower;

void addToTower(int number) {
	if(number == sizeTower) {
		printf("%d", number);
		sizeTower--;
		if(!queueueue.empty()) {
			while(queueueue.top() == sizeTower) {
				printf(" %d", queueueue.top());
				queueueue.pop();
				sizeTower--;
				if(queueueue.empty()) {
					break;
				}
			}
		}
		printf("\n");
	} else {
		queueueue.push(number);
		printf("\n");
	}
}

void readInput() {
	int n; scanf("%d", &n);
	sizeTower = n;
	int in;
	while (n--) {
		scanf("%d", &in);
		addToTower(in);
	}
	if(!queueueue.empty()) {
		while(queueueue.top() == sizeTower) {
			printf(" %d", queueueue.top());
			queueueue.pop();
			sizeTower--;
		}
	}
}

int main() {
	readInput();
	return 0;
}
