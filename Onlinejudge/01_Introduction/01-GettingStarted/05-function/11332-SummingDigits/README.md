# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Realizar iterativamente la suma de dígitos hasta que este tenga por longitud 1 (sea menor a 10).

# Enfoque
<!-- Describe your approach to solving the problem. -->
La solución al problema es iterar sobre el número hasta que este se reduzca a 1 solo dígito, realizando la suma de todos sus dígitos contenidos en este. La solución presentada aquí se realizó manejando el número como un string (debido a que personalmente me parece más sencillo iterar sobre los caracteres de un string que los dígitos de un tipo de dato entero). Para esto, se crea una función que pase por todos los caracteres de la cadena, los convierta en su valor entero (c++ interpreta los caracteres como enteros usando su valor ascii cuando se realizan operaciones con ellos, por lo tanto podemos transformar cada caracter a su valor entero simplemente restando a este el caracter '0', lo cual, si usamos como ejemplo el caracter 0, al hacer '0' - '0', traducido a su valor ascii 48 - 48, el resultado es 0, el valor del 1 es 49, del 2 es 50 y así sucesivamente), y los va sumando. Al final se transforma este número a cadena y se retorna. Todo esto se itera mediante un ciclo while que está revisando el momento en que el tamaño de la cadena sea 1 para terminar. Finalmente, como no interesa guardar un paso anterior, el resultado de la suma de caracteres se puede almacenar sobre la misma variable, de este modo, es posible estar revisando el tamaño de la cadena en cada iteración.

# Complejidad
- Complejidad de tiempo:
    <!-- Add your time complexity here, e.g. $$O(n)$$ -->
    $$O(1)$$

- Complejidad de espacio:
    <!-- Add your space complexity here, e.g. $$O(n)$$ -->
    $$O(1)$$

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

string sumDigits(string number) {
  int sum = 0;
  for(int i = 0; i < number.size(); i++) {
    sum+=number[i] - '0';
  }
  return to_string(sum);
}
 
void readInput() {
  string sIn;
  char in[100];
  while (scanf("%s", in) != EOF && in[0] != '0') {
    sIn = in;
    while (sIn.size() > 1) {
      sIn = sumDigits(sIn);
    }
    printf("%s\n", sIn.c_str());
  }
}

int main() {
  readInput();
  return 0;
}

```
