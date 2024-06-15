#include <bits/stdc++.h>

using namespace std;

int AliceBucket[100000];
int BettyBucket[100000];

void clearData(int maxi) {
  for (int i = 0; i <= maxi; i++) {
    AliceBucket[i] = 0;
    BettyBucket[i] = 0;
  }
}

int calculateTrades(int maxi) {
  int AliceCanTrade = 0;
  int BettyCanTrade = 0;
  for (int i = 0; i <= maxi; i++) {
    if (AliceBucket[i] != 0 && BettyBucket[i] == 0) {
      AliceCanTrade++;
    }
    if (AliceBucket[i] == 0 && BettyBucket[i] != 0) {
      BettyCanTrade++;
    }
  }
  return min(BettyCanTrade, AliceCanTrade);
}

void readInput() {
  int A, B;
  int in;
  int maxi;
  while (scanf("%d%d", &A, &B) != EOF && A != 0 && B != 0) {
    maxi = 0;
    while (A--) {
      scanf("%d", &in);
      maxi = max(maxi, in);
      AliceBucket[in]++;
    }
    while (B--) {
      scanf("%d", &in);
      maxi = max(maxi, in);
      BettyBucket[in]++;
    }
    printf("%d\n", calculateTrades(maxi));
    clearData(maxi);
  }
}

int main() {
  readInput();
  return 0;
}
