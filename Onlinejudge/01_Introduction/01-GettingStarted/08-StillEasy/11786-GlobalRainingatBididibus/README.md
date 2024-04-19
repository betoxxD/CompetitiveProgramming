# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Para resolver este problema, necesitamos seguir la topografía del universo Bididibus e identificar los valles formados por las montañas. Luego, calculamos la cantidad de agua que se acumula en cada valle y sumamos estas cantidades para obtener el total de unidades de agua en el universo.

# Enfoque
<!-- Describe your approach to solving the problem. -->
* Leemos la entrada que contiene la representación simplificada del universo Bididibus.
* Iteramos sobre cada símbolo en la entrada.
* Si encontramos una montaña ('\\'), la agregamos a una pila para rastrear las montañas.
* Si encontramos una caída ('/'), calculamos la cantidad de agua que se acumula en el valle asociado restando la posición de la caída de la posición de la última montaña en la pila. Luego, eliminamos la montaña de la pila.
* Sumamos todas las cantidades de agua calculadas para obtener el resultado para ese caso de prueba.

# Complejidad
- Complejidad de tiempo:
    <!-- Add your time complexity here, e.g. $$O(n)$$ -->
    $$O(n)$$

- Complejidad de espacio:
    <!-- Add your space complexity here, e.g. $$O(n)$$ -->
    $$O(n)$$

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n;
  char orography[10005];
  int orographySize;
  scanf("%d", &n); // Leemos el número de casos de prueba
  vector<int> queueValley; // Creamos una pila para rastrear las montañas en cada caso de prueba
  int waterUnits; // Variable para almacenar la cantidad total de unidades de agua en cada caso de prueba
  while (n--) { // Iteramos sobre cada caso de prueba
    waterUnits = 0;
    scanf("%s", orography); // Leemos la representación simplificada del universo Bididibus
    orographySize = strlen(orography); // Obtenemos la longitud de la línea leída
    for(int i = 0; i < orographySize; i++) { // Iteramos sobre cada símbolo en la línea leída
      if(orography[i] == '\\') { // Si encontramos una montaña ('\\')
        queueValley.push_back(i); // Agregamos su posición a la pila
      } else if(orography[i] == '/') { // Si encontramos una caída ('/')
        if(queueValley.size() != 0) { // Verificamos si hay montañas en la pila
          // Calculamos la cantidad de agua que se acumula en el valle restando la posición de la caída
          // de la posición de la última montaña en la pila, y luego eliminamos la montaña de la pila
          waterUnits += i - queueValley[queueValley.size() - 1];
          queueValley.pop_back();
        }
      }
    }
    printf("%d\n", waterUnits); // Imprimimos la cantidad total de unidades de agua para el caso de prueba actual
    queueValley.clear(); // Limpiamos la pila para el siguiente caso de prueba
  }
}

int main() {
  readInput();
  return 0;
}

```
