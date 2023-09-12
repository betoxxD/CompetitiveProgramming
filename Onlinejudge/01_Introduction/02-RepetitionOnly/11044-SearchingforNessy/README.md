# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
Debido a lo que pide el problema, podría resolverse utilizando un algoritmo greedy, tratando de emular en una matriz lo que el problema presenta.

# Enfoque
<!-- Describe your approach to solving the problem. -->
Si bien el problema podría resolverse como anteriormente se mencionó, hay una manera más sencilla de codificar para obtener *Acepted*. Para esto, tenemos que analizar como se comporta cada sonar en el lago (la matriz). Primero que hada, hay que considerar que las orillas no se deben de considerar porque el monstruo no puede estar ahí, por lo tanto, el área que deben ocupar los sonar queda representado en la siguiente tabla, considerando un tamaño de $6*6$.

| x | x | x | x | x | x |
|---|---|---|---|---|---|
| x |   |   |   |   | x |
| x |   |   |   |   | x |
| x |   |   |   |   | x |
| x |   |   |   |   | x |
| x | x | x | x | x | x |

Esto deja un margen de búsqueda de $(n - 2) * (m - 2)$. Entonces, para un lago de $6 * 6$ una de las soluciones más factibles es la siguiente, dónde 0 es un sonar y 1 el lugar que cubre un sonar.

| x | x | x | x | x | x |
|---|---|---|---|---|---|
| x | 1 | 1 | 1 | 1 | x |
| x | 1 | 0 | 1 | 0 | x |
| x | 1 | 1 | 1 | 1 | x |
| x | 1 | 0 | 1 | 0 | x |
| x | x | x | x | x | x |

Para un lago de $7 * 7$, $8 * 8$ y $9 * 9$ quedaría de la siguiente manera.

| x | x | x | x | x | x | x |
|---|---|---|---|---|---|---|
| x | 1 | 1 | 1 | 1 | 1 | x |
| x | 1 | 0 | 1 | 1 | 0 | x |
| x | 1 | 1 | 1 | 1 | 1 | x |
| x | 1 | 1 | 1 | 1 | 1 | x |
| x | 1 | 0 | 1 | 1 | 0 | x |
| x | x | x | x | x | x | x |

| x | x | x | x | x | x | x | x |
|---|---|---|---|---|---|---|---|
| x | 1 | 1 | 1 | 1 | 1 | 1 | x |
| x | 1 | 0 | 1 | 1 | 0 | 1 | x |
| x | 1 | 1 | 1 | 1 | 1 | 1 | x |
| x | 1 | 1 | 1 | 1 | 1 | 1 | x |
| x | 1 | 0 | 1 | 1 | 0 | 1 | x |
| x | 1 | 1 | 1 | 1 | 1 | 1 | x |
| x | x | x | x | x | x | x | x |

| x | x | x | x | x | x | x | x | x |
|---|---|---|---|---|---|---|---|---|
| x | 1 | 1 | 1 | 1 | 1 | 1 | 1 | x |
| x | 1 | 0 | 1 | 1 | 0 | 1 | 0 | x |
| x | 1 | 1 | 1 | 1 | 1 | 1 | 1 | x |
| x | 1 | 1 | 1 | 1 | 1 | 1 | 1 | x |
| x | 1 | 0 | 1 | 1 | 0 | 1 | 0 | x |
| x | 1 | 1 | 1 | 1 | 1 | 1 | 1 | x |
| x | 1 | 0 | 1 | 1 | 0 | 1 | 0 | x |
| x | x | x | x | x | x | x | x | x |

Si analizamos bien el patrón, para cubrir verticalmente (y horizontalmente) 1, 2 y 3 espacios, se necesita 1 sonar, para cubrir 4, 5 y 6, se necesitan 2, y así sucesivamente, por lo tanto, cada 3 espacios se ocupa un sonar más. Esto podría resolverse con un bucle, sin embargo, podemos crear una fórmula para resolver cada caso en $O(1)$.

Revisando paso a paso y tomando en cuenta el patrón anterior, si dividimos estos entre 3, obtenemos que ${1\over3} = 0.333...$, ${2\over3} = 0.666...$, ${3\over3} = 1...$, ${4\over3} = 1.333...$, ${5\over3} = 1.666...$, ${6\over3} = 2...$, etc. Si bien, esto no nos da el resultado correcto, podemos utilizar la función [ceil](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions) para convertir estos números que no son múltiplo de 3 en el número de sonar que estamos buscando (ceil retorna el número más próximo hacia arriba), obteniendo como resultado la siguiente fórmula:

$$r = ⌈{n \over 3}⌉$$
$$c = ⌈{m \over 3}⌉$$

Dónde: 
* r: Cantidad de sonar por fila
* c: Cantidad de sonar por columna
* n: Cantidad de filas
* m: Cantidad de columnas

Ahora como ya tenemos la cantidad de sonar necesarios por fila y columna, solamente hace falta multiplicar estos dos valores entre ellos y obtenemos la cantidad total de sonar necesarios, solamente que esta operación está considerando las orillas (el problema pide no considerarlas), así que, haciendo esta modificación, quitamos 2 espacios a las filas y las columnas (correspondientes a cada orilla del lago), obtenemos la siguiente fórmula:

$$s = ⌈{(n - 2) \over 3}⌉ * ⌈{(m - 2) \over 3}⌉$$

Dónde:
* s = Cantidad de sonar total necesarios para resolver el problema.

De esta manera obtendremos el resultado que el problema está solicitando en $O(1)$ por caso de uso.

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

void readInput()
{
	int q, n, m, result;
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &n, &m);
		result = ceil((n - 2) / 3.0) * ceil((m - 2) / 3.0);
		printf("%d\n", result);
	}
}

int main()
{
	readInput();
	return 0;
}

```
