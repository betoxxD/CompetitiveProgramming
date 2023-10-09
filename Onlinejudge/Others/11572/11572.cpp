#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

vector<int> numbers;
unordered_map<int, int> position;
int cont;
int maxi;

void clearData()
{
	cont = 0;
	maxi = 0;
	numbers.clear();
	position.clear();
}

void addPacket()
{
	int start = 0;
	int number;
	int count;
	number = numbers[0];
	position[number] = 0;
	for (int i = 1; i < numbers.size(); i++)
	{
		number = numbers[i];
		// printf("[%d - %d] = %d %d\n", start, i, numbers[start], numbers[i]);
		// printf("%d\n", position[number]);
		// getchar();
		if (position[number] == -1)
		{
			if(i == numbers.size() - 1){
				count = i - start + 1;
				maxi = max(count, maxi);
			}
		}
		else
		{
			count = i - start;
			maxi = max(count, maxi);
			if (position[number] + 1 > start)
			{
				start = position[number] + 1;
			}
		}
		position[number] = i;
	}
	if (maxi == 0)
	{
		maxi = 1;
	}
}

void readInput()
{
	int n;
	scanf("%d", &n);
	int m;
	int input;
	int cont;
	while (n--)
	{
		scanf("%d", &m);
		cont = 0;
		if (m == 0)
		{
			printf("0\n");
			continue;
		}
		while (m--)
		{
			scanf("%d", &input);
			numbers.push_back(input);
			position[input] = -1;
		}
		addPacket();
		printf("%d\n", maxi);
		clearData();
	}
}

int main()
{
	readInput();
	return 0;
}
