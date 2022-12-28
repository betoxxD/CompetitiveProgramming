#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> numbers;
unordered_map<int, int> packet;
int cont;
int maxi;

void clearData() {
	cont = 0;
	maxi = 0;
	packet.clear();
	numbers.clear();
}

void addPacket() {
	for( int i = 0; i < numbers.size(); i++ ){
		if(packet[numbers[i]] != 0) {
			packet.clear();
			maxi = max(maxi, cont);
			cont = 1;
		} else {
			cont++;
			maxi = max(maxi, cont);
		}
		packet[numbers[i]]++;
	}
	packet.clear();
	cont = 0;
	for(int i = numbers.size() - 1; i >= 0; i-- ) {
		if(packet[numbers[i]] != 0) {
			packet.clear();
			maxi = max(maxi, cont);
			cont = 1;
		} else {
			cont++;
			maxi = max(maxi, cont);
		}
		packet[numbers[i]]++;
	}
}


void readInput() {
	int n; scanf("%d", &n);
	int m;
	int input;
	while (n--) {
		scanf("%d", &m);
		while (m--) {
			scanf("%d", &input);
			numbers.push_back(input);
		}
		addPacket();
		printf("%d\n", maxi);
		clearData();
	}
}

int main() {
	readInput();
	return 0;
}
