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
    if(n != 0) {
      if(first) {
        first = !first;
      } else {
        printf("\n");
      }
    } else {
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
    for (; a < b;)
    {
      for (; b < c;)
      {
        for (; c < d;)
        {
          for (; d < e;)
          {
            for (; e < f;)
            {
              for (; f < numbers.size();)
              {
                printf("%d %d %d %d %d %d\n", numbers[a], numbers[b],
                       numbers[c], numbers[d], numbers[e], numbers[f]);
                f++;
              }
              if (e < f - 1)
              {
                e++;
              }
              if (e >= f - 1)
              {
                break;
              }
              printf("%d %d %d %d %d %d\n", numbers[a], numbers[b], numbers[c],
                     numbers[d], numbers[e], numbers[f - 1]);
            }
            if (d < e - 1)
            {
              d++;
            }
            if (d >= e - 1)
            {
              break;
            }
            printf("%d %d %d %d %d %d\n", numbers[a], numbers[b], numbers[c],
                   numbers[d], numbers[e - 1], numbers[f - 1]);
          }

          if (c < d - 1)
          {
            c++;
          }
          if (c >= d - 1)
          {
            break;
          }
          printf("%d %d %d %d %d %d\n", numbers[a], numbers[b], numbers[c],
                 numbers[d - 1], numbers[e - 1], numbers[f - 1]);
        }

        if (b < c - 1)
        {
          b++;
        }
        if (b >= c - 1)
        {
          break;
        }
        printf("%d %d %d %d %d %d\n", numbers[a], numbers[b], numbers[c - 1],
               numbers[d - 1], numbers[e - 1], numbers[f - 1]);
      }
      if (a < b - 1)
      {
        a++;
      }
      if (a >= b - 1)
      {
        break;
      }
      printf("%d %d %d %d %d %d\n", numbers[a], numbers[b - 1], numbers[c - 1],
             numbers[d - 1], numbers[e - 1], numbers[f - 1]);
    }
  }
}

int main()
{
  readInput();
  return 0;
}
