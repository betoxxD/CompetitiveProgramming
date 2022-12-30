#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

vector<long long> strongs;

int countMonos() {
	int cont = 0;
	for(long strong : strongs) {
		if(strong > strongs[0] && strong < strongs[strongs.size() - 1]) {
			cont++;
		}
	}
	return cont;
}

void orderData() {
	sort(strongs.begin(), strongs.end());
}

void readInput() {
	int n; scanf("%d",&n);
	long long input;
	while (n--) {
		scanf("%lld", &input);
		strongs.push_back(input);
	}
	orderData();
	printf("%d\n", countMonos());
}

int main() {
	readInput();
	return 0;
}
