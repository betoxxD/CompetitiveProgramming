#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <set>

using namespace std;

multiset<long long> structure;
long long cost;

void clearData() {
	while (!structure.empty()) {
		structure.erase(structure.begin());
	}
	structure.clear();
	cost = 0;
}

void makeCalculus() {
	int maxNumber, minNumber;
	if(structure.size() >= 2) {
		minNumber = *(structure.begin()); 
		maxNumber = *(prev(structure.end()));
		cost += maxNumber - minNumber;
		if(!structure.empty()) {
			structure.erase(prev(structure.end()));
		}
		if(!structure.empty()) {
			structure.erase(structure.begin());
		}
	}
}

void readData() {
	int n,m;
	long long in;
	while (scanf("%d", &n) != EOF) {
		if(n == 0) {
			break;
		}
		while (n--) {
			scanf("%d", &m);
			while (m--) {
				scanf("%lld", &in);
				structure.insert(in);
			}
			makeCalculus();
		}
		printf("%lld\n", cost);
		clearData();
	}
}

int main() {
	readData();
	return 0;
}
