#include <bits/stdc++.h>

using namespace std;

char JanePileUp[105];
char JanePileDown[105];
char JohnPileUp[105];
char JohnPileDown[105];

int JanePileUpSize;
int JohnPileUpSize;
int JanePileDownSize;
int JohnPileDownSize;

void printCards(int JanePos, int JohnPos) {
  printf("Jane:\n%s  %s\n", JanePileDown, JanePileUp);
  for (int i = 0; i < JanePos; i++)
    printf(" ");
  printf("*\n");
  printf("John:\n%s  %s\n", JohnPileDown, JohnPileUp);
  for (int i = 0; i < JohnPos; i++)
    printf(" ");
  printf("*\n\n");
  getchar();
}

void initialiceValues() {
  JanePileUp[0] = 0;
  JohnPileUp[0] = 0;
  JanePileDown[0] = 0;
  JohnPileDown[0] = 0;
  JanePileDownSize = 0;
  JohnPileDownSize = 0;
  JanePileUpSize = 0;
  JohnPileUpSize = 0;
}

string printReverse(string pile) {
  string result = "";
  int pileStart = pile.size() - 1;
  for (int i = pileStart; i >= 0; i--) {
    result += pile[i];
  }
  return result;
}

void callSnap() {
  int result = random() / 141 % 2;
  if (result == 0) {
    strcat(JanePileUp, JohnPileUp);
    JanePileUpSize += JohnPileUpSize;
    printf("Snap! for Jane: %s\n", printReverse(JanePileUp).c_str());
    JohnPileUp[0] = 0;
    JohnPileUpSize = 0;
  } else {
    strcat(JohnPileUp, JanePileUp);
    JohnPileUpSize += JanePileUpSize;
    printf("Snap! for John: %s\n", printReverse(JohnPileUp).c_str());
    JanePileUp[0] = 0;
    JanePileUpSize = 0;
  }
}

void simulateGame() {
  int JanePileDownPos = 0;
  int JohnPileDownPos = 0;
  JanePileDownSize = strlen(JanePileDown);
  int JanePileDownControl = JanePileDownSize;
  JohnPileDownSize = strlen(JohnPileDown);
  int JohnPileDownControl = JohnPileDownSize;
  bool JohnWins = false;
  bool JaneWins = false;
  for (int i = 0; i < 1000; i++) {
    JanePileUp[JanePileUpSize++] = JanePileDown[JanePileDownPos];
    JohnPileUp[JohnPileUpSize++] = JohnPileDown[JohnPileDownPos];
    JanePileUp[JanePileUpSize] = 0;
    JohnPileUp[JohnPileUpSize] = 0;
    // printCards(JanePileDownPos, JohnPileDownPos);
    JanePileDownControl--;
    JohnPileDownControl--;
    if (JanePileDown[JanePileDownPos] == JohnPileDown[JohnPileDownPos]) {
      callSnap();
      if (JanePileUpSize == 0 && JanePileDownControl == 0) {
        JohnWins = true;
        break;
      } else if (JohnPileUpSize == 0 && JohnPileDownControl == 0) {
        JaneWins = true;
        break;
      }
    }
    JanePileDownPos++;
    JohnPileDownPos++;
    if (JanePileDownPos == JanePileDownSize) {
      JanePileDown[0] = 0;
      JohnPileDown[0] = 0;
      JanePileDownSize = JanePileUpSize;
      JanePileDownControl = JanePileUpSize;
      strcpy(JanePileDown, JanePileUp);
      JanePileUp[0] = 0;
      JanePileUpSize = 0;
      JanePileDownPos = 0;
    }
    if (JohnPileDownPos == JohnPileDownSize) {
      JohnPileDown[0] = 0;
      JohnPileDownSize = JohnPileUpSize;
      JohnPileDownControl = JohnPileUpSize;
      strcpy(JohnPileDown, JohnPileUp);
      JohnPileUp[0] = 0;
      JohnPileUpSize = 0;
      JohnPileDownPos = 0;
    }
  }
  if (JohnWins)
    printf("John wins.\n");
  else if (JaneWins)
    printf("Jane wins.\n");
  else
    printf("Keeps going and going ...\n");
}

void readInput() {
  int n;
  char strInput[100];
  scanf("%d", &n);
  while (n--) {
    initialiceValues();
    getchar();
    scanf("%s", strInput);
    strcpy(JanePileDown, strInput);
    scanf("%s", strInput);
    strcpy(JohnPileDown, strInput);
    simulateGame();
    if (n != 0)
      printf("\n");
  }
}

int main() {
  readInput();
  return 0;
}
