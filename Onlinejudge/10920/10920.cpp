#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int size;
long long point;
int x, y;

void generateBoard() {
	/*
	 * 0 = arriba
	 * 1 = izquierda
	 * 2 = abajo
	 * 3 = derecha
	 * */
	int direccion = 0;
	long long aumento = 0;
	long long current = 1;
	x = size / 2;
	y = size / 2;
	y++;
	x++;
	while(current < point) {
		if(direccion == 0 || direccion == 2) {
			aumento++;
		}
		if(direccion == 0) {
			if( current + aumento > point ) {
				x+= point - current;
				break;
			} else {
				current+= aumento;
				x+= aumento;
			}
		}
		if(direccion == 1) {
			if( current + aumento > point ) {
				y-= point - current;
				break;
			} else {
				current+= aumento;
				y-= aumento;
			}
		}
		if(direccion == 2) {
			if( current + aumento > point ) {
				x-= point - current;
				break;
			} else {
				current+= aumento;
				x-= aumento;
			}
		}
		if(direccion == 3) {
			if( current + aumento > point ) {
				y+= point - current;
				break;
			} else {
				current+= aumento;
				y+= aumento;
			}
		}
		if(direccion == 3) {
			direccion = 0;
		} else {
			direccion++;
		}
	}
}

void printOutput() {
	printf("Line = %d, column = %d.\n",x,y);
}

void readInput() {
	while(scanf("%d%lld",&size, &point) != EOF){
		if(size == 0 && point == 0) {
			return;
		}
		generateBoard();
		printOutput();
	}
}

int main() {
	readInput();
	return 0;
}
