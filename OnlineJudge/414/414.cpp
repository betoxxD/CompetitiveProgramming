#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

int n;
vector<string> images;
vector<int> quantity;
int mini = 10e8;

void cleanData(){
	mini = 10e8;
	images.clear();
	quantity.clear();
}

int lastCount(){
	int cantB = 0;
	for(int quant: quantity){
		cantB += quant - mini;
	}
	return cantB;
}

void getMin(){
	for(int quant: quantity){
		mini = min(mini, quant);
	}
}

void countBs(){
	int cont;
	for(string image: images){
		cont = 0;
		for(int i = 0; i < image.size(); i++){
			if(image[i] == 32){
				cont++;
			}
		}
		quantity.push_back(cont);
	}
}

void readInput(){
	char input[200];
	while(scanf("%d", &n) != EOF){
		if(n == 0){
			return;
		}
		for(int i = 0; i < n; i++){
			scanf("%s",input);
			images.push_back(input);
		}
		countBs();
		getMin();
		printf("%d\n",lastCount());
		cleanData();	
	}
}

int main(){
	readInput();
	
	return 0;
}
