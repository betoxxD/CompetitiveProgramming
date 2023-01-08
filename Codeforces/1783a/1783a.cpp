#include <bits/stdc++.h>
#include <cstdio>
#include <functional>
#include <vector>

using namespace std;

vector<int> arr;

void printInput(bool isPossible) {
	if(isPossible) {
		printf("YES\n");
		for(int num: arr) {
			printf("%d ", num);
		}
		printf("\n");
	} else {
		printf("NO\n");
	}
}

void readInput() {
	int n; scanf("%d", &n);
	int arrSize, in, aux; 
	bool printed;
	while (n--) {
		scanf("%d", &arrSize);
		printed = false;
		while (arrSize--) {
			scanf("%d", &in);
			arr.push_back(in);
		}
		
		sort(arr.begin(), arr.end(), greater<int>());
		if(arr[0] == arr[1]) {
			aux = arr[0];
			for(int i = arr.size() - 1; i > 0; i--) {
				if(arr[i] != arr[0]) {
					if(arr[i] + arr[1] != arr[2]){
						arr[0] = arr[i];
						arr[i] = aux;
						printInput(true);
						printed = true;
						break;
					}
				}
			}
			if(!printed) {
				printInput(false);
			}
		} else {
			printInput(true);
		}
		arr.clear();
	}
}

int main() {
	readInput();
	return 0;
}
