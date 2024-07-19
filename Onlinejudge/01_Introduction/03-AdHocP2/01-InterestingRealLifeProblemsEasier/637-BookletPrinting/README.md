# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Para resolver este problema, debemos simular la disposición de las páginas en una libreta plegada, donde cada hoja contiene cuatro páginas: dos en el frente y dos en la parte posterior. Al plegar las hojas por la mitad, las páginas deben aparecer en el orden correcto. Si el número de páginas no es múltiplo de cuatro, debemos insertar páginas en blanco donde sea necesario.

# Enfoque
<!-- Describe your approach to solving the problem. -->
1. **Identificar el número de páginas en blanco**: Si el número total de páginas no es un múltiplo de cuatro, necesitamos calcular cuántas páginas en blanco son necesarias para completar los grupos de cuatro. Para esto usamos la fórmula $Bl = 4 - (n \mod 4)$ donde n es el número de páginas que estamos buscando. Esto funciona debido a que cada 4 páginas se debe de agregar una hoja más, por lo tanto, el número de hojas en blanco siempre será el restante de la división entre 4 de la página (a excepción de las páginas que son divisibles entre 4, estas su valor siempre será 0).
2. **Calcular el número de páginas reales necesarias**: Cada hoja tiene cuatro páginas, así que, para obtener el número de páginas necesarias (front y back), utilizamos la fórmula $({n \over 4} + 1) \cdot 2$ y para números que son múltiplo de 4 ${n \over 4} \cdot 2$, esto debido a que cada hoja puede contener 4 páginas, al dividirlo entre 4 estamos obteniendo la cantidad de hojas necesarias, pero, como necesitamos las páginas, cada hoja tiene 2 páginas, por eso se multiplica por 2.
3. **Simular la impresión de cada hoja**: Alternar entre el frente y la parte posterior de cada hoja, asignando las páginas de acuerdo al orden requerido para que, al plegar la libreta, las páginas aparezcan en el orden correcto. Este orden puede determinarse primero consumiendo el número de páginas en blanco que tenemos que agregar (y que previamente calculamos) combinado con la cuenta de 1 hasta x, donde x es el número de páginas que necesitamos para imprimir todas las hojas. Una vez que nos acabemos las páginas en blanco que necesitamos, entonces ahora si se debe de colocar de la página n hasta x + 1. Estos se van alternando, primero a la izquierda x y n a la derecha y viceversa hasta que cubramos todas las hojas.

4. **Imprimir los resultados**: Para cada hoja, imprimir las páginas en el formato especificado, indicando "Blank" cuando corresponda.

# Complejidad
- Complejidad de tiempo: $O({n \over 4} \cdot 2)$ donde n es el número de páginas, ya que iteramos a través de las páginas una vez para determinar el orden de impresión.

- Complejidad de espacio: $O(1)$, ya que no utilizamos estructuras de datos adicionales que dependan del tamaño de la entrada.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

// Función para imprimir el orden de las páginas para cada número de páginas n
void printResult(int n) {
    int blank;  // Número de páginas en blanco necesarias
    int pages;  // Número total de hojas necesarias
    bool alternate = true;  // Alternar entre el frente y la parte posterior de la hoja
    int cont = 1;  // Contador de páginas impresas desde el principio
    int numberSheet = 1;  // Contador de hojas
    printf("Printing order for %d pages:\n", n);

    if (n == 1) {
        // Caso especial para 1 página
        printf("Sheet 1, front: Blank, 1\n");
    } else {
        // Calcular el número de páginas en blanco necesarias
        blank = n % 4 == 0 ? 0 : 4 - (n % 4);
        // Calcular el número de hojas necesarias
        pages = n % 4 == 0 ? n / 4 * 2 : (n / 4 + 1) * 2;

        while (pages--) {
            if (alternate) {
                // Imprimir el frente de la hoja
                printf("Sheet %d, front: %s, %d\n", numberSheet,
                       blank <= 0 ? to_string(n).c_str() : "Blank", cont);
                alternate = !alternate;  // Alternar al siguiente lado
                if (blank <= 0) {
                    n--;  // Decrementar el número de páginas restantes
                }
                blank--;  // Decrementar el número de páginas en blanco restantes
                cont++;  // Incrementar el contador de páginas impresas desde el principio
            } else {
                // Imprimir la parte posterior de la hoja
                printf("Sheet %d, back : %d, %s\n", numberSheet, cont,
                       blank <= 0 ? to_string(n).c_str() : "Blank");
                numberSheet++;  // Incrementar el contador de hojas
                alternate = !alternate;  // Alternar al siguiente lado
                if (blank <= 0) {
                    n--;  // Decrementar el número de páginas restantes
                }
                blank--;  // Decrementar el número de páginas en blanco restantes
                cont++;  // Incrementar el contador de páginas impresas desde el principio
            }
        }
    }
}

// Función para leer la entrada y procesar cada caso de prueba
void readInput() {
    int n;
    // Leer cada caso de prueba hasta encontrar un 0
    while (scanf("%d", &n) != EOF && n != 0) {
        printResult(n);
    }
}

// Función principal
int main() {
    readInput();  // Llamar a la función para leer y procesar la entrada
    return 0;
}

```
