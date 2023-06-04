#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

bool isYes(string word)
{
	if (word.size() > 3)
		return false;

	if (word[0] != 'Y' && word[0] != 'y')
		return false;
	if (word[1] != 'E' && word[1] != 'e')
		return false;
	if (word[2] != 'S' && word[2] != 's')
		return false;

	return true;
}

void readInput()
{
	int n;
	scanf("%d", &n);
	char wInput[10];
	while (n--) {
		scanf("%s", wInput);
		printf("%s\n", isYes(wInput) ? "YES" : "NO");
	}
}

int main()
{
	readInput();
	return 0;
}
