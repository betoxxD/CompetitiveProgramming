#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> positions[1000005];

void clearData() {
	for(int i = 0; i < 1000005; i++) {
		positions[i].clear();
	}
}

int searchPosition(int a, int b) {
	a--;
	if(a >= positions[b].size()) {
		return 0;
	}
	return positions[b][a];
}

void readInput() {
	int n, m;
	int input;
	int a, b;
	while (scanf("%d", &n) != EOF) {
		scanf("%d", &m);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &input);
			positions[input].push_back(i);
		}
		while(m--) {
			scanf("%d%d",&a, &b);
			printf("%d\n", searchPosition(a, b));
		}
		clearData();
	}
}

int main() {
	readInput();
	return 0;
}
