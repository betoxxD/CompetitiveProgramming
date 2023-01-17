#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

void readInput() {
	char n[1000000]; scanf("%s", n);
	string in = n;
	string rightP = "";
	string leftP = "";
	int lastI;
	for(int i = 0; i < in.size(); i++) {
		if(in[i] == '|'){
			lastI = i+1;
			break;
		}
		leftP += in[i];
	}
	for(int i = lastI; i < in.size(); i++) {
		rightP += in[i]; 
	}
	char n2[1000000]; scanf("%s", n2);
	string in2 = n2;
	for(int i = 0; i < in2.size(); i++) {
		if(leftP.size() < rightP.size()) {
			leftP += in2[i];
		} else {
			rightP += in2[i];
		}
	}
	if(leftP.size() == rightP.size()) {
		printf("%s|%s\n", leftP.c_str(), rightP.c_str());
	} else {
		printf("Impossible\n");
	}
}

int main() {
	readInput();
	return 0;
}
