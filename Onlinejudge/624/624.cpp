#include <bits/stdc++.h>

using namespace std;

bitset<100> control;
bitset<100> selectedNumbers;
vector<int> numbers;

int maxi;

void readInput() {
  int n, m, in;
  int sum, size;
  int limit;
  while (scanf("%d", &n) != EOF) {
    maxi = 0;
    scanf("%d", &m);
    while (m--) {
      scanf("%d", &in);
      numbers.push_back(in);
    }
    sum = 0;
    size = numbers.size();
    limit = pow(2, size);
    for (int i = 1; i <= limit; i++) {
      sum = 0;
      for (int j = 0; j < size; j++) {
        if (control[j] == 1) {
          sum += numbers[j];
        }
      }
      if (sum > maxi && sum <= n) {
        maxi = sum;
        selectedNumbers = control;
      }
      control = i;
    }
    sum = 0;
    for (int i = 0; i < size; i++) {
      if (selectedNumbers[i] == 1) {
        sum += numbers[i];
        printf("%d ", numbers[i]);
      }
    }
    printf("sum:%d\n", sum);
    control = 0;
    selectedNumbers = 0;
    numbers.clear();
  }
}

int main() {
  readInput();
  return 0;
}
