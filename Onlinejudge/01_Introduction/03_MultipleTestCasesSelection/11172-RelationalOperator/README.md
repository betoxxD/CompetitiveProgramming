# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Problema sencillo, simplemente comparar ambos números e imprimir su relación entre ellos.

# Enfoque
<!-- Describe your approach to solving the problem. -->
El problema pide que relación hay entre ambos números dados, solamente se necesitan comparar ambos e imprimir la relación que hay entre ellos.

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
  int n;
  scanf("%d", &n);
  int a, b;
  while(n--) {
    scanf("%d%d", &a, &b);
    if(a > b) printf(">\n");
    else if(a < b) printf("<\n");
    else printf("=\n");
  }
}

int main() {
  readInput();
  return 0;
}

```
