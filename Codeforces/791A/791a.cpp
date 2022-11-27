#include <stdio.h>


int main () {
	int a, b, cont = 0;
	scanf("%d%d",&a, &b);
	while(a<=b){
		a*=3;
		b*=2;
		cont++;
	}
	printf("%d\n",cont);
	return 0;
}
