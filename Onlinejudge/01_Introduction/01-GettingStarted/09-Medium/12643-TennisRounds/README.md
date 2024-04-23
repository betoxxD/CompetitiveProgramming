# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
suponiendo N = 3, entonces habrá 8 enfrentamientos al principio (1 vs 2, 3 vs 4, 5 vs 6 y 7 vs 8), al dividir entre 2 y redondear hacia arriba, lo que se hace es avanzar un bracket en la competición, y los equipos que se enfrentan siempre tendrán el mismo resultado (por ejemplo 7 vs 8, 7/2 = 3.5 y sube a 4, y 8/2 = 4), además de que, los adyacentes, al dividirlos entre 2, quedan separados por una unidad ( por ejemplo, el juego de 8 vs 7 da como resultado 4 en ambas divisiones, y en 6 vs 5 da como resultado 3), por lo tanto, estamos tomando un nuevo juego de números adyacentes. Si queremos ver en que juego se enfrenta 5 vs 8, ya sabemos que en el juego del 8 es 4 y en el del 5 es 3, la siguiente división da 2 en ambos, qué es cuando coinciden en un juego, por lo tanto el resultado es 2. Se realiza una división entre 2 por la naturaleza de la estructura de torneo (pasa solamente 1 de 2).

# Enfoque
<!-- Describe your approach to solving the problem. -->
1. Leer el número de rondas N y los números de semilla i y j de cada caso de prueba.
2. Para cada caso de prueba, iterar hasta que los números de semilla de i y j coincidan, contando el número de rondas.
3. Imprimir el número de rondas en las que se enfrentarán los jugadores i y j.

# Complejidad
- Complejidad de tiempo:
    <!-- Add your time complexity here, e.g. $$O(n)$$ -->
    $$O(log n)$$

- Complejidad de espacio:
    <!-- Add your space complexity here, e.g. $$O(n)$$ -->
    $$O(1)$$

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n;
  int i, j;
  int cont;  // Variable para contar el número de rondas
  while (scanf("%d", &n) != EOF) {  // Leer el número de rondas N
    int cont;  // Reiniciar el contador de rondas para cada caso de prueba
    scanf("%d%d", &i, &j);  // Leer los números de de los jugadores i y j
    for(cont = 0; i != j; cont++) {  // Iterar hasta que los números de jugador coincidan
      if(i % 2 != 0){  // Si i es impar, avanzar al siguiente "bracket" redondeando hacia arriba
        i = (i / 2) + 1;
      } else {  // Si i es par, dividir por 2
        i /= 2;
      }
      if(j % 2 != 0){  // Lo mismo para j
        j = (j / 2) + 1;
      } else {
        j /= 2;
      }
    }
    printf("%d\n", cont);  // Imprimir el número de ronda en la que se enfrentarán i y j
  }
}

int main() {
  readInput();  // Llamar a la función para procesar la entrada
  return 0;
}


```
