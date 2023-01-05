#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
	long long x, y; scanf("%lld%lld", &x, &y);
	long long result = 0;
	long long trunkY = y / 5;	
	long long trunkX = x / 5;
	result = (trunkX * 5) * trunkY;
	getchar();
	long long restX = x - (trunkX * 5);
	long long restY = y - (trunkY * 5);
	result += restX * trunkY;
	result += restY * trunkX;
	long long may, mini;
	may = max(restX, restY);
	mini = min(restX, restY);
	for(long long i = 1; i <= mini; i++) {
		if((i + may) % 5 == 0) {
			may--;
			result++;
		}
	}
	printf("%lld\n", result);
	return 0;
}
