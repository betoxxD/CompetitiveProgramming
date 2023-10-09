#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> graph[1000000];
int smallestMartian = 90000;
int scopeMartians;
int currentMartian;
int cases, nMartians;
vector<bool> imHere;
bool memo[1000000];

void clearData() {
	smallestMartian = 90000;
	scopeMartians = 0;
	currentMartian = 0;
	imHere.clear();
	for(int i = 0; i < nMartians + 50; i++){
		graph[i].clear();
		memo[i] = 0;
	}
}

void crossGraph(int node, int quantMartians){
	// printf("Current: %d Martian: %d Count: %d Scope: %d Smallest: %d\n", currentMartian, node,quantMartians, scopeMartians, smallestMartian);
	// getchar();
	memo[node] = 1;
	if(imHere[node]){
		if(quantMartians - 1 > scopeMartians) {
			scopeMartians = quantMartians - 1;
			smallestMartian = currentMartian;
		} else if (quantMartians - 1 == scopeMartians) {
			smallestMartian = min(smallestMartian, currentMartian);
		}
		return;
	}
	
	imHere[node] = 1;
	for(int nextNode: graph[node]){
		crossGraph(nextNode, quantMartians + 1);
	}
	imHere[node] = 0;
	if(quantMartians > scopeMartians) {
		scopeMartians = quantMartians;
		smallestMartian = currentMartian;
	} else if (quantMartians == scopeMartians) {
		smallestMartian = min(smallestMartian, currentMartian);
	}
}

void readInput() {
	int u, v;
	scanf("%d", &cases);
	for(int i = 0; i < cases; i++) {
		scanf("%d", &nMartians);
		for (int j = 0; j < nMartians; j++) {
			scanf("%d%d",&u, &v);
			graph[u].push_back(v);
		}
		imHere.reserve(nMartians + 100);
		for (int j = 0; j < nMartians; j++) {
			currentMartian = j+1;
			if(!memo[j+1])
				crossGraph(j+1, 0);
		}
		printf("Case %d: %d\n", i + 1, smallestMartian);
		clearData();
	}
}

int main(){
	readInput();
	return 0;
}
