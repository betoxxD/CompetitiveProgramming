#include <bits/stdc++.h>

using namespace std;

void initMaps(char pRobot_map[15][15], char pReal_map[15][15]) {
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      pRobot_map[i][j] = '?';
      pReal_map[i][j] = 'D';
    }
  }
}

int searchPaths(int x, int y, char pRobot_map[15][15], char pReal_map[15][15]) {
  pRobot_map[x][y] = '0';
  pReal_map[x][y] = 'P';
  int first_location = 0;

  if (pReal_map[x - 1][y] == '0') {
    first_location = 1;
  } else if (pReal_map[x][y + 1] == '0') {
    first_location = 2;
  } else if (pReal_map[x + 1][y] == '0') {
    first_location = 3;
  } else if (pReal_map[x][y - 1] == '0') {
    first_location = 4;
  }

  pRobot_map[x - 1][y] = pReal_map[x - 1][y] != 'P' ? pReal_map[x - 1][y] : '0';
  pRobot_map[x][y + 1] = pReal_map[x][y + 1] != 'P' ? pReal_map[x][y + 1] : '0';
  pRobot_map[x + 1][y] = pReal_map[x + 1][y] != 'P' ? pReal_map[x + 1][y] : '0';
  pRobot_map[x][y - 1] = pReal_map[x][y - 1] != 'P' ? pReal_map[x][y - 1] : '0';

  return first_location;
}

void printMap(int size_x, int size_y, char pRobot_map[15][15]) {
  int i, j;
  printf("\n");
  for (i = 0; i < size_y; i++) {
    printf("|---");
  }
  printf("|\n");

  for (i = 1; i <= size_x; i++) {
    for (j = 1; j <= size_y; j++) {
      printf("| %c ", pRobot_map[i][j]);
    }
    printf("|\n");
    for (j = 0; j < size_y; j++) {
      printf("|---");
    }
    printf("|\n");
  }
  printf("\n");
}

int makeMap(int x, int y, char pRobot_map[15][15], char pReal_map[15][15]) {
  int movements = 0;

  int orientation = -1;
  while (orientation != 0) {
    orientation = searchPaths(x, y, pRobot_map, pReal_map);
    // printMap(10, 10, pRobot_map);
    // getchar();
    if (orientation == 0) {
      break;
    }

    movements++;

    if (orientation == 1) {
      x--;
    } else if (orientation == 2) {
      y++;
    } else if (orientation == 3) {
      x++;
    } else if (orientation == 4) {
      y--;
    }
  }

  return movements;
}

void solve() {
  int size_x, size_y, x, y, i, j, movements;
  char pRobot_map[15][15];
  char pReal_map[15][15];

  while (scanf("%d%d", &size_x, &size_y) != EOF && size_x != 0 && size_y != 0) {
    initMaps(pRobot_map, pReal_map);
    scanf("%d%d", &x, &y);
    for (i = 1; i <= size_x; i++) {
      for (j = 1; j <= size_y; j++) {
        scanf(" %c", &pReal_map[i][j]);
      }
    }

    movements = makeMap(x, y, pRobot_map, pReal_map);

    printMap(size_x, size_y, pRobot_map);

    printf("NUMBER OF MOVEMENTS: %d\n", movements);
  }
}

int main() {
  solve();
  return 0;
}
