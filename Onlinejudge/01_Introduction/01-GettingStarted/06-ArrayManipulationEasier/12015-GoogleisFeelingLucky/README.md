# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
El problema requiere determinar qué páginas web son posibles candidatas a ser mostradas cuando un usuario utiliza la función "I'm feeling lucky" en el motor de búsqueda de Google. Esto significa identificar las páginas web con la relevancia más alta.

# Enfoque
<!-- Describe your approach to solving the problem. -->
El enfoque consiste en leer las URL y sus relevancias para cada caso de prueba. Luego, se busca la relevancia más alta entre todas las páginas web. Finalmente, se imprimen las URL que tienen esa relevancia máxima.

# Complejidad
- Complejidad de tiempo:
    <!-- Add your time complexity here, e.g. $$O(n)$$ -->
    La complejidad de tiempo es $O(n)$, donde nn es el número de casos de prueba. Para cada caso de prueba, se recorren las 10 páginas web una vez para encontrar la relevancia máxima.

- Complejidad de espacio:
    <!-- Add your space complexity here, e.g. $$O(n)$$ -->
    La complejidad de espacio es $O(1)$, ya que no se utiliza espacio adicional en función del tamaño de los datos de entrada. Se almacena un número constante de variables independientemente del tamaño de las URL y sus relevancias.

# Código
```cpp
#include<bits/stdc++.h>

using namespace std;

vector<string> urls; // Vector para almacenar las URL de las páginas web
vector<int> relevances; // Vector para almacenar las relevancias de las páginas web
int greatest; // Variable para almacenar la relevancia máxima encontrada

// Función para limpiar los datos almacenados
void clearData() {
  urls.clear(); // Limpiar el vector de URLs
  relevances.clear(); // Limpiar el vector de relevancias
  greatest = 0; // Reiniciar la relevancia máxima
}

// Función para imprimir las páginas web con la relevancia máxima
void getPopular(){
  for(int i = 0; i < 10; i++){
    if(relevances[i] == greatest) printf("%s\n", urls[i].c_str()); // Imprimir la URL si la relevancia coincide con la máxima
  }
}

// Función para leer la entrada y procesar los casos de prueba
void readInput(){
  int n;
  char url[200]; // Variable para almacenar temporalmente la URL
  int relevance; // Variable para almacenar temporalmente la relevancia
  scanf("%d", &n); // Leer el número de casos de prueba
  int caseN = 1; // Variable para contar el número de caso de prueba actual
  while(n--) { // Iterar sobre cada caso de prueba
    greatest = 0; // Reiniciar la relevancia máxima para el caso actual
    for(int i = 0; i < 10; i++){
      scanf("%s", url); // Leer la URL
      scanf("%d", &relevance); // Leer la relevancia
      urls.push_back(url); // Agregar la URL al vector
      relevances.push_back(relevance); // Agregar la relevancia al vector
      if(relevance > greatest) greatest = relevance; // Actualizar la relevancia máxima si se encuentra una nueva relevancia más alta
    }
    printf("Case #%d:\n", caseN++); // Imprimir el número de caso de prueba actual
    getPopular(); // Llamar a la función para imprimir las páginas web con la relevancia máxima
    clearData(); // Limpiar los datos almacenados para el siguiente caso de prueba
  }
}

int main() {
  readInput(); // Llamar a la función para procesar la entrada
  return 0;
}

```
