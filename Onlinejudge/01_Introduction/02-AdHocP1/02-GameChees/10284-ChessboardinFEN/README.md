# Intuición
Dado un tablero de ajedrez en notación FEN (Forsyth-Edwards Notation), debemos determinar el número de casillas no ocupadas que no están siendo atacadas por ninguna pieza. La solución implica traducir la notación FEN a un tablero de ajedrez, marcar las casillas atacadas por las piezas, y contar las casillas no ocupadas y no atacadas.
 
# Enfoque
1. Leer la entrada: Obtener la notación FEN del tablero.
2. Convertir la FEN a un tablero: Traducir la notación FEN a una matriz bidimensional que representa el tablero.
3. Marcar casillas atacadas: Identificar y marcar todas las casillas atacadas por cada tipo de pieza en el tablero.
4. Contar casillas seguras: Contar las casillas que están vacías y no atacadas.
5. Mostrar el resultado: Imprimir el número de casillas no atacadas para cada línea de entrada.

# Complejidad
- Complejidad de tiempo: $O(1)$, debido a que el tamaño del tablero es constante (8x8).

- Complejidad de espacio: $O(1)$, ya que el tamaño del tablero es constante (8x8).

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

char board[10][10];

// Limpia el tablero
void clearBoard() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      board[i][j] = '0';
    }
  }
}

// Imprime el tablero (solo para debug)
void printBoard() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

// Ataque de la torre
void atackRook(int x, int y) {
  // Expandir hacia arriba
  for (int i = x - 1; i >= 0; i--) {
    if (!isdigit(board[i][y])) {
      break;
    }
    board[i][y] = '1';
  }
  // Expandir hacia abajo
  for (int i = x + 1; i < 8; i++) {
    if (!isdigit(board[i][y])) {
      break;
    }
    board[i][y] = '1';
  }

  // Expandir hacia izquierda
  for (int i = y - 1; i >= 0; i--) {
    if (!isdigit(board[x][i])) {
      break;
    }
    board[x][i] = '1';
  }
  // Expandir hacia derecha
  for (int i = y + 1; i < 8; i++) {
    if (!isdigit(board[x][i])) {
      break;
    }
    board[x][i] = '1';
  }
}

// Ataque del caballo
void atackKnight(int x, int y) {
  // Ataque hacia arriba
  if (x - 2 >= 0) {
    // Ataque arriba a la izquierda
    if (y - 1 >= 0) {
      if (isdigit(board[x - 2][y - 1])) {
        board[x - 2][y - 1] = '1';
      }
    }
    // Ataque arriba a la derecha
    if (y + 1 < 8) {
      if (isdigit(board[x - 2][y + 1])) {
        board[x - 2][y + 1] = '1';
      }
    }
  }
  // Ataque hacia abajo
  if (x + 2 < 8) {
    // Ataque abajo a la izquierda
    if (y - 1 >= 0) {
      if (isdigit(board[x + 2][y - 1])) {
        board[x + 2][y - 1] = '1';
      }
    }
    // Ataque abajo a la derecha
    if (y + 1 < 8) {
      if (isdigit(board[x + 2][y + 1])) {
        board[x + 2][y + 1] = '1';
      }
    }
  }

  // Ataque hacia la izquierda
  if (y - 2 >= 0) {
    // Ataque izquierda arriba
    if (x - 1 >= 0) {
      if (isdigit(board[x - 1][y - 2])) {
        board[x - 1][y - 2] = '1';
      }
    }
    // Ataque izquierda abajo
    if (x + 1 < 8) {
      if (isdigit(board[x + 1][y - 2])) {
        board[x + 1][y - 2] = '1';
      }
    }
  }
  // Ataque hacia derecha
  if (y + 2 < 8) {
    // Ataque derecha arriba
    if (x - 1 >= 0) {
      if (isdigit(board[x - 1][y + 2])) {
        board[x - 1][y + 2] = '1';
      }
    }
    // Ataque derecha abajo
    if (x + 1 < 8) {
      if (isdigit(board[x + 1][y + 2])) {
        board[x + 1][y + 2] = '1';
      }
    }
  }
}

// Ataque del alfil
void atackBishop(int x, int y) {
  // Atack top left
  int posX = x - 1, posY = y - 1;
  while (posX >= 0 && posY >= 0) {
    if (!isdigit(board[posX][posY])) {
      break;
    }
    board[posX][posY] = '1';
    posX--;
    posY--;
  }
  // Atack top rigth
  posX = x - 1, posY = y + 1;
  while (posX >= 0 && posY < 8) {
    if (!isdigit(board[posX][posY])) {
      break;
    }
    board[posX][posY] = '1';
    posX--;
    posY++;
  }
  // Atack bottom left
  posX = x + 1, posY = y - 1;
  while (posX < 8 && posY >= 0) {
    if (!isdigit(board[posX][posY])) {
      break;
    }
    board[posX][posY] = '1';
    posX++;
    posY--;
  }
  // Atack bottom rigth
  posX = x + 1, posY = y + 1;
  while (posX < 8 && posY < 8) {
    if (!isdigit(board[posX][posY])) {
      break;
    }
    board[posX][posY] = '1';
    posX++;
    posY++;
  }
}

// Ataque de la reina
void atackQueen(int x, int y) {
  atackRook(x, y);   // Combina el ataque de la torre
  atackBishop(x, y); // con el ataque del alfil
}

// Ataque del rey
void atackKing(int x, int y) {
  // Atack top
  if (x - 1 >= 0) {
    // Atack top left
    if (y - 1 >= 0) {
      if (isdigit(board[x - 1][y - 1])) {
        board[x - 1][y - 1] = '1';
      }
    }
    // Atack top rigth
    if (y + 1 < 8) {
      if (isdigit(board[x - 1][y + 1])) {
        board[x - 1][y + 1] = '1';
      }
    }
    // Atack only top
    if (isdigit(board[x - 1][y])) {
      board[x - 1][y] = '1';
    }
  }

  // Atack bottom
  if (x + 1 < 8) {
    // Atack bottom left
    if (y - 1 >= 0) {
      if (isdigit(board[x + 1][y - 1])) {
        board[x + 1][y - 1] = '1';
      }
    }
    // Atack bottom rigth
    if (y + 1 < 8) {
      if (isdigit(board[x + 1][y + 1])) {
        board[x + 1][y + 1] = '1';
      }
    }
    // Atack only bottom
    if (isdigit(board[x + 1][y])) {
      board[x + 1][y] = '1';
    }
  }

  // Atack left
  if (y - 1 >= 0) {
    // Atack top left
    if (x - 1 >= 0) {
      if (isdigit(board[x - 1][y - 1])) {
        board[x - 1][y - 1] = '1';
      }
    }
    // Atack bottom left
    if (x + 1 < 8) {
      if (isdigit(board[x + 1][y - 1])) {
        board[x + 1][y - 1] = '1';
      }
    }
    // Atack only left
    if (isdigit(board[x][y - 1])) {
      board[x][y - 1] = '1';
    }
  }

  // Atack right
  if (y + 1 < 8) {
    // Atack top right
    if (x - 1 >= 0) {
      if (isdigit(board[x - 1][y + 1])) {
        board[x - 1][y + 1] = '1';
      }
    }
    // Atack bottom rigth
    if (x + 1 < 8) {
      if (isdigit(board[x + 1][y + 1])) {
        board[x + 1][y + 1] = '1';
      }
    }
    // Atack only right
    if (isdigit(board[x][y + 1])) {
      board[x][y + 1] = '1';
    }
  }
}

// Ataque de peones
void atackPawn(int x, int y, char piece) {
  if (piece == 'p') {
    // Pieza negra
    if (x + 1 < 8) {
      // Ataque a la izquierda
      if (y - 1 >= 0) {
        if (isdigit(board[x + 1][y - 1])) {
          board[x + 1][y - 1] = '1';
        }
      }
      // Ataque a la derecha
      if (y + 1 < 8) {
        if (isdigit(board[x + 1][y + 1])) {
          board[x + 1][y + 1] = '1';
        }
      }
    }
  } else {
    // Pieza blanca
    if (x - 1 >= 0) {
      // Ataque a la izquierda
      if (y - 1 >= 0) {
        if (isdigit(board[x - 1][y - 1])) {
          board[x - 1][y - 1] = '1';
        }
      }
      // Ataque a la derecha
      if (y + 1 < 8) {
        if (isdigit(board[x - 1][y + 1])) {
          board[x - 1][y + 1] = '1';
        }
      }
    }
  }
}

// Calcula los espacios que atacan las piezas
void atack() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] == 'r' || board[i][j] == 'R') {
        atackRook(i, j);
      } else if (board[i][j] == 'n' || board[i][j] == 'N') {
        atackKnight(i, j);
      } else if (board[i][j] == 'b' || board[i][j] == 'B') {
        atackBishop(i, j);
      } else if (board[i][j] == 'q' || board[i][j] == 'Q') {
        atackQueen(i, j);
      } else if (board[i][j] == 'k' || board[i][j] == 'K') {
        atackKing(i, j);
      } else if (board[i][j] == 'p' || board[i][j] == 'P') {
        atackPawn(i, j, board[i][j]);
      }
    }
  }
  /*printBoard();*/
}

// Cuenta los espacios libres en el tablero
int countFreeSpaces() {
  int cont = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board[i][j] == '0') {
        cont++;
      }
    }
  }
  return cont;
}

// Convierte una cadena FEN a un tablero
void FENToBoard(string FEN) {
  // Limpiar tablero
  clearBoard();
  int FENSize = FEN.size();
  int posX = 0, posY = 0;
  int digitValue;
  for (int i = 0; i < FENSize; i++) {
    if (isdigit(FEN[i])) { // Es un número
      digitValue = FEN[i] - '0';
      posY += digitValue;
    } else if (FEN[i] == '/') { // Cambio de fila
      posX++;
      posY = 0;
    } else { // Es una pieza
      board[posX][posY] = FEN[i];
      posY++;
    }
  }
  /*printBoard();*/
}

void readInput() {
  char input[100];
  while (scanf("%s", input) != EOF) {
    FENToBoard(input);
    atack();
    printf("%d\n", countFreeSpaces());
  }
}

int main() {
  readInput();
  return 0;
}

```
