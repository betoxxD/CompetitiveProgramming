#include <bits/stdc++.h> 
#include <vector>

using namespace std;

vector<int> a;

void readInput() {
  int n; scanf("%d", &n);
  int m, in, sum, cont;
  while(n--) {
    sum = 0;
    scanf("%d", &m);
    while(m--) {
      scanf("%d", &in);
      a.push_back(in);
    }
    for(int i = 1; i < a.size(); i++) {
      for(int j = 0; j < i; j++) {
        if(a[i] >= a[j]) {
          sum++;
        }
      }
    }
    printf("%d\n", sum);
    a.clear();
  }
}

int main() {
  readInput();
  return 0;
}
