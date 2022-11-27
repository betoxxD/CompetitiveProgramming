#include <stdio.h>

int main() {
	int n, h, s, result = 0;
	scanf("%d%d",&n, &h);
	for(int i = 0; i < n; i++){
		scanf("%d", &s);
		if(s > h){
			result+=2;
		} else {
			result += 1;
		}
	}
	printf("%d\n",result);
	return 0;
}
