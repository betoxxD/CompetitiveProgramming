#include <bits/stdc++.h>

using namespace std;

// Función que calcula el puntaje de un juego de bolos
int calculateScore(string score) {
  int scoreSize = score.size();
  int sum;
  int games = 0;
  for (int i = 0; i < scoreSize;) {
    // Si ya se han jugado 10 juegos, se termina el ciclo
    if (games == 10) {
      break;
    }
    // Si el caracter actual es un número y el siguiente también, se suman ambos
    if (isdigit(score[i]) && isdigit(score[i + 1])) {
      sum += score[i] - '0' + score[i + 1] - '0';
      i += 2;
      // Si el caracter actual es un número y el siguiente es un spare, se suman
      // 10 puntos y el siguiente score
    } else if (isdigit(score[i]) && score[i + 1] == '/') {
      sum += 10;
      if (isdigit(score[i + 2])) {
        sum += score[i + 2] - '0';
      } else {
        sum += 10;
      }
      i += 2;
      // Si el caracter actual es un strike, se suman 10 puntos y los siguientes
      // dos scores
    } else {
      sum += 10;
      if (isdigit(score[i + 1])) {
        if (isdigit(score[i + 2])) {
          sum += score[i + 1] - '0' + score[i + 2] - '0';
        } else {
          sum += 10;
        }
      } else {
        sum += 10;
        if (isdigit(score[i + 2])) {
          sum += score[i + 2] - '0';
        } else {
          sum += 10;
        }
      }
      i++;
    }
    games++;
  }

  return sum;
}

void readInput() {
  char input[100] = "";
  int inputLenght;
  int position = 0;
  int sum = 0;
  string cleanInput;
  while (strcmp(input, "Game Over") != 0) {
    cleanInput = "";
    fgets(input, 100, stdin);
    // Elimina el salto de línea
    input[strcspn(input, "\n")] = 0;
    // Si el input es "Game Over", se termina el ciclo
    if (strcmp(input, "Game Over") == 0) {
      break;
    }
    inputLenght = strlen(input);
    // Se eliminan los espacios del input
    for (int i = 0; i < inputLenght; i++) {
      if (input[i] != ' ') {
        cleanInput += input[i];
      }
    }
    printf("%d\n", calculateScore(cleanInput));
  }
}

int main() {
  readInput();
  return 0;
}
