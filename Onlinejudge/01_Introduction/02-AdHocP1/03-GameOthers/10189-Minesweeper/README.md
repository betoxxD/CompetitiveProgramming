# Intuición
El problema de Minesweeper se trata de transformar un campo de minas representado por caracteres '\*' y '.' en una matriz donde cada '.' es reemplazado por el número de minas adyacentes. Si el carácter es una mina ('\*'), se queda igual.

# Enfoque
1. Representación de la matriz: Usamos una matriz board de tamaño 105x105 (para evitar desbordamientos de arreglos, se agregan 5 espacios más) para representar el campo. Inicialmente, convertimos los caracteres '*' en -1 y los '.' en 0.
2. Expansión de las minas: Para cada mina encontrada, incrementamos los contadores de sus celdas adyacentes (máximo 8 adyacentes) si no son minas.
3. Construcción de la salida: Transformamos la matriz board en su representación final y la imprimimos, incluyendo la gestión del formato de salida requerido.

# Complejidad
- Complejidad de tiempo: $O(n \cdot m)$ donde $n$ y $m$ son las dimensiones del tablero. Debido a que la matriz board es de un tamaño pequeño (105x105), la complejidad es aceptable.
- Complejidad de espacio: $O(n \cdot m)$ donde $n$ y $m$ son las dimensiones del tablero. La matriz board es de tamaño $n \cdot m$.

# Código
```cpp
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

```
