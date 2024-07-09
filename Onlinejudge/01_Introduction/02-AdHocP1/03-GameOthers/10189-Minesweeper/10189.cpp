#include <bits/stdc++.h>

using namespace std;

int board[105][105];

// Imprime el tablero
void printBoard(int n, int m) {
  char charPrint;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      // Si es bomba, imprime '*'
      // Si no, imprime el número de bombas adyacentes
      charPrint = board[i][j] == -1 ? '*' : '0' + board[i][j];
      printf("%c", charPrint);
    }
    printf("\n");
  }
}

// Marca las casillas adyacentes a la bomba
void expandBomb(int n, int m) {
  // Expandir arriba
  if (board[n - 1][m] != -1) {
    board[n - 1][m]++;
  }
  // Expandir arriba izquierda
  if (board[n - 1][m - 1] != -1) {
    board[n - 1][m - 1]++;
  }
  // Expandir arriba izquierda
  if (board[n - 1][m + 1] != -1) {
    board[n - 1][m + 1]++;
  }
  // Expandir izquierda
  if (board[n][m - 1] != -1) {
    board[n][m - 1]++;
  }
  // Expandir derecha
  if (board[n][m + 1] != -1) {
    board[n][m + 1]++;
  }
  // Expandir abajo
  if (board[n + 1][m] != -1) {
    board[n + 1][m]++;
  }
  // Expandir abajo izquierda
  if (board[n + 1][m - 1] != -1) {
    board[n + 1][m - 1]++;
  }
  // Expandir abajo izquierda
  if (board[n + 1][m + 1] != -1) {
    board[n + 1][m + 1]++;
  }
}

// Recorre el tablero y llena las casillas adyacentes a las bombas
void fillBoard(int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (board[i][j] == -1) {
        expandBomb(i, j);
      }
    }
  }
}

// Convierte el tablero de caracteres a numeros
// -1 si es bomba
// 0 si no es bomba
void charToNumberBoard(int n, int m, char in) {
  int rep = in == '*' ? -1 : 0;
  board[n][m] = rep;
}

void readInput() {
  int n, m;
  char in;
  int field = 1;
  while (scanf("%d%d", &n, &m) != EOF && n != 0 && m != 0) {
    // Imprime un salto de linea entre los tableros
    if (field != 1)
      printf("\n");
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        scanf(" %c", &in);
        charToNumberBoard(i, j, in);
      }
    }
    fillBoard(n, m);
    printf("Field #%d:\n", field++);
    printBoard(n, m);
  }
}

int main() {
  readInput();
  return 0;
}
