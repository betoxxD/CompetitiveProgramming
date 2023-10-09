#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<int> numbers;

void readInput()
{
  int n;
  int in;
  bool first = true;
  while (scanf("%d", &n) != EOF)
  {
    if (n != 0)
    {
      if (first)
      {
        first = !first;
      }
      else
      {
        printf("\n");
      }
    }
    else
    {
      break;
    }
    numbers.clear();
    while (n--)
    {
      scanf("%d", &in);
      numbers.push_back(in);
    }
    int a, b, c, d, e, f;
    a = 0;
    b = 1;
    c = 2;
    d = 3;
    e = 4;
    f = 5;
    for (; a < b; a++)
    {
      for (b = a + 1; b < c; b++)
      {
        for (c = b + 1; c < d; c++)
        {
          for (d = c + 1; d < e; d++)
          {
            for (e = d + 1; e < f; e++)
            {
              for (f = e + 1; f < numbers.size(); f++)
              {
                printf("%d %d %d %d %d %d\n", numbers[a], numbers[b],
                        numbers[c], numbers[d], numbers[e], numbers[f]);
              }
            }
          }
        }
      }
    }
  }
}

int main()
{
  readInput();
  return 0;
}
