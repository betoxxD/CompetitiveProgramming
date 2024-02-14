# Intuición
El problema es bastante sencillo. Indica que la partícula en el tiempo ***t*** tiene una velocidad ***v***, y pregunta por ***2t***. Esto se puede hacer en una operación simple utilizando la fórmula de distancia.

# Enfoque
Tenemos que considerar la fórmula de distancia, que dice que $d = v * t + 1/2 * a$ donde $d = distancia$, $v = velocidad$, $t = tiempo$ y $a = aceleración$. Considerando la aceleración como 0, obtenemos que $d = v * t$. El problema quiere saber la distancia después del doble del tiempo que conocemos. Sumando esto, la fórmula final se ve así:

$$d = v * 2t$$

# Complejidad
- Complejidad de tiempo:
    La complejidad de tiempo es $$O(1)$$, ya que la operación realizada es una multiplicación simple y no depende del tamaño de los datos de entrada.

- Complejidad de espacio:
    La complejidad de espacio es $$O(1)$$, ya que no se utiliza espacio adicional en función del tamaño de los datos de entrada.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int v, t;
	while (scanf("%d%d", &v, &t) != EOF) {
		printf("%d\n", 2 * v * t);
	}
	return 0;
}

```