# Intuición
El objetivo del juego "Serpientes y Escaleras" es mover a los jugadores en un tablero de 100 casillas según los resultados de los dados, teniendo en cuenta las serpientes y escaleras que modifican las posiciones. El juego termina cuando un jugador alcanza o supera la casilla 100.

# Enfoque
1. Leer el número de casos de prueba.
2. Para cada caso de prueba:
    * Inicializar el juego y las posiciones de los jugadores.
    * Leer las posiciones de las serpientes y escaleras.
    * Leer los resultados de los dados y mover a los jugadores en consecuencia.
    * Actualizar las posiciones de los jugadores considerando las serpientes y escaleras.
    * Finalizar el juego si un jugador alcanza o supera la casilla 100.
3. Imprimir las posiciones finales de los jugadores.

# Complejidad
- Complejidad de tiempo: $O(n)$ debido a que el resultado se obtiene de forma lineal.
- Complejidad de espacio: $O(n)$ debido a que se almacenan las posiciones de los jugadores y las serpientes y escaleras.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

// Almacena la posición de las serpientes y escaleras y hacia donde llevan
unordered_map<int, int> snakesAndLaders;
unordered_map<int, int> playersPosition;

// Bandera para verificar si el juego finalizó
bool gameFinished;

// Limpia el juego
void clearGame() {
  gameFinished = false;
  snakesAndLaders.clear();
  playersPosition.clear();
}

// Mueve al jugador en el tablero
void movePlayer(int player, int diceResult) {
  // Si el juego ya finalizó, no se hace nada
  if (gameFinished) {
    return;
  }
  // Se obtiene la posición actual del jugador
  int currentPosition = playersPosition[player];
  // Se calcula la nueva posición del jugador
  int newPosition = currentPosition + diceResult;
  // Si la nueva posición está en una serpiente o escalera, se mueve a la nueva
  // posición
  if (snakesAndLaders[newPosition] != 0) {
    newPosition = snakesAndLaders[newPosition];
  }
  // El juego finaliza si la nueva posición es mayor o igual a 100
  if (newPosition >= 100) {
    newPosition = 100;
    gameFinished = true;
  }
  playersPosition[player] = newPosition;
}

void readInput() {
  int n;
  int a, b, c;
  int init, fin;
  int dice;
  int currentPlayer;
  int diceResult;
  scanf("%d", &n);
  while (n--) {
    // Se inicializan las variables
    clearGame();
    currentPlayer = 1;
    scanf("%d%d%d", &a, &b, &c);
    // Leyendo las serpientes y escaleras
    while (b--) {
      scanf("%d%d", &init, &fin);
      snakesAndLaders[init] = fin;
    }
    // Inicializando las posiciones de los jugadores en 1
    for (int i = 1; i <= a; i++) {
      playersPosition[i] = 1;
    }
    // Tirando los dados
    while (c--) {
      scanf("%d", &diceResult);
      movePlayer(currentPlayer, diceResult);
      // Se pasa al siguiente jugador
      currentPlayer = currentPlayer + 1 > a ? 1 : currentPlayer + 1;
    }
    // Imprimiendo las posiciones finales de los jugadores
    for (int i = 1; i <= a; i++) {
      printf("Position of player %d is %d.\n", i, playersPosition[i]);
    }
  }
}

int main() {
  readInput();
  return 0;
}

```
