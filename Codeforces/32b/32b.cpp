#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

string transformNumber(string borze) {
	string ret = "";
	for(int i = 0; i < borze.size(); i++) {
		if(borze[i] == '.') {
			ret += "0";
		} else {
			if(borze[i + 1] == '.'){
				ret += "1";
			} else {
				ret += "2";
			}
			i++;
		}
	}
	return  ret;
}

void readInput() {
	char in[500];
	scanf("%s", in);
	printf("%s\n", transformNumber(in).c_str());
}

int main() {
	readInput();
	return 0;
}
