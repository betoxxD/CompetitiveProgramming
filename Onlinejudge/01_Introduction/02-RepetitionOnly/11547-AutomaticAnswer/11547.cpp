#include <bits/stdc++.h>

using namespace std;

void readInput()
{
	int t;
	long long n;
	string ns;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		n *= 567;
		n /= 9;
		n += 7492;
		n *= 235;
		n /= 47;
		n -= 498;
		ns = to_string(n);
		printf("%c\n", ns.size() >= 2 ? ns[ns.size() - 2] : 0);
	}
}

int main()
{
	readInput();
	return 0;
}
