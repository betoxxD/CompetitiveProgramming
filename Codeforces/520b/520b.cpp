#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

long long n;
int m;
long long minimum = 10e17;
long long memo[1000000];
long long difference;

void searchMinimum(long long position, long long steps) {
		if(position > 10e8){
		return;
	}
	if( position < 1000000 && memo[position] != 0) {
		if(position == m){
			memo[position] = min(memo[position], steps);
			minimum = min(minimum, memo[position]);
		}
		if(memo[position] < steps){
			return;
		}
	}
	if(position <= 0) {
		return;
	}
	if (steps > minimum) {
		return;
	}
	if(position == m) {
		minimum = min(minimum, steps);
		return;
	}
	//printf("position: %lld steps: %lld mini: %lld\n",position, steps,minimum);
	//getchar();

	if(position < 1000000){
		memo[position] = steps;
	}
	//printf("Rest one\n");
	searchMinimum(position - 1, steps + 1);
	if(m > position) {
		//printf("Multiply 2\n");
		searchMinimum(position * 2, steps + 1);
	}
}

void readInput() {
	scanf("%lld%d",&n, &m);
}

int main() {
	readInput();
	searchMinimum(n, 0);
	printf("%lld\n", minimum);
	return 0;
}
