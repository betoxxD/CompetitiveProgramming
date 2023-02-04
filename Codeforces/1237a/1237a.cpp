#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n;
  scanf("%d", &n);
  int in;
  int cont = 0;
  int diff;
  int multiplier = 1;
  while (n--) {
    scanf("%d", &in);
    
    if (in % 2 != 0) {
      printf("%d\n", (in + multiplier) / 2);
      multiplier *= -1;
    } else {
      printf("%d\n", in / 2);
    }
  }
}

int main() {
  readInput();
  return 0;
}
