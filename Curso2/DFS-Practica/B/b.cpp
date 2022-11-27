#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int memory[100][100];
int mapa[100][100];
int n, m, x, y, a, b;

void expandPoints(int xl, int yl, int pasos){
	if(xl >= n || xl < 0){
		return;
	}
	if(yl >= m || yl < 0){
		return;
	}
	if(mapa[xl][yl] == 1) {
		return;
	}
	if(memory[xl][yl] != 0){
		if(pasos < memory[xl][yl]){
			memory[xl][yl] = pasos;
		} else {
			return;
		}
	} else {
			memory[xl][yl] = pasos;
	}
	
	expandPoints(xl + 1, yl, pasos + 1);
	expandPoints(xl - 1, yl, pasos + 1);
	expandPoints(xl, yl + 1, pasos + 1);
	expandPoints(xl, yl - 1, pasos + 1);
}

void readInput() {
	scanf("%d%d",&n, &m);
	for(int i = 0; i <n; i++){
		for (int j = 0; j < m; j++){
			scanf("%d",&mapa[i][j]);
		}
	}
	scanf("%d%d",&x, &y);
	scanf("%d%d",&a, &b);
}

void printMemory(){
	for(int i = 0; i <n; i++){
		for (int j = 0; j < m; j++){
			printf("%d",memory[i][j]);
		}
		printf("\n");
	}
}

int main(){
	readInput();
	expandPoints(x,y,1);
	printf("%d\n", memory[a][b]);
	return 0;
}
