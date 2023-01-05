#include <bits/stdc++.h>
#include <bitset>
#include <cstdio>

using namespace std;

bool thereIsConflict;
bitset<1000001> calendar;

void clearData() {
	calendar.reset();
}

void addToCalendar(int start, int end) {
	for(int i = start; i < end; i++) {
		if(i >= 1000001) {
			break;
		}
		if(calendar[i] == 1) {
			thereIsConflict = true;
			break;
		}
		calendar[i] = 1;
	}
}

void repeatedTasks(int start, int end, int repetition) {
	while (start <= 1000001) {
		addToCalendar(start, end);
		start += repetition;
		end += repetition;
		if(thereIsConflict) {
			break;
		}
	}
}

void readInput() {
	int n, m; 
	int start, end, repetition;
	while (scanf("%d", &n) != EOF) {
		thereIsConflict = false;
		scanf("%d", &m);
		if(n == 0 && m == 0) {
			break;
		}
		while (n--) {
			scanf("%d%d", &start, &end);
			if(!thereIsConflict) {
				addToCalendar(start, end);
			}
		}
		while (m--) {
			scanf("%d%d%d", &start, &end, &repetition);
			if(!thereIsConflict) {
				repeatedTasks(start, end, repetition);
			}
		}
		if(thereIsConflict) {
			printf("CONFLICT\n");
		} else {
			printf("NO CONFLICT\n");
		}
		clearData();
	}
}

int main() {
	readInput();
	return 0;
}
