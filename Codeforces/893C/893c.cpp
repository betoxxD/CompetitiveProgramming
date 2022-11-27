#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

int n, m;

vector<long long> prices;
vector<vector<int>> conections;
long long minimum = 10e10;
bool marks[1000000];

void traverseGraph(int node){
	if(marks[node]){
		return;
	}
	minimum = min(minimum, prices[node - 1]);
	marks[node] = 1;
	for(int anotherNode: conections[node]){
		traverseGraph(anotherNode);
	}
}

long long calculateMinimum(){
	long long mini = 0;
	for(int i = 1; i <= n; i++){
		traverseGraph(i);
		if(minimum != 10e10){
			mini += minimum;
			minimum = 10e10;
		}
	}
	return mini;
}

void readInput(){
	long long price;
	scanf("%d%d",&n, &m);
	for(int i = 0; i < n; i++){
		scanf("%lld",&price);
		prices.push_back(price);
	}
	int a, b;
	conections.resize(n + 10);
	while(m--){
		scanf("%d%d",&a, &b);
		conections[a].push_back(b);
		conections[b].push_back(a);
	}
}

int main(){
	readInput();
	printf("%lld\n",calculateMinimum());
	return 0;
}
