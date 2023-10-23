#include <bits/stdc++.h>

using namespace std;

void readInput()
{
  int n, m;
  int maxi;
  int in;
  int arrSize;
  scanf("%d", &n);
  int cont;
  while (n--) {
    maxi = -100005;
    scanf("%d", &m);
    arrSize = m;
    cont = 0;
    int current;
    scanf("%d", &current);
    m--;
    while (m--) {
      scanf("%d", &in);
      maxi = current - in > maxi ? current - in : maxi;
      current = in > current ? in : current;
    }
    printf("%d\n", maxi);
  }
}

int main()
{
  readInput();
  return 0;
}
