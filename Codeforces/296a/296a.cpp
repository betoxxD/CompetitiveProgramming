#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> numbers;
unordered_map<int, int> apparitions;
int maxi = 0;

void readInput() {
  int n;
  scanf("%d", &n);
  int nCopy = n;
  int in;
  int truncDiv;
  while (n--) {
    scanf("%d", &in);
    numbers.push_back(in);
    apparitions[in]++;
  }
  for (int number : numbers) {
    maxi = max(maxi, apparitions[number]);
  }
  truncDiv = nCopy / 2;
  if (nCopy % 2 == 0) {
    if (maxi <= truncDiv) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  } else {
    if (maxi <= (truncDiv) + 1) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
}

int main() {
  readInput();
  return 0;
}
