#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

vector<long long> uppers, lowers;

void readInput() {
  int n;
  long long upper, lower;
  int cont, aux;
  long long divisor, dividendo;
  while (scanf("%d", &n) != EOF) {
    upper = n * 2;
    lower = n * 2;
    cont = 0;
    for (long long i = lower; i > n; i--) {
      divisor = i - n;
      dividendo = n * i;
      if(dividendo % divisor != 0) {
        continue;
      }
      lowers.push_back(i);
      uppers.push_back(dividendo / divisor);
      cont++;
    }
    printf("%d\n", cont);
    aux = cont;
    for (int i = cont - 1; i >= 0; i--) {
      printf("1/%d = 1/%lld + 1/%lld\n", n, uppers[i], lowers[i]);
    }
    uppers.clear();
    lowers.clear();
  }
}

int main() {
  readInput();
  return 0;
}
