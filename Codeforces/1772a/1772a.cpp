#include <bits/stdc++.h>
#include <cstdio>

using namespace std;


void readInput() {
	int n;
	int a, b;
	scanf("%d", &n);
	while(n--) {
		scanf("%d+%d",&a, &b);
		printf("%d\n", a + b);
	}
}

int main() {
	readInput();
	return 0;
} 
