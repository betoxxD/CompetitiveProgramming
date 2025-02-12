#include <bits/stdc++.h>

using namespace std;

bool is_number(char c) { return c >= '0' && c <= '9'; }

void build_numbers(char new_number[], char str[]) {
  int i, str_size, position = 0;
  new_number[0] = '\0';
  str_size = strlen(str);
  for (i = 0; i < str_size; i++) {
    if (is_number(str[i])) {
      new_number[position++] = str[i];
    }
  }
  new_number[position] = '\0';
}

bool accepted(char answer[], char output[]) {
  int i, answer_size, output_size;
  answer_size = strlen(answer);
  output_size = strlen(output);

  if (answer_size != output_size)
    return false;

  for (i = 0; i < answer_size; i++) {
    if (answer[i] != output[i])
      return false;
  }

  return true;
}

bool presentation_error(char answer[], char output[]) {
  char answer_numbers[500], output_numbers[500];
  build_numbers(answer_numbers, answer);
  build_numbers(output_numbers, output);
  return strcmp(answer_numbers, output_numbers) == 0;
}

void solve(char answer[], char output[], int case_number) {
  if (accepted(answer, output)) {
    printf("Run #%d: Accepted\n", case_number);
  } else if (presentation_error(answer, output)) {
    printf("Run #%d: Presentation Error\n", case_number);
  } else {
    printf("Run #%d: Wrong Answer\n", case_number);
  }
}

int main() {
  int n, m, i, case_number = 1;
  char answer[100005], output[100005];
  char answer_input[500], output_input[500];
  while (scanf("%d", &n) != EOF && n != 0) {
    getchar();
    for (i = 0; i < n; i++) {
      fgets(answer_input, 500, stdin);
      strcat(answer, answer_input);
    }
    scanf("%d", &m);
    getchar();
    for (i = 0; i < m; i++) {
      fgets(output_input, 500, stdin);
      strcat(output, output_input);
    }
    solve(answer, output, case_number++);
    answer[0] = '\0';
    output[0] = '\0';
    answer_input[0] = '\0';
    output_input[0] = '\0';
  }
  return 0;
}
