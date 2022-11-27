#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int limN = 10;
vector<int> adj[limN];
bool mark[limN];
int n, m;
int fin;
int mini = 1e9;

void traverse (int nodo, int pasos) {
	if (nodo == fin) {
		mini = min(mini, pasos);
	}
	if(mark[nodo]){
		return;
	}
	mark[nodo] = 1;
	for (int v: adj[nodo]) {
		traverse(v, pasos+1);
	}
	mark[nodo] = 0;
}

int main() {
	cin >> n >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}
	fin = 5;
	traverse(1, 0);
	printf("%d\n", mini);
	return 0;
}
