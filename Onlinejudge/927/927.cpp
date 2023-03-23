#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

vector<long long> equation;

void readInput() {
	long long n; scanf("%lld", &n);
	long long expo;
	long long in;
	long long d, k;
	long long cont;
	long long lExpo;
	long long sum;
	long long bm;
	long long newD;
	while (n--) {
		cont = 1;
		sum = 0;
		lExpo = 0;
		bm = 0;
		scanf("%lld", &expo);	
		for(int i = 0; i < expo + 1; i++) {
			scanf("%lld", &in);
			equation.push_back(in);
		}
		scanf("%lld%lld", &d, &k);
		newD = d;
		while (bm < k) {
			//printf("%lld + %lld = %lld\n", bm, newD, bm + newD);
			if(bm + newD < k ) {
				bm += newD;
			} else {
				break;
			}
			cont++;
			newD = d * (cont );
		}
		for(long long number : equation) {
			sum += number * (pow(cont, lExpo));
			lExpo++;
		}
		printf("%lld\n", sum);
		equation.clear();
	}
}

int main() {
	readInput();
	return 0;
}
