# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
El problema consiste en simular las instrucciones dadas a un robot que se encuentra en la posición de origen en el eje x. Las instrucciones pueden ser moverse una unidad a la izquierda (LEFT), una unidad a la derecha (RIGHT) o repetir la misma acción que en una instrucción anterior (SAME AS i). Se necesita seguir las instrucciones y predecir la posición final del robot.

# Enfoque
<!-- Describe your approach to solving the problem. -->
El enfoque es seguir las instrucciones una por una, manteniendo la posición actual del robot. Cuando se encuentra una instrucción SAME AS i, se repite la acción que se realizó en la i-ésima instrucción. Se actualiza la posición del robot en consecuencia.

# Complejidad
- Complejidad de tiempo:
    <!-- Add your time complexity here, e.g. $$O(n)$$ -->
    La complejidad de tiempo es $O(n)$, donde n es el número total de instrucciones. Se recorren todas las instrucciones para calcular la posición final del robot.

- Complejidad de espacio:
    <!-- Add your space complexity here, e.g. $$O(n)$$ -->
    La complejidad de espacio es $O(1)$, ya que no se utiliza espacio adicional en función del tamaño de los datos de entrada. Se almacena un número constante de variables independientemente del tamaño de las instrucciones.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

vector<string> instructions; // Vector para almacenar las instrucciones
int pos; // Variable para almacenar la posición del robot

void clearData() {
  instructions.clear(); // Limpiar el vector de instrucciones
  pos = 0; // Reiniciar la posición del robot
}

void doSomething() {
  int current;
  int arrPos;
  for(int i = 0; i < instructions.size(); i++) {
    current = i;
    // Mientras la instrucción actual no sea LEFT o RIGHT, seguir la instrucción SAME AS
    while (instructions[current][0] != 'L' && instructions[current][0] != 'R') {
      sscanf(instructions[current].c_str(), "SAME AS %d", &arrPos);
      current = arrPos - 1;
    }
    // Actualizar la posición del robot según la instrucción
    if(instructions[current][0] == 'L') pos--;
    else pos++;
  }
}

void readInput() {
  int n;
  int cantInst;
  char inst[100];
  scanf("%d", &n); // Leer el número de casos de prueba
  while (n--) {
    scanf("%d", &cantInst); // Leer el número de instrucciones
    getchar(); // Consumir el salto de línea
    while (cantInst--) {
      fgets(inst, sizeof(inst), stdin); // Leer la instrucción
      instructions.push_back(inst); // Agregar la instrucción al vector
    }
    
    doSomething(); // Procesar las instrucciones
    printf("%d\n", pos); // Imprimir la posición final del robot

    clearData(); // Limpiar los datos para el siguiente caso de prueba
  }
}

int main() {
  readInput(); // Llamar a la función para procesar la entrada
  return 0;
}

```
