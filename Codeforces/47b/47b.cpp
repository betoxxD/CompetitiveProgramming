#include <algorithm>
#include <bits/stdc++.h>
#include <cerrno>
#include <cstdio>
#include <unordered_map>

using namespace std;

int a, b, c;

vector<pair<char, int>> coins;

bool customOrder(pair<char, int> p1, pair<char, int> p2) {
	return p1.second < p2.second;
}

void readInput() {
	char in[10];
	for(int i = 0; i < 3; i++) {
		scanf("%s", in);
		if((in[0] == 'A' && in[1] == '>') || (in[2] == 'A' && in[1] == '<')) {
			a++;
		} else if((in[0] == 'B' && in[1] == '>') || (in[2] == 'B' && in[1] == '<')) {
			b++;
		} else if((in[0] == 'C' && in[1] == '>') || (in[2] == 'C' && in[1] == '<')) {
			c++;
		}
	}
	coins.push_back(pair<char, int>('A', a));
	coins.push_back(pair<char, int>('B', b));
	coins.push_back(pair<char, int>('C', c));
	if(a == b || a == c || b == c) {
		printf("Impossible\n");
	} else {
		sort(coins.begin(), coins.end(), customOrder);
		for(pair<char, int> coin : coins) {
			printf("%c", coin.first);
		}
		printf("\n");
	}
}

int main() {
	readInput();
	return 0;
}
