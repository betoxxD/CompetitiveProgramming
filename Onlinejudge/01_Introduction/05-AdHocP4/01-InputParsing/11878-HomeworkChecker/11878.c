#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_digit(char c) { return c >= '0' && c <= '9'; }

int char_to_int(char *c) {
  int i, c_len, multipier = 1, result = 0;
  c_len = strlen(c);
  for (i = c_len - 1; i >= 0; i--) {
    result += (c[i] - '0') * multipier;
    multipier *= 10;
  }
  return result;
}

int calculate_result(int a, int b, char op) {
  if (op == '+') {
    return a + b;
  } else {
    return a - b;
  }
}

void solve() {
  int a, b, int_c, result, cont = 0;
  char op, c[200];
  while (scanf("%d%c%d=%s", &a, &op, &b, c) != EOF) {
    if (c[0] == '?') {
      continue;
    }
    result = calculate_result(a, b, op);
    int_c = char_to_int(c);
    if (result == int_c) {
      cont++;
    }
  }
  printf("%d\n", cont);
}

int main() {
  solve();
  return 0;
}
