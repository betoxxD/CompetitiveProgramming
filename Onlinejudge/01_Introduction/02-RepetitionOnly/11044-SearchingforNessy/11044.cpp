#include <bits/stdc++.h>

using namespace std;

void readInput()
{
	int q, n, m, result;
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &n, &m);
		result = ceil((n - 2) / 3.0) * ceil((m - 2) / 3.0);
		printf("%d\n", result);
	}
}

int main()
{
	readInput();
	return 0;
}
