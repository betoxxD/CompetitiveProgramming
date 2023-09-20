# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
El problema parece ser muy sencillo, simplemente seguir las operaciones indicadas y al final obtener de alguna manera el número de los decimales.

# Enfoque
<!-- Describe your approach to solving the problem. -->
El problema pide realizar unas operaciones y posteriormente obtener su número decimal. Simplemente hacer estas operaciones. Para obtener el número decimal del resultado existen diferentes formas. En este código se utilizó el método de convertir el número a cadena y obtener el penúltimo número validando que este exista, si no existe se retorna un 0 (debido a que en el rango de números del 0 al 9, el número decimal es 0).

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
	int t;
	long long n;
	string ns;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		n *= 567;
		n /= 9;
		n += 7492;
		n *= 235;
		n /= 47;
		n -= 498;
		ns = to_string(n);
		printf("%c\n", ns.size() >= 2 ? ns[ns.size() - 2] : 0);
	}
}

int main()
{
	readInput();
	return 0;
}

```
