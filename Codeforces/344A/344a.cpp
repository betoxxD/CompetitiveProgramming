#include <stdio.h>

int cant, current, input;

int main() {
	int cont = 1;
	scanf("%d", &cant);
	scanf("%d", &current);
	for (int i = 0; i < cant - 1; i++) {
		scanf("%d", &input);
		if(input != current) {
			current = input;
			cont++;
		}
	}
	printf("%d\n", cont);
	return 0;
}
