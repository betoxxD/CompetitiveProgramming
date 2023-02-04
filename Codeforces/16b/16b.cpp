#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <utility>

using namespace std;

vector<pair<long long, long long>> containers;

bool orderContainers(pair<long long, long long> ai, pair<long long, long long> bi) {
  return bi.second < ai.second;
}

void readInput() {
  long long n, m; scanf("%lld%lld", &n, &m);
  long long ai, bi;
  pair<long long, long long> container;
  while (m--)
  {
    scanf("%lld%lld", &ai, &bi);
    container.first = ai;
    container.second = bi;
    containers.push_back(container);
  }
  sort(containers.begin(), containers.end(), orderContainers);
  int cont = 0;
  for(pair<long long, long long> contain : containers) {
    if(n > contain.first) {
      cont += contain.second * contain.first;
      n -= contain.first;
    } else {
      cont += n * contain.second;
      n -= contain.first;
    }
    if(n <= 0) {
      break;
    }
  }
  printf("%d\n", cont);
}

int main() {
  readInput();
  return 0;
}
