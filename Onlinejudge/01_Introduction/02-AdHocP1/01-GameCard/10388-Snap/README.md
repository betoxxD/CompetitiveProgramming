# Intuición
<!-- Describe your first thoughts on how to solve this problem. -->
El problema consiste en simular el juego de cartas "Snap" entre dos jugadores, Jane y John. Los jugadores tienen dos pilas de cartas, una cara abajo y otra cara arriba, y juegan sus cartas en sincronía. La clave es detectar cuando las cartas jugadas simultáneamente son iguales y determinar quién grita "Snap" primero para obtener la pila de cartas del otro jugador. El juego continúa hasta que un jugador tiene todas las cartas o se alcanzan 1000 turnos.

# Enfoque
<!-- Describe your approach to solving the problem. -->
1. Inicialización: Inicializar las pilas de cartas de Jane y John para cada caso de prueba.
2. Simulación del Juego:

    * En cada turno, ambos jugadores colocan una carta de sus pilas cara abajo en sus respectivas pilas cara arriba.
    * Si las cartas jugadas en ese turno son iguales, se simula un "Snap" utilizando una función aleatoria para determinar quién gana la pila cara arriba del oponente.
    * Se añaden las cartas boca arriba del perdedor en cima de la pila boca arriba del ganador.
    * Si una pila cara abajo se vacía, se voltea la pila cara arriba para formar la nueva pila cara abajo.

3. Finalización del Juego:

    El juego termina cuando un jugador tiene todas las cartas o se alcanzan 1000 turnos.
    Se imprime el resultado correspondiente dependiendo del estado del juego.


# Complejidad
- Complejidad de tiempo:
    <!-- Add your time complexity here, e.g. $$O(n)$$ -->
    La complejidad de tiempo es $O(n)$, donde $n$ es el número de turnos jugados. En el peor caso, el juego puede durar 1000 turnos.

- Complejidad de espacio:
    <!-- Add your space complexity here, e.g. $$O(n)$$ -->
    La complejidad de espacio es $O(m)$, donde $m$ es el número total de cartas en las pilas de cartas de Jane y John.

# Código
```cpp
#include <bits/stdc++.h>

using namespace std;

// Definición de las pilas de cartas para Jane y John
char JanePileUp[105];
char JanePileDown[105];
char JohnPileUp[105];
char JohnPileDown[105];

// Tamaños de las pilas de cartas
int JanePileUpSize;
int JohnPileUpSize;
int JanePileDownSize;
int JohnPileDownSize;

// Inicialización de los valores y pilas de cartas
void initialiceValues() {
    JanePileUp[0] = 0;
    JohnPileUp[0] = 0;
    JanePileDown[0] = 0;
    JohnPileDown[0] = 0;
    JanePileDownSize = 0;
    JohnPileDownSize = 0;
    JanePileUpSize = 0;
    JohnPileUpSize = 0;
}

// Función para imprimir una pila en orden inverso
string printReverse(string pile) {
    string result = "";
    int pileStart = pile.size() - 1;
    for (int i = pileStart; i >= 0; i--) {
        result += pile[i];
    }
    return result;
}

// Función que simula el grito "Snap" y determina quién gana la pila de cartas
void callSnap() {
    int result = random() / 141 % 2;
    if (result == 0) { // Jane grita "Snap" primero
        strcat(JanePileUp, JohnPileUp);
        JanePileUpSize += JohnPileUpSize;
        printf("Snap! for Jane: %s\n", printReverse(JanePileUp).c_str());
        JohnPileUp[0] = 0;
        JohnPileUpSize = 0;
    } else { // John grita "Snap" primero
        strcat(JohnPileUp, JanePileUp);
        JohnPileUpSize += JanePileUpSize;
        printf("Snap! for John: %s\n", printReverse(JohnPileUp).c_str());
        JanePileUp[0] = 0;
        JanePileUpSize = 0;
    }
}

// Función que simula el juego completo
void simulateGame() {
    // Posiciones iniciales en las pilas cara abajo
    int JanePileDownPos = 0;
    int JohnPileDownPos = 0;
    // Tamaños iniciales de las pilas cara abajo
    JanePileDownSize = strlen(JanePileDown);
    int JanePileDownControl = JanePileDownSize;
    JohnPileDownSize = strlen(JohnPileDown);
    int JohnPileDownControl = JohnPileDownSize;
    // Variables para determinar el ganador
    bool JohnWins = false;
    bool JaneWins = false;
    // Simulación del juego hasta 1000 turnos
    for (int i = 0; i < 1000; i++) {
        // Jane y John juegan sus cartas
        JanePileUp[JanePileUpSize++] = JanePileDown[JanePileDownPos];
        JohnPileUp[JohnPileUpSize++] = JohnPileDown[JohnPileDownPos];
        JanePileUp[JanePileUpSize] = 0;
        JohnPileUp[JohnPileUpSize] = 0;
        JanePileDownControl--;
        JohnPileDownControl--;
        // Si las cartas jugadas son iguales, se llama a Snap
        if (JanePileDown[JanePileDownPos] == JohnPileDown[JohnPileDownPos]) {
            callSnap();
            // Verificación de las condiciones de victoria
            if (JanePileUpSize == 0 && JanePileDownControl == 0) {
                JohnWins = true;
                break;
            } else if (JohnPileUpSize == 0 && JohnPileDownControl == 0) {
                JaneWins = true;
                break;
            }
        }
        // Avance a la siguiente carta
        JanePileDownPos++;
        JohnPileDownPos++;
        // Si la pila cara abajo de Jane se vacía, se voltea la pila cara arriba
        if (JanePileDownPos == JanePileDownSize) {
            JanePileDown[0] = 0;
            JohnPileDown[0] = 0;
            JanePileDownSize = JanePileUpSize;
            JanePileDownControl = JanePileUpSize;
            strcpy(JanePileDown, JanePileUp);
            JanePileUp[0] = 0;
            JanePileUpSize = 0;
            JanePileDownPos = 0;
        }
        // Si la pila cara abajo de John se vacía, se voltea la pila cara arriba
        if (JohnPileDownPos == JohnPileDownSize) {
            JohnPileDown[0] = 0;
            JohnPileDownSize = JohnPileUpSize;
            JohnPileDownControl = JohnPileUpSize;
            strcpy(JohnPileDown, JohnPileUp);
            JohnPileUp[0] = 0;
            JohnPileUpSize = 0;
            JohnPileDownPos = 0;
        }
    }
    // Impresión del resultado final
    if (JohnWins)
        printf("John wins.\n");
    else if (JaneWins)
        printf("Jane wins.\n");
    else
        printf("Keeps going and going ...\n");
}

// Función para leer la entrada y ejecutar los casos de prueba
void readInput() {
    int n;
    char strInput[100];
    scanf("%d", &n);
    while (n--) {
        initialiceValues();
        getchar();
        scanf("%s", strInput);
        strcpy(JanePileDown, strInput);
        scanf("%s", strInput);
        strcpy(JohnPileDown, strInput);
        simulateGame();
        if (n != 0)
            printf("\n");
    }
}

// Función principal
int main() {
    readInput();
    return 0;
}


```
