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
