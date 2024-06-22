# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
La idea inicial es ordenar las cartas de ambos jugadores para facilitar las comparaciones y luego determinar cuál es la menor carta que se le puede dar al Príncipe para asegurarse de que gane el juego sin importar cómo juegue.

# Enfoque
<!-- Describe your approach to solving the problem. -->
1. Ordenar las cartas de la Princesa y del Príncipe.
2. Comparar las cartas de ambos jugadores para identificar las posibles situaciones en las que el Príncipe puede ganar dos de los tres rounds.
3. Probar todas las cartas posibles (que no están en las manos actuales) para encontrar la menor carta que garantice la victoria del Príncipe.
4. Si no hay una carta que asegure la victoria, devolver -1.

# Complejidad
- Complejidad de tiempo:
* Complejidad de tiempo: O(1) para cada conjunto de cartas ya que solo hacemos operaciones simples y el número de cartas es constante.

- Complejidad de espacio:
* Complejidad de espacio: O(1) para cada conjunto de cartas ya que solo necesitamos almacenar las cartas de la Princesa y del Príncipe.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

// Función para leer la entrada y procesar cada caso de prueba
void readInput() {
    int A, B, C, X, Y;  // Cartas de la Princesa (A, B, C) y del Príncipe (X, Y)
    int aux;  // Variable auxiliar para intercambiar valores
    bool printed;  // Bandera para verificar si ya se ha impreso un resultado

    // Leer la entrada hasta encontrar cinco ceros
    while (scanf("%d%d%d%d%d", &A, &B, &C, &X, &Y) != EOF && (A != 0 && B != 0 && C != 0 && X != 0 && Y != 0)) {
        printed = false;

        // Ordenar las cartas de la Princesa (A, B, C) en orden ascendente
        if (A > B) {
            aux = A;
            A = B;
            B = aux;
        }
        if (A > C) {
            aux = A;
            A = C;
            C = aux;
        }
        if (B > C) {
            aux = B;
            B = C;
            C = aux;
        }

        // Ordenar las cartas del Príncipe (X, Y) en orden ascendente
        if (X > Y) {
            aux = X;
            X = Y;
            Y = aux;
        }

        // Caso 1: La carta menor del Príncipe es mayor que la carta mayor de la Princesa
        if (X > C) {
            for (int i = 1; i <= 52; i++) {
                if (i != A && i != B && i != C && i != X && i != Y) {
                    printf("%d\n", i);  // Imprimir la menor carta posible
                    printed = true;
                    break;
                }
            }
        }
        // Caso 2: La carta menor del Príncipe es mayor que la segunda carta mayor de la Princesa
        else if (X > B) {
            for (int i = B; i <= 52; i++) {
                if (i != A && i != B && i != C && i != X && i != Y) {
                    printed = true;
                    printf("%d\n", i);  // Imprimir la menor carta posible
                    break;
                }
            }
        }
        // Caso 3: La carta menor del Príncipe es menor que la segunda carta mayor de la Princesa
        // y la carta mayor del Príncipe es mayor que la carta mayor de la Princesa
        else if (X < B && Y > C) {
            for (int i = C; i <= 52; i++) {
                if (i != A && i != B && i != C && i != X && i != Y) {
                    printf("%d\n", i);  // Imprimir la menor carta posible
                    printed = true;
                    break;
                }
            }
        }

        // Si no se ha encontrado ninguna carta válida, imprimir -1
        if (!printed)
            printf("-1\n");
    }
}

int main() {
    readInput();  
    return 0;  
}

```
