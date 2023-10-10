#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n, m, in, mayor, cont = 1;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &m);
    mayor = 0;
    while (m--) {
      scanf("%d", &in);
      if(in > mayor) mayor = in;
    }
    printf("Case %d: %d\n", cont++, mayor);
  }
}

int main() {
  readInput();
  return 0;
}
