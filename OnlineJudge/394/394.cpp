#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

vector<int> base;
vector<string> name;
vector<int> size;
vector<int> dimensions;

vector<vector<int>> low;
vector<vector<int>> up;
vector<vector<int>> values;
vector<vector<int>> c;

void printNames() {
	for(string elName : name){
		printf("%s\n", elName.c_str());
	}
}

void calculateC0(int arrId) {
	int d = dimensions.at(arrId);
	c[arrId][0] = base[arrId];
	for(int i = 1; i <= d; i++){
		c[arrId][0] -= c[arrId][i] * low[arrId][i - 1];
	}
}

void calculateCd(int arrId) {
	int d = dimensions.at(arrId);
	c[arrId].resize(d + 10);
	c[arrId][d] = size.at(arrId);
	for(int i = d - 1; i > 0; i--){
		c[arrId][i] = c[arrId][i + 1] * (up[arrId][i] - low[arrId][i] + 1);
	}
}

int calculateMemory(int arrId) {
	int d = dimensions[arrId];
	int rMemory = c[arrId][0];
	for(int i = 1; i <= d; i++){
		rMemory+= c[arrId][i] * values[arrId][i - 1];
	}
	return rMemory;
}

int getArrId(string cName){
	int id = -1;
	int cont = 0;
	for(string iName: name){
		if(iName == cName){
			id = cont;
			break;
		}
		cont++;
	}
	return id;
}

void readInputsDef(int n) {
	char lName[20];
	int lBase, lSize, lDimensions, lLow, lUp;
	int cont = 0;
	while(n--) {
		scanf("%s%d%d%d", lName, &lBase, &lSize, &lDimensions);
		name.push_back(lName);
		base.push_back(lBase);
		size.push_back(lSize);
		dimensions.push_back(lDimensions);
		for(int i = 0; i < lDimensions; i++){
			scanf("%d%d", &lLow, &lUp);
			low[cont].push_back(lLow);
			up[cont].push_back(lUp);
		}
		cont++;
	}
	//printNames();
}

void printResult(int id, int memory){
	int d = dimensions[id];
	printf("%s[", name[id].c_str());
	for(int i = 0; i < d; i++){
		printf("%d", values[id][i]);
		if(i == d - 1){
			printf("] = ");
		} else {
			printf(", ");
		}
	}
	printf("%d\n", memory);
}

void cleanC(int id){
	c[id].clear();
	values[id].clear();
}

void readInputsAsign(int m){
	char lName[20];
	int id;
	int value;
	while(m--) {
		scanf("%s",lName);
		id = getArrId(lName); 
		if(id != -1) {
			for(int i = 0; i < dimensions.at(id); i++){
				scanf("%d", &value);
				values[id].push_back(value);
			}
				calculateCd(id);
				calculateC0(id);
				int memory = calculateMemory(id);
				printResult(id, memory);
				cleanC(id);
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	values.resize(n + 10);
	c.resize(n + 10);
	low.resize(n + 10);
	up.resize(n + 10);
	readInputsDef(n);
	readInputsAsign(m);
	return 0;
}
