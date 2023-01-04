#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int primes[100000];

void getPrimes() {
	for(int i = 2; i <= 50; i++) {
		for(int j = i; j <= 50; j+=i) {
			primes[j]++;
		}
	}
}

int getSecondPrime(int n) {
	int secondPrime = 0;
	getPrimes();
	for(int i = n + 1; i <= 50; i++) {
		if(primes[i] == 1) {
			secondPrime = i;
			break;
		}
	}
	return secondPrime;
}

void readInput() {
	int n, m; scanf("%d%d", &n, &m);
	if(m == getSecondPrime(n)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}

int main() {
	readInput();
	return 0;
}
