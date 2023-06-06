#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>

using namespace std;

bool hasOddDivisor(long long input)
{
	long long calcPow;
	for (int i = 1; i < 10e8; i++) {
		calcPow = pow(2, i);
		if (calcPow == input)
			return false;

		if (calcPow > input)
			return true;
	}
	return true;
}

void readInput()
{
	int n;
	long long input;
	scanf("%d", &n);
	while (n--) {
		scanf("%lld", &input);
		printf((hasOddDivisor(input) ? "YES\n" : "NO\n"));
	}
}

int main()
{
	readInput();
	return 0;
}
