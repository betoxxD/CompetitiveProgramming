#include <bits/stdc++.h>

using namespace std;

void readInput() {
	int n; scanf("%d", &n);
	int a, b, c;
	int gx, gy, gz;
	long long fA, fB, fC;
	int maxi;
	bool solution;
	while (n--) {
		solution = false;
		scanf("%d%d%d", &a, &b, &c);
		maxi = max(a,max(b,c));
		for(int x = -maxi; x < maxi; x++) {
			if(solution) {
				break;
			}
			fA = x + x + x;
			fB = x * x * x;
			fC = pow(x, 2) + pow(x, 2) + pow(x, 2);
			//printf("%d %d %d\n", a, b, c);
			//printf("%lld %lld %lld\n", fA, fB, fC);
			//getchar();
			if(fC > c) {
				continue;
			}
			if(fB > b) {
				continue;
			}
			if(fA > a) {
				break;
			}
			for(int y = x; y < maxi + 2; y++) {
				if(solution) {
					break;
				}
				for(int z = y; z < maxi + 2; z++) {
					if(solution) {
						break;
					}
					fA = x + y + z;
					fB = x * y * z;
					fC = pow(x, 2) + pow(y, 2) + pow(z, 2);
					if(fC > c) {
						break;
					}
					if(fB > b) {
						break;
					}
					if(fA > a) {
						break;
					}
					if(fA == a && fB == b && fC == c) {
						if(x != y && x != z && y != z){
							solution = true;
							gx = x;
							gy = y;
							gz = z;
							break;
						}
					}
				}
			}
		}

		if(solution) {
			printf("%d %d %d\n", gx, gy, gz);
		} else {
			printf("No solution.\n");
		}
	}
	
}

int main() {
	readInput();
	return 0;
}
