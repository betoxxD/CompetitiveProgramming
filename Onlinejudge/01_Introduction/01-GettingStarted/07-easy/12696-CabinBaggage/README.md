# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Podemos resolver este problema verificando si las medidas de la bolsa de cabina cumplen con los límites establecidos por la aerolínea. Además, debemos asegurarnos de que el peso de la bolsa no exceda el límite permitido. Podemos usar una estructura de control para cada caso de prueba e imprimir 1 si la bolsa está permitida y 0 si no lo está.

# Enfoque
<!-- Describe your approach to solving the problem. -->
Leeremos el número de casos de prueba y luego leeremos las medidas de longitud, ancho, profundidad y peso para cada caso. Luego, comprobaremos si las medidas cumplen con los límites especificados y si el peso está dentro del límite permitido. Finalmente, imprimiremos 1 si la bolsa está permitida y 0 si no lo está. También llevaremos un contador para mantener un registro del número total de bolsas permitidas.

# Complejidad
- Complejidad de tiempo:
    <!-- Add your time complexity here, e.g. $$O(n)$$ -->
    La complejidad de tiempo de este enfoque es $O(1)$.

- Complejidad de espacio:
    <!-- Add your space complexity here, e.g. $$O(n)$$ -->
    La complejidad de espacio es O(1)O(1), ya que no estamos utilizando ninguna estructura de datos adicional que crezca con la entrada. Solo necesitamos espacio para almacenar las variables individuales y no hay ninguna estructura de datos que aumente con el tamaño de la entrada.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

// Definimos los límites permitidos para la longitud, ancho, profundidad, volumen y peso del equipaje de cabina.
float permitedLength = 56;
float permitedWidth = 45;
float permitedDepth = 25;
float permitedVolume = 125;
float permitedWeight = 7;

// Función para leer la entrada y verificar el equipaje de cabina.
void readInput() {
  int n;
  // Leemos el número de casos de prueba.
  scanf("%d", &n);
  float length, width, depth, weight;
  bool permited;
  int cont = 0; // Contador para el número total de maletas permitidas.
  float size;
  // Iteramos a través de cada caso de prueba.
  while (n--) {
    permited = false;
    // Leemos las medidas de longitud, ancho, profundidad y peso del equipaje de cabina.
    scanf("%f%f%f%f", &length, &width, &depth, &weight);
    size = length + width + depth; // Calculamos la suma de las medidas (largo + ancho + profundidad).
    // Verificamos si las medidas cumplen con los límites permitidos de la aerolínea.
    if ((length <= permitedLength && width <= permitedWidth && depth <= permitedDepth) || size <= permitedVolume)
      permited = true; // Si las medidas cumplen con los límites de tamaño, marcamos el equipaje como permitido.
    // Verificamos si el peso del equipaje es menor o igual al límite permitido y si el equipaje está permitido en términos de tamaño.
    if (!(weight <= permitedWeight && permited))
      permited = false; // Si el peso excede el límite permitido o el tamaño del equipaje no es válido, marcamos el equipaje como no permitido.
    printf("%d\n", permited); // Imprimimos 1 si el equipaje está permitido, 0 si no lo está.
    cont += permited; // Incrementamos el contador si el equipaje está permitido.
  }
  printf("%d\n", cont); // Imprimimos el número total de maletas permitidas.
}

int main() {
  readInput(); // Llamamos a la función para procesar la entrada.
  return 0;
}

```
