#include <bits/stdc++.h>

using namespace std;

char one[3][2] = {{'*', '.'}, {'.', '.'}, {'.', '.'}};
char two[3][2] = {{'*', '.'}, {'*', '.'}, {'.', '.'}};
char three[3][2] = {{'*', '*'}, {'.', '.'}, {'.', '.'}};
char four[3][2] = {{'*', '*'}, {'.', '*'}, {'.', '.'}};
char five[3][2] = {{'*', '.'}, {'.', '*'}, {'.', '.'}};
char six[3][2] = {{'*', '*'}, {'*', '.'}, {'.', '.'}};
char seven[3][2] = {{'*', '*'}, {'*', '*'}, {'.', '.'}};
char eight[3][2] = {{'*', '.'}, {'*', '*'}, {'.', '.'}};
char nine[3][2] = {{'.', '*'}, {'*', '.'}, {'.', '.'}};
char zero[3][2] = {{'.', '*'}, {'*', '*'}, {'.', '.'}};

void print_decimal_to_braile(char *dec, int dec_size) {
  int j, i;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < dec_size; j++) {
      if (dec[j] == '1') {
        printf("%c%c", one[i][0], one[i][1]);
      } else if (dec[j] == '2') {
        printf("%c%c", two[i][0], two[i][1]);
      } else if (dec[j] == '3') {
        printf("%c%c", three[i][0], three[i][1]);
      } else if (dec[j] == '4') {
        printf("%c%c", four[i][0], four[i][1]);
      } else if (dec[j] == '5') {
        printf("%c%c", five[i][0], five[i][1]);
      } else if (dec[j] == '6') {
        printf("%c%c", six[i][0], six[i][1]);
      } else if (dec[j] == '7') {
        printf("%c%c", seven[i][0], seven[i][1]);
      } else if (dec[j] == '8') {
        printf("%c%c", eight[i][0], eight[i][1]);
      } else if (dec[j] == '9') {
        printf("%c%c", nine[i][0], nine[i][1]);
      } else if (dec[j] == '0') {
        printf("%c%c", zero[i][0], zero[i][1]);
      }
      if (j < dec_size - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }
}

void print_braile_to_decimal(char braile[3][1000], int braile_size) {
  int i;
  for (i = 0; i < braile_size; i += 3) {
    if (braile[0][i] == one[0][0] && braile[0][i + 1] == one[0][1] &&
        braile[1][i] == one[1][0] && braile[1][i + 1] == one[1][1]) {
      printf("1");
    } else if (braile[0][i] == two[0][0] && braile[0][i + 1] == two[0][1] &&
               braile[1][i] == two[1][0] && braile[1][i + 1] == two[1][1]) {
      printf("2");
    } else if (braile[0][i] == three[0][0] && braile[0][i + 1] == three[0][1] &&
               braile[1][i] == three[1][0] && braile[1][i + 1] == three[1][1]) {
      printf("3");
    } else if (braile[0][i] == four[0][0] && braile[0][i + 1] == four[0][1] &&
               braile[1][i] == four[1][0] && braile[1][i + 1] == four[1][1]) {
      printf("4");
    } else if (braile[0][i] == five[0][0] && braile[0][i + 1] == five[0][1] &&
               braile[1][i] == five[1][0] && braile[1][i + 1] == five[1][1]) {
      printf("5");
    } else if (braile[0][i] == six[0][0] && braile[0][i + 1] == six[0][1] &&
               braile[1][i] == six[1][0] && braile[1][i + 1] == six[1][1]) {
      printf("6");
    } else if (braile[0][i] == seven[0][0] && braile[0][i + 1] == seven[0][1] &&
               braile[1][i] == seven[1][0] && braile[1][i + 1] == seven[1][1]) {
      printf("7");
    } else if (braile[0][i] == eight[0][0] && braile[0][i + 1] == eight[0][1] &&
               braile[1][i] == eight[1][0] && braile[1][i + 1] == eight[1][1]) {
      printf("8");
    } else if (braile[0][i] == nine[0][0] && braile[0][i + 1] == nine[0][1] &&
               braile[1][i] == nine[1][0] && braile[1][i + 1] == nine[1][1]) {
      printf("9");
    } else if (braile[0][i] == zero[0][0] && braile[0][i + 1] == zero[0][1] &&
               braile[1][i] == zero[1][0] && braile[1][i + 1] == zero[1][1]) {
      printf("0");
    }
  }
  printf("\n");
}

void solve() {
  int n;
  while (scanf("%d", &n) != EOF && n) {
    char option;
    char dec[222];
    char braile[3][1000];
    scanf(" %c", &option);
    getchar();
    if (option == 'S') {
      fgets(dec, 222, stdin);
      print_decimal_to_braile(dec, n);
    } else {
      fgets(braile[0], 1000, stdin);
      fgets(braile[1], 1000, stdin);
      fgets(braile[2], 1000, stdin);
      print_braile_to_decimal(braile, (n * 3) - 1);
    }
  }
}

int main() {
  solve();
  return 0;
}
