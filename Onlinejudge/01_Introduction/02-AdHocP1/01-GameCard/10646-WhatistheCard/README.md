
# Intuición
El problema puede parecer complejo al principio debido a las reglas del juego, pero se simplifica al analizar las operaciones repetitivas y su impacto en la posición de las cartas. Observamos que después de realizar las operaciones descritas en el juego, siempre obtenemos la carta en la posición número 33 del mazo inicial. Este resultado surge de un análisis matemático detallado de las iteraciones y movimientos de cartas en el mazo.

# Enfoque
1. **Analizar el juego paso a paso**: Desglosamos cada operación para comprender cómo se modifica el mazo y cuál es el impacto en la posición final de las cartas.
2. **Formular el valor acumulado Y**: Identificamos que el valor acumulado Y se determina sumando los valores de tres cartas específicas.
3. **Calcular el número de cartas retiradas**: Para cada iteración, determinamos cuántas cartas se retiran del mazo, acumulando estos valores.
4. **Identificar la fórmula general**: Descubrimos que la posición final de la carta de interés se puede expresar matemáticamente, y simplificamos esta fórmula para obtener una constante.

### Paso a Paso del Análisis
1. **Separación Inicial**:
   - Tomamos las primeras 25 cartas y trabajamos con las restantes 27.
2. **Iteraciones**:
   - En cada iteración, tomamos la carta superior, determinamos su valor, y calculamos el número de cartas a retirar.
   - Actualizamos el valor acumulado Y y la cantidad total de cartas retiradas (ret Acum).
3. **Repetición y Acumulación**:
   - Repetimos el proceso tres veces y sumamos los valores obtenidos.

### Fórmulas Derivadas
- **Valor acumulado Y**: 
  $$Y = X1 + X2 + X3$$
  - Donde X1, X2 y X3 son los valores de las cartas tomadas en cada iteración.
- **Cartas retiradas en cada iteración**: 
  $$Ret1 = 10 - X1 + 1$$
  $$Ret2 = 10 - X2 + 1$$
  $$Ret3 = 10 - X3 + 1$$
- **Acumulado de cartas retiradas**:
  $$Acum = Ret1 + Ret2 + Ret3$$
- **Posición final**:
  $$Pos Result = Acum + Y$$

### Simplificación
Para simplificar y entender por qué siempre obtenemos la posición 33, realizamos las siguientes sustituciones paso a paso:

1. Sustituimos las fórmulas de Ret en la ecuación de Acum:
   $$Ret1 = 10 - X1 + 1$$
   $$Ret2 = 10 - X2 + 1$$
   $$Ret3 = 10 - X3 + 1$$
   - Entonces:
   $$Acum = (10 - X1 + 1) + (10 - X2 + 1) + (10 - X3 + 1)$$

2. Simplificamos los términos:
   $$Acum = (10 + 1 - X1) + (10 + 1 - X2) + (10 + 1 - X3)$$
   $$Acum = 11 + 11 + 11 - (X1 + X2 + X3)$$
   $$Acum = 33 - (X1 + X2 + X3)$$

3. Sustituimos Y y Acum en la fórmula de Pos Result:
   $$Pos Result = Acum + Y$$
   $$Y = X1 + X2 + X3$$
   $$Acum = 33 - (X1 + X2 + X3)$$
   $$Pos Result = (33 - (X1 + X2 + X3)) + (X1 + X2 + X3)$$

4. Simplificamos los términos:
   $$Pos Result = 33 - (X1 + X2 + X3) + (X1 + X2 + X3)$$
   $$Pos Result = 33$$

### Explicación de la Posición Final
La razón por la cual podemos obtener la posición de la carta buscada en el mazo completo sumando las cartas retiradas (Acum) y el valor acumulado (Y) es debido a la naturaleza inversamente proporcional de las operaciones realizadas en cada iteración. En cada iteración, avanzamos X cartas hacia adelante pero retiramos \(10 - X + 1\) cartas, lo que efectivamente nos deja con una posición constante cuando sumamos estas dos cantidades. Por tanto, cada iteración nos acerca de manera consistente a la posición 33, independientemente de los valores específicos de las cartas.

# Complejidad
- Complejidad de tiempo:
    $O(1)$ por cada caso de prueba ya que el número de operaciones es constante y no depende del número de cartas en el mazo.

- Complejidad de espacio:
    $O(1)$ ya que solo se utilizan un número fijo de variables y una lista para almacenar las cartas, sin importar el número de casos de prueba.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

vector<string> cards;

void readInput() {
  char in[2];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cards.assign(52, "");
    for (int j = 0; j < 52; j++) {
      scanf("%s", in);
      cards[j] = in;
    }

    // La carta en la posición 33 (index 32) es siempre la respuesta
    printf("Case %d: %s\n", i + 1, cards[32].c_str());
  }
}

int main() {
  readInput();
  return 0;
}

```
