#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

vector<int> courses;
map<string, int> combinations;

void clearData() {
	combinations.clear();
}

string makeString() {
	sort(courses.begin(), courses.end());
	string ret = "";
	for(int i = 0; i < 5; i++){
		ret += to_string(courses[i]) + "|";
	}
	return ret;
}

void addToCombinations(string combination) {
	combinations[combination]++;
}

int getMostCommon() {
	int mayor = 0;
	bool isSame = true;
	int cont = 0;
	for(pair<string, int> combination : combinations) {
		if(combination.second != mayor && mayor != 0) {
			isSame = false;
		}
		if(combination.second == mayor){
			cont+=combination.second;
		}
		if(mayor < combination.second) {
			cont = combination.second;
			mayor = combination.second;
		}
	}
	if(isSame) {
		return cont;
	}
	return max(mayor, cont);
}

void readInput() {
	int n = 1;
	int cours;
	while (n!=0) {
		scanf("%d", &n);
		if(n == 0) {
			break;
		}
		while(n--) {
			for( int i = 0; i < 5; i++ ) {
				scanf("%d",&cours);
				courses.push_back(cours);
			}
			addToCombinations(makeString());
			courses.clear();
		}
		printf("%d\n", getMostCommon());
		clearData();

	}
}

int main() {
	readInput();
	return 0;
}
