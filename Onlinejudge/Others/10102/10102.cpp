#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

vector<pair<int, int>> ones;
vector<pair<int, int>> threes;

int n;

int x, y;
int minimum = 0;
bool nextOne;

void findNextMini(pair<int, int> one) {
	int mini = 10e8;
	int sum;
	for(pair<int, int> three : threes) {
		sum = 0;
		sum += abs(one.first - three.first);
		sum += abs(one.second - three.second);
		mini = min(sum, mini);
	}
	minimum = max(minimum, mini);
}

void readInput() {
	char in;
	while (scanf("%d", &n) != EOF) {
		nextOne = false;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				scanf(" %c", &in);
				if(in == '1') {
					ones.push_back(pair<int, int>(i,j));
				} else if(in == '3') {
					threes.push_back(pair<int, int>(i,j));
				}
			}
		}
		for(pair<int, int> one : ones) {
			findNextMini(one);
		}
		printf("%d\n", minimum);
		ones.clear();
		threes.clear();
		minimum = 0;
	}
}

int main() {
	readInput();
	return 0;
}
