#include <bits/stdc++.h>

using namespace std;

float permitedLength = 56;
float permitedWidth = 45;
float permitedDepth = 25;

float permitedVolume = 125;

float permitedWeight = 7;

void readInput() {
  int n;
  scanf("%d", &n);
  float length, width, depth, weight;
  bool permited;
  int cont = 0;
  float size;
  while (n--) {
    permited = false;
    scanf("%f%f%f%f", &length, &width, &depth, &weight);
    size = length + width + depth;
    if((length <= permitedLength && width <= permitedWidth && depth <= permitedDepth) || size <= permitedVolume)
      permited = true;
    if(!(weight <= permitedWeight && permited))
      permited = false;
    printf("%d\n", permited);
    cont += permited;
  }
  printf("%d\n", cont);
}

int main() {
  readInput();
  return 0;
}
