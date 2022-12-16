#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> values;
char line[1000000];
double amount; 
double pricePerLine;
long long lineSize;

void clearData() {
	values.clear();
	amount = 0;
	pricePerLine = 0;
	lineSize = 0;
}

void countPricePerLine() {
	pricePerLine = 0;
	lineSize = strlen(line);
	for( int i = 0; i < lineSize; i++ ) {
		pricePerLine += values[line[i]];
	} 
	amount += pricePerLine / 100;
}

void readInput() {
	int cases, letters;
	char character;
	int price;
	int lines;
	scanf("%d" ,&cases);
	while (cases--) {
		scanf("%d", &letters);
		while (letters--) {
			scanf(" %c%d",&character, &price);
			values[character] = price;
		}
		scanf("%d",&lines);
		getchar();
		while (lines--) {
			fgets(line, 1000000, stdin);
			countPricePerLine();
		}
		printf("%.2lf$\n", amount);
		clearData();
	}
}

int main() {
	values.reserve(1000);
	readInput();
	return 0;
}
