#include <stdio.h>

char numbers[10][5] = {" ",   ".,?\"", "abc",  "def", "ghi",
                       "jkl", "mno",   "pqrs", "tuv", "wxyz"};

char get_char(int number, int pressed) {
  int cant_pressions =
      number == 7 || number == 9 || number == 1 ? pressed % 5 : pressed % 4;
  return numbers[number][cant_pressions - 1];
}

void solve(int inputs[2][1005], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%c", get_char(inputs[0][i], inputs[1][i]));
  }
  printf("\n");
}

int main() {
  int tests, n, i, j;
  int inputs[2][1005];
  scanf("%d", &tests);
  for (i = 0; i < tests; i++) {
    scanf("%d", &n);
    for (j = 0; j < n; j++) {
      scanf("%d", &inputs[0][j]);
    }
    for (j = 0; j < n; j++) {
      scanf("%d", &inputs[1][j]);
    }
    solve(inputs, n);
  }
  return 0;
}
