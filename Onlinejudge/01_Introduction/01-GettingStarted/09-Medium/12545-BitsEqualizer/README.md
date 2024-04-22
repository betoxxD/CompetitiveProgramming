# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Dado que tenemos que convertir la cadena S en la cadena T en el menor número de movimientos posible, podemos observar que hay tres operaciones que podemos realizar: cambiar un '0' en S por '1', cambiar un '?' en S por '0' o '1', y finalmente, intercambiar caracteres en S.

# Enfoque
<!-- Describe your approach to solving the problem. -->
1. Primero, verificamos si es posible convertir S en T. Esto lo hacemos asegurándonos de que haya suficientes '1' en T para cubrir todos los '1' en S.
2. Calculamos la cantidad de cambios necesarios para convertir cada '?' en S en '0' o '1' para que S coincida con T, para esto consideramos que la manera más óptima de hacerlo es convertir los '?' en el número que está en su misma posición en la cadena T a menos que ya hayamos cubierto la cantidad de esos números necesarios (verificar que tengan la misma cantidad de 0 y 1). Posterior a esto, el siguiente paso más óptimo sería hacer los intercambios, intentando que cada posición que tenga números diferentes, pueda ser intercambiado por otra posición que no haga match. Finalmente, considerar los casos de convertir 0 a 1 para igualar ambas cadenas.
3. Aplicamos estos cambios en S y contamos la cantidad total de movimientos necesarios.
4. Si no es posible convertir S en T, devolvemos -1.

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

// Función para verificar si es posible convertir S en T
bool canConvert(string S, string T){
  // Verificar si las longitudes de S y T son iguales
  if(S.length() != T.length()) return false;
  
  // Contadores para '0', '1' y '?' en S y T
  int s0 = 0, s1 = 0, sQ = 0 ;
  int t0 = 0, t1 = 0;
  
  // Contar la cantidad de '0', '1' y '?' en S y T
  for(int i = 0; i < S.length(); i++) {
    if(S[i] == '0') s0++;
    else if(S[i] == '1') s1++;
    else sQ++;

    if(T[i] == '0') t0++;
    else t1++;
  }

  // Verificar si hay suficientes '1' en T para cubrir todos los '1' en S
  if(t1 - s1 < 0) return false;

  return true;
}

// Función para convertir S en T
int convertString(string S, string T) {
  int steps = 0;

  int aux;

  int s0 = 0, s1 = 0, sQ = 0 ;
  int t0 = 0, t1 = 0;
  // Contar la cantidad de '0', '1' y '?' en S y T
  for(int i = 0; i < S.length(); i++) {
    if(S[i] == '0') s0++;
    else if(S[i] == '1') s1++;
    else sQ++;

    if(T[i] == '0') t0++;
    else t1++;
  }
  // Calcular la cantidad de cambios necesarios para convertir '?' en S en '0' o '1'
  int neededS0 = t0 - s0;
  int neededS1 = t1 - s1;
  int stringSize = S.length();
  // Realizar cambios necesarios en S para que coincida con T
  for(int i = 0; i < stringSize; i++) {
    if(S[i] == '?') {
      // Si el carácter correspondiente en T es '0'
      if(T[i] == '0') {
        // Si aún se necesitan cambios de '0' en S
        if(neededS0 > 0) {
          S[i] = '0'; // Cambiar '?' por '0'
          neededS0--; // Reducir el número de cambios necesarios de '0'
        } else {
          S[i] = '1'; // Cambiar '?' por '1' ya que se necesitan más '1'
          neededS1--; // Reducir el número de cambios necesarios de '1'
        }
      } else { // Si el carácter correspondiente en T es '1'
        // Si aún se necesitan cambios de '1' en S
        if(neededS1 > 0) {
          S[i] = '1'; // Cambiar '?' por '1'
          neededS1--; // Reducir el número de cambios necesarios de '1'
        } else {
          S[i] = '0'; // Cambiar '?' por '0' ya que se necesitan más '0'
          neededS0--; // Reducir el número de cambios necesarios de '0'
        }
      }
      steps++; // Incrementar el contador de pasos
    }
  }
  // Realizar intercambios necesarios en S para que coincida con T
  for(int i = 0; i < stringSize; i++) {
    if(S[i] != T[i]) {
      for(int j = i + 1; j < stringSize; j++) {
        if(S[j] != T[j]) {
          if(S[i] == T[j]) {
            aux = S[i];
            S[i] = S[j];
            S[j] = aux;
            steps++; // Incrementar el contador de pasos
            break;
          }
        }
      }
    }
  }
  // Verificar si se han realizado todos los cambios necesarios
  for(int i = 0; i < stringSize; i++) {
    // Si S y T no son iguales, verificar si se puede realizar el cambio de '0' a '1' y aumentar
    // el contador. Si no, establecer 'Steps' en -1 y terminar el ciclo for
    if(S[i] != T[i]) {
      if(S[i] == '0') {
        S[i] = '1'; // Convertir en S en la posición indicada de '0' a '1'
        steps++; // Incrementar el contador de pasos
      } else {
        // Si no es posible convertir S en T, devolver -1
        steps = -1;
        break;
      }
    }
  }
  return steps; // Devolver el número total de pasos realizados
}

// Función para leer la entrada y llamar a las funciones anteriores
void readInput() {
  int n;
  scanf("%d", &n); // Leer el número de casos
  char S[105], T[105];
  for(int i = 1; i <= n; i++) {
    scanf("%s%s", S, T); // Leer las cadenas S y T
    // Verificar si es posible convertir S en T
    if(canConvert(S, T)) {
      // Imprimir el número de pasos requeridos para convertir S en T
      printf("Case %d: %d\n", i, convertString(S, T));
    } else {
      // Si no es posible convertir S en T, imprimir -1
      printf("Case %d: -1\n", i);
    }
  }
}

int main() {
  readInput(); // Llamar a la función principal
  return 0;
}

```
