
#include <stdio.h>
#include <string.h>

#define SIZE 10000000

// Función que calcula la longitud del prefijo común entre las cadenas s1 y s2
int prefix_length(char s1[], char s2[]) {
  int i = 1; // Comienza desde el índice 1 porque el problema especifica que
             // tiene que ser unoindexado
  // Compara carácter por carácter hasta encontrar una diferencia
  while (s1[i] == s2[i]) {
    i++;
  }
  return i - 1; // Devuelve la longitud del prefijo común
                // Nota: Se resta 1 porque el índice i se incrementa una vez más
                // después de encontrar la diferencia, por lo que i - 1 es la
                // longitud del prefijo común
}

// Función que calcula la longitud del sufijo común entre las cadenas s1 y s2
int suffix_length(char s1[], char s2[], int len) {
  // Comienza desde el último índice de la cadena, al ser unoindexado,
  // el último índice es igual a la longitud de la cadena
  int i = len;

  // Compara desde el final de las cadenas
  while (i >= 2 && s1[i] == s2[i - 1]) {
    i--;
  }
  return len - i; // Devuelve la longitud del sufijo común
                  // Nota: Se resta i de la longitud total para obtener la
                  // longitud del sufijo común
}

int main() {
  // Se inicializa ambos char con un tamaño + 2 porque
  // Se empezará a tomar en cuenta desde el índice 1 (el problema indica que
  // debe ser 1 indexado) y se requiere 1 elemento para el terminador null (\0)
  static char s1[SIZE + 2], s2[SIZE + 2];
  int len, prefix, suffix, total;

  // Se lee la entrada de la cadena s1 y s2 comenzando desde el índice 1
  fgets(&s1[1], SIZE, stdin);
  fgets(&s2[1], SIZE, stdin);

  // Se elimina el salto de línea al final de la cadena usando strcspn
  // Se agrega 1 al índice porque se empieza a contar desde el índice 1
  s1[strcspn(&s1[1], "\n") + 1] = '\0';
  s2[strcspn(&s2[1], "\n") + 1] = '\0';

  // Se calcula la longitud de la cadena más grande
  len = strlen(&s1[1]);

  // Se calcula la longitud del prefijo común
  prefix = prefix_length(s1, s2);

  // Se calcula la longitud del sufijo común
  suffix = suffix_length(s1, s2, len);

  // Se calcula el total usando la fórmula ajustada:
  // El prefijo y el sufijo se superponen, por lo que se realiza este ajuste.
  total = (prefix + 1) - (len - suffix) + 1;

  // Si el total es negativo, se ajusta a 0 porque no hay coincidencias válidas
  if (total < 0) {
    total = 0;
  }

  // Se imprime el total, que es el número de posiciones de coincidencia
  printf("%d\n", total);

  // Se imprimen los índices de las posiciones de la cadena 1 que coinciden con
  // la cadena 2
  for (int i = 0; i < total; i++) {
    // Se calcula el índice en la cadena 1 desde donde empieza el sufijo
    printf("%d", i + len - suffix);

    // Se imprime un espacio entre los índices, pero no después del último
    if (i < total - 1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }

  return 0;
}
