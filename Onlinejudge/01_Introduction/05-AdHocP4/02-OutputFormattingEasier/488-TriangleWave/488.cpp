#include <bits/stdc++.h>

using namespace std;

void printTriangle(int amp, int freq, int n) {
  for (int i = 0; i < freq; i++) {
    for (int j = 1; j <= amp; j++) {
      for (int k = 0; k < j; k++) {
        printf("%d", j);
      }
      printf("\n");
    }
    for (int j = amp - 1; j > 0; j--) {
      for (int k = 0; k < j; k++) {
        printf("%d", j);
      }
      printf("\n");
    }
    if (n == 0) {
      if (i < freq - 1) {
        printf("\n");
      }
    } else {
      printf("\n");
    }
  }
}

void readInput() {
  int n, amp, freq;
  scanf("%d", &n);
  getchar();
  while (n--) {
    scanf("%d%d", &amp, &freq);
    printTriangle(amp, freq, n);
  }
}
int main() {
  readInput();
  return 0;
}
