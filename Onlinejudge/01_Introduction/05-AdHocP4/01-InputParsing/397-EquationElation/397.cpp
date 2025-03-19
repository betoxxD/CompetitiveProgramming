#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int delete_int_by_id(int *numbers, int id, int arr_size) {
  memmove(&numbers[id], &numbers[id + 1], (arr_size - id - 1) * sizeof(int));
  arr_size--;
  return arr_size;
}

int delete_char_by_id(char *operators, int id, int arr_size) {
  memmove(&operators[id], &operators[id + 1],
          (arr_size - id - 1) * sizeof(char));
  arr_size--;
  return arr_size;
}

int operate(int a, int b, char op) {
  if (op == '+')
    return a + b;
  if (op == '-')
    return a - b;
  if (op == '*')
    return a * b;
  else
    return a / b;
}

bool search_multipliers(char operators[], int n) {
  for (int i = 0; i < n; i++) {
    if (operators[i] == '*' || operators[i] == '/') {
      return true;
    }
  }
  return false;
}

void print_equation(int numbers[], char operators[], int n,
                    char *variable_name) {
  int i, op_result;
  bool operated, stop = false;
  char operator_1, operator_2;
  operator_1 = '*';
  operator_2 = '/';
  for (i = 0; i < n; i++) {
    printf("%d %c ", numbers[i], operators[i]);
  }
  printf("%d = %s\n", numbers[i], variable_name);

  while (true) {
    operated = false;
    for (i = 0; i < n; i++) {
      if (operators[i] == operator_1 || operators[i] == operator_2) {
        operated = true;
        op_result = operate(numbers[i], numbers[i + 1], operators[i]);
        numbers[i + 1] = op_result;
        delete_char_by_id(operators, i, n);
        delete_int_by_id(numbers, i, n + 1);
        n--;
        break;
      }
    }
    if (!operated) {
      if (!stop) {
        operator_1 = '+';
        operator_2 = '-';
        stop = true;
        continue;
      } else {
        break;
      }
    }
    for (i = 0; i < n; i++) {
      printf("%d %c ", numbers[i], operators[i]);
    }
    printf("%d = %s\n", numbers[i], variable_name);
  }
}

void print_numbers(int *numbers, int size) {
  for (int i = 0; i < size; i++) {
    printf("n(i) = %d\n", numbers[i]);
  }
}

void solve() {
  char variable_name[100];
  int numbers[100];
  char operators[100];
  int number_index = 0;
  int operator_index = 0;
  char op;
  while (scanf("%d", &numbers[number_index++]) != EOF) {
    scanf(" %c", &op);
    if (op == '=') {
      scanf("%s", variable_name);
      print_equation(numbers, operators, number_index - 1, variable_name);
      number_index = 0;
      operator_index = 0;
    } else if (op == '+' || op == '-' || op == '*' || op == '/') {
      operators[operator_index++] = op;
    }
  }
}

int main() {
  solve();
  return 0;
}
