#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
#include <stdexcept>

using namespace std;


bool pLeft = true; 
queue<int> carsLeft;
queue<int> carsRight;
int ferryLength;
int times;

void transportLeft() {
	pLeft = false;
	times++;
	if(carsLeft.empty()) {
		return;
	}
	int charge = 0;
	while (carsLeft.front() + charge <= ferryLength) {
		if(carsLeft.empty()) {
			break;
		}
		charge += carsLeft.front();
		carsLeft.pop();
	}
}

void transportRight() {
	pLeft = true;
	times++;
	if(carsRight.empty()) {
		return;
	}
	int charge = 0;
	while (carsRight.front() + charge <= ferryLength) {
		if(carsRight.empty()) {
			break;
		}
		charge += carsRight.front();
		carsRight.pop();
	}
}

void transportCars() {
	while (!carsLeft.empty() || !carsRight.empty()) {
		if(pLeft) {
			transportLeft();
		} else {
			transportRight();
		}
	}
}


void readInput(){
	int n; scanf("%d",&n);
	int numberCars;
	int carSize;
	string position;
	char positionIn[10];
	while(n--) {
		times = 0;
		pLeft = true;
		scanf("%d%d",&ferryLength, &numberCars);
		ferryLength *= 100;
		while (numberCars--) {
			scanf("%d%s",&carSize,positionIn);
			position = positionIn;
			if(position == "left") {
				carsLeft.emplace(carSize);
			} else {
				carsRight.emplace(carSize);
			}
		}
		transportCars();
		printf("%d\n", times);
	}
}

int main() {
	readInput();
	return 0;
}
