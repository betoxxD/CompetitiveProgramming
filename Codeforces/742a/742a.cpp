#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	int nDivided = n / 4;
	if( n == 0 ) {
		printf("1\n");
	} else if(nDivided * 4 == n) {
		printf("6\n");
	} else if( n - (nDivided * 4) == 1 ) {
		printf("8\n");
	} else if( n - (nDivided * 4) == 2 ) {
		printf("4\n");
	} else if( n - (nDivided * 4) == 3 ) {
		printf("2\n");
	}

	return 0;
}
