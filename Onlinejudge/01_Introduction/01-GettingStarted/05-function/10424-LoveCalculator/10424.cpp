#include <bits/stdc++.h>

using namespace std;

int getNameValue(string name) {
  int value = 0;
  for(int i = 0; i < name.size(); i++) {
    if(name[i] >= 'a' && name[i] <= 'z') value+=name[i] - 'a' + 1;
    if(name[i] >= 'A' && name[i] <= 'Z') value+=name[i] - 'A' + 1;
  }
  return value;
}

string reduceNumber(string value) {
  int number = 0;
  for(int i = 0; i < value.size(); i++) {
    number += value[i] - '0';
  }
  return to_string(number);
}

void readInput() {
  char inA[100], inB[100];
  string sInA, sInB, sValueA, sValueB;
  int valueA, valueB;
  while (fgets(inA, 100, stdin) != NULL) {
    fgets(inB, 100, stdin);
    sInA = inA;
    sInB = inB;
    valueA = getNameValue(sInA);
    valueB = getNameValue(sInB);
    sValueA = to_string(valueA);
    sValueB = to_string(valueB);
    while (sValueA.size() > 1) {
      sValueA = reduceNumber(sValueA);
    }
    while (sValueB.size() > 1) {
      sValueB = reduceNumber(sValueB);
    }
    valueA = sValueA[0] - '0';
    valueB = sValueB[0] - '0';
    if(valueA < valueB) printf("%.2f %%\n", (valueA * 1.0 / valueB * 1.0) * 100);
    else printf("%.2f %%\n", (valueB * 1.0 / valueA * 1.0) * 100);

  }
}

int main() {
  readInput();
  return 0;
}
