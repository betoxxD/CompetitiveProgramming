# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Encontrar la velocidad más alta entre los participantes, esa sería la velocidad que el payaso debería tener para ser alcanzado.

# Enfoque
<!-- Describe your approach to solving the problem. -->
El problema pide que el payaso debería de correr lo suficiente para no ser alcanzado rápidamente, pero tampoco para que el juego dure para siempre, por lo que la respuesta es la velocidad del concursante más rápido.

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
  int n, m, in, mayor, cont = 1;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &m);
    mayor = 0;
    while (m--) {
      scanf("%d", &in);
      if(in > mayor) mayor = in;
    }
    printf("Case %d: %d\n", cont++, mayor);
  }
}

int main() {
  readInput();
  return 0;
}

```
