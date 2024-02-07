# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
El problema requiere calcular la puntuación de cada caso de prueba en función de una cadena de respuestas correctas e incorrectas. Cada respuesta correcta incrementa la puntuación basada en el número de respuestas consecutivas correctas anteriores a ella.

# Enfoque
<!-- Describe your approach to solving the problem. -->
El enfoque consiste en iterar sobre la cadena de respuestas y mantener un contador de incremento que se incrementa en 1 para cada respuesta correcta consecutiva. Se suma este contador a la puntuación total cada vez que se encuentra una respuesta correcta. Si se encuentra una respuesta incorrecta, el contador de incremento se restablece a 1. Al final, se devuelve la puntuación total.

# Complejidad
- Complejidad de tiempo:
    <!-- Add your time complexity here, e.g. $$O(n)$$ -->
    La complejidad de tiempo es $O(n)$, donde nn es el tamaño de la cadena de respuestas. Se recorre la cadena una vez para calcular la puntuación total.

- Complejidad de espacio:
    <!-- Add your space complexity here, e.g. $$O(n)$$ -->
    La complejidad de espacio es $O(1)$, ya que no se utiliza espacio adicional en función del tamaño de los datos de entrada. Se almacena un número constante de variables independientemente del tamaño de la cadena de respuestas.

# Código
```cpp
#include<bits/stdc++.h>

using namespace std;

// Función para calcular la puntuación de una cadena de respuestas
int calculateScore(string result){
  int increment = 1; // Inicializar el contador de incremento
  int sum = 0; // Inicializar la suma de puntuación
  for(int i = 0; i < result.size(); i++){
    if(result[i] == 'O') { // Si la respuesta es correcta
     sum+= increment; // Incrementar la puntuación por el valor del contador de incremento
     increment++; // Incrementar el contador de incremento para la próxima respuesta correcta
    } else {
      increment = 1; // Restablecer el contador de incremento si la respuesta es incorrecta
    }
  }
  return sum; // Devolver la puntuación total
}

// Función para leer la entrada y procesar los casos de prueba
void readInput(){
  int t;
  char result[100]; // Variable para almacenar temporalmente la cadena de respuestas
  scanf("%d", &t); // Leer el número de casos de prueba
  while(t--){
    scanf("%s", result); // Leer la cadena de respuestas
    printf("%d\n", calculateScore(result)); // Calcular y imprimir la puntuación
  }
}

int main() {
  readInput(); // Llamar a la función para procesar la entrada
  return 0;
}

```
