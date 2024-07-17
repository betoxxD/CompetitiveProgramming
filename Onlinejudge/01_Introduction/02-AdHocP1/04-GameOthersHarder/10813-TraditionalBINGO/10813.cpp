#include <bits/stdc++.h>

using namespace std;

// Matriz para almacenar si ya pasó algún número en la carta
int card[6][6];
// hashmap para el almacenamiento de la posición de un número determinado
// (también es posible resolverse mediante el uso de cubetas por el pequeño
// tamaño de los números).
unordered_map<int, int> positions;

void printCard() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", card[i][j]);
    }
    printf("\n");
  }
}

// Limpia las estructuras utilizadas para almacenar los datos
void clearCard() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      card[i][j] = 0;
    }
  }
  positions.clear();
}

// Convierte una posición de (x,y) a su número correspondiente si se contara
// de izquierda a derecha y de arriba para abajo
int posToNumber(int x, int y) { return (x * 5) + y; }

// Marca el número si ya salió en la cuenta
void markNumber(int ball) {
  // Obtiene la posición almacenada en el hashmap
  int pos = positions[ball];
  // Si la posición no es 0, la convierte a cordenadas y marca el número en la
  // carta
  if (pos != 0) {
    pos--;
    int x = pos / 5;
    int y = pos % 5;
    card[x][y] = -1;
  }
}

// Checa si alguna de las condiciones de victoria se cumplen
bool checkIfWin() {
  /*printCard();*/
  bool win = true;
  // Verificar horizontalmente
  for (int i = 0; i < 5; i++) {
    win = true;
    for (int j = 0; j < 5; j++) {
      if (card[i][j] == 0) {
        win = false;
        break;
      }
    }
    if (win) {
      return true;
    }
  }

  // Verificar verticalmente
  for (int i = 0; i < 5; i++) {
    win = true;
    for (int j = 0; j < 5; j++) {
      if (card[j][i] == 0) {
        win = false;
        break;
      }
    }
    if (win) {
      return true;
    }
  }

  // Verificar vertical izquierda
  win = true;
  for (int i = 0; i < 5; i++) {
    if (card[i][i] == 0) {
      win = false;
      break;
    }
  }
  if (win) {
    return true;
  }
  // Verificar vertical derecha
  win = true;
  for (int i = 0; i < 5; i++) {
    if (card[i][4 - i] == 0) {
      win = false;
      break;
    }
  }
  if (win) {
    return true;
  }
  return false;
}

void readInput() {
  int n;
  scanf("%d", &n);
  int in;
  int pos;
  int ball;
  bool win;
  while (n--) {
    clearCard();
    win = false;
    // Lee la carta. Si llega a la posición 12 (la casilla de en medio)
    // inmediatamente la marca como pasada.
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        pos = posToNumber(i, j);
        if (pos == 12) {
          card[i][j] = -1;
        } else {
          scanf("%d", &in);
          // Se almacena la posición del número en el número correspondiente
          // dentro del hashmap
          positions[in] = pos + 1;
        }
      }
    }

    for (int i = 1; i <= 75; i++) {
      scanf("%d", &ball);
      // Si no ha ganado, continua marcando
      if (!win) {
        markNumber(ball);
        // Si detecta que ganó, imprime el resultado y pone la bandera win en
        // true para que no siga imprimiendo el resultado.
        win = checkIfWin();
        if (win) {
          printf("BINGO after %d numbers announced\n", i);
        }
      }
    }
  }
}

int main() {
  readInput();
  return 0;
}
