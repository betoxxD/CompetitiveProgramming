#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

long long limit = 1073741824;

int main() {
	int n; scanf("%d", &n);
	int cont = 0;
	while (limit > 0) {
		if(limit <= n) {
			n -= limit;
			cont++;
		}	
		limit/= 2;
	}
	printf("%d\n", cont);
	return 0;
}
