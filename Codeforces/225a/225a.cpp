#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

void readInput() {
	int n; scanf("%d", &n);
	int top; scanf("%d", &top);
	int bottom = 7 - top;
	int lef, rig;
	int backL, backR;
	bool predict = true;
	while (n--) {
		scanf("%d%d", &lef, &rig);
		if(predict) {
			backL = 7 - lef;
			backR = 7 - rig;
			if(backL == top || backL == bottom) {
				predict = false;
			}
			if(backR == top || backR == bottom) {
				predict = false;
			}
			if(lef == top || lef == bottom) {
				predict = false;
			}
			if(rig == top || rig == bottom) {
				predict = false;
			}
		}
	}
	(predict) ? printf("YES\n") : printf("NO\n");
}

int main() {
	readInput();
	return 0;
}
