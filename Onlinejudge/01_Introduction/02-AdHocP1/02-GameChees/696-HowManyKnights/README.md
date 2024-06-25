# Intuición
El problema consiste en colocar el mayor número posible de caballos en un tablero de ajedrez sin que ninguno ataque a otro. Un caballo en ajedrez se mueve en forma de "L", es decir, puede moverse dos filas y una columna, o dos columnas y una fila. Esto implica que debemos tener en cuenta las posiciones atacadas por cada caballo al colocarlos en el tablero.

El comportamiento del problema varía dependiendo del tamaño del tablero. En tableros de 1 fila o columna, simplemente se pueden colocar todos los caballos en una línea. En tableros de 2 filas o columnas, se necesita alternar las posiciones de los caballos debido al movimiento en "L". En tableros más grandes, podemos llenar la mitad de las casillas, alternando posiciones en un patrón de tablero de ajedrez.

# Enfoque
1. Tableros de 1 fila o columna: Se pueden colocar todos los caballos en una línea, porque no hay restricciones de ataque.
2. Tableros de 2 filas o columnas: Se debe alternar la colocación de los caballos debido a su movimiento. Se pueden colocar 2 caballos en cada bloque de 4 casillas.
3. Tableros más grandes: En tableros mayores, se pueden colocar caballos en la mitad de las casillas de forma alternada, similar a un patrón de tablero de ajedrez.

# Complejidad
- Complejidad de tiempo: $O(n)$ dónde $n$ es el lado más grande del tablero.
- Complejidad de espacio: $O(1)$ debido a que no se necesita almacenar información adicional.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

void readInput() {
  int n, m;  // Variables para filas (n) y columnas (m)
  int maxi;  // Variables auxiliares
  int r;  // Resultado: número máximo de caballos
  int cont;  // Contador para alternar posiciones en tableros de 2 filas o columnas
  bool put;  // Bandera para alternar la colocación de caballos

  // Leer pares de enteros hasta encontrar un par de ceros
  while (scanf("%d%d", &n, &m) != EOF && (n != 0 && m != 0)) {
    cont = 0;
    put = true;
    r = 0;
    maxi = max(n, m);  // Tomar el mayor de n y m

    // Caso 1: Si hay una sola fila o columna, se pueden colocar todos los caballos en una línea
    if (n == 1 || m == 1) {
      r = maxi;
    } 
    // Caso 2: Si hay dos filas o columnas, se alternan los caballos para evitar ataques
    else if (n == 2 || m == 2) {
      for (int i = 1; i <= maxi; i++) {
        if (cont == 2) {
          cont = 0;
          put = !put;  // Alternar la colocación de caballos
        }
        if (put) {
          r += 2;  // Colocar dos caballos en cada bloque de 4 casillas
        }
        cont++;
      }
    } 
    // Caso 3: Para tableros más grandes, se llenan la mitad de las casillas en un patrón de tablero de ajedrez
    else {
      r = ((n * m) + 1) / 2;  // La fórmula (n * m + 1) / 2 asegura la mitad de las casillas ocupadas
    }

    // Imprimir el resultado
    printf("%d knights may be placed on a %d row %d column board.\n", r, n, m);
  }
}

int main() {
  readInput();  // Llamada a la función principal para leer la entrada y calcular los resultados
  return 0;
}

```
