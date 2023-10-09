#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> lights;
int status;
vector<int> aument;
vector<bool> isGreen;

int minor = 10e8;

void clearData() {
	status = 0;
	for(int i = 0; i < lights.size(); i++) {
		lights[i] = 0;
		aument[i] = 0;
		isGreen[i] = false;
	}
	lights.clear();
	aument.clear();
	isGreen.clear();
	minor = 10e8;
}

bool checkGreens() {
	for(bool light : isGreen) {
		if(!light){
			return false;
		}
	}
	return true;
}

void makeFormat(int second){
	int hour, minute, pSecond;
	hour = second / 3600;
	second -= hour * 3600;
	minute = second / 60;
	second -= minute * 60;
	pSecond = second;
	if(hour < 10){
		printf("0%d:",hour);
	} else {
		printf("%d:",hour);
	}
	if(minute < 10){
		printf("0%d:",minute);
	} else {
		printf("%d:",minute);
	}
	if(second < 10){
		printf("0%d",pSecond);
	} else {
		printf("%d",pSecond);
	}
	printf("\n");
}

void sumOne() {
	status++;
	// printf("%d | ", status);
	for(int i = 0; i < lights.size(); i++) {
		if(isGreen[i]) {
			if(status == aument[i] - 5) {
				isGreen[i] = !isGreen[i];
				aument[i] += lights[i];
			} 
		} else {
			if(status == aument[i]) {
				isGreen[i] = !isGreen[i];
				aument[i] += lights[i];
			}
		}
		// printf("%d ", isGreen[i] * 1);
	}
	// printf("\n");
	// getchar();
}

void countTime() {
	bool allGreen = false;
	while (status <= 18000) {
		if(checkGreens()) {
			allGreen = true;
			break;
		}
		sumOne();
	}
	if(allGreen) {
		makeFormat(status);
	} else {
		printf("Signals fail to synchronise in 5 hours\n");
	}
}

void searchMinor() {
	for(int time : lights) {
		minor = min(minor, time - 5);
	}
	for(int i = 0; i < lights.size(); i++) {
		if(lights[i] - 5 == minor) {
			isGreen[i] = false;
			aument[i] *= 2;

		}
		status = minor;
	}
}

void readData() {
	int input;
	bool firstZero, secondZero, thirdZero;
	firstZero = false;
	secondZero = false;
	thirdZero = false;
	while(!thirdZero) {
		scanf("%d", &input);
		if(input == 0) {
			if(firstZero){
				if(secondZero) {
					thirdZero = true;
					break;
				} else {
					secondZero = true;
				}
			} else {
				if(lights.size() == 0) {
					firstZero = true;
				} else {
					searchMinor();
					countTime();
					clearData();
				}
			}
		} else {
			firstZero = false;
			secondZero = false;
			thirdZero = false;
			lights.push_back(input);
			aument.push_back(input);
			isGreen.push_back(true);

		}
	}
}

int main() {
	readData();
	return 0;
}
