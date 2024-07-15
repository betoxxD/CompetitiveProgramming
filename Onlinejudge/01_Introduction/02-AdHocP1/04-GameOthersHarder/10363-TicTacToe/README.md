# Intuición
En el juego de Tic Tac Toe, la verificación de un estado válido implica asegurar que la cantidad de 'X' y 'O' en el tablero sean consistentes con las reglas del juego, y que las condiciones de victoria no se violen. Un tablero válido debe cumplir con las siguientes condiciones:

1. El número de 'X' debe ser igual al número de 'O' o uno más (ya que 'X' siempre empieza).
2. No puede haber ambos jugadores ganando al mismo tiempo.
3. Si 'X' gana, debe haber exactamente un 'X' más que 'O'.
4. Si 'O' gana, debe haber exactamente el mismo número de 'X' que de 'O'.

# Enfoque
1. Leer el número de casos de prueba.
2. Para cada caso de prueba, leer el tablero y contar el número de 'X' y 'O'.
3. Verificar si alguna de las condiciones de victoria se cumple para 'X' o 'O'.
4. Validar las condiciones mencionadas en la intuición y determinar si el tablero es válido o no.

# Complejidad
- Complejidad de tiempo: $O(N)$ por caso de prueba, donde NN es el número de celdas en el tablero (siempre 9 en este caso).
- Complejidad de espacio: $O(N)$ ya que solo se usa una cantidad constante de espacio adicional.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

char board[5][5];

// Cuenta el número de X por línea leida
int countX(string in) {
  int sum = 0;
  int inSize = in.size();
  for (int i = 0; i < inSize; i++) {
    if (in[i] == 'X') {
      sum++;
    }
  }
  return sum;
}

// Cuenta el número de O por línea leida
int countO(string in) {
  int sum = 0;
  int inSize = in.size();
  for (int i = 0; i < inSize; i++) {
    if (in[i] == 'O') {
      sum++;
    }
  }
  return sum;
}

// Agrega la nueva línea al tablero
void addToBoard(string in, int pos) { strcpy(board[pos], in.c_str()); }

// Verificar si X ganó la partida
bool checkXWin() {
  // Verificar horizontalmente
  if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
    return true;
  if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
    return true;
  if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
    return true;
  // Verificar verticalmente
  if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
    return true;
  if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
    return true;
  if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
    return true;
  // Verificar diagonales
  if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
    return true;
  if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
    return true;
  return false;
}

// Verifica si el jugador O ganó
bool checkOWin() {
  // Verificar horizontalmente
  if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
    return true;
  if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
    return true;
  if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
    return true;
  // Verificar verticalmente
  if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
    return true;
  if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
    return true;
  if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
    return true;
  // Verificar diagonales
  if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
    return true;
  if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
    return true;
  return false;
}

void readInput() {
  int n;
  scanf("%d", &n);
  char in[5];
  int xS, oS;
  bool xWin, oWin;
  while (n--) {
    xS = oS = 0;
    for (int i = 0; i < 3; i++) {
      scanf("%s", in);
      // Cuenta las X en la línea
      xS += countX(in);
      // Cuenta las Y en la línea
      oS += countO(in);
      // Agrega la nueva línea al tablero
      addToBoard(in, i);
    }
    // lee el espacio en blanco
    getchar();
    // Verifica si el jugador X ganó el juego
    xWin = checkXWin();
    // Verifica si el jugador O ganó el juego
    oWin = checkOWin();
    // Si ambos jugadores ganaron, no es válido
    if (xWin && oWin) {
      printf("no\n");
    } else if (xS - 1 == oS) {
      // Si X es mayor con 1 y O ganó, entonces no es válido
      // ya que al X tirar primero, O al ganar debería de tener
      // la misma cantidad de fichas en el tablero
      if (oWin)
        printf("no\n");
      else
        printf("yes\n");
    } else if (xS == oS) {
      // Si X y O son iguales y X gana, no es posible
      // debido a que X tira primero, si X gana, debería de
      // tener una ficha más en el tablero
      if (xWin)
        printf("no\n");
      else
        printf("yes\n");
    } else {
      // Si ninguna de las condiciones anteriores se cumple,
      // no es posible validar como correcto el tablero
      printf("no\n");
    }
  }
}

int main() {
  readInput();
  return 0;
}

```
