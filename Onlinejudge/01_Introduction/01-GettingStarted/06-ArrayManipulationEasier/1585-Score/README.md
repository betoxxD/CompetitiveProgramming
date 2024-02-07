# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
El problema parece ser sencillo, llevar una cuenta y sumar, en caso de que se encuentre una x se reinicia el contador.

# Enfoque
<!-- Describe your approach to solving the problem. -->
El problema, a resumidas cuentas, pide contar un marcador. Cada 'O' consecutivo acumula puntos, si aparece una 'X', entonces esta acumulación se reinicia en 1. Solamente queda sumar al marcador el acumulado que se vaya obteniendo teniendo en cuenta lo anterior.

# Complejidad
- Complejidad de tiempo:
    <!-- Add your time complexity here, e.g. $$O(n)$$ -->
    $$O(n)$$

- Complejidad de espacio:
    <!-- Add your space complexity here, e.g. $$O(n)$$ -->
    $$O(1)$$

# Código
```cpp
#include<bits/stdc++.h>

using namespace std;

int calculateScore(string result){
  int increment = 1;
  int sum = 0;
  for(int i = 0; i < result.size(); i++){
    if(result[i] == 'O') {
     sum+= increment;
     increment++;
    } else {
      increment = 1;
    }
  }
  return sum;
}

void readInput(){
  int t;
  char result[100];
  scanf("%d", &t);
  while(t--){
    scanf("%s", result);
    printf("%d\n", calculateScore(result));
  }
}

int main() {
  readInput();
  return 0;
}

```
