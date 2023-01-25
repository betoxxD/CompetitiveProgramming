#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<long long> numbers;
int minimum = 0;

void countOperations() {
  long long firstNumber, secondNumber;
  long long firstRes, secondRes;
  vector<long long>::iterator it;
  for (int i = 0; i < numbers.size() - 1; i++) {
    firstNumber = numbers[i];
    secondNumber = numbers[i + 1];
    firstRes = firstNumber % 2;
    secondRes = secondNumber % 2;
    if ((firstRes == 0 && secondRes == 0) ||
        (firstRes != 0 && secondRes != 0)) {
      it = numbers.begin() + i;
      numbers.erase(it);
      numbers[i] = firstNumber * secondNumber;
      minimum++;
      i--;
    }
  }
}

void readInput() {
  int n;
  scanf("%d", &n);
  int m;
  long long input;
  while (n--) {
    scanf("%d", &m);
    while (m--) {
      scanf("%lld", &input);
      numbers.push_back(input);
    }
    countOperations();
    printf("%d\n", minimum);
    numbers.clear();
    minimum = 0;
  }
}

int main() {
  readInput();
  return 0;
}
