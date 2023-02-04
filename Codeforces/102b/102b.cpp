#include <bits/stdc++.h>
#include <cstring>
#include <string>

using namespace std;

char n[1000000];

void readInput() {
  scanf("%s", n);
  int sum = 0;
  int cont = 0;
  while (strlen(n) > 1) {
    cont++;
    sum = 0;
    for (int i = 0; i < strlen(n); i++) {
      sum += n[i] - '0';
    }
    strcpy(n, to_string(sum).c_str());
  }
  printf("%d\n", cont);
}

int main() {
  readInput();
  return 0;
}
