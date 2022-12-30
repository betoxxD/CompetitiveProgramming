#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

stack<int> pila;
queue<int> cola;
priority_queue<int> colaPrioritaria;

bool isPila;
bool isCola;
bool isColaPrioritaria;

void clearData() {
	while (!pila.empty()) {
		pila.pop();
	}
	while (!cola.empty()) {
		cola.pop();
	}
	while (!colaPrioritaria.empty()) {
		colaPrioritaria.pop();
	}
	isPila = true;
	isCola = true;
	isColaPrioritaria = true;
}

void addPila(int number) {
	pila.push(number);
}

void addCola(int number) {
	cola.push(number);
}

void addColaPrioritaria(int number) {
	colaPrioritaria.push(number);
}

void removePila(int number) {
	if(pila.empty()) {
		isPila = false;
		return;
	}
	if(!isPila) {
		return;
	}
	if(pila.top() == number) {
		isPila = true;
		pila.pop();
	} else {
		isPila = false;
		return;
	}
}

void removeCola(int number) {
	if(cola.empty()) {
		isCola = false;
		return;
	}
	if(!isCola) {
		return;
	}
	if(cola.front() == number) {
		isCola = true;
		cola.pop();
	} else {
		isCola = false;
		return;
	}
}

void removeColaPrioritaria(int number) {
	if(colaPrioritaria.empty()) {
		isColaPrioritaria = false;
		return;
	}
	if(!isColaPrioritaria) {
		return;
	}
	if(colaPrioritaria.top() == number) {
		isColaPrioritaria = true;
		colaPrioritaria.pop();
	} else {
		isColaPrioritaria = false;
		return;
	}
}

void checkStructure() {
	if((isCola && isPila) ||(isCola && isColaPrioritaria) || (isPila && isColaPrioritaria) || (isCola && isPila && isColaPrioritaria)) {
		printf("not sure\n");
	} else if(isPila) {
		printf("stack\n");
	} else if (isCola) {
		printf("queue\n");
	} else if (isColaPrioritaria) {
		printf("priority queue\n");
	} else {
		printf("impossible\n");
	}
}

void readInput() {
	int n;
	int action, number;
	isPila = true;
	isCola = true;
	isColaPrioritaria = true;
	while(scanf("%d", &n) != EOF) {
		while (n--) {
			scanf("%d%d", &action, &number);		
			if(action == 1) {
				addPila(number);
				addCola(number);
				addColaPrioritaria(number);
			} else {
				removePila(number);
				removeCola(number);
				removeColaPrioritaria(number);
			}
		}
		checkStructure();
		clearData();
	}
}

int main() {
	readInput();
	return 0;
}
