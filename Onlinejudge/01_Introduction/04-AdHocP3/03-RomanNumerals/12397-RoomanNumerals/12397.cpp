#include <bits/stdc++.h>

using namespace std;

char units[10][10] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
char tens[10][10] = {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char hund[10][10] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
char thou[10][10] = {"M", "MM", "MMM"};

void unitArabicToRoman(int unit, char *roman_number) {
  if (unit < 0)
    return;
  strcat(roman_number, units[unit - 1]);
}
void tenArabicToRoman(int ten, char *number) {
  if (ten < 0)
    return;
  strcat(number, tens[ten - 1]);
}
void hundArabicToRoman(int hundred, char *number) {
  if (hundred < 0)
    return;
  strcat(number, hund[hundred - 1]);
}
void thouArabicToRoman(int thousand, char *number) {
  if (thousand < 0)
    return;
  strcat(number, thousand[thou - 1]);
}

void arabicToNumber(char number[], char roman_number[]) {
  int number_len = strlen(number);
  if (number_len > 3) {
    thouArabicToRoman(number[0] - '0', roman_number);
    hundArabicToRoman(number[1] - '0', roman_number);
    tenArabicToRoman(number[2] - '0', roman_number);
    unitArabicToRoman(number[3] - '0', roman_number);
  } else if (number_len > 2) {
    hundArabicToRoman(number[0] - '0', roman_number);
    tenArabicToRoman(number[1] - '0', roman_number);
    unitArabicToRoman(number[2] - '0', roman_number);
  } else if (number_len > 1) {
    tenArabicToRoman(number[0] - '0', roman_number);
    unitArabicToRoman(number[1] - '0', roman_number);
  } else {
    unitArabicToRoman(number[0] - '0', roman_number);
  }
}

int countMatches(char number[]) {
  int matches = 0;
  char roman_number[2000] = {};
  arabicToNumber(number, roman_number);
  int roman_number_size = strlen(roman_number);
  for (int i = 0; i < roman_number_size; i++) {
    if (roman_number[i] == 'I') {
      matches += 1;
    } else if (roman_number[i] == 'V' || roman_number[i] == 'X' ||
               roman_number[i] == 'L' || roman_number[i] == 'C') {
      matches += 2;
    } else if (roman_number[i] == 'D') {
      matches += 3;
    } else {
      matches += 4;
    }
  }
  return matches;
}

void solve() {
  char number[1000];
  while (scanf("%s", number) != EOF) {
    printf("%d\n", countMatches(number));
  }
}

int main() {
  solve();
  return 0;
}
