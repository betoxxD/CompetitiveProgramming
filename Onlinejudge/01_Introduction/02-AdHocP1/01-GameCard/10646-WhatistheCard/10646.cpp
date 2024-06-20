#include <bits/stdc++.h>

using namespace std;

const int init = 26;

vector<string> cards;
bitset<100> passedCard;

string getYValue(int Y) {
  string ret = "";
  for (int i = 0; i < 52; i++) {
    if (passedCard[i]) {
      continue;
    }
    if (Y == 0) {
      ret = cards[i];
      break;
    }
    Y--;
  }
  return ret;
}

int simulateGame() {
  int X;
  int currentPos = init;
  int Y = 0;
  int retro;
  for (int i = 0; i < 3; i++) {
    if (cards[currentPos][0] >= '2' && cards[currentPos][0] <= '9') {
      X = cards[currentPos][0] - '0';
    } else {
      X = 10;
    }
    Y += X;
    retro = 10 - X;
    for (int j = 0; j <= retro; j++) {
      passedCard[currentPos--] = 1;
    }
  }
  return Y - 1;
}

void readInput() {
  char in[2];
  int Y;
  cards.assign(52, "");
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    passedCard = 0;
    for (int j = 0; j < 52; j++) {
      scanf("%s", in);
      cards[j] = in;
    }

    Y = simulateGame();

    // printf("Case %d: %s\n", i + 1, cards[32].c_str());
    printf("Case %d: %s\n", i + 1, getYValue(Y).c_str());
  }
}

int main() {
  readInput();
  return 0;
}
