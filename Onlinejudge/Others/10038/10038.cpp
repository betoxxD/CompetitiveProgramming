#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <unistd.h>
#include <vector>

using namespace std;

const char EOL = '\n';
vector<int> integers;
vector<bool> flags;
int n;

bool isJolly(){
	bool joly = true;

	for (int i = 1; i < n; i++){
		if(flags[i] == 0){
			joly = 0;
			break;
		}
	}
	return joly;
}

void getSums(){
	int rest;
	for(int i = 0; i < n; i++){
		rest = abs(integers[i] - integers[i + 1]);
		flags[rest] = 1;
	}
}

void cleanData() {
	int n = 0;
	flags.clear();
	integers.clear();
}

void readInput(){
	int newNumber;
	int m;
	while(scanf("%d", &n) != EOF) {
		m = n;
		flags.resize(m + 5, 0);
		while(m--){
			scanf("%d", &newNumber);
			integers.push_back(newNumber);
		}
		getSums();
		if(isJolly()){
			printf("Jolly\n");
		}else {
			printf("Not jolly\n");
		}
		cleanData();
	}
}

int main() {
	readInput();
	return 0;
}
