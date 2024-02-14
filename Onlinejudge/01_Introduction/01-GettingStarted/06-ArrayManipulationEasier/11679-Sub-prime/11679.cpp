#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

vector<int> banks;

void clearData()
{
  banks.clear();
}

void readInput()
{
  int b, n;
  int deb;
  int debitor, creditor, debenture;
  bool canPay = true;
  while (scanf("%d%d", &b, &n) != EOF && (b != 0 && n != 0))
  {
    canPay = true;
    for (int i = 0; i < b; i++)
    {
      scanf("%d", &deb);
      banks.push_back(deb);
    }
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%d", &debitor, &creditor, &debenture);
      debitor--;
      creditor--;
      banks[debitor] -= debenture;
      banks[creditor] += debenture;
    }
    for (int i = 0; i < b; i++)
    {
      if (banks[i] < 0)
        canPay = false;
    }
    if (canPay)
    {
      printf("S\n");
    }
    else
    {
      printf("N\n");
    }
    clearData();
  }
}

int main()
{
  readInput();
  return 0;
}
