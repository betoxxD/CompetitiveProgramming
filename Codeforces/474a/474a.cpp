#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

bool isRight;

string lineOne = "qwertyuiop";
string lineTwo = "asdfghjkl;";
string lineThree = "zxcvbnm,./";
string input;

string result() {
	string result = "";
	bool found = false;
	for(int i = 0; i < input.size(); i++) {
		found = false;
		for(int j = 0; j < lineOne.size(); j++) {
			if(lineOne[j] == input[i]){
				if(isRight) {
					result += lineOne[j - 1];
				} else {
					result += lineOne[j + 1];
				}
				found = true;
				break;
			}
		}
		if(found) {
			continue;
		}
		for(int j = 0; j < lineTwo.size(); j++) {
			if(lineTwo[j] == input[i]){
				if(isRight) {
					result += lineTwo[j - 1];
				} else {
					result += lineTwo[j + 1];
				}
				found = true;
				break;
			}
		}
		if(found) {
			continue;
		}
		for(int j = 0; j < lineThree.size(); j++) {
			if(lineThree[j] == input[i]){
				if(isRight) {
					result += lineThree[j - 1];
				} else {
					result += lineThree[j + 1];
				}
				break;
			}
		}
	}
	return result;
}

void readData() {
	char r; scanf(" %c", &r);
	char in[1000];
	if(r == 'R'){
		isRight = true;
	} else {
		isRight = false;
	}
	scanf("%s", in);
	input = in;
	printf("%s\n", result().c_str());
}

int main() {
	readData();
	return 0;
}
