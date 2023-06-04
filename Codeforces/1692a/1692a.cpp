#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int participants[10];
int timur;

int countFront()
{
	int cont = 0;
	for (int i = 0; i < 3; i++) {
		if (participants[i] > timur)
			cont++;
	}
	return cont;
}

void readInput()
{
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d%d", &timur, &participants[0], &participants[1], &participants[2]);
		printf("%d\n", countFront());
	}
}

int main()
{
	readInput();
	return 0;
}
