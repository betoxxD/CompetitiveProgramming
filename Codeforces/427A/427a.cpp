#include <stdio.h>

int n, polis, untreated;

void checkAbailibility(int acts) {
	if(acts == -1){
		if(polis<1){
			untreated++;
		} else {
			polis--;
		}
	} else {
		polis+=acts;
	}
}

void scanValues() {
	int acts;
	scanf("%d", &n);
	for( int i = 0; i < n; i++ ) {
		scanf("%d",&acts);
		checkAbailibility(acts);
	}
}



int main() {
	scanValues();
	printf("%d\n", untreated);
	return 0;
}
