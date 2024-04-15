# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Este problema implica calcular la mayor caída en los precios de las acciones dados ciertos parámetros de una función modelada. Dado que el problema proporciona una función para modelar los precios de las acciones, podemos usarla para generar los precios y luego encontrar la mayor caída entre ellos.

# Enfoque
<!-- Describe your approach to solving the problem. -->
El enfoque propuesto consiste en generar los precios de las acciones utilizando la función proporcionada y luego iterar sobre ellos para encontrar la mayor caída. Para ello, podemos calcular el precio para cada valor de k (dado el rango de 1 a n) y compararlos para determinar la mayor diferencia. Como siempre se busca la mayor caida, este problema puede resolverse con una iteración, si el número siguiente es más chico que el actual, entonces se calcula la caida y se compara con la anterior caida más grande. En cambio, si el número siguiente es mayor, se toma este como base para seguir buscando la mayor caida.

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

double p, a, b, c, d;
int n;

// Función para calcular el precio de las acciones en un momento dado k
double price(int k) {
  return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

// Función para leer la entrada y encontrar la mayor caída en los precios de las acciones
void readInput() {
  double maxi;        // Variable para almacenar la mayor caída
  double biggest;     // Variable para almacenar el precio más alto visto hasta el momento
  double current;     // Variable para almacenar el precio actual
  double difference;  // Variable para almacenar la diferencia entre el precio más alto y el precio actual
  
  // Leer hasta el final del archivo de entrada
  while (scanf("%lf", &p) != EOF) {
    maxi = 0;
    biggest = 0;
    current = 0;
    difference = 0;
    scanf("%lf%lf%lf%lf%d", &a, &b, &c, &d, &n); // Leer los parámetros de la función y el número de precios

    // Iterar a través de cada valor de k (de 1 a n)
    for(int i = 1; i <= n; i++) {
      current = price(i); // Calcular el precio de las acciones en el momento actual

      // Comprobar si el precio actual es mayor que el precio más alto visto hasta el momento
      if(current > biggest)
        biggest = current; // Si es así, actualizar el precio más alto

      // Si no, calcular la diferencia entre el precio más alto y el precio actual
      else {
        difference = biggest - current;

        // Actualizar la mayor caída si la diferencia actual es mayor que la mayor caída registrada
        if(difference > maxi)
          maxi = difference;
      }
    }

    // Imprimir la mayor caída para este caso de prueba
    printf("%lf\n", maxi);
  }
}

int main() {
  readInput();
  return 0;
}

```
