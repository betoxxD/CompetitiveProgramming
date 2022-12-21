#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct Car{
	int position;
	int arrived;
	int unloaded;
};

queue<Car> leftCars;
queue<Car> rightCars;
vector<Car> gCars;
bool isLeft = true;
string input;
int transcurredTime;
int capacity;
int timeToCome;

void clearData() {
	isLeft = true;
	input = "";
	transcurredTime = 0;
	capacity = 0;
	timeToCome = 0;
	for(Car car: gCars) {
		car = {0};
	}
	gCars.clear();
}

bool orderCriteria(struct Car car1, struct Car car2) {
	return car1.position < car2.position;
}

void printResults() {
	sort(gCars.begin(), gCars.end(), orderCriteria);
	for(Car car: gCars) {
		printf("%d\n", car.unloaded);
	}
}

void crossCarsLeft() {
	int cont = 0;
	isLeft = false;
	transcurredTime += timeToCome;
	if(leftCars.empty()) {
		if(rightCars.front().arrived > transcurredTime) {
			isLeft = true;
			transcurredTime = rightCars.front().arrived;
		}
		return;
	}
	if( leftCars.front().arrived > transcurredTime -timeToCome ) {
		if(rightCars.empty()) {
			isLeft = true;
			transcurredTime = leftCars.front().arrived;
			return;
		}
		if(rightCars.front().arrived > transcurredTime - timeToCome) {
			if(rightCars.front().arrived > leftCars.front().arrived){
				transcurredTime = leftCars.front().arrived;
				isLeft = true;
			} else {
				transcurredTime = rightCars.front().arrived + timeToCome;
			}
		}	
		return;
	}
	while(cont < capacity) {
		if(leftCars.empty()) {
			break;
		}
		if(leftCars.front().arrived <= transcurredTime - timeToCome) {
			leftCars.front().unloaded = transcurredTime;
			gCars.push_back(leftCars.front());
			leftCars.pop();
		} else {
			break;
		}
		cont++;
	}
} 

void crossCarsRight() {
	int cont = 0;
	isLeft = true;
	transcurredTime += timeToCome;
	if(rightCars.empty()) {
		if(leftCars.front().arrived > transcurredTime) {
			isLeft = false;
			transcurredTime = leftCars.front().arrived;
		}
		return;
	}
	if( rightCars.front().arrived > transcurredTime - timeToCome) {
		if(leftCars.empty()) {
			isLeft = false;
			transcurredTime = rightCars.front().arrived;
			return;
		}
		if(leftCars.front().arrived > transcurredTime - timeToCome) {
			if(leftCars.front().arrived > rightCars.front().arrived){
				transcurredTime = rightCars.front().arrived;
				isLeft = false;
			} else {
				transcurredTime = leftCars.front().arrived + timeToCome;

			}
		}
		return;
	}
	while(cont < capacity) {
		if(rightCars.empty()) {
			break;
		}
		if(rightCars.front().arrived <= transcurredTime - timeToCome) {
			rightCars.front().unloaded = transcurredTime;
			gCars.push_back(rightCars.front());
			rightCars.pop();
		} else {
			break;
		}
		cont++;
	}
}

void crossCars() {
	while (!leftCars.empty() || !rightCars.empty()) {
		if(isLeft) {
			crossCarsLeft();
		} else {
			crossCarsRight();
		}
	}
}

void readInput() {
	int n; scanf("%d", &n);
	int cars;
	char inChar[10];
	int timeArrived;
	struct Car car = {0};
	int cont = 0;
	while (n--) {
		car = {0};
		cont = 0;
		transcurredTime = 0;
		scanf("%d%d%d",&capacity, &timeToCome, &cars);
		while (cars--) {
			scanf("%d%s",&timeArrived,inChar);
			input = inChar;
			car.position = cont++;
			car.arrived = timeArrived;
			if(input == "left") {
				leftCars.emplace(car);
			} else {
				rightCars.emplace(car);
			}
		}
		crossCars();
		printResults();
		if(n > 0) {
			printf("\n");
		}
		clearData();
	}
}

int main() {
	readInput();
	return 0;
}
