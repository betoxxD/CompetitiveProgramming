#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n, k; scanf("%d%d", &n, &k);
  int sum = 0;
  int ina, inb;
  int next;
  while (n--)
  {
    scanf("%d%d", &ina, &inb);
    sum += inb - ina + 1;
  }
  if(sum % k == 0) {
    printf("0\n");
  } else {
    next = sum / k;
    next *= k;
    next += k;
    printf("%d\n", next - sum);
  }
}

int main() {
  readInput();
  return 0;
}
