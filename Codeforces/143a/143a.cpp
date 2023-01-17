#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
int r1,r2;
int c1,c2;
int d1,d2; 
int calcX2(int x1) {
	return r1 - x1;
}

int calcX3(int x1) {
	return c1 - x1;
}

int calcX4(int x1) {
	return d1 - x1;
}

bool checkR2(int x3, int x4) {
	return (r2 == x3 + x4);
}

bool checkC2(int x2, int x4) {
	return (c2 == x2 + x4);
}

bool checkD2(int x2, int x3) {
	return (d2 = x2 + x3);
}

bool checkXs(int x1, int x2, int x3, int x4){
	if(x1 > 9 || x2 > 9 || x3 > 9 || x4 > 9){
		return false;
	}
	return (x1 != x2 && x1 != x3 && x1 != x4 && x2 != x3 && x2 != x4 && x3 != x4);
}

void readInput(){
	scanf("%d%d", &r1, &r2);
	scanf("%d%d", &c1, &c2);
	scanf("%d%d", &d1, &d2);
	int x1, x2, x3, x4;
	int mini;
	mini = min(d1, c1);
	mini = min(mini, r1);
	bool canOpen = false;
	for(int i = 1; i < mini; i++) {
		x1 = i;
		x2 = calcX2(x1);
		x3 = calcX3(x1);
		x4 = calcX4(x1);
		//printf("%d %d\n%d %d\n", x1, x2, x3, x4);
		if(checkR2(x3, x4) && checkC2(x2, x4) && checkD2(x2, x3) && checkXs(x1, x2, x3, x4)) {
			printf("%d %d\n%d %d\n", x1, x2, x3, x4);
			canOpen = true;
			break;
		}
	}
	if(!canOpen) {
		printf("-1\n");
	}
}

int main() {
	readInput();
	return 0;
}
