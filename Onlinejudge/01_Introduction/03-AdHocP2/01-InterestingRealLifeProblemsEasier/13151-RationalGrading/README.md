# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Para resolver este problema, necesitamos evaluar la exactitud de la salida de un programa de acuerdo con las instrucciones dadas y sus resultados esperados. La evaluación se basa en si el resultado de cada instrucción es correcto según el valor actual de una variable, y la calificación depende de cuántas instrucciones se ejecutan correctamente secuencialmente.

# Enfoque
<!-- Describe your approach to solving the problem. -->
1. **Leer la entrada**: Cada caso de prueba incluye un valor inicial para la variable i y una serie de instrucciones junto con los resultados esperados.
2. **Convertir el valor inicial**: Dependiendo del formato (decimal, octal, hexadecimal), convertir el valor inicial i a un número entero.
3. **Evaluar cada instrucción**: Para cada instrucción, verificar si el resultado proporcionado es correcto dado el valor actual de i. Actualizar i según la instrucción si es correcta, o ajustar i al valor dado si es incorrecta.
4. **Calcular la calificación**: Contar cuántas instrucciones se ejecutaron correctamente y almacenar este resultado.
5. **Imprimir los resultados**: Para cada caso de prueba, imprimir la calificación obtenida.

# Complejidad
- Complejidad de tiempo: $O(T×t)$, donde $T$ es el número de casos de prueba y tt es el número de instrucciones por caso, ya que cada instrucción se evalúa una vez.

- Complejidad de espacio: $O(1)$, ya que solo se utilizan variables simples para almacenar el estado actual de i y la calificación.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

int iGValue;  // Variable global para almacenar el valor actual de 'i'

// Función para convertir el valor inicial de 'i' a un entero
int convertToInt(string iValue) {
    if (iValue[0] == '0') {
        if (iValue[1] == 'x') {
            // Conversión de hexadecimal a entero
            return stoi(iValue, 0, 16);
        } else {
            // Conversión de octal a entero
            return stoi(iValue, 0, 8);
        }
    }
    // Conversión de decimal a entero
    return stoi(iValue);
}

// Función para evaluar el resultado de una instrucción y actualizar 'i'
bool evaluateResult(string expression, int outputValue) {
    if (expression == "++i") {
        if (iGValue + 1 == outputValue) {
            iGValue++;
            return true;
        } else {
            iGValue = outputValue;
            return false;
        }
    } else if (expression == "i++") {
        if (iGValue == outputValue) {
            iGValue++;
            return true;
        } else {
            iGValue = outputValue;
            iGValue++;
            return false;
        }
    } else if (expression == "--i") {
        if (iGValue - 1 == outputValue) {
            iGValue--;
            return true;
        } else {
            iGValue = outputValue;
            return false;
        }
    } else if (expression == "i--") {
        if (iGValue == outputValue) {
            iGValue--;
            return true;
        } else {
            iGValue = outputValue;
            iGValue--;
            return false;
        }
    } else {
        if (iGValue == outputValue) {
            return true;
        } else {
            iGValue = outputValue;
            return false;
        }
    }
    return false;
}

// Función para leer la entrada y procesar cada caso de prueba
void readInput() {
    char iValue[100000];
    int nEval;
    char expressionIn[10];
    int outputValue;
    int cont;

    while (scanf("%s%d", iValue, &nEval) != EOF && strcmp(iValue, "0") != 0 && nEval != 0) {
        cont = 0;
        iGValue = convertToInt(iValue);  // Convertir el valor inicial de 'i'
        while (nEval--) {
            scanf("%s%d", expressionIn, &outputValue);
            if (evaluateResult(expressionIn, outputValue)) {
                cont++;  // Contar las instrucciones correctas
            }
        }
        printf("%d\n", cont);  // Imprimir la calificación para el caso de prueba
    }
}

// Función principal
int main() {
    readInput();  // Llamar a la función para leer y procesar la entrada
    return 0;
}

```
