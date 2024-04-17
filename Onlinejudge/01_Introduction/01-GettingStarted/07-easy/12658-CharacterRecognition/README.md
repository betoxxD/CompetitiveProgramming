# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
La tarea consiste en reconocer tres dígitos (1, 2 y 3) representados por caracteres en un formato específico. Para resolver este problema, necesitamos comparar los caracteres dados con los patrones de los dígitos conocidos y determinar cuál coincide.

# Enfoque
<!-- Describe your approach to solving the problem. -->
El enfoque consiste en definir los patrones de cada dígito (1, 2 y 3) como cadenas de caracteres y luego comparar cada característica con estos patrones para determinar qué dígito se está representando. Utilizaremos bucles para recorrer los caracteres y realizar las comparaciones necesarias.

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

// Definición de los patrones para cada dígito
string oneDigit = ".*.";
string twoOne   = "***";
string twoTwo   = "..*";
string twoThree = "***";
string twoFour  = "*..";
string twoFive  = "***";
string threeOne   = "***";
string threeTwo   = "..*";
string threeThree = "***";
string threeFour  = "..*";
string threeFive  = "***";

void readInput() {
  // Lectura del número de caracteres a reconocer
  int n;
  scanf("%d", &n);
  
  // Variables para almacenar cada línea de caracteres
  char line1[1000];
  char line2[1000];
  char line3[1000];
  char line4[1000];
  char line5[1000];
  
  // Lectura de los caracteres
  scanf("%s", line1);
  scanf("%s", line2);
  scanf("%s", line3);
  scanf("%s", line4);
  scanf("%s", line5);
  
  // Tamaño de los caracteres
  int size = strlen(line1);
  int dPos;
  bool one, two, three;
  
  // Iteración sobre los caracteres
  for(int i = 0; i < size; i+=4) {
    dPos = 0;
    one = true;
    two = true;
    three = true;
    
    // Comprobación de cada dígito para el conjunto de caracteres actual
    for(int j = i; j < i+3; j++) {
      // Comprobación del patrón para el dígito 1
      if(line1[j] != oneDigit[dPos]) one = false;
      if(line2[j] != oneDigit[dPos]) one = false;
      if(line3[j] != oneDigit[dPos]) one = false;
      if(line4[j] != oneDigit[dPos]) one = false;
      if(line5[j] != oneDigit[dPos]) one = false;

      // Comprobación del patrón para el dígito 2
      if(line1[j] != twoOne[dPos]) two = false;
      if(line2[j] != twoTwo[dPos]) two = false;
      if(line3[j] != twoThree[dPos]) two = false;
      if(line4[j] != twoFour[dPos]) two = false;
      if(line5[j] != twoFive[dPos]) two = false;

      // Comprobación del patrón para el dígito 3
      if(line1[j] != threeOne[dPos]) three = false;
      if(line2[j] != threeTwo[dPos]) three = false;
      if(line3[j] != threeThree[dPos]) three = false;
      if(line4[j] != threeFour[dPos]) three = false;
      if(line5[j] != threeFive[dPos]) three = false;
      dPos++;
    }
    
    // Impresión de los dígitos reconocidos
    if(one) printf("1");
    if(two) printf("2");
    if(three) printf("3");
  }
  printf("\n");
}

int main() {
  readInput();
  return 0;
}

```
