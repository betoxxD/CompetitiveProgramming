#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char units[10][10] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
char tens[10][10] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char hund[10][10] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
char thou[10][10] = {"M", "MM", "MMM"};

void strcatchar(char *str, char c) {
  int str_size = strlen(str);
  str[str_size] = c;
  str[str_size + 1] = '\0';
}

void unit_arabic_to_roman(int unit, char *number) {
  if (unit < 0)
    return;
  strcat(number, units[unit - 1]);
}
void ten_arabic_to_roman(int ten, char *number) {
  if (ten < 0)
    return;
  strcat(number, tens[ten - 1]);
}
void hund_arabic_to_roman(int hundred, char *number) {
  if (hundred < 0)
    return;
  strcat(number, hund[hundred - 1]);
}
void thou_arabic_to_roman(int thousand, char *number) {
  if (thousand < 0)
    return;
  strcat(number, thousand[thou - 1]);
}

char *arabic_to_roman(char *number) {
  int number_size;
  char *roman_number = (char *)malloc(200 * sizeof(char));
  number_size = strlen(number);
  if (number_size == 4) {
    thou_arabic_to_roman(number[0] - '0', roman_number);
    hund_arabic_to_roman(number[1] - '0', roman_number);
    ten_arabic_to_roman(number[2] - '0', roman_number);
    unit_arabic_to_roman(number[3] - '0', roman_number);
  } else if (number_size == 3) {
    hund_arabic_to_roman(number[0] - '0', roman_number);
    ten_arabic_to_roman(number[1] - '0', roman_number);
    unit_arabic_to_roman(number[2] - '0', roman_number);
  } else if (number_size == 2) {
    ten_arabic_to_roman(number[0] - '0', roman_number);
    unit_arabic_to_roman(number[1] - '0', roman_number);
  } else {
    unit_arabic_to_roman(number[0] - '0', roman_number);
  }
  return roman_number;
}

int get_roman_value(char c) {
  switch (c) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  default:
    return 0;
  }
}

int roman_to_arabic(char *roman_number) {
  int i, roman_number_size, arabic_number = 0, current_value, next_value;
  roman_number_size = strlen(roman_number);
  for (i = 0; i < roman_number_size; i++) {
    current_value = get_roman_value(roman_number[i]);
    next_value =
        i + 1 < roman_number_size ? get_roman_value(roman_number[i + 1]) : 0;
    if (current_value < next_value) {
      arabic_number -= current_value;
    } else {
      arabic_number += current_value;
    }
    current_value = next_value;
  }
  return arabic_number;
}

void solve() {
  char input[100];
  while (scanf("%s", input) != EOF) {
    if (input[0] >= '0' && input[0] <= '9') {
      printf("%s\n", arabic_to_roman(input));
    } else {
      printf("%d\n", roman_to_arabic(input));
    }
    input[0] = '\0';
  }
}

int main() {
  solve();
  return 0;
}
