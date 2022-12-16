#include <bits/stdc++.h>
#include <cstdio>
 
using namespace std;
 
int maxi, mini = 10e8;
int sizeNumbers;
 
vector<int> numbers;
 
void clearData() {
	maxi = 0;
	mini = 10e8;
	numbers.clear();
}
 
long getIterations(int number) {
	int iterations = 0;
	for( int i = 1; i < number; i++ ) {
		iterations += i;
	}
	return iterations;
}
 
void getMaxAndMin() {
	for(int number: numbers) {
		maxi = max(maxi, number);
		mini = min(number, mini);
	}
}
 
long long countPosibilities() {
  int cont = 0;
	long long int contMax = 0;
	long long int contMin = 0;
	for(int number: numbers) {
		if(number == maxi) {
			contMax++;
			cont++;
		}
		if(number == mini) {
			contMin++;
			cont++;
		}
	}
	/*if(maxi == mini) {
		return  getIterations(cont) * 2;
	}*/
	return contMax * contMin * 2;
}
 
void readInput() {
	int n;
	int number;
	scanf("%d",&n);
	while(n--) {
		scanf("%d", &sizeNumbers);
		for(int i = 0; i < sizeNumbers; i++) {
			scanf("%d", &number);
			numbers.push_back(number);
		}
 
		getMaxAndMin();
		printf("%lld\n",countPosibilities());
		clearData();
	}
}
 
int main() {
	readInput();
	return 0;
}
