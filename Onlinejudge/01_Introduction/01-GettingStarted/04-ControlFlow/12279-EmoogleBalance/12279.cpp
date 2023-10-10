#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n;
  int in;
  int cont = 1;
  int balance;
  while (scanf("%d", &n) != EOF && n != 0) {
    balance = 0;
    while (n--) {
      scanf("%d", &in);
      if(in == 0) balance--;
      else balance++;
    }
    printf("Case %d: %d\n", cont++, balance);
  }
}

int main() {
  readInput();
  return 0;
}
