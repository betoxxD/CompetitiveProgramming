# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Verificar si la caja cabe en la maleta.

# Enfoque
<!-- Describe your approach to solving the problem. -->
El problema es sencillo, simplemente es necesario verificar si la caja cabe en la maleta. Debido a que la maleta siempre mide lo mismo ($$20*20*20$$),el problema se reduce a verificar que las tres medidas ingresadas sean menores al tamaño de la caja.

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
#include <cstdio>

using namespace std;

void readInput() {
  int n;
  int cont = 1;
  scanf("%d", &n);
  int l, w, h;
  while (n--) {
    scanf("%d%d%d", &l, &w, &h);
    if(l <= 20 && w <= 20 && h <= 20) printf("Case %d: good\n", cont++);
    else printf("Case %d: bad\n", cont++);
  }
}

int main() {
  readInput();
  return 0;
}

```
