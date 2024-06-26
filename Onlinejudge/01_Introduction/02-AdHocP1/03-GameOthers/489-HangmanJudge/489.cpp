#include <bits/stdc++.h>

using namespace std;

// Inicialización de cubetas para la revisión de letras
bool bucket[200];
bool bucketPassed[200];

// Limpia las cubetas
void clearBucket() {
  for (int i = 'a'; i <= 'z'; i++) {
    bucket[i] = false;
  }
  for (int i = 'a'; i <= 'z'; i++) {
    bucketPassed[i] = false;
  }
}

// Llena la cubeta con las letras de la solución
void fillBucket(string solution) {
  clearBucket();
  int solutionSize = solution.size();
  for (int i = 0; i < solutionSize; i++) {
    bucket[solution[i]] = true;
  }
}

// Revisa si el jugador ganó
bool checkIfWin(string guess, string solution) {
  bool win = true;
  int solutionSize = solution.size();
  // Revisa si todas las letras de la solución están en el arreglo de letras
  // adivinadas
  for (int i = 0; i < solutionSize; i++) {
    if (!bucketPassed[solution[i]]) {
      win = false;
      break;
    }
  }
  return win;
}

// Revisa el resultado del juego
string checkGameResult(string guess, string solution) {
  string result = "";
  int life = 7;
  bool loose = false;
  bool win = false;
  int guessSize = guess.size();
  for (int i = 0; i < guessSize; i++) {
    // Si la letra no está en la solución y no ha sido adivinada, se resta una
    if (!bucket[guess[i]]) {
      if (!bucketPassed[guess[i]]) {
        life--;
        // Si la vida llega a 0, se pierde
        if (life == 0) {
          result = "You lose.";
          loose = true;
          break;
        }
      }
    }
    // Se marca la letra como pasada
    bucketPassed[guess[i]] = true;
    // Si el jugador adivina la palabra, gana
    win = checkIfWin(guess, solution);
    if (win) {
      result = "You win.";
      break;
    }
  }
  // Si no se ha perdido ni ganado, se imprime que se retiró
  if (!loose && !win) {
    result = "You chickened out.";
  }
  return result;
}

void readInput() {
  int n;
  char solution[100000];
  char guess[100000];
  while (scanf("%d", &n) != EOF && n != -1) {
    scanf("%s", solution);
    scanf("%s", guess);
    fillBucket(solution);
    printf("Round %d\n%s\n", n, checkGameResult(guess, solution).c_str());
  }
}

int main() {
  readInput();
  return 0;
}
