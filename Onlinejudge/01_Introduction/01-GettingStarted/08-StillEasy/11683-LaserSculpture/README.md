# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
La intuición detrás de este enfoque radica en el hecho de que cuando el número que sigue en la secuencia es mayor que el número actual, significa que el láser debe encenderse para eliminar la diferencia entre estos dos números. Esta diferencia representa la cantidad de veces que el láser debe encenderse para esculpir la siguiente capa de la forma deseada. Por el lado contrario, si el siguiente número es menor, ese espacio se irá acumulando hasta que encuentre un número mayor siguiente (no es necesario computar). Por ejemplo, si la secuencia es 2, 0, 1, 3, entonces, el 2 se cortará hasta el número 3, debido a que los dos números siguientes son menores y debido a que estos siguientes ya consideran ese espacio que acumula el 2, entonces no es necesario realizar ninguna operación. Finalmente, considerar que el tamaño de la tabla puede ser más grande que la figura más grande necesitada, por esto mismo, es necesario agregar el tamaño al final del arreglo, para considerar este espacio faltante que pudiera haber.

# Enfoque
<!-- Describe your approach to solving the problem. -->
* Iteramos a través de la secuencia de alturas del bloque.
* Comparamos cada altura con la siguiente.
* Si la altura siguiente es mayor que la altura actual, añadimos la diferencia entre estas alturas al contador de veces que se enciende el láser.
* Al finalizar la iteración, el contador contiene el número total de veces que se enciende el láser.

# Complejidad
- Complejidad de tiempo:
    <!-- Add your time complexity here, e.g. $$O(n)$$ -->
    El tiempo de ejecución del algoritmo es lineal en función del número de alturas en la secuencia. Por lo tanto, la complejidad de tiempo es $O(n)$, donde nn es la longitud de la secuencia de alturas.

- Complejidad de espacio:
    <!-- Add your space complexity here, e.g. $$O(n)$$ -->
    a única estructura de datos adicional que utilizamos es un vector para almacenar las alturas del bloque, lo que implica una complejidad de espacio de $O(n)$, donde nn es la longitud de la secuencia de alturas.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

vector<int> numbers; // Vector para almacenar las alturas del bloque

// Función para calcular el número total de veces que se enciende el láser
int turns() {
  int nTurns = 0;
  for(int i = 0; i < numbers.size() - 1; i++) {
    if(numbers[i] < numbers[i + 1]) // Comparamos cada altura con la siguiente
      nTurns += numbers[i + 1] - numbers[i]; // Si la altura siguiente es mayor, sumamos la diferencia al contador de veces que se enciende el láser
  }
  return nTurns;
}

// Función para leer la entrada y resolver el problema
void readInput() {
  int A,C; // Variables para almacenar la altura y longitud del bloque
  int size; // Variable temporal para leer cada altura
  while (scanf("%d", &A) != EOF) { // Leemos hasta el final del archivo
    if(A == 0) {
      break; // Si la altura es cero, terminamos la ejecución
    }
    scanf("%d", &C); // Leemos la longitud del bloque
    for(int i = 0; i < C; i++) {
      scanf("%d", &size); // Leemos cada altura de la secuencia
      numbers.push_back(size); // Agregamos la altura al vector
    }
    numbers.push_back(A); // Agregamos la altura final del bloque para considerar si el resultado de la figura es mas pequeño que el tamaño del bloque

    printf("%d\n", turns()); // Imprimimos el resultado
    numbers.clear(); // Limpiamos el vector para el siguiente caso de prueba
  }
}

int main() {
  readInput(); // Llamamos a la función para resolver el problema
  return 0;
}

```
