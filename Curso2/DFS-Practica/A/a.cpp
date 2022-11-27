#include <bits/stdc++.h>

using namespace std;

int n, m;
int numbers[100];
bool bitasos[50];
int mini = 10e8;

void readInput() {
	scanf("%d%d",&n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &numbers[i]);
	}
}

void printCombination(){
	for(int i = 0; i < n; i++){
		printf("%d ",bitasos[i]);
	}
	printf("\n");
}

void checkMin(){
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum+=bitasos[i] * numbers[i];
	}
	if(sum >= m){
		mini = min(mini, sum - m);
	}
}

void makeCombinations(int pos, bool nuevo) {
	if(nuevo){
		checkMin();
	}
	if(pos < 0){
		return;
	}
	if(!bitasos[pos]){
		bitasos[pos] = 1;
		makeCombinations(n - 1, true);
	} else {
		bitasos[pos] = 0;
		makeCombinations(pos - 1, false);
	}
}

int main() {
	readInput();
	makeCombinations(n, true);
	printf("%d\n",mini);
	return 0;
}
