#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int A, B, C, X, Y;
  int aux;
  bool printed;
  while (scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y) != EOF &&
         (A != 0 && B != 0 && C != 0 && X != 0 && Y != 0)) {
    printed = false;
    if (A > B) {
      aux = A;
      A = B;
      B = aux;
    }
    if (A > C) {
      aux = A;
      A = C;
      C = aux;
    }
    if (B > C) {
      aux = B;
      B = C;
      C = aux;
    }
    if (X > Y) {
      aux = X;
      X = Y;
      Y = aux;
    }

    if (X > C) {
      for (int i = 1; i <= 52; i++) {
        if (i != A && i != B && i != C && i != X && i != Y) {
          printf("%d\n", i);
          printed = true;
          break;
        }
      }
    } else if (X > B) {
      for (int i = B; i <= 52; i++) {
        if (i != A && i != B && i != C && i != X && i != Y) {
          printed = true;
          printf("%d\n", i);
          break;
        }
      }
    } else if (X < B && Y > C) {
      for (int i = C; i <= 52; i++) {
        if (i != A && i != B && i != C && i != X && i != Y) {
          printf("%d\n", i);
          printed = true;
          break;
        }
      }
    }
    if (!printed)
      printf("-1\n");
  }
}

int main() {
  readInput();
  return 0;
}
