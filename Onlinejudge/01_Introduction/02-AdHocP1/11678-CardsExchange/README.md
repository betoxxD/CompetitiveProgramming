# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Para resolver el problema debemos determinar cuantas cartas que posee Alice pero no Betty y biceversa. Para ello, podemos hacer uso de cubetas para almacenar las cartas de cada jugador. Luego, recorremos las cartas de Alice y Betty y contamos cuantas cartas de cada jugador no posee el otro.

# Enfoque
<!-- Describe your approach to solving the problem. -->
1. Inicializamos dos cubetas para almacenar las cartas de Alice y Betty.
2. Recorremos las cartas de Alice y Betty y almacenamos las cartas en sus respectivas cubetas.
3. Recorremos ambas cubetas y si alguna de las 2 cubetas no contiene una carta de la otra, incrementamos el contador de cartas que no posee el otro jugador.
4. Si solamente uno de los 2 jugadores cuenta con carta en la posición en la cubeta, entonces aumentamos el contador de la persona que tenga carta. Si ambas tienen, no se aumenta debido a que no están interesadas en cambiar la carta.
5. Finalmente se debe imprimir el número menor correspondiente al número de cartas que pueden intercambiar ambos jugadores.

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

// Arreglos en forma de cubeta para almacenar las cartas que tienen Alice y Betty
int AliceBucket[100000];
int BettyBucket[100000];

// Función para limpiar los conteos de cartas para el siguiente caso de prueba
void clearData(int maxi) {
  for (int i = 0; i <= maxi; i++) {
    AliceBucket[i] = 0;
    BettyBucket[i] = 0;
  }
}

// Función para calcular el número máximo de intercambios
int calculateTrades(int maxi) {
  int AliceCanTrade = 0;
  int BettyCanTrade = 0;
  
  // Iteramos a través de los posibles valores de cartas
  for (int i = 0; i <= maxi; i++) {
    // Contamos las cartas que Alice puede intercambiar y que Betty no tiene
    if (AliceBucket[i] != 0 && BettyBucket[i] == 0) {
      AliceCanTrade++;
    }
    // Contamos las cartas que Betty puede intercambiar y que Alice no tiene
    if (AliceBucket[i] == 0 && BettyBucket[i] != 0) {
      BettyCanTrade++;
    }
  }
  // El número máximo de intercambios es el mínimo de los dos conteos
  return min(BettyCanTrade, AliceCanTrade);
}

// Función para leer la entrada y procesar cada caso de prueba
void readInput() {
  int A, B;
  int in;
  int maxi;
  
  // Leemos hasta encontrar la condición de terminación (0 0)
  while (scanf("%d%d", &A, &B) != EOF && A != 0 && B != 0) {
    maxi = 0;
    
    // Leemos las cartas de Alice y actualizamos el conteo
    while (A--) {
      scanf("%d", &in);
      maxi = max(maxi, in);
      AliceBucket[in]++;
    }
    
    // Leemos las cartas de Betty y actualizamos el conteo
    while (B--) {
      scanf("%d", &in);
      maxi = max(maxi, in);
      BettyBucket[in]++;
    }
    
    // Calculamos e imprimimos el número máximo de intercambios
    printf("%d\n", calculateTrades(maxi));
    
    // Limpiamos los datos para el siguiente caso de prueba
    clearData(maxi);
  }
}

int main() {
  // Iniciamos la lectura de entrada y el procesamiento de los casos de prueba
  readInput();
  return 0;
}
 
```
