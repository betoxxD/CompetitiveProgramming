#include <bits/stdc++.h>

using namespace std;

void printResult(int n) {
  int blank;
  int pages;
  bool alternate = true;
  int cont = 1;
  int numberSheet = 1;
  printf("Printing order for %d pages:\n", n);
  if (n == 1) {
    printf("Sheet 1, front: Blank, 1\n");
  } else {
    blank = n % 4 == 0 ? 0 : 4 - (n % 4);
    pages = n % 4 == 0 ? n / 4 * 2 : (n / 4 + 1) * 2;
    while (pages--) {
      if (alternate) {
        printf("Sheet %d, front: %s, %d\n", numberSheet,
               blank <= 0 ? to_string(n).c_str() : "Blank", cont);
        alternate = !alternate;
        if (blank <= 0) {
          n--;
        }
        blank--;
        cont++;
      } else {
        printf("Sheet %d, back : %d, %s\n", numberSheet, cont,
               blank <= 0 ? to_string(n).c_str() : "Blank");
        numberSheet++;
        alternate = !alternate;
        if (blank <= 0) {
          n--;
        }
        blank--;
        cont++;
      }
    }
  }
}

void readInput() {
  int n;
  while (scanf("%d", &n) != EOF && n != 0) {
    printResult(n);
  }
}

int main() {
  readInput();
  return 0;
}
