#include <bits/stdc++.h>

using namespace std;

vector<int> numbers;

int turns() {
  int nTurns = 0;
  for(int i = 0; i < numbers.size() - 1; i++) {
    if(numbers[i] < numbers[i + 1]) nTurns += numbers[i + 1] - numbers[i];
  }
  return nTurns;
}

void readInput() {
  int A,C;
  int cont;
  int size;
  while (scanf("%d", &A) != EOF) {
    cont = 0;
    if(A == 0) {
      break;
    }
    scanf("%d", &C);
    for(int i = 0; i < C; i++) {
      scanf("%d", &size);
      numbers.push_back(size);
    }
    numbers.push_back(A);


    printf("%d\n", turns());
    numbers.clear();
  }
}

int main() {
  readInput();
  return 0;
}
