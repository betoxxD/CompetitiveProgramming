#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n;
  scanf("%d", &n);
  int a, b;
  while(n--) {
    scanf("%d%d", &a, &b);
    if(a > b) printf(">\n");
    else if(a < b) printf("<\n");
    else printf("=\n");
  }
}

int main() {
  readInput();
  return 0;
}
