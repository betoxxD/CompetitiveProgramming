#include <bits/stdc++.h>

using namespace std;

char JanePileUp[100];
char JanePileDown[100];
char JohnPileUp[100];
char JohnPileDown[100];

void simulateGame() {}

void readInput() {
  int n;
  char strInput[100];
  scanf("%d", &n);
  while (n--) {
    getchar();
    scanf("%s", strInput);
    strcpy(JanePileUp, strInput);
    scanf("%s", strInput);
    strcpy(JohnPileUp, strInput);
  }
}

int main() {
  return 0;
  readInput();
}
