#include <bits/stdc++.h>
#include <bitset>

using namespace std;

vector<int> nodes[1000000];

bitset<1000000> pass;

int day, maxi;

void bfs(int i) {
  day = 0;
  maxi = 0;
  queue<int> q;
  q.push(i);
  int current;
  int cont = 1;
  int nCont = 0;
  int days = 0;
  while (!q.empty()) {
    current = q.front();
    q.pop();
    cont--;
    pass[current] = 1;
    for (int node : nodes[current]) {
      if (!pass[node]) {
        pass[node] = 1;
        q.push(node);
        nCont++;
      }
    }
    if (cont == 0) {
      cont = nCont;
      days++;
      if (nCont > maxi) {
        maxi = nCont;
        day = days;
      }
      nCont = 0;
    }
  }
}

void readInput() {
  int n, m;
  int input;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &m);
    while (m--) {
      scanf("%d", &input);
      nodes[i].push_back(input);
    }
  }
  int t, in;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &in);
    bfs(in);
    if (maxi != 0) {
      printf("%d %d\n", maxi, day);
    } else {
      printf("0\n");
    }
    pass = 0;
  }
}

int main() {
  readInput();
  return 0;
}
