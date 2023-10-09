#include <bits/stdc++.h>

using namespace std;

void readInput() {
	long long n;
	long long raiz;
	while (scanf("%lld" ,&n) != EOF && n != 0) {
		raiz = sqrt(n);
		raiz * raiz == n ? printf("yes\n") : printf("no\n");
	}
}

int main() {
	readInput();
	return 0;
}
