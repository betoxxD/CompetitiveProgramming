#include <bits/stdc++.h>

#define MAX_LINES 100

using namespace std;

int shortest_line_index(int lines[], int n) {
  int shortest = 0;
  for (int i = 0; i < n; i++) {
    if (lines[i] < lines[shortest]) {
      shortest = i;
    }
  }
  return shortest;
}

void solve(int lines[], int n, int m) {
  int shortests = 0;
  for (int i = 0; i < m; i++) {
    shortests = shortest_line_index(lines, n);
    printf("%d\n", lines[shortests]);
    lines[shortests]++;
  }
}

void read_input() {
  int n, m, lines[MAX_LINES];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &lines[i]);
  }
  solve(lines, n, m);
}

int main() {
  read_input();
  return 0;
}
