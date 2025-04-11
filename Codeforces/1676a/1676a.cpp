#include <bits/stdc++.h>

using namespace std;

int getSumFirst3Digits(char ticket[]) {
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    sum += ticket[i] - '0';
  }
  return sum;
}

int getSumLast3Digits(char ticket[]) {
  int sum = 0;
  int ticket_size = strlen(ticket);
  for (int i = ticket_size - 1, j = 0; j < 3; i--, j++) {
    sum += ticket[i] - '0';
  }
  return sum;
}

void solve() {
  int n;
  scanf("%d", &n);
  int num1, num2;
  char ticket[10];
  while (n--) {
    scanf("%s", ticket);
    num1 = getSumFirst3Digits(ticket);
    num2 = getSumLast3Digits(ticket);
    if (num1 == num2) {
      printf("YES\n");
    } else {

      printf("NO\n");
    }
  }
}

int main() {
  solve();
  return 0;
}
