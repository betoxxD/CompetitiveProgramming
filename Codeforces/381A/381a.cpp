#include <stdio.h>

int n, cards[1005];
int serja, dima;

void readInput() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&cards[i]);
	}
}

void countCards() {
	int start = 0, end = n - 1;
	bool turn = true;
	while(start <= end) {
		if(turn){
			turn = false;
			if(cards[start] > cards[end]){
				serja+=cards[start];
				start++;
			} else {
				serja+=cards[end];
				end--;
			}
		} else {
			turn = true;
			if(cards[start] > cards[end]){
				dima+=cards[start];
				start++;
			} else {
				dima+=cards[end];
				end--;
			}
		}
	}
}

int main() {
	readInput();
	countCards();
	printf("%d %d\n",serja, dima);
	return 0;
}
