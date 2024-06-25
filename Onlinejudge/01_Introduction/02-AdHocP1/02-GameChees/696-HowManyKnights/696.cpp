#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n, m;
  int maxi, mini;
  int r;
  int cont;
  bool put;
  while (scanf("%d%d", &n, &m) != EOF && (n != 0 && m != 0)) {
    cont = 0;
    put = true;
    r = 0;
    maxi = max(n, m);
    if (n == 1 || m == 1) {
      r = maxi;
    } else if (n == 2 || m == 2) {
      for (int i = 1; i <= maxi; i++) {
        if (cont == 2) {
          cont = 0;
          put = !put;
        }
        if (put) {
          r += 2;
        }
        cont++;
      }
    } else {
      r = ((n * m) + 1) / 2;
    }
    printf("%d knights may be placed on a %d row %d column board.\n", r, n, m);
  }
}

int main() {
  readInput();
  return 0;
}
