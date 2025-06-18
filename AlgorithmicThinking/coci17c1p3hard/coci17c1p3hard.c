
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición del tamaño máximo permitido para un password
#define MAX_PASSWORD 10
// Número de bits para la tabla hash (tamaño de 2^NUM_BITS)
#define NUM_BITS 20

// Macros para calcular el tamaño y la máscara de la tabla hash
#define hashsize(n) ((unsigned long)1 << (n)) // Tamaño de la tabla hash: 2^n
#define hashmask(n)                                                            \
  (hashsize(n) - 1) // Máscara para mantener el hash dentro de los límites

// Estructura para representar un nodo de password dentro de la tabla hash
typedef struct password_node {
  char password[MAX_PASSWORD + 1]; // El password (terminado en '\0')
  int total; // Número de veces que se ha insertado (ocurrencias)
  struct password_node *next; // Puntero al siguiente nodo (para colisiones)
} password_node;

// Algoritmo de hashing "One-at-a-time" (OAAT) de Bob Jenkins
// Devuelve un hash de longitud 'bits' para una cadena dada
unsigned long oaat(char *key, unsigned long len, unsigned long bits) {
  unsigned long hash, i;
  for (hash = 0, i = 0; i < len; i++) {
    hash += key[i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }
  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);
  return hash & hashmask(bits); // Aplicar máscara para evitar desbordamiento
}

// Busca un password en la tabla hash
// Devuelve un puntero al nodo si se encuentra, o NULL si no existe
password_node *in_hash_table(password_node *hash_table[], char *find) {
  unsigned password_code;
  password_node *password_ptr;
  password_code =
      oaat(find, strlen(find), NUM_BITS);   // Calcular el hash del password
  password_ptr = hash_table[password_code]; // Ir al bucket correspondiente

  while (password_ptr) { // Recorrer la lista enlazada en ese bucket
    if (strcmp(password_ptr->password, find) ==
        0) {               // Comparar con el password buscado
      return password_ptr; // Si se encuentra, retornar el nodo
    }
    password_ptr =
        password_ptr->next; // Avanzar al siguiente nodo en caso de colisión
  }
  return NULL; // No se encontró el password
}

// Agrega un password a la tabla hash o incrementa su contador si ya existe
void add_to_hash_table(password_node *hash_table[], char *find) {
  unsigned password_code;
  password_node *password_ptr;
  password_ptr = in_hash_table(
      hash_table, find); // Verificar si el password ya está en la tabla
  if (!password_ptr) {   // Si no está, crear nuevo nodo
    password_code = oaat(find, strlen(find), NUM_BITS); // Calcular el hash
    password_ptr =
        malloc(sizeof(password_node)); // Asignar memoria para nuevo nodo
    if (password_ptr == NULL) {        // Manejo de error por falta de memoria
      fprintf(stderr, "malloc error\n");
      exit(1);
    }

    strcpy(password_ptr->password, find); // Copiar el password al nodo
    password_ptr->total = 0;              // Inicializar contador de ocurrencias
    password_ptr->next =
        hash_table[password_code]; // Insertar al inicio de la lista del bucket
    hash_table[password_code] = password_ptr; // Apuntar el bucket al nuevo nodo
  }
  password_ptr->total++; // Incrementar el contador
}

// Verifica si un substring ya ha sido procesado anteriormente
int already_added(char all_substrings[][MAX_PASSWORD + 1], int total_substrings,
                  char *find) {
  int i;

  for (i = 0; i < total_substrings; i++) {
    if (strcmp(all_substrings[i], find) ==
        0) {    // Comparar con todos los substrings anteriores
      return 1; // Si ya fue agregado, retornar verdadero
    }
  }
  return 0; // No fue encontrado, se puede agregar
}

int main(void) {
  // Declarar e inicializar la tabla hash (punteros a listas enlazadas)
  static password_node *hash_table[1 << NUM_BITS] = {NULL};

  int num_ops, op, op_type, i, j;
  char password[MAX_PASSWORD + 1], substring[MAX_PASSWORD + 1];
  password_node *password_ptr;
  int total_substrings;
  char all_substrings[MAX_PASSWORD * MAX_PASSWORD]
                     [MAX_PASSWORD +
                      1]; // Almacena substrings únicos de cada password

  scanf("%d", &num_ops); // Leer número de operaciones

  int password_size;
  for (op = 0; op < num_ops; op++) {
    scanf("%d%s", &op_type, password); // Leer tipo de operación y el password
    password_size = strlen(password);  // Calcular longitud del password

    if (op_type == 1) { // Operación de tipo 1: insertar substrings
      total_substrings = 0;
      for (i = 0; i < password_size; i++) {
        for (j = i; j < password_size; j++) {
          strncpy(substring, &password[i],
                  j - i + 1);          // Extraer substring desde i hasta j
          substring[j - i + 1] = '\0'; // Asegurar terminación nula

          // Verificar si el substring ya fue procesado antes
          if (!already_added(all_substrings, total_substrings, substring)) {
            add_to_hash_table(hash_table,
                              substring); // Agregar substring a la tabla hash
            strcpy(all_substrings[total_substrings],
                   substring);  // Guardar el substring en la lista de vistos
            total_substrings++; // Aumentar contador de substrings únicos
          }
        }
      }
    } else { // Operación de tipo 2: consultar ocurrencias
      password_ptr = in_hash_table(
          hash_table, password); // Buscar el password exacto en la tabla hash
      if (!password_ptr) {
        printf("0\n"); // No se encontró: imprimir 0
      } else {
        printf("%d\n",
               password_ptr->total); // Se encontró: imprimir cantidad de veces
      }
    }
  }

  return 0;
}
