#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n;
  scanf("%d", &n);
  long long in;
  while (n--) {
    scanf("%lld", &in);
    if (in % 2 != 0) {
      printf("-1\n");
    } else {
      printf("1 %lld\n",  in / 2);
    }
  }
}

int main() {
  readInput();
  return 0;
}
