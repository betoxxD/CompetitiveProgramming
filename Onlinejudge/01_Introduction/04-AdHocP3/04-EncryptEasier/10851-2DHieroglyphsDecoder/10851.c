#include <stdio.h>
#include <string.h>

void clear_matrix(char matrix[10][100]) {
  for (int i = 0; i < 10; i++) {
    matrix[i][0] = '\0';
  }
}

int binary_to_decimal(char *binary) {
  int binary_base, decimal_value;
  binary_base = 1;
  decimal_value = 0;
  for (int i = 7; i >= 0; i--) {
    if (binary[i] == '/') {
      binary_base *= 2;
    } else {
      decimal_value += binary_base;
      binary_base *= 2;
    }
  }
  return decimal_value;
}

void scan_matrix(char matrix[10][100]) {
  for (int i = 0; i < 10; i++) {
    scanf("%s", matrix[i]);
  }
}

void solve(char matrix[10][100]) {
  int matrix_size = strlen(matrix[0]);
  int binary_position = 0;
  char binary[10];
  for (int i = 1; i < matrix_size - 1; i++) {
    binary[0] = '\0';
    binary_position = 0;
    for (int j = 8; j > 0; j--) {
      binary[binary_position++] = matrix[j][i];
    }
    printf("%c", binary_to_decimal(binary));
  }
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);
  char matrix[10][100];
  for (int i = 0; i < n; i++) {
    scan_matrix(matrix);
    solve(matrix);
    clear_matrix(matrix);
    getchar();
  }
  return 0;
}
