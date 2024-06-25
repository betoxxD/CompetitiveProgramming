# Intuición
El problema consiste en colocar el máximo número de piezas de ajedrez de un tipo dado en un tablero de dimensiones m x n, de manera que ninguna pieza pueda capturar a otra. Cada tipo de pieza (Torre, Caballo, Reina, Rey) tiene reglas de movimiento específicas, por lo que se deben usar diferentes estrategias para cada una.

# Enfoque
1. Torres (Rooks, 'r'):
    * Las torres pueden moverse horizontal y verticalmente. La solución óptima es colocar una torre en la diagonal del tablero, como la diagonal siempre terminará con el lado más pequeño del tablero, el resultado máximo es el número mínimo ($min(m, n)$) torres en el tablero.

      0X00

      00X0

      000X

2. Caballos (Knights, 'k'):

    * Los caballos tienen un patrón de movimiento en "L". En un tablero de ajedrez, la máxima cantidad de caballos que se pueden colocar sin que se ataquen entre sí es aproximadamente la mitad de las casillas del tablero (cuando un caballo está en una casilla blanca, solamente puede atacar casillas negras, por lo tanto, podemos colocar un caballo en las casillas del mismo color), es decir, $(m * n + 1) / 2$. Al agregar un $+ 1$ en la fórmula, se asegura que el resultado sea redondeado hacia arriba.

3. Reinas (Queens, 'Q'):

    * Las reinas pueden moverse horizontal, vertical y diagonalmente. El problema de las reinas es más complejo, pero en un tablero de ajedrez m x n, la solución es similar a la de las torres, resultando en $min(m, n)$.

4. Reyes (Kings, 'K'):

    * Los reyes pueden moverse una casilla en cualquier dirección. Simplemente colocar los reyes desde la posición 0,0 hasta la última casilla posible sin que se ataquen. Esto resulta en $((m + 1) / 2) * ((n + 1) / 2)$ reyes (el $+ 1$ en la fórmula es para redondear). Para cada fila, se coloca un rey en la primera casilla, luego se salta una casilla y se coloca otro rey, y así sucesivamente. Para la siguiente fila no se coloca nada y la siguiente, se coloca un rey en la segunda casilla, luego se salta una casilla y se coloca otro rey, y así sucesivamente. De esta manera, los reyes no se atacan entre sí, lo que resulta en la mitad de las filas multiplicado por la mitad de las columnas.

# Complejidad
- Complejidad de tiempo: La complejidad de tiempo es $O(1)$ debido a que solamente se ejecuta una sola operación.

- Complejidad de espacio: La complejidad de espacio es $O(1)$ debido a que no se almacena ningún dato.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n; // Número de problemas
  scanf("%d", &n);
  char piece; // Tipo de pieza
  int x, y; // Dimensiones del tablero (m x n)
  
  while (n--) {
    // Leer el tipo de pieza y las dimensiones del tablero
    scanf(" %c", &piece);
    scanf("%d%d", &x, &y);
    
    if (piece == 'r') {
      // Para torres, la solución es el mínimo de filas o columnas
      printf("%d\n", min(x, y));
    } else if (piece == 'k') {
      // Para caballos, aproximadamente la mitad de las casillas del tablero
      printf("%d\n", (x * y + 1) / 2);
    } else if (piece == 'Q') {
      // Para reinas, la solución es el mínimo de filas o columnas
      printf("%d\n", min(x, y));
    } else {
      // Para reyes, el producto de las mitades de filas y columnas (redondeando hacia arriba)
      printf("%d\n", ((x + 1) / 2) * ((y + 1) / 2));
    }
  }
}

int main() {
  readInput();
  return 0;
}

```
