#include <bits/stdc++.h>

using namespace std;

int symbol_value['Z'];
int counted_symbols['Z'];

void initialiceCountSymbols() {
  counted_symbols['B'] = 0;
  counted_symbols['U'] = 0;
  counted_symbols['S'] = 0;
  counted_symbols['P'] = 0;
  counted_symbols['F'] = 0;
  counted_symbols['T'] = 0;
  counted_symbols['M'] = 0;
}

void initialiceSymbolValue() {
  symbol_value['B'] = 1;
  symbol_value['U'] = 10;
  symbol_value['S'] = 100;
  symbol_value['P'] = 1000;
  symbol_value['F'] = 10000;
  symbol_value['T'] = 100000;
  symbol_value['M'] = 1000000;
}

bool hasCorrectOrder(char pEgipcian_number[]) {
  int i, egipcian_number_size;
  bool is_descendent;

  egipcian_number_size = strlen(pEgipcian_number);

  if (egipcian_number_size == 1) {
    return 1;
  }

  for (i = 0; i < egipcian_number_size; i++) {
    counted_symbols[(int)pEgipcian_number[i]]++;
    if (counted_symbols[(int)pEgipcian_number[i]] > 9) {
      return false;
    }
  }

  is_descendent = false;

  for (i = 0; i < egipcian_number_size - 1; i++) {
    if (pEgipcian_number[i] != pEgipcian_number[i + 1]) {
      if (symbol_value[(int)pEgipcian_number[i]] >
          symbol_value[(int)pEgipcian_number[i + 1]]) {
        is_descendent = true;
      } else {
        is_descendent = false;
      }
      break;
    }
  }

  if (is_descendent) {
    for (i = 0; i < egipcian_number_size - 1; i++) {
      if (symbol_value[(int)pEgipcian_number[i]] <
          symbol_value[(int)pEgipcian_number[i + 1]]) {
        return false;
      }
    }
  } else {
    for (i = 0; i < egipcian_number_size - 1; i++) {
      if (symbol_value[(int)pEgipcian_number[i]] >
          symbol_value[(int)pEgipcian_number[i + 1]]) {
        return false;
      }
    }
  }
  return true;
}

int sumSymbolValue(char pEgipcian_number[]) {
  int i, sum = 0, egipcian_number_size;
  egipcian_number_size = strlen(pEgipcian_number);
  for (i = 0; i < egipcian_number_size; i++) {
    sum += symbol_value[(int)pEgipcian_number[i]];
  }
  return sum;
}

void solve() {
  int number_of_cases;
  char pEgipcian_number[600];
  scanf("%d", &number_of_cases);
  while (number_of_cases--) {
    initialiceCountSymbols();
    scanf("%s", pEgipcian_number);
    if (hasCorrectOrder(pEgipcian_number)) {
      printf("%d\n", sumSymbolValue(pEgipcian_number));
    } else {
      printf("error\n");
    }
  }
}

int main() {

  initialiceSymbolValue();
  solve();

  return 0;
}
