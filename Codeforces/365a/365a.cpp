#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int bucket[15];
int cont;
int k;

void isKGood(string num) {
	if(num.size() < k + 1){
		return;
	}
	bool isGood;
	for(int i = 0; i < num.size(); i++) {
		isGood = true;
		if( i + k >= num.size() ){
			break;
		}
		for(int j = i; j <= i + k; j++){
			bucket[num[j] - '0']++;
		}
		for(int j = 0; j <= k; j++){
			if(bucket[j] == 0) {
				isGood = false;
			} 
			bucket[j] = 0;
		}
		for(int j = k + 1; j <= 9; j++){
			if(bucket[j] != 0) {
				isGood = false;
			} 
			bucket[j] = 0;
		}
		if(isGood) {
			cont++;
		}
	}
}

void readInput() {
	int n; scanf("%d%d", &n, &k);
	char in[100];
	for( int i = 0; i < n; i++ ){
		scanf("%s", in);
		isKGood(in);
	}
	printf("%d\n", cont);
}

int main() {
	readInput();
	return 0;
}
