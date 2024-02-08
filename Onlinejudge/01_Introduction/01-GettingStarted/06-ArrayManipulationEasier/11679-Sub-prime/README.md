# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
El problema implica determinar si es posible liquidar todas las debentures entre bancos sin la necesidad de un rescate del Banco Central de Nlogonia. Para cada caso de prueba, necesitamos verificar si cada banco puede pagar sus deudas utilizando solo sus reservas monetarias.

# Enfoque
<!-- Describe your approach to solving the problem. -->
1. Leemos la entrada que contiene el número de bancos (B), el número de debentures (N), las reservas monetarias de cada banco y la información sobre las deudas.
2. Para cada debenture, restamos el valor de la debenture de las reservas del banco deudor y sumamos el mismo valor a las reservas del banco acreedor.
3. Verificamos si alguna de las reservas de los bancos es negativa. Si todas las reservas son no negativas, significa que todas las deudas pueden ser pagadas sin necesidad de un rescate del Banco Central.
4. Imprimimos 'S' si todas las deudas pueden ser pagadas sin un rescate, de lo contrario, imprimimos 'N'.

# Complejidad
- Complejidad de tiempo:
    <!-- Add your time complexity here, e.g. $$O(n)$$ -->
    $$O(n)$$

- Complejidad de espacio:
    <!-- Add your space complexity here, e.g. $$O(n)$$ -->
    $$O(n)$$

# Código
```cpp
#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

vector<int> banks; // Vector para almacenar las reservas monetarias de los bancos

void clearData() // Función para limpiar los datos del vector
{
  banks.clear();
}

void readInput() // Función para leer la entrada y resolver el problema
{
  int b, n; // Variables para el número de bancos (B) y el número de debentures (N)
  int deb; // Variable temporal para almacenar la reserva monetaria de cada banco
  int debitor, creditor, debenture; // Variables temporales para almacenar la información sobre las deudas
  bool canPay = true; // Bandera para verificar si todas las deudas pueden ser pagadas sin necesidad de un rescate

  // Iteramos sobre cada caso de prueba
  while (scanf("%d%d", &b, &n) != EOF && (b != 0 && n != 0))
  {
    canPay = true; // Reiniciamos la bandera

    // Leemos las reservas monetarias de cada banco
    for (int i = 0; i < b; i++)
    {
      scanf("%d", &deb);
      banks.push_back(deb); // Almacenamos la reserva en el vector
    }

    // Procesamos cada debenture
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%d", &debitor, &creditor, &debenture); // Leemos la información de la deuda
      debitor--; // Ajustamos los índices a partir de 0
      creditor--; // Ajustamos los índices a partir de 0
      banks[debitor] -= debenture; // Restamos el valor de la deuda de las reservas del banco deudor
      banks[creditor] += debenture; // Sumamos el valor de la deuda a las reservas del banco acreedor
    }

    // Verificamos si alguna reserva es negativa, lo que indica que una deuda no puede ser pagada
    for (int i = 0; i < b; i++)
    {
      if (banks[i] < 0)
        canPay = false; // Cambiamos la bandera si encontramos una reserva negativa
    }

    // Imprimimos el resultado
    if (canPay)
    {
      printf("S\n"); // Si todas las deudas pueden ser pagadas, imprimimos 'S'
    }
    else
    {
      printf("N\n"); // Si se necesita un rescate, imprimimos 'N'
    }

    clearData(); // Limpiamos los datos del vector para el próximo caso de prueba
  }
}

int main()
{
  readInput(); // Llamamos a la función para leer la entrada y resolver el problema
  return 0;
}

```
