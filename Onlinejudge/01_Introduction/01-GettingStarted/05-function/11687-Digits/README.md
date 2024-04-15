# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
La intuición inicial para resolver este problema es utilizar un bucle para iterar sobre los números de la secuencia generada según la recurrencia dada, y en cada iteración calcular el número de dígitos en la representación decimal del número actual. Luego, comparamos este número con el número anterior en la secuencia hasta que encontremos un número que sea igual al anterior.

# Enfoque
<!-- Describe your approach to solving the problem. -->
El enfoque consiste en implementar un bucle para generar la secuencia según la recurrencia dada. En cada iteración, contamos los dígitos y lo comparamos con el número anterior. Si son iguales, hemos encontrado el punto en la secuencia donde se repite un número.

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

char inp[1000005];

void readInput()
{
  string current, last; // Definimos dos cadenas de caracteres para almacenar el número actual y el anterior en la secuencia
  int lastSize; // Variable para almacenar el tamaño del número anterior
  int cont; // Contador para el número de iteraciones necesarias para encontrar el número repetido
  while (scanf("%s", inp) != EOF) { // Bucle principal que lee la entrada hasta el final del archivo
    cont = 1; // Inicializamos el contador en 1
    last = inp; // Almacenamos el número inicial como el último número de la secuencia
    if(last == "END") break; // Si encontramos la señal de fin, terminamos el bucle
    while (100000) { // Bucle interno para generar la secuencia según la recurrencia
      lastSize = last.size(); // Calculamos el tamaño del número anterior
      current = to_string(lastSize); // Convertimos el tamaño a una cadena de caracteres
      if(current == last) break; // Si el tamaño es igual al número anterior, hemos encontrado el número repetido y salimos del bucle interno
      cont++; // Incrementamos el contador de iteraciones
      last = current; // Actualizamos el número anterior con su tamaño
    }
    printf("%d\n", cont); // Imprimimos el número de iteraciones necesarias para encontrar el número repetido
  }
}

int main()
{
  readInput();
  return 0;
}


```
