#include <bits/stdc++.h>
#include <cstdio>
#include <string.h>
#include <string>

using namespace std;

int kNumber(int number) {
	int cont = 0;
	int retNumber = 0;
	string numberInString;
	bool canAument = false;
	while( cont < number ) {
		canAument = true;
		retNumber++;
		if(retNumber % 3 == 0){
			canAument = false;
		}
		numberInString = to_string(retNumber);
		if(numberInString[numberInString.size() - 1] == '3'){
			canAument = false;
		}
		if(canAument) {
			cont++;
		}
		
	}
	return retNumber;
}

void readInput() {
	int n; scanf("%d", &n);
	int in;
	while (n--) {
		scanf("%d",&in);
		printf("%d\n",kNumber(in));
	}
}

int main() {
	readInput();
	return 0;
}
