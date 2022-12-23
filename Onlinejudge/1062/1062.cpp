#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

string containersStr;

int stacks[1000000];
int cont;
int size;

void clearData() {
	for(int i = 0; i < size; i++) {
		stacks[i] = 0;
	}
	cont = 0;
	size = 0;
}

void stackContainers() {
	int position = 0; 
	cont = 0;
	for(int i = 0; i < containersStr.size(); i++) {
		position = 0;
		while (position < 1000000) {
			if(stacks[position] == 0) {
				stacks[position] = containersStr[i];
				size = max(size, position + 1);
				break;
			}
			if(containersStr[i] <= stacks[position]) {
				stacks[position] = containersStr[i];
				size = max(size, position + 1);
				break;
			}
			position++;
		}
	}
}

void readData() {
	char input[100000];
	int nCase = 1;
	while (scanf("%s", input) != EOF) {
		containersStr = input;
		if(containersStr == "end") {
			break;
		}
		stackContainers();
		printf("Case %d: %d\n", nCase++, size);
		clearData();
	}
}

int main() {
	readData();
	return 0;
}
