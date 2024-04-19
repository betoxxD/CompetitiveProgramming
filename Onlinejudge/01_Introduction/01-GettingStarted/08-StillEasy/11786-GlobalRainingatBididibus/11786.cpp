#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n;
  char orography[10005];
  int orographySize;
  scanf("%d", &n);
  vector<int> queueValley;
  int waterUnits;
  while (n--) {
    waterUnits = 0;
    scanf("%s", orography);
    orographySize = strlen(orography);
    for(int i = 0; i < orographySize; i++) {
      if(orography[i] == '\\') {
        queueValley.push_back(i);
      } else if(orography[i] == '/') {
        if(queueValley.size() != 0) {
          waterUnits += i - queueValley[queueValley.size() - 1];
          queueValley.pop_back();
        }
      }
    }
    printf("%d\n", waterUnits);
    queueValley.clear();
  }
}

int main() {
  readInput();
  return 0;
}
