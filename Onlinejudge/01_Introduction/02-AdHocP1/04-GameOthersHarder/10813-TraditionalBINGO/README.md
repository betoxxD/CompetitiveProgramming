# Intuición
Para resolver el problema de determinar cuándo un jugador gana un juego de Bingo dado un único cartón y una secuencia de números anunciados, debemos simular el proceso del juego. Esto incluye marcar los números anunciados en el cartón y verificar después de cada número si se ha completado una línea horizontal, vertical o diagonal.

# Enfoque
1. Lectura de Entrada: Leer el número de juegos que se analizarán.
2. Inicialización de la Carta: Para cada juego, inicializar el cartón y un mapa para rastrear las posiciones de los números.
3. Marcar Números: A medida que se anuncian los números, marcarlos en el cartón.
4. Verificación de Victoria: Después de cada número anunciado, verificar si alguna de las condiciones de victoria (línea horizontal, vertical o diagonal) se cumple.
5. Salida de Resultados: Imprimir el número de números anunciados hasta que se declare "BINGO".

# Complejidad
- Complejidad de tiempo: $O(n * 75)$, donde n es el número de juegos y 75 es el número máximo de números anunciados en cada juego.
- Complejidad de espacio: $O(1)$ debido a la poca cantidad de números dentro del bingo.

# Código
```cpp
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

```
