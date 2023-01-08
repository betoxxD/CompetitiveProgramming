#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
	long long n, m; scanf("%lld%lld", &n, &m);
	if(n % 2 != 0) {
		n++;
	}
	if(m - n >= 2) {
		printf("%lld %lld %lld\n", n, n + 1, n + 2);
	} else {
		printf("-1\n");
	}
	return 0;
}
