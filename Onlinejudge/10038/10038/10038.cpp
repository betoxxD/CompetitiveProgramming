#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

vector<bool> appears;
vector<int> numbers;
int n;

void clearData() {
	appears.clear();
	numbers.clear();
	n = 0;
}

void makeDiferences() {
	int difference;
	for(int i = 0; i < n - 1; i++) {
		difference = abs(numbers[i] - numbers[i + 1]);
		appears[difference] = 1;
	}
}

bool checkIfJolly() {
	bool isJolly = true;
	for(int i = 1; i < n; i++) {
		if(!appears[i]) {
			isJolly = false;
			break;
		}
	}
	return isJolly;
}

void readInput() {
	int input;
	while(scanf("%d",&n) != EOF) {
		for( int i = 0; i < n; i++ ) {
			scanf("%d", &input);
			numbers.push_back(input);
		}
		makeDiferences();
		if(checkIfJolly()) {
			printf("Jolly\n");
		} else {
			printf("Not jolly\n");
		}
		clearData();
	}
}

int main() {
	appears.reserve(4000);
	readInput();
	return 0;
}
