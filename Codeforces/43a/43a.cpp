#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

unordered_map<string, int> goals;

void readData() {
	int n; scanf("%d", &n);
	char in[100];
	string input;
	string teamA = "", teamB = "";
	while (n--) {
		scanf("%s", in);
		input = in;
		if(teamA == "") {
			teamA = input;
		} else if(teamB == "" && input != teamA) {
			teamB = input;
		}
		goals[input]++;
	}
	if(goals[teamA] > goals[teamB]) {
		printf("%s\n", teamA.c_str());
	} else {
		printf("%s\n", teamB.c_str());
	}
}

int main() {
	readData();
	return 0;
}
