#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

unsigned long long makeOperations(int number) {
  if( number == 1) {
    return 0;
  }
  unsigned long long ret = 1;
  for(int i = number; i > 0; i--) {
    ret *= i % 1000000007;
    printf("%llu\n", ret);
    getchar();
  }
  ret *= number;
  return ret;
}

void readInput() {
  int n;
  scanf("%d", &n);
  int in;
  while (n--) {
    scanf("%d", &in);
    printf("%lld\n", makeOperations(in) % 1000000007);
  }
}

int main() {
  readInput();
  return 0;
}
