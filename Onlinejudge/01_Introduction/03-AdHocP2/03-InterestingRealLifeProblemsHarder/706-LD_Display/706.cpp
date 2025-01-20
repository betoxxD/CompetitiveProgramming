#include <bits/stdc++.h>

using namespace std;

bool numbers[100][100] = {{1, 1, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 0, 0, 0},
                          {0, 1, 1, 0, 1, 1, 1}, {0, 1, 1, 1, 1, 0, 1},
                          {1, 0, 1, 1, 0, 0, 1}, {1, 1, 0, 1, 1, 0, 1},
                          {1, 1, 0, 1, 1, 1, 1}, {0, 1, 1, 1, 0, 0, 0},
                          {1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 0, 1}};

void printLine(int width, int height, string number, int ind) {
  int numberSize = number.size();
  int intNumber;
  ind++;
  for (int i = 0; i < numberSize; i++) {
    intNumber = number[i] - '0';
    if (ind == 1) {
      // Fila numero 1
      printf(" ");
      for (int j = 0; j < width - 2; j++) {
        if (numbers[intNumber][1]) {
          printf("-");
        } else {
          printf(" ");
        }
      }
      printf(" ");

    } else if (ind == (height / 2) + 1) {
      // Fila de enmedio
      printf(" ");
      for (int j = 0; j < width - 2; j++) {
        if (numbers[intNumber][6]) {
          printf("-");
        } else {
          printf(" ");
        }
      }
      printf(" ");
    } else if (ind == height) {
      // Fila del final
      printf(" ");
      for (int j = 0; j < width - 2; j++) {
        if (numbers[intNumber][4]) {
          printf("-");
        } else {
          printf(" ");
        }
      }
      printf(" ");
    } else if (ind < (height / 2) + 1) {
      if (numbers[intNumber][0]) {
        printf("|");
      } else {
        printf(" ");
      }
      for (int j = 0; j < width - 2; j++) {
        printf(" ");
      }
      if (numbers[intNumber][2]) {
        printf("|");
      } else {
        printf(" ");
      }
    } else {
      if (numbers[intNumber][5]) {
        printf("|");
      } else {
        printf(" ");
      }
      for (int j = 0; j < width - 2; j++) {
        printf(" ");
      }
      if (numbers[intNumber][3]) {
        printf("|");
      } else {
        printf(" ");
      }
    }
    if (i < numberSize - 1) {
      printf(" ");
    }
  }
}

void printNumbers(int width, int height, string number) {
  for (int i = 0; i < height; i++) {
    printLine(width, height, number, i);
    printf("\n");
  }
}

void readInput() {
  int s, width, height;
  char number[20];

  while (scanf("%d", &s) != EOF) {
    scanf("%s", number);
    // Termina el programa si encuentra un 0
    if (s == 0)
      break;

    width = s + 2;
    height = 2 * s + 3;

    printNumbers(width, height, number);
    printf("\n");
  }
}

int main() {
  readInput();
  return 0;
}
