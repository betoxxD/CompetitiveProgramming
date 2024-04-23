#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n;
  int i, j;
  int cont;
  while (scanf("%d", &n) != EOF) {
    int cont;
    scanf("%d%d", &i, &j);
    for(cont = 0; i != j; cont++) {
      if(i % 2 != 0){
        i = (i / 2) + 1;
      } else {
        i /= 2;
      }
      if(j % 2 != 0){
        j = (j / 2) + 1;
      } else {
        j /= 2;
      }
    }
    printf("%d\n", cont);
  }
}

int main() {
  readInput();
  return 0;
}
