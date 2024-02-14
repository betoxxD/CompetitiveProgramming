#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

vector<string> instructions;
int pos;

void clearData() {
  instructions.clear();
  pos = 0;
}

void doSomething() {
  int current;
  int arrPos;
  for(int i = 0; i < instructions.size(); i++) {
    current = i;
    while (instructions[current][0] != 'L' && instructions[current][0] != 'R') {
      sscanf(instructions[current].c_str(), "SAME AS %d", &arrPos);
      current = arrPos - 1;
    }
    if(instructions[current][0] == 'L') pos--;
    else pos++;
  }
}

void readInput() {
  int n;
  int cantInst;
  char inst[100];
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &cantInst);
    getchar();
    while (cantInst--) {
      fgets(inst, sizeof(inst), stdin);
      instructions.push_back(inst);
    }
    
    doSomething();
    printf("%d\n", pos);

    clearData();
  }
}

int main() {
  readInput();
  return 0;
}
