#include <bits/stdc++.h>

using namespace std;

long long countLines(long long warriors)
{
	return (-1 + sqrt(1 - (4 * -2 * warriors))) / 2;
}

void readInput()
{
	// Read all the input needed on the problem and store it on global variables (or pass to another function)
	int n;
	long long warriors;
	scanf("%d", &n);
	while (n--) {
		scanf("%lld", &warriors);
		printf("%lld\n", countLines(warriors));
	}
}

int main()
{
	readInput();
	return 0;
}
