#include <bits/stdc++.h>

using namespace std;

int a, b, n;

int steps[1000000];
bitset<1000000> passed;

void bfs(int i) {
  passed = 0;
  queue<int> q;
  q.push(i);
  int current;
  int multi, div;
  int cont = 0;
  passed[i] = 1;
  while (!q.empty()) {
    current = q.front();
    q.pop();
    multi = current * a;
    div = current / b;
    cont++;
    if (multi <= 9999) {
      if (passed[multi] == 0) {
        steps[multi] = steps[current] + 1;
        passed[multi] = 1;
        q.push(multi);
      }
    }
    if (div > 0) {
      if (passed[div] == 0) {
        passed[div] = 1;
        steps[div] = steps[current] + 1;
        q.push(div);
      }
    }
    if (n == div || n == multi) {
      break;
    }
  }
}

void readInput() {
  scanf("%d%d%d", &a, &b, &n);
  bfs(1);
  printf("%d\n", steps[n]);
}

int main() {
  readInput();
  return 0;
}
