#include <bits/stdc++.h>

using namespace std;

float calculateMass(string formula) {
  int C = 0;
  int H = 0;
  int O = 0;
  int N = 0;
  float mass = 0;
  string newNumber;
  int formulaSize = formula.size();
  for (int i = 0, j = 0; i < formulaSize; i++) {
    j = 0;
    newNumber = "";
    switch (formula[i]) {
    case 'C':
      if (i + 1 < formulaSize && isdigit(formula[i + 1])) {
        j = i + 1;
        while (isdigit(formula[j])) {
          newNumber += formula[j];
          j++;
        }
        i = j - 1;
        C += stoi(newNumber);
      } else {
        C++;
      }
      break;
    case 'H':
      if (i + 1 < formulaSize && isdigit(formula[i + 1])) {
        j = i + 1;
        while (isdigit(formula[j])) {
          newNumber += formula[j];
          j++;
        }
        i = j - 1;
        H += stoi(newNumber);
      } else {
        H++;
      }
      break;
    case 'O':
      if (i + 1 < formulaSize && isdigit(formula[i + 1])) {
        j = i + 1;
        while (isdigit(formula[j])) {
          newNumber += formula[j];
          j++;
        }
        i = j - 1;
        O += stoi(newNumber);
      } else {
        O++;
      }
      break;
    case 'N':
      if (i + 1 < formulaSize && isdigit(formula[i + 1])) {
        j = i + 1;
        while (isdigit(formula[j])) {
          newNumber += formula[j];
          j++;
        }
        i = j - 1;
        N += stoi(newNumber);
      } else {
        N++;
      }
      break;
    }
    mass = (C * 12.01) + (H * 1.008) + (O * 16.00) + (N * 14.01);
  }
  return mass;
}

void readInput() {
  int n;
  scanf("%d", &n);
  char in[1000];
  while (n--) {
    scanf("%s", in);
    printf("%.3f\n", calculateMass(in));
  }
}

int main() {
  readInput();
  return 0;
}
