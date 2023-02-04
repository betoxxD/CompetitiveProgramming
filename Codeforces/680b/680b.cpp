#include <bits/stdc++.h>

using namespace std;

int criminals[500];

void readInput() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &criminals[i]);
  }
  m--;
  int pointA = m, pointB = m;
  int cont = 0;
  while (pointA >= 0 || pointB < n) {
    if (pointA >= 0 && pointB < n) {

      if (criminals[pointA] == 1 && criminals[pointB] == 1) {
        if (pointA == pointB)
          cont++;
        else
          cont += 2;
      }
    } else {
      if(pointA < 0) {
        if(criminals[pointB] == 1){
          cont++;
        }
      } else if(pointB >= n) {
        if(criminals[pointA] == 1) {
          cont++;
        }
      }
    }
    pointA--;
    pointB++;
  }
  printf("%d\n", cont);
}

int main() {
  readInput();
  return 0;
}
