#include <bits/stdc++.h>
#include <cstdio>
#include <unordered_map>

using namespace std;

int cont;

unordered_map<int, int> jackCds;

void clearData() {
	jackCds.clear();
	cont = 0;
}

void checkIfExist( int cd ) {
	if(jackCds[cd] > 0) {
		jackCds[cd]--;
		cont++;
	}
}

void readInput() {
	int cd;
	int n = 1,m = 1;
	while (n != 0 || m != 0) {
		scanf("%d%d", &n, &m);
		if(n == 0 && m == 0) {
			return;
		}
		while (n--) {
			scanf("%d", &cd);
			jackCds[cd]++;
		}
		while (m--) {
			scanf("%d", &cd);		
			checkIfExist(cd);
		}
		printf("%d\n", cont);
		clearData();
	}
}

int main() {
	readInput();
	return 0;
}
