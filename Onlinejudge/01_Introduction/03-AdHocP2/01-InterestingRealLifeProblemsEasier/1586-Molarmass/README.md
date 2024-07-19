# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Para resolver este problema, debemos calcular la masa molar de un compuesto orgánico dado su fórmula molecular. Cada fórmula molecular contiene las cantidades de los elementos Carbono (C), Hidrógeno (H), Oxígeno (O) y Nitrógeno (N). Usando las masas atómicas estándar de estos elementos, podemos calcular la masa molar total sumando las contribuciones de cada elemento.

# Enfoque
<!-- Describe your approach to solving the problem. -->
1. **Leer la entrada**: La entrada contiene múltiples casos de prueba. Primero, leemos el número de casos de prueba.
2. **Parsear la fórmula molecular**: Para cada fórmula molecular, recorremos el string y extraemos las cantidades de cada elemento. Si un elemento no tiene un subíndice, asumimos que hay un solo átomo de ese elemento.
3. **Calcular la masa molar**: Utilizando las masas atómicas estándar (C = 12.01 g/mol, H = 1.008 g/mol, O = 16.00 g/mol, N = 14.01 g/mol), calculamos la masa molar total del compuesto.
4. **Imprimir los resultados**: Para cada caso de prueba, imprimimos la masa molar con tres decimales de precisión.

# Complejidad
- Complejidad de tiempo: $O(T×n)$, donde $T$ es el número de casos de prueba y nn es la longitud de la fórmula molecular, ya que recorremos cada fórmula una vez.

- Complejidad de espacio: $O(1)$, ya que solo utilizamos variables simples para almacenar las cantidades de elementos y la masa molar.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

// Función para calcular la masa molar de una fórmula molecular
float calculateMass(string formula) {
    int C = 0;  // Cantidad de átomos de Carbono
    int H = 0;  // Cantidad de átomos de Hidrógeno
    int O = 0;  // Cantidad de átomos de Oxígeno
    int N = 0;  // Cantidad de átomos de Nitrógeno
    float mass = 0;  // Masa molar total
    string newNumber;  // String para almacenar los subíndices
    int formulaSize = formula.size();

    // Recorrer la fórmula molecular
    for (int i = 0, j = 0; i < formulaSize; i++) {
        j = 0;
        newNumber = "";
        // Dependiendo del elemento, leer el subíndice si existe
        switch (formula[i]) {
            case 'C':
                if (i + 1 < formulaSize && isdigit(formula[i + 1])) {
                    j = i + 1;
                    while (isdigit(formula[j])) {
                        newNumber += formula[j];
                        j++;
                    }
                    i = j - 1;
                    C += stoi(newNumber);
                } else {
                    C++;
                }
                break;
            case 'H':
                if (i + 1 < formulaSize && isdigit(formula[i + 1])) {
                    j = i + 1;
                    while (isdigit(formula[j])) {
                        newNumber += formula[j];
                        j++;
                    }
                    i = j - 1;
                    H += stoi(newNumber);
                } else {
                    H++;
                }
                break;
            case 'O':
                if (i + 1 < formulaSize && isdigit(formula[i + 1])) {
                    j = i + 1;
                    while (isdigit(formula[j])) {
                        newNumber += formula[j];
                        j++;
                    }
                    i = j - 1;
                    O += stoi(newNumber);
                } else {
                    O++;
                }
                break;
            case 'N':
                if (i + 1 < formulaSize && isdigit(formula[i + 1])) {
                    j = i + 1;
                    while (isdigit(formula[j])) {
                        newNumber += formula[j];
                        j++;
                    }
                    i = j - 1;
                    N += stoi(newNumber);
                } else {
                    N++;
                }
                break;
        }
        // Calcular la masa molar total
        mass = (C * 12.01) + (H * 1.008) + (O * 16.00) + (N * 14.01);
    }
    return mass;
}

// Función para leer la entrada y procesar cada caso de prueba
void readInput() {
    int n;
    scanf("%d", &n);  // Leer el número de casos de prueba
    char in[1000];
    // Procesar cada caso de prueba
    while (n--) {
        scanf("%s", in);
        printf("%.3f\n", calculateMass(in));  // Imprimir la masa molar con 3 decimales
    }
}

// Función principal
int main() {
    readInput();  // Llamar a la función para leer y procesar la entrada
    return 0;
}

```
