# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
El problema pide la ecuación más simple y ofrece la entrada como $< símbolo > = < valor>$, por lo que imprimir la entrada podría ser la solución.

# Enfoque
<!-- Describe your approach to solving the problem. -->
Indagando un poco más en la naturaleza de las ecuaciones, tenemos que la forma más simple de una ecuación es $a = b$ dónde a y b pueden ser un valor o una variable. El ejemplo que nos muestra el problema podría ayudarnos con esto. Dice que teniendo $x = 2$, podríamos crear ecuaciones tales como $9 - X = 7$ o $X > 0; X² = 4$. Estas dos son ecuaciones válidas que cumplen $X = 2$, sin embargo, no es más simple que la misma ecuación que se nos presentó al principio. Debido a que la entrada que se nos presenta está en su forma más simple, lo único que hay que hacer es imprimir la entrada.

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

int main()
{
	char in[100000];
	while (fgets(in, 100000, stdin) != NULL) {
		printf("%s", in);
	}
	return 0;
}

```
