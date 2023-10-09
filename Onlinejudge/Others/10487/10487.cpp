#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> numbers;
vector<int> sums;

void readInput() {
  int n;
  int in;
  int m;
  int querie;
  bool enter;
  int cont = 1;
  int mini;
  while (scanf("%d", &n) != EOF && n != 0) {
    printf("Case %d:\n", cont++);
    while (n--) {
      scanf("%d", &in);
      numbers.push_back(in);
    }
    for (int i = 0; i < numbers.size(); i++) {
      for (int j = i + 1; j < numbers.size(); j++) {
        sums.push_back(numbers[i] + numbers[j]);
      }
    }
    sort(sums.begin(), sums.end());
    scanf("%d", &m);
    while (m--) {
      enter = false;
      scanf("%d", &querie);
      for (int i = 0; i < sums.size(); i++) {
        if (querie == sums[i]) {
          printf("Closest sum to %d is %d.\n", querie, sums[i]);
          enter = true;
          break;
        } else if (querie < sums[i]) {
          enter = true;
          if (i == 0) {
            printf("Closest sum to %d is %d.\n", querie, sums[i]);
          } else {
            if(querie - sums[i - 1] < sums[i] - querie){
              printf("Closest sum to %d is %d.\n", querie, sums[i - 1]);
            } else {
              printf("Closest sum to %d is %d.\n", querie, sums[i]);
            }
          }
          break;
        }
      }
      if (!enter) {
        printf("Closest sum to %d is %d.\n", querie, sums[sums.size() - 1]);
      }
    }
    numbers.clear();
    sums.clear();
  }
}

int main() {
  readInput();
  return 0;
}
