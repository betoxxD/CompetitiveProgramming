#include <bits/stdc++.h>

using namespace std;
//  *          *          *    *          *          *          *    *
// 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B', 'C'
unordered_map<string, bool> CScale = {{"C", true}, {"D", true}, {"E", true},
                                      {"F", true}, {"G", true}, {"A", true},
                                      {"B", true}};
//  *          *          *    *          *          *          *    *
// 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B', 'C', 'C#'
unordered_map<string, bool> CSScale = {{"C#", true}, {"D#", true}, {"F", true},
                                       {"F#", true}, {"G#", true}, {"A#", true},
                                       {"C", true}};

//  *          *          *    *          *          *          *    *
// 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B', 'C', 'C#', 'D'
unordered_map<string, bool> DScale = {{"D", true}, {"E", true}, {"F#", true},
                                      {"G", true}, {"A", true}, {"B", true},
                                      {"C#", true}};

//  *          *          *    *          *          *          *    *
// 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B', 'C', 'C#', 'D', 'D#'
unordered_map<string, bool> DSScale = {{"D#", true}, {"F", true},  {"G", true},
                                       {"G#", true}, {"A#", true}, {"C", true},
                                       {"D", true}};

//  *          *          *    *          *          *          *    *
// 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E'
unordered_map<string, bool> EScale = {{"E", true}, {"F#", true}, {"G#", true},
                                      {"A", true}, {"B", true},  {"C#", true},
                                      {"D#", true}};

//  *          *          *    *          *          *          *    *
// 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F'
unordered_map<string, bool> FScale = {{"F", true},  {"G", true}, {"A", true},
                                      {"A#", true}, {"C", true}, {"D", true},
                                      {"E", true}};

//  *          *          *    *          *          *          *    *
// 'F#', 'G', 'G#', 'A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#'
unordered_map<string, bool> FSScale = {{"F#", true}, {"G#", true}, {"A#", true},
                                       {"B", true},  {"C#", true}, {"D#", true},
                                       {"F", true}};

//  *          *          *    *          *          *          *    *
// 'G', 'G#', 'A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G'
unordered_map<string, bool> GScale = {{"G", true}, {"A", true}, {"B", true},
                                      {"C", true}, {"D", true}, {"E", true},
                                      {"F#", true}};

//  *          *          *    *          *          *          *    *
// 'G#', 'A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#'
unordered_map<string, bool> GSScale = {{"G#", true}, {"A#", true}, {"C", true},
                                       {"C#", true}, {"D#", true}, {"F", true},
                                       {"G", true}};

//  *          *          *    *          *          *          *    *
// 'A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A'
unordered_map<string, bool> AScale = {{"A", true}, {"B", true}, {"C#", true},
                                      {"D", true}, {"E", true}, {"F#", true},
                                      {"G#", true}};

//  *          *          *    *          *          *          *    *
// 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#'
unordered_map<string, bool> ASScale = {{"A#", true}, {"C", true}, {"D", true},
                                       {"D#", true}, {"F", true}, {"G", true},
                                       {"A", true}};

//  *          *          *    *          *          *          *    *
// 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B'
unordered_map<string, bool> BScale = {{"B", true}, {"C#", true}, {"D#", true},
                                      {"E", true}, {"F#", true}, {"G#", true},
                                      {"A#", true}};

bool C, CS, D, DS, E, F, FS, G, GS, A, AS, B;

void initializeValues() {
  C = true;
  CS = true;
  D = true;
  DS = true;
  E = true;
  F = true;
  FS = true;
  G = true;
  GS = true;
  A = true;
  AS = true;
  B = true;
}

void analiceScales(string secuence) {
  if (!CScale[secuence])
    C = false;
  if (!CSScale[secuence])
    CS = false;
  if (!DScale[secuence])
    D = false;
  if (!DSScale[secuence])
    DS = false;
  if (!EScale[secuence])
    E = false;
  if (!FScale[secuence])
    F = false;
  if (!FSScale[secuence])
    FS = false;
  if (!GScale[secuence])
    G = false;
  if (!GSScale[secuence])
    GS = false;
  if (!AScale[secuence])
    A = false;
  if (!ASScale[secuence])
    AS = false;
  if (!BScale[secuence])
    B = false;
}

void readInput() {
  char input[10000];
  char *token;
  char *endToken;
  int inputSize;
  bool afterPrinted;
  while (true) {
    afterPrinted = false;
    initializeValues();
    fgets(input, 10000, stdin);
    inputSize = strlen(input);
    inputSize[input - 1] = '\0';
    // Verificamos si la secuencia es END
    endToken = strstr(input, "END");
    if (endToken != NULL) {
      break;
    }

    // Tokenizamos la secuencia separando por espacios
    token = strtok(input, " ");
    while (token != NULL) {
      analiceScales(token);
      token = strtok(NULL, " ");
    }

    if (C) {
      printf("C");
      afterPrinted = true;
    }
    if (CS) {
      if (afterPrinted) {
        printf(" ");
      }
      printf("C#");
      afterPrinted = true;
    }
    if (D) {
      if (afterPrinted) {
        printf(" ");
      }
      printf("D");
      afterPrinted = true;
    }
    if (DS) {
      if (afterPrinted) {
        printf(" ");
      }
      printf("D#");
      afterPrinted = true;
    }
    if (E) {
      if (afterPrinted) {
        printf(" ");
      }
      printf("E");
      afterPrinted = true;
    }
    if (F) {
      if (afterPrinted) {
        printf(" ");
      }
      printf("F");
      afterPrinted = true;
    }
    if (FS) {
      if (afterPrinted) {
        printf(" ");
      }
      printf("F#");
      afterPrinted = true;
    }
    if (G) {
      if (afterPrinted) {
        printf(" ");
      }
      printf("G");
      afterPrinted = true;
    }
    if (GS) {
      if (afterPrinted) {
        printf(" ");
      }
      printf("G#");
      afterPrinted = true;
    }
    if (A) {
      if (afterPrinted) {
        printf(" ");
      }
      printf("A");
      afterPrinted = true;
    }
    if (AS) {
      if (afterPrinted) {
        printf(" ");
      }
      printf("A#");
      afterPrinted = true;
    }
    if (B) {
      if (afterPrinted) {
        printf(" ");
      }
      printf("B");
      afterPrinted = true;
    }
    printf("\n");
  }
}

int main() {
  readInput();
  return 0;
}
