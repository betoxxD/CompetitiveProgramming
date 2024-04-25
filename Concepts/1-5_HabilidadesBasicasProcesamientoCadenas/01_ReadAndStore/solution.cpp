#include <bits/stdc++.h>

using namespace std;

void readInput() {
	// 1.-----------------------------------------------------
	// Leer un conjunto de cadenas y terminar cuando se encuentre la cadena ".......", concatenar las cadenas recibidas antes de encontrar el patrón anterior
	// C
	char strInput[100];
	char strConcat[10000] = "";
	while(true) {
		// Leer una cadena con espacios
		fgets(strInput, 40, stdin);
		// Elimina el salto de línea estableciendo donde
		// encuentre uno como 0. C detecta como final de
		// línea cuando el valor en el char es 0.
		strInput[strcspn(strInput, "\n")] = 0;
		// Detiene la ejecución al encontrar 7 puntos
		// con la función strncmp()
		// la cual indica que comparará los primeros 7 caracteres
		// de ambos strings
		if(strncmp(strInput, ".......", 7) == 0) {
			break;
		}
		strcat(strConcat, " ");
		// Concatenación de diferentes cadenas con la función
		// strcat()
		strcat(strConcat, strInput);
	}
	// Imprime la cadena concatenada
	printf("%s\n", strConcat);

	// 2.-----------------------------------------------------
	// Buscar una cadena dentro de otra cadena
	// C
	// Definición de cadenas propuestas en el libro
	char T[10000] = "I love CS3233 Competitive Programming. i also love AlGoRiThM";
	char P[100] = "love";

	// Definición de un puntero
	char *point;
	int pos = 0;

	// Buscar la primera ocurrencia de P en T, al ser pos 0
	// tomará en cuenta toda la cadena.
	point = strstr(T + pos, P);

	// La función strstr regresa nulo si no encuentra alguna
	// coincidencia
	if(point != NULL) {
		// Iteramos mientras que nuesro puntero sea diferente de NULL
		while (point != NULL) {
			// Imprimimos el valor del puntero
			printf("%s\n", point);
			// Se obtiene la posición restando el puntero menos T.
			// Ambos apuntadores a una dirección de memoria, por
			// lo que al realizar una resta, se está ejecutando
			// una operación aritmética de punteros. Esta, en
			// resumen, resta a la posición de memoria del puntero
			// "point", la posición en la que se encuentra el
			// puntero "T", que, al point ser parte de T
			// básicamente se está restando a la posición de la
			// cadena encontrada, el inicio de la cadena.
			pos = point - T;
			pos++;
			printf("%d\n", pos);
			// Al sumarle pos al puntero T, lo que hace C es
			// mover la posición de memoria pos veces, por lo que
			// básicamente está moviendo generando un nuevo
			// puntero que apunta a "pos" posiciones adelante de T
			// hasta el final de T
			point = strstr(T + pos, P);
		}
	} else {
		printf("-1\n");
	}

	// 3.-----------------------------------------------------
	// Transformar a minúsculas y mayúsculas una cadena
	// C/C++
	int TSize = strlen(T);
	printf("Normal:\n%s\n", T);
	// Convertir a minúsculas una cadena
	for(int i = 0; i < TSize; i++) {
		T[i] = tolower(T[i]);
	}
	printf("Minusculas:\n%s\n", T);

	// Convertir a mayúsculas una cadena
	for(int i = 0; i < TSize; i++) {
		T[i] = toupper(T[i]);
	}
	printf("Mayusculas:\n%s\n", T);


	// 4.-----------------------------------------------------
	// Separar una cadena por ciertos caracteres
	// C/C++
	// Se crea vector para almacenar las palabras
	vector<string> words;
	// Se crea un apuntador donde se almacenará temporalmente
	// la palabra
	char *token;
	token = strtok(T, " .");
	// Mientras el token tenga valor
	while (token != NULL) {
		// Se agrega el Token al vector
		words.push_back(token);
		// Se hace la llamada para la siguiente palabra, al
		// indicar que lo haga con NULL, se le está diciendo
		// a la función strtok que realice la operación de
		// "búsqueda" desde donde se quedó.
		// strtok regresa un apuntador desde donde se le indica
		// que inicia hasta una posición
		// donde encuentra alguno de los caracteres indicados
		// como segundo argumento.
		token = strtok(NULL, " .");
	}

	// Se ordena el vector, words.begin retorna un apuntador
	// al inicio del vector y words.end al final de este.
	// Esto ordena las palabras lexicográficamente.
	sort(words.begin(), words.end());

	for(int i = 0; i < words.size(); i++) {
		printf("%s\n", words[i].c_str());
	}

	// 5.----------------------------------------------------
	// Contar la frecuencia de cada palabra en una cadena
	// C/C++
	// Se crea estructura de almacenamiento, unordered_map
	// almacena información del tipo <clave, valor>
	unordered_map<string, int> frecuencies;
	for (int i = 0; i < words.size(); i++) {
		frecuencies[words[i]]++;
	}
	for(int i = 0; i < words.size(); i++) {
		printf("%s: %d\n", words[i].c_str(), frecuencies[words[i]]);
	}

	// 6.----------------------------------------------------
	// Leer una cadena sin conocer el tamaño
	// C/C++
	string indefiniedSizeString;
	char charInput;
	scanf("%c", &charInput);
	while (charInput != '\n') {
		indefiniedSizeString += charInput;
		scanf("%c", &charInput);
	}
	printf("%s\n", indefiniedSizeString.c_str());
}

int main() {
	readInput();
	return 0;
}
