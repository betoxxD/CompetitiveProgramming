#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n;
  scanf("%d", &n);
  char in[100000];
  scanf("%s", in);
  int s, t;
  bool first = true;
  bool onlyLs = false;
  for (int i = 0; i < n; i++) {
    if (in[i] == 'R' && first) {
      s = i + 1;
      first = !first;
    }
    if (in[i] == '.' && !first) {
      if (onlyLs) {
        s = i;
      } else {
        t = i + 1;
      }
      break;
    }
    if (in[i] == 'L') {
      if (first) {
        onlyLs = true;
        t = i;
        first = !first;
      } else if (!onlyLs) {
        t = i;
        break;
      }
    }
  }
  printf("%d %d\n", s, t);
}

int main() {
  readInput();
  return 0;
}
