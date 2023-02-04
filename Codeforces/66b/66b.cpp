#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int sections[1000000];

int countRiegos(int pos, int size) {
  int ret = 1;
  int mini = sections[pos];
  for(int i = pos + 1; i < size; i++) {
    if(mini < sections[i]) {
      break;
    }
    ret++;
    mini = min(sections[i], mini);
  }
  mini = sections[pos];
  for(int i = pos - 1; i >= 0; i--) {
    if(mini < sections[i]) {
      break;
    }
    ret++;
    mini = min(sections[i], mini);
  }
  return ret;
}

void readInput() {
  int n;
  scanf("%d", &n);
  int cont = 0;
  int maxi = 0;
  while (n--) {
    scanf("%d", &sections[cont++]);
  }
  for(int i = 0; i < cont; i++) {
    maxi = max(maxi,countRiegos(i, cont));
  }
  printf("%d\n", maxi);
}

int main() {
  readInput();
  return 0;
}
