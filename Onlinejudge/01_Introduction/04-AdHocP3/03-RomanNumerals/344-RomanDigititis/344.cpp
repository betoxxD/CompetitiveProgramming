#include <bits/stdc++.h>

using namespace std;

vector<string> units = {"i", "ii", "iii", "iv", "v", "vi", "vii", "viii", "ix"};
vector<string> cents = {"x", "xx", "xxx", "xl", "l", "lx", "lxx", "lxxx", "xc"};

int countedChars[200];

void initializeNumbers() {
  countedChars['i'] = 0;
  countedChars['v'] = 0;
  countedChars['x'] = 0;
  countedChars['l'] = 0;
  countedChars['c'] = 0;
}

void countRomanNumbers(string romanNumber) {
  int romanNumberSize = romanNumber.size();
  for (int i = 0; i < romanNumberSize; i++) {
    countedChars[romanNumber[i]]++;
  }
}

void printResult(string number) {
  printf("%s: %d i, %d v, %d x, %d l, %d c\n", number.c_str(),
         countedChars['i'], countedChars['v'], countedChars['x'],
         countedChars['l'], countedChars['c']);
}

string convertToRoman(string number) {
  int numberi = stoi(number);
  string romanNumber = "";
  string currentNumber = "";
  int centsN, unitsN;
  for (int i = 1; i <= numberi; i++) {
    currentNumber = to_string(i);
    if (i == 100) {
      romanNumber = romanNumber + "c";
    } else if (i > 9) {
      centsN = currentNumber[0] - '0';
      unitsN = currentNumber[1] - '0';
      romanNumber = romanNumber + cents[centsN - 1] + "" + units[unitsN - 1];
    } else {
      unitsN = currentNumber[0] - '0';
      romanNumber = romanNumber + units[unitsN - 1];
    }
  }
  return romanNumber;
}

void resolve(string number) {
  string romanNumber = convertToRoman(number);
  countRomanNumbers(romanNumber);
  printResult(number);
}

void readInput() {
  char number[10];
  while (scanf("%s", number) != EOF) {
    initializeNumbers();
    if (number[0] == '0') {
      break;
    }
    resolve(number);
  }
}

int main() {
  readInput();
  return 0;
}
