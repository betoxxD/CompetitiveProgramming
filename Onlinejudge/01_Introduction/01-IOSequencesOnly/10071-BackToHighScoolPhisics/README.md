# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The problem is really easy. It says that the particle at time ***t*** has ***v*** of velocity, and is asking for ***2t***. It could be done in a simple operation using the distance formula.

# Approach
<!-- Describe your approach to solving the problem. -->
We have to consider the distance formula, which says that $d = v * t + 1/2 * a$ where $d = distance$, $v = velocity$, $t = time$ and $a = aceleration$. Considering aceleration as 0 we get that $d = v * t$. The problem wants to know the distance after the double of the time that we know. Adding this, the final formula looks like this.

$$d = v * 2t$$

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

int main()
{
	int v, t;
	while (scanf("%d%d", &v, &t) != EOF) {
		printf("%d\n", 2 * v * t);
	}
	return 0;
}

```
