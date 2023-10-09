#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int t, n, current, next;
  int hj, lj;
  int cont = 1;
  scanf("%d", &t);
  while (t--) {
    hj = 0;
    lj = 0;
    scanf("%d", &n);
    scanf("%d", &current);
    for(int i = 0; i < n - 1; i++) {
      scanf("%d",&next);
      if(current < next) hj++;
      else if(current > next) lj++;
      current = next;
    }
    printf("Case %d: %d %d\n", cont++, hj, lj);
  }
}

int main() {
  readInput();
  return 0;
}
