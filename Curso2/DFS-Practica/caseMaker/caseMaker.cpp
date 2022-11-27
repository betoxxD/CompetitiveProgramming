#include <stdio.h>

int main() {

	printf("50 50\n");
	for(int i = 0; i < 50; i++){
		for(int j = 0; j < 50; j++){
			printf("0");
			if (j != 49) {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("10 2\n");
	printf("10 4\n");
	return 0;
}
