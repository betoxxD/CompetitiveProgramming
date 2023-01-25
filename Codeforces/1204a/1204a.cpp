#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>

using namespace std;

void readInput() {
  char in[100000];
  scanf("%s", in);

  int cont = 0;
  bool change = true;
  bool thereIsOne = false;
  for (int i = 0; i < strlen(in); i++) {
    if (in[i] == '1' && i != 0) {
      thereIsOne = true;
    }
    if (change) {
      cont++;
    }
    change = !change;
  }
  if (!thereIsOne) {
    if(strlen(in) % 2 != 0) {
      cont--;
    }
  }
  printf("%d\n", cont);
}

int main() {
  readInput();
  return 0;
}
