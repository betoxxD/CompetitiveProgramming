#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

vector<char> graph[1000000];
vector<char> nodes;

bool imHere[1000000];
bool passed[1000000];
bool isTree;
int trees;
int acorns;

void clearData() {
	for(char node: nodes) {
		graph[node].clear();
		imHere[node] = 0;
		passed[node] = 0;
	}
	nodes.clear();
	isTree = false;
	trees = 0;
	acorns = 0;
}

void checkTree(char node, int numNodes) {
	if(imHere[node]) {
		return;
	}
	if(numNodes > 1) {
		isTree = true;
	}
	passed[node] = 1;

	imHere[node] = 1;
	for(char nextNode: graph[node]) {
		checkTree(nextNode, numNodes + 1);
	}
	imHere[node] = 0;
}

void countForest() {
	for(char node: nodes){
		if(passed[node]){
			continue;
		}
		isTree = false;
		checkTree(node, 1);
		if(isTree) {
			trees++;
		} else {
			acorns++;
		}
	}
}

void readInput() {
	int n; scanf("%d", &n);
	char node1, node2;
	char input;
	getchar();
	char in[100000];
	while (n--) {
		while(fgets(in, sizeof(in), stdin) != NULL) {
			if(in[0] == '*') {
				break;
			}
			sscanf(in, "( %c, %c)", &node1, &node2);
			graph[node1].push_back(node2);
			graph[node2].push_back(node1);
		}
		fgets(in, sizeof(in), stdin);
		for(int i = 0; i < strlen(in); i+=2) {
			nodes.push_back(in[i]);
		}
		countForest();
		printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
		clearData();
	}
}

int main() {
	readInput();
	return 0;
}
