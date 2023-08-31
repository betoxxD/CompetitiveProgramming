# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
A primera vista parece ser un problema que se resuelve con un ciclo. Podría considerarse al número de guerrerros restarle primero 1, y verificar si el número de guerreros es mayor o igual a 2, si es así, restar a los guerreros 2 y así sucesivamente. En caso de que sean menos guerreros que el número actual que estamos restando, entonces romper el ciclo e imprimir ese número - 1.

# Enfoque
<!-- Describe your approach to solving the problem. -->
Si bien el algoritmo podría resolver el problema, este no lo haría en tiempo debido al límite superior de la entrada ($10¹⁸$), lo cual podría ejecutar siendo optimistas $10⁹$ operaciones (insuficientes para ejecutarse en 1 segundo), por lo que hay que buscar otra estrategia.

El problema nos indica que en la primera en la fila 1 hay 1 guerrero, en la fila 2 hay 2 guerreros, en la 3 hay 3 y así sucesivamente, lo que quiere decir que en la fila i hay i guerreros. Indagando un poco más en el problema podemos notar que para completar 1 fila se necesita 1 guerrero, para completar la fila 2 se necesitan 3 guerreros (1 de la fila 1 más 2 de la fila 2), para la fila 3 se necesitan 6 ($1 + 2 + 3$) y para la 4 10 ($1 + 2 + 3 + 4$). Notamos que para obtener el número de guerreros de la fila $n$, hay que sumar todos los números desde 1 hasta $n$, por lo cual, es prudente considerar la fórmula para sumatorias, la cual dice lo siguiente:

$$\sum_{i=1}^n i = {n (n + 1) \over 2}$$

Debido a que en el problema se está buscando el valor de $n$ (el número de filas que alcanzaremos a cubrir con $w$ guerreros), es necesario despejar la fórmula, obteniendo la siguiente ecuación de segundo grado:

$$w = {n (n + 1) \over 2}$$

$$0 = n² + n - 2w$$

Ahora simplemente queda aplicar la fórmula general sobre esta ecuación, teniendo como resultado lo siguiente:

$$n = {-1 + \sqrt{1 - 4(-2w)}\over 2}$$

Si analizamos bien la ecuación de segundo grado, podemos notar que el único valor variable es $c$ (recordar la forma de una ecuación de estas características, la cual es $ax² + bx +c = 0$), por lo tanto, en la fórmula general el único valor variable será $w$. Además de esto, considerar también que el valor que necesitamos es el positivo (porque buscamos cuantas filas podemos armar). De esta manera, el resultado entero de la fórmula es el número de filas que podemos formar con $w$ guerreros.

# Complexity
- Time complexity:
    <!-- Add your time complexity here, e.g. $$O(n)$$ -->
    $$O(1)$$

- Space complexity:
    <!-- Add your space complexity here, e.g. $$O(n)$$ -->
    $$O(1)$$

# Code
```cpp
#include <bits/stdc++.h>

using namespace std;

long long countLines(long long warriors)
{
	return (-1 + sqrt(1 - (4 * -2 * warriors))) / 2;
}

void readInput()
{
	// Read all the input needed on the problem and store it on global variables (or pass to another function)
	int n;
	long long warriors;
	scanf("%d", &n);
	while (n--) {
		scanf("%lld", &warriors);
		printf("%lld\n", countLines(warriors));
	}
}

int main()
{
	readInput();
	return 0;
}
```
