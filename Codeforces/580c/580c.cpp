#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

int n,m;
bool cats[1000000];
vector<int> tree[1000000];
int visitedRestaurants;
bool imHere[1000000];

void crossTree(int node, int consecutive) {
	//printf("node: %d Consecutive: %d there is cats? %d\n",node, consecutive, cats[node]);
	//getchar();
	if(consecutive > m) {
		return;
	}
	if(imHere[node]) {
		return;
	}
	if(tree[node].empty() || (tree[node].size() == 1 && imHere[tree[node][0]])) {
		visitedRestaurants++;
		//printf("Visited restaurants: %d\n", visitedRestaurants);
		//getchar();
		return;
	}
	imHere[node] = 1;
	for(int nextNode: tree[node]) {
		if(cats[node])
			crossTree(nextNode, consecutive + cats[nextNode]);
		else
			crossTree(nextNode, cats[nextNode]);
	}
	imHere[node] = 0;
}

void readInput() {
	int input, secondInput;
	scanf("%d%d",&n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &input);
		cats[i + 1] = input;
	}
	for(int i = 0; i < n - 1; i++) {
		scanf("%d%d", &input, &secondInput);
		tree[input].push_back(secondInput);
		tree[secondInput].push_back(input);
	}
}

int main() {
	readInput();
	crossTree(1, cats[1]);
	printf("%d\n",visitedRestaurants);
	return 0;
}
