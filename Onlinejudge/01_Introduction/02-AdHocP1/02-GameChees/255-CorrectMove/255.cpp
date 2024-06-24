#include <bits/stdc++.h>

using namespace std;

int table[10][10] = {0};

void clearTable() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      table[i][j] = 0;
    }
  }
}

void printTable() {

  printf("-------------------------------------------\n");
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      printf("%d ", table[i][j]);
    }
    printf("\n");
  }

  printf("-------------------------------------------\n");
  getchar();
}

int getX(int number) { return (number / 8); }
int getY(int number) { return (number % 8); }

void makeTable(int kingPos, int queenPos) {
  clearTable();
  int kingX = getX(kingPos);
  int kingY = getY(kingPos);
  table[kingX][kingY] = 2;
  if (kingX > 0)
    table[kingX - 1][kingY] = 2;
  if (kingX < 7)
    table[kingX + 1][kingY] = 2;
  if (kingY > 0)
    table[kingX][kingY - 1] = 2;
  if (kingY < 7)
    table[kingX][kingY + 1] = 2;

  int queenX = getX(queenPos);
  int queenY = getY(queenPos);
  table[queenX][queenY] = 1;
  for (int i = queenX - 1; i >= 0; i--) {
    if (table[i][queenY] == 2) {
      table[i][queenY] = 3;
      if (kingY == queenY) {
        break;
      }
    } else {
      table[i][queenY] = 1;
    }
  }
  for (int i = queenX + 1; i < 8; i++) {
    if (table[i][queenY] == 2) {
      table[i][queenY] = 3;
      if (kingY == queenY) {
        break;
      }
    } else {
      table[i][queenY] = 1;
    }
  }
  for (int i = queenY - 1; i >= 0; i--) {
    if (table[queenX][i] == 2) {
      table[queenX][i] = 3;
      if (queenX == kingX) {
        break;
      }
    } else {
      table[queenX][i] = 1;
    }
  }
  for (int i = queenY + 1; i < 8; i++) {
    if (table[queenX][i] == 2) {
      table[queenX][i] = 3;
      if (queenX == kingX) {
        break;
      }
    } else {
      table[queenX][i] = 1;
    }
  }
  table[kingX][kingY] = 2;
  /*printTable();*/
}

void makeQueenTable(int queenPos) {
  clearTable();
  int queenX = getX(queenPos);
  int queenY = getY(queenPos);
  table[queenX][queenY] = 2;
  if (queenX > 0)
    table[queenX - 1][queenY] = 2;
  if (queenX < 7)
    table[queenX + 1][queenY] = 2;
  if (queenY > 0)
    table[queenX][queenY - 1] = 2;
  if (queenY < 7)
    table[queenX][queenY + 1] = 2;
  /*printTable();*/
}

bool kingCanMove(int kingPos) {
  bool moveBack = false, moveFront = false, moveUp = false, moveDown = false;
  int kingX = getX(kingPos);
  int kingY = getY(kingPos);

  if (kingX > 0 && table[kingX - 1][kingY] == 0)
    moveUp = true;
  if (kingX < 7 && table[kingX + 1][kingY] == 0)
    moveDown = true;
  if (kingY > 0 && table[kingX][kingY - 1] == 0)
    moveBack = true;
  if (kingY < 7 && table[kingX][kingY + 1] == 0)
    moveFront = true;

  return moveBack || moveFront || moveUp || moveDown;
}

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
