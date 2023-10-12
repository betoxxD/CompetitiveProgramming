# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Realizar la suma del valor de las letras (omitiendo espacios, dígitos y caracteres) y posteriormente realizar la suma de los dígitos del resultado obtenido.

# Enfoque
<!-- Describe your approach to solving the problem. -->
Primero que nada, se realiza la suma de los valores correspondientes a cada letra (debido a que 'a' = 1, 'b' = 2, 'c' = 3, etc, es fácil calcular este número usando las propiedades de c++ con la fórmula $v = letra - 'a' + 1$ considerando cada letra como caracter, e igual lo mismo con las mayúsculas cambiando 'a' por 'A'). Posteriormente, y usando la misma técnica ($numero = digito - '0'$), realizamos la suma de los dígitos (es importante guardar el nuevo número como cadena para acceder a sus propiedades de tamaño y el acceso rápido mediante índices) hasta que este quede solamente de un solo dígito. Finalmente, se calcula el ratio dividiendo el número menor entre el número mayor (para que el valor siempre salga <= a 100) correspondiente al nombre, e imprimir este valor multiplicado por 100 (para sacar el valor en porcentaje). Importante considerar que se debe imprimir redondeado a 2 dígitos, esto se hace mediante las propiedades de printf, las cuales permiten redondear agregando el parámetro %.2f en la cadena de formato.

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

int getNameValue(string name) {
  int value = 0;
  for(int i = 0; i < name.size(); i++) {
    if(name[i] >= 'a' && name[i] <= 'z') value+=name[i] - 'a' + 1;
    if(name[i] >= 'A' && name[i] <= 'Z') value+=name[i] - 'A' + 1;
  }
  return value;
}

string reduceNumber(string value) {
  int number = 0;
  for(int i = 0; i < value.size(); i++) {
    number += value[i] - '0';
  }
  return to_string(number);
}

void readInput() {
  char inA[100], inB[100];
  string sInA, sInB, sValueA, sValueB;
  int valueA, valueB;
  while (fgets(inA, 100, stdin) != NULL) {
    fgets(inB, 100, stdin);
    sInA = inA;
    sInB = inB;
    valueA = getNameValue(sInA);
    valueB = getNameValue(sInB);
    sValueA = to_string(valueA);
    sValueB = to_string(valueB);
    while (sValueA.size() > 1) {
      sValueA = reduceNumber(sValueA);
    }
    while (sValueB.size() > 1) {
      sValueB = reduceNumber(sValueB);
    }
    valueA = sValueA[0] - '0';
    valueB = sValueB[0] - '0';
    if(valueA < valueB) printf("%.2f %%\n", (valueA * 1.0 / valueB * 1.0) * 100);
    else printf("%.2f %%\n", (valueB * 1.0 / valueA * 1.0) * 100);

  }
}

int main() {
  readInput();
  return 0;
}

```
