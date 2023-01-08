#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

char square[10][10];

int main() {
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			scanf(" %c", &square[i][j]);
		}
	}
	int cantBlack = 0;
	int cantWhite = 0;
	bool isGuapo = false;
	for(int i = 0; i < 3; i++) {
		if(isGuapo) {
			break;
		}
		for(int j = 0; j < 3; j++) {
			cantWhite = 0;
			cantBlack = 0;
			if(square[i][j] == '#') {
				cantBlack++;
			} else {
				cantWhite++;
			}
			if(square[i][j + 1] == '#') {
				cantBlack++;
			} else {
				cantWhite++;
			}
			if(square[i + 1][j] == '#') {
				cantBlack++;
			} else {
				cantWhite++;
			}
			if(square[i + 1][j + 1] == '#') {
				cantBlack++;
			} else {
				cantWhite++;
			}
			if(cantBlack >= 3 || cantWhite >= 3) {
				isGuapo = true;
				break;
			}
		}
	}
	(isGuapo) ? printf("YES\n") : printf("NO\n");
	return 0;
}
