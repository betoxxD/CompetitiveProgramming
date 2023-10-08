#include <bits/stdc++.h>

using namespace std;

void readInput() {
  char inp[20];
  string inpu;
  int cont = 1;
  while (scanf("%s", inp) != EOF) {
    inpu = inp;
    if(inpu == "#") break;
    else if(inpu == "HELLO") printf("Case %d: ENGLISH\n", cont++);
    else if(inpu == "HOLA") printf("Case %d: SPANISH\n", cont++);
    else if(inpu == "HALLO") printf("Case %d: GERMAN\n", cont++);
    else if(inpu == "BONJOUR") printf("Case %d: FRENCH\n", cont++);
    else if(inpu == "CIAO") printf("Case %d: ITALIAN\n", cont++);
    else if(inpu == "ZDRAVSTVUJTE") printf("Case %d: RUSSIAN\n", cont++);
    else printf("Case %d: UNKNOWN\n", cont++);
  }
}

int main() {
  readInput();
  return 0;
}
