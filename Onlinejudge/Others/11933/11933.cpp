#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

long long a, b;

	void calculateValues(long long number) {
		long long increment = 1;
		bool isA = true;
		while (increment <= number) {
			if((number & increment) == increment) {
				if(isA) {
					a += increment;
					isA = false;
				} else {
					b += increment;
					isA = true;
				}
			}
			increment *= 2;
		}
}

void readInput() {
	long long number;
	while(scanf("%lld",&number) != EOF) {
		if(number == 0) {
			return;
		}
		calculateValues(number);
		printf("%lld %lld\n", a, b);
		a = 0;
		b = 0;
	}
}

int main() {
	readInput();
	return 0;
}
