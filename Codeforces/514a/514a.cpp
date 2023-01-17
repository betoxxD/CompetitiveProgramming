#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int transformToNumber( char number ) {
	return number - '0';
}

void readInput() {
	char n[1000]; scanf("%s", n);
	string in = n;
	int number;
	for(int i = 0; i < in.size(); i++) {
		number = transformToNumber(in[i]);
		if(9 - number < number) {
			if(i == 0 && number == 9){
				printf("%d", number);
			} else {
				printf("%d", 9 - number);
			}
		} else {
			printf("%d", number);
		}
	}
	printf("\n");
}

int main() {
	readInput();
	return 0;
}
