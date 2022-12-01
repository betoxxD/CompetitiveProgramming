#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;
int n;
int t;
vector<int> graph[1000000];
bool visited;

void visitGraph(int node){
	if(visited) {
		return;
	}
	if(node == t){
		visited = true;
		return;
	}
	for(int otherNode: graph[node]){
		visitGraph(otherNode);
	}
}

void readInput(){
	int input;
	visited = false;
	scanf("%d%d", &n, &t);
	for(int i = 0; i < n - 1; i++) {
		scanf("%d",&input);
		graph[i + 1].push_back(i + 1 + input);
	}
}

int main(){
	readInput();
	visitGraph(1);
	if (visited) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
