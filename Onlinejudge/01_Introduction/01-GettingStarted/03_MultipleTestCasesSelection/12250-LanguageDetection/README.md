# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Simple sistema de decisiones que compare si la entrada es alguna de las palabras dadas.

# Enfoque
<!-- Describe your approach to solving the problem. -->
El problema pide identificar un "lenguaje" mediante una palabra ingresada. Si esta corresponde a alguna de las maneras de decir hola en los diferentes lenguajes entonces simplemente imprimir el correspondiente, por lo tanto podemos decir que:
* HELLO -> ENGLISH
* HOLA -> SPANISH
* HALLO -> GERMAN
* BONJOUR -> FRENCH
* CIAO -> ITALIAN
* ZDRAVSTVUJTE -> RUSSIAN
* Cualquier otra palabra -> UNKNOWN

# Complejidad
- Complejidad de tiempo:
    <!-- Add your time complexity here, e.g. $$O(n)$$ -->
    $$O(1)$$

- Complejidad de espacio:
    <!-- Add your space complexity here, e.g. $$O(n)$$ -->
    $$O(1)$$

# Código
```cpp
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

```
