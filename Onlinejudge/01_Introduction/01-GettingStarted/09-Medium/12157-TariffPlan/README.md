# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Este problema parece requerir calcular el costo total de las llamadas para los paquetes "Mile" y "Juice" y luego comparar cuál de los dos es más barato.

# Enfoque
<!-- Describe your approach to solving the problem. -->
Para resolver este problema, podemos seguir los siguientes pasos:

1. Definir dos funciones priceMile y priceJuice que calculen el costo total de las llamadas para los paquetes "Mile" y "Juice", respectivamente.
2. Leer el número total de casos de prueba.
3. Para cada caso de prueba, leer la cantidad de llamadas y luego leer la duración de cada llamada.
4. Calcular el costo total de las llamadas para ambos paquetes.
5. omparar los costos totales y determinar cuál es más barato.

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

// Función para calcular el costo total de las llamadas para el paquete "Mile"
int priceMile(int time) {
  int price;
  // Calcular el número de bloques de 30 segundos necesarios para cubrir la duración de la llamada
  price = (time / 30) + 1;
  // Multiplicar el número de bloques por el costo por bloque (10 centavos)
  return price * 10;
}

// Función para calcular el costo total de las llamadas para el paquete "Juice"
int priceJuice(int time) {
  int price;
  // Calcular el número de bloques de 60 segundos necesarios para cubrir la duración de la llamada
  price = (time / 60) + 1;
  // Multiplicar el número de bloques por el costo por bloque (15 centavos)
  return price * 15;
}

// Función para leer la entrada y resolver el problema para cada caso de prueba
void readInput() {
  int n;
  int calls, call;
  int totalPriceMile;
  int totalPriceJuice;
  int cont;
  scanf("%d", &n);

  cont = 1;
  while (n--) {
    totalPriceMile = 0;
    totalPriceJuice = 0;
    scanf("%d", &calls);
    while (calls--) {
      scanf("%d", &call);
      // Calcular el costo total de las llamadas para el paquete "Mile"
      totalPriceMile += priceMile(call);
      // Calcular el costo total de las llamadas para el paquete "Juice"
      totalPriceJuice += priceJuice(call);
    }
    // Comparar los costos totales y determinar cuál es más barato
    if(totalPriceMile < totalPriceJuice) {
      printf("Case %d: Mile %d\n", cont, totalPriceMile);
    } else if(totalPriceMile > totalPriceJuice) {
      printf("Case %d: Juice %d\n", cont, totalPriceJuice);
    } else {
      // Si ambos paquetes tienen el mismo costo, imprimir ambos nombres
      printf("Case %d: Mile Juice %d\n", cont, totalPriceJuice);
    }
    cont++;
  }
}

int main() {
  readInput();
  return 0;
}

```
