# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Se podría intentar un ciclo que itere y compare cada número con sus siguientes números.

# Enfoque
<!-- Describe your approach to solving the problem. -->
La parte importante del problema está en que dice que están ordenados por su nivel de expertiz de mayor a menor, por lo tanto, es posible resolverlo en $O(n)$. Para lograr esto, es importante considerar 2 ámbitos importante para este problema. El primero es que no porque un alumno tenga más expertiz tiene un IQ más alto, y el segundo es el orden de expertiz comentado anteriormente. Teniendo esto en cuenta, podemos tener una variable que almacene el valor máximo hasta el momento, este será comparado con todos los demás valores de IQ de los estudiantes menos expertos (los valores que entren después de ese). Además, tener una variable para almacenar la máxima diferencia. Si la diferencia entre el valor IQ actual más alto y el IQ nuevo es mayor a la que tenemos almacenada, entonces se almacena esta nueva diferencia. Debido a que queremos obtener la mayor diferencia, es importante tener el IQ más alto hasta el momento, por lo que también se hace la comparación si el valor IQ más alto actual es menor al nuevo valor IQ, entonces remplazamos este valor.

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

void readInput()
{
  int n, m;
  int maxi;
  int in;
  int arrSize;
  scanf("%d", &n);
  int cont;
  while (n--) {
    maxi = -100005;
    scanf("%d", &m);
    arrSize = m;
    cont = 0;
    int current;
    scanf("%d", &current);
    m--;
    while (m--) {
      scanf("%d", &in);
      maxi = current - in > maxi ? current - in : maxi;
      current = in > current ? in : current;
    }
    printf("%d\n", maxi);
  }
}

int main()
{
  readInput();
  return 0;
}


```
