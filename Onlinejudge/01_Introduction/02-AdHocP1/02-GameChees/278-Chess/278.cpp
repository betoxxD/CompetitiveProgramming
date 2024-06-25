#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n;
  scanf("%d", &n);
  char piece;
  int x, y;
  while (n--) {
    scanf(" %c", &piece);
    scanf("%d%d", &x, &y);
    if (piece == 'r') {
      printf("%d\n", min(x, y));
    } else if (piece == 'k') {
      printf("%d\n", (x * y + 1) / 2);
    } else if (piece == 'Q') {
      printf("%d\n", min(x, y));
    } else {
      printf("%d\n", ((x + 1) / 2) * ((y + 1) / 2));
    }
  }
}

int main() {
  readInput();
  return 0;
}
