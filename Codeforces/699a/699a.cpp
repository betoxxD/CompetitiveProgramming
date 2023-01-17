#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

vector<long long> goLeft;
vector<long long> goRight;

void readInput() {
	int n; scanf("%d", &n);
	char str[300000]; scanf("%s", str);
	long long in;
	string nStr = str;
	long long collision = 10e11;
	for(int i = 0; i < n; i++){
		scanf("%lld", &in);
		if(nStr[i] == 'L') {
			goLeft.push_back(in);
		} else {
			goRight.push_back(in);
		}
	}
	if(goLeft.size() > goRight.size()){
		for( int i = 0; i < goLeft.size(); i++ ) {
			for(int j = 0; j < goRight.size(); j++) {
				if(goLeft[i] > goRight[j]) {
					if((goLeft[i] - goRight[j]) % 2 == 0){
						collision = min(collision, (goLeft[i] - goRight[j]) / 2);
					}
				} else {
					break;
				}
			}
		}
	} else {
		for( int i = 0; i < goRight.size(); i++ ) {
			for(int j = 0; j < goLeft.size(); j++) {
				if(goLeft[i] > goRight[j]) {
					if((goLeft[i] - goRight[j]) % 2 == 0){
						collision = min(collision, (goLeft[i] - goRight[j]) / 2);
					}
				} else {
					break;
				}
			}
		}
	}
	if(collision == 10e11) {
		printf("-1\n");
	} else {
		printf("%lld\n", collision);
	}
	
}

int main() {
	readInput();
	return 0;
}
