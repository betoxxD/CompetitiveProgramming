#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

void readInput() {
  int n;
  int cont = 1;
  scanf("%d", &n);
  int l, w, h;
  while (n--) {
    scanf("%d%d%d", &l, &w, &h);
    if(l <= 20 && w <= 20 && h <= 20) printf("Case %d: good\n", cont++);
    else printf("Case %d: bad\n", cont++);
  }
}

int main() {
  readInput();
  return 0;
}
