#include <bits/stdc++.h>

using namespace std;


char inp[1000005];

void readInput()
{
  string current, last;
  int lastSize;
  int cont;
  while (scanf("%s", inp) != EOF) {
    cont = 1;
    last = inp;
    if(last == "END") break;
    while (100000) {
      lastSize = last.size();
      current = to_string(lastSize);
      if(current == last) break;
      cont++;
      last = current;
    }
    printf("%d\n", cont);
  }
}

int main()
{
  readInput();
  return 0;
}
