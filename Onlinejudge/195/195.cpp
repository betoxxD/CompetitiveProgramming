#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

char data[1000000];

bool mayor;
bool thereIsMayus;

bool customOrder(char a, char b) {
	thereIsMayus = false;
	mayor = true;
	if(a >= 'a') {
		a -= 'a' - 'A';
	} else {
		thereIsMayus = true;
		mayor = true;
	}
	if(b >= 'a') {
		b -= 'a' - 'A';
	} else {
		thereIsMayus = true;
		mayor = false;
	}
	if(a == b) {
		if(thereIsMayus) {
			return mayor;
		} else {
			return false;
		}
	}
	return a < b;
}

void sortString() {
	string strData = data;
	sort(strData.begin(), strData.end(), customOrder);
	do{
		printf("%s\n", strData.c_str());
	}	while(next_permutation(strData.begin(), strData.end(), customOrder));
}

void readData() {
	int n; scanf("%d",&n);
	while (n--) {
		scanf("%s", data);
		sortString();
	}
}

int main(){
	readData();
	return 0;
}
