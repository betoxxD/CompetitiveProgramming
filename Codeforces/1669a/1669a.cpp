#include <bits/stdc++.h>

using namespace std;

int calculateDivision(int rating) {
  if (rating <= 1399) {
    return 4;
  } else if (rating <= 1599) {
    return 3;
  } else if (rating <= 1899) {
    return 2;
  } else {
    return 1;
  }
}

void solve() {
  int n, rating;
  scanf("%d", &n);

  while (n--) {
    scanf("%d", &rating);
    printf("Division %d\n", calculateDivision(rating));
  }
}

int main() {
  solve();
  return 0;
}
