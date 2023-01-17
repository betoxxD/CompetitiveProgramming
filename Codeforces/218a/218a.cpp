#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> numbers;

void readInput() {
	int n, k; scanf("%d%d", &n, &k);
	n = 2*n  + 1; 
	int in;
	for(int i = 0; i < n; i++) {
		scanf("%d", &in);
		numbers.push_back(in);
	}
	for(int i = 0; i < n; i++) {
		if(k <= 0 ){
			break;
		}
		if(i == 0) {
			if(numbers[i] > numbers[i + 1]) {
				k--;
				numbers[i]--;
			}
		} else {
			if (i < numbers.size() - 1 && numbers[i - 1] < numbers[i] - 1 && numbers[i] - 1 > numbers[i + 1]) {
				numbers[i]--;
				k--;
			}
		}
	}
	if(k != 0) {
		if(numbers[numbers.size() - 1] - 1 > numbers[numbers.size() - 2]) {
			k--;
			numbers[numbers.size() - 1]--;
		}
	}
	for(int number: numbers) {
		printf("%d ", number);
	}
}

int main() {
	readInput();
	return 0;
}
