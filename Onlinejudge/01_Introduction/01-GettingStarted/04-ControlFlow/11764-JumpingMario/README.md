# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Verificar de los tamaños ingresados, cuál es mayor y cuál es menor con respecto a la posición en la que se encuentra mario.

# Enfoque
<!-- Describe your approach to solving the problem. -->
El problema pide contar el número de saltos largos y cortos que mario tendrá que dar dependiendo del mapa (tamaño de los pilares a los que deberá saltar), por lo que esto puede realizarse mediante una simple comparación pasando por cada pilar. Se lee el primer pilar y se guarda en una variable (debido a que inicialmente aparecemos en este pilar), y el siguiente lo almacenamos en una segunda variable, hacemos la comparación entre estos 2 y aumentamos el contador correspondiente. Almacenamos el valor nuevo en la primera variable y volvemos a repetir el proceso desde leer la segunda variable.

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
  int t, n, current, next;
  int hj, lj;
  int cont = 1;
  scanf("%d", &t);
  while (t--) {
    hj = 0;
    lj = 0;
    scanf("%d", &n);
    scanf("%d", &current);
    for(int i = 0; i < n - 1; i++) {
      scanf("%d",&next);
      if(current < next) hj++;
      else if(current > next) lj++;
      current = next;
    }
    printf("Case %d: %d %d\n", cont++, hj, lj);
  }
}

int main() {
  readInput();
  return 0;
}

```
