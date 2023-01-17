#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

#define LSOne(S) (S & (-S))

class FenwickTree {
	private:
		vector<int> ft;
		vector<int> back;
	
	public:
		FenwickTree(int n) {
			ft.assign(n + 1, 1);
			back.assign(n + 1, 0);
		}

		int rsq(int b) {
			int product = 1;
			for(;b;b-=LSOne(b)){
				printf("ft[%d] = %d\n", b, ft[b]);
				product *= ft[b];
			}
			return product;
		}

		int rsq(int a, int b) {
			int rsqA = rsq(a);
			int rsqB = rsq(b);
			printf("rsq(%d) = %d rsq(%d) = %d\n", a, rsqA, b, rsqB);
			return rsqA * rsqB;
		}

		void assign(int k, int v) {
			if(v < 0) {
				v = -1;
			}
			if(v > 0){
				v = 1;
			}
			back[k] = v;
			for(; k < ft.size(); k+= LSOne(k)) {
					ft[k] *= v;
			}
		}

		void adjust(int k, int v) {
			if(v < 0) {
				v = -1;
			}
			if(v > 0){
				v = 1;
			}
			bool changeToValue = false;
			ft[k] = v;
			back[k] = v;
			k+=LSOne(k);
			for(; k < ft.size(); k+= LSOne(k)) {
				ft[k] = v * back[k];
			}
		}

		void printFt() {
			for(int i = 1; i < ft.size(); i++) {
				printf("%d ", ft[i]);
			}
			printf("\n");
			for(int i = 1; i < back.size(); i++) {
				printf("%d ", back[i]);
			}
			printf("\n");
		}
};


void readInput() {
	int n,m, in, cont;
	int a,b, backA, backB;
	char action;
	int result;
	string sResult = "";
	bool first = true;
	while (scanf("%d", &n) != EOF) {
		cont = 1;
		sResult = "";
		a = 1;
		b = 1;
		scanf("%d", &m);
		FenwickTree ft(n);
		first = true;
		while (n--) {
			scanf("%d", &in);
			ft.assign(cont++, in);
		}
		ft.printFt();
		while (m--) {
			scanf(" %c%d%d", &action, &a, &b);
			if(action == 'C') {
				ft.adjust(a, b);
				ft.printFt();
			} else {
				result = ft.rsq(a,b);
				sResult += (result > 0) ? '+' : (result < 0) ? '-' : '0';
				printf("%d\n", result);
			}
		}
		printf("%s\n",sResult.c_str());
	}
}

int main() {
	readInput();
	return 0;
}
