#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n;
  scanf("%d", &n);
  char str[300000];
  scanf("%s", str);
  long long in;
  string nStr = str;
  long long collision = -1;
  bool thereIsR = false;
  long long backR;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &in);
    if (nStr[i] == 'R') {
      thereIsR = true;
      backR = in;
    } else if (thereIsR) {
      thereIsR = false;
      if (collision == -1) {
        collision = (in - backR) / 2;
      } else {
        collision = min(collision, (in - backR) / 2);
      }
    }
  }
  printf("%lld\n", collision);
}

int main() {
  readInput();
  return 0;
}
