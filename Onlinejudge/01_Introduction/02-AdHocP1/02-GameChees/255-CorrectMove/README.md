
# Intuición
El problema implica verificar y validar movimientos de un rey y una reina en un tablero de ajedrez de 8x8, asegurándose de que las piezas no se superpongan y que sus movimientos sean legales según las reglas descritas. La solución debe también verificar si el rey está bloqueado después de un movimiento de la reina.

# Enfoque
1. Representar el tablero y las posiciones de las piezas.
2. Verificar si el estado inicial es legal (las piezas no están en la misma posición).
3. Verificar si el movimiento de la reina es legal (no violar las reglas).
4. Verificar si el movimiento de la reina está permitido (no debe moverse a una posición accesible por el rey).
5. Después de un movimiento válido, verificar si el rey está bloqueado en su nueva posición.

# Complejidad
- Complejidad de tiempo: O(1) por cada consulta debido a las operaciones limitadas en un tablero de tamaño fijo.
- Complejidad de espacio: O(1) para almacenar el tablero y las posiciones de las piezas.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

int table[10][10] = {0}; // Representa el tablero

// Función para limpiar el tablero
void clearTable() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      table[i][j] = 0;
    }
  }
}

// Función para obtener la coordenada X de una posición en el tablero
int getX(int number) { return (number / 8); }

// Función para obtener la coordenada Y de una posición en el tablero
int getY(int number) { return (number % 8); }

// Función para configurar el tablero con las posiciones del rey y la reina
void makeTable(int kingPos, int queenPos) {
  clearTable();
  int kingX = getX(kingPos);
  int kingY = getY(kingPos);
  table[kingX][kingY] = 2; // Marca la posición del rey y sus movimientos posibles
  if (kingX > 0) table[kingX - 1][kingY] = 2;
  if (kingX < 7) table[kingX + 1][kingY] = 2;
  if (kingY > 0) table[kingX][kingY - 1] = 2;
  if (kingY < 7) table[kingX][kingY + 1] = 2;

  int queenX = getX(queenPos);
  int queenY = getY(queenPos);
  table[queenX][queenY] = 1; // Marca la posición de la reina y sus movimientos posibles (si se topa con una posición a la que podría estar el rey, se marca con un 3 para identificarlo, si no, se marca con un 1).
  // Si se topa con la posición del rey, termina su camino por ese eje hacia la direcicón que iba
  for (int i = queenX - 1; i >= 0; i--) {
    if (table[i][queenY] == 2) {
      table[i][queenY] = 3;
      if (kingY == queenY) break;
    } else {
      table[i][queenY] = 1;
    }
  }
  for (int i = queenX + 1; i < 8; i++) {
    if (table[i][queenY] == 2) {
      table[i][queenY] = 3;
      if (kingY == queenY) break;
    } else {
      table[i][queenY] = 1;
    }
  }
  for (int i = queenY - 1; i >= 0; i--) {
    if (table[queenX][i] == 2) {
      table[queenX][i] = 3;
      if (queenX == kingX) break;
    } else {
      table[queenX][i] = 1;
    }
  }
  for (int i = queenY + 1; i < 8; i++) {
    if (table[queenX][i] == 2) {
      table[queenX][i] = 3;
      if (queenX == kingX) break;
    } else {
      table[queenX][i] = 1;
    }
  }
  // Regresar su valor al rey en caso de toparse con el
  table[kingX][kingY] = 2;
}

// Función para configurar el tablero con la nueva posición de la reina
void makeQueenTable(int queenPos) {
  clearTable();
  int queenX = getX(queenPos);
  int queenY = getY(queenPos);
  table[queenX][queenY] = 2; // Marca la posición de la reina y su primer movimiento posible (para verificar si el rey puede moverse a esos lugares)
  if (queenX > 0) table[queenX - 1][queenY] = 2;
  if (queenX < 7) table[queenX + 1][queenY] = 2;
  if (queenY > 0) table[queenX][queenY - 1] = 2;
  if (queenY < 7) table[queenX][queenY + 1] = 2;
}

// Función para verificar si el rey puede moverse
bool kingCanMove(int kingPos) {
  bool moveBack = false, moveFront = false, moveUp = false, moveDown = false;
  int kingX = getX(kingPos);
  int kingY = getY(kingPos);

  if (kingX > 0 && table[kingX - 1][kingY] == 0) moveUp = true;
  if (kingX < 7 && table[kingX + 1][kingY] == 0) moveDown = true;
  if (kingY > 0 && table[kingX][kingY - 1] == 0) moveBack = true;
  if (kingY < 7 && table[kingX][kingY + 1] == 0) moveFront = true;

  return moveBack || moveFront || moveUp || moveDown;
}

// Función para determinar el resultado de acuerdo con las reglas del problema
string getResult(int kingPos, int queenPos, int newQueenPos) {
  string result = "";
  int queenX = getX(queenPos);
  int queenY = getY(queenPos);
  int newQueenX = getX(newQueenPos);
  int newQueenY = getY(newQueenPos);
  if (kingPos == queenPos) {
    result = "Illegal state";
  } else if (table[newQueenX][newQueenY] == 0 ||
             table[newQueenX][newQueenY] == 2 ||
             (queenX == newQueenX && queenY == newQueenY)) {
    result = "Illegal move";
  } else if (table[newQueenX][newQueenY] == 3) {
    result = "Move not allowed";
  } else {
    makeQueenTable(newQueenPos);
    if (kingCanMove(kingPos)) {
      result = "Continue";
    } else {
      result = "Stop";
    }
  }
  return result;
}

// Función para leer la entrada y procesar cada línea
void readInput() {
  int kingPos;
  int queenPos;
  int newQueenPos;
  while (scanf("%d", &kingPos) != EOF) {
    scanf("%d%d", &queenPos, &newQueenPos);
    makeTable(kingPos, queenPos);
    printf("%s\n", getResult(kingPos, queenPos, newQueenPos).c_str());
  }
}

int main() {
  readInput();
  return 0;
}

