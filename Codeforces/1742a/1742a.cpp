#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

bool isSum(int a, int b, int c)
{
	if (a + b == c)
		return true;
	if (a + c == b)
		return true;
	if (b + c == a)
		return true;
	return false;
}

void readInput()
{
	int n;
	scanf("%d", &n);
	int a, b, c;
	while (n--) {
		scanf("%d%d%d", &a, &b, &c);
		printf("%s\n", isSum(a, b, c) ? "YES" : "NO");
	}
}

int main()
{
	readInput();
	return 0;
}
