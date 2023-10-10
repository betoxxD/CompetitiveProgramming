# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
De acuerdo a lo que dice el problema, la solución podría ser contar el número de 0 y números diferentes a 0 y restar unos a otros.  

# Enfoque
<!-- Describe your approach to solving the problem. -->
El problema dice que la fórmula de Emoogle Balance es el número de veces que Emoogle debería de haber dado un premio de acuerdo al libro - el número de veces que si les dió un premio. Debido a que 0 significa que Emoogle dió un premio y los demás números (1 - 99) las razones por las que se debería dar un premio, una de las posibles soluciones es tener una variable contadora que vaya aumentando o disminuyendo su valor de acuerdo a lo establecido anteriormente, por lo tanto tenemos que si el número es 0, disminuimos en 1 la variable, y si la variable no es 0, aumentamos en uno el valor del contador.

# Complejidad
- Complejidad de tiempo:
    <!-- Add your time complexity here, e.g. $$O(n)$$ -->
    $$O(n)$$

- Complejidad de espacio:
    <!-- Add your space complexity here, e.g. $$O(n)$$ -->
    $$O(1)$$

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n;
  int in;
  int cont = 1;
  int balance;
  while (scanf("%d", &n) != EOF && n != 0) {
    balance = 0;
    while (n--) {
      scanf("%d", &in);
      if(in == 0) balance--;
      else balance++;
    }
    printf("Case %d: %d\n", cont++, balance);
  }
}

int main() {
  readInput();
  return 0;
}

```
