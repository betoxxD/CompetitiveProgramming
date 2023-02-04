#include <bits/stdc++.h>
#include <vector>

using namespace std;

void readInput()
{
  int n;
  scanf("%d", &n);
  int dollars = 0;
  int in;
  bool first = true;
  int mayor = 0;
  while (n--)
  {
    scanf("%d", &in);
    mayor = max(mayor, in);
  }
  printf("%d\n", mayor);
}

int main()
{
  readInput();
  return 0;
}
