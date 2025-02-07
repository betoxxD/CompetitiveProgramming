#include <bits/stdc++.h>

using namespace std;

bool isvowel(char c) {
  c = tolower(c);
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

void processInput(char input[1000000]) {
  int inSize = strlen(input);
  bool isWord = false;
  bool isVowel = false;
  char firstChar = '\0';
  for (int i = 0; i < inSize; i++) {
    if (isalpha(input[i])) {
      if (isWord) {
        printf("%c", input[i]);
      } else {
        isWord = true;
        if (isvowel(input[i])) {
          printf("%c", input[i]);
          isVowel = true;
        } else {
          isVowel = false;
          firstChar = input[i];
        }
      }
    } else {
      if (isWord) {
        if (!isVowel) {
          printf("%c", firstChar);
        }
        printf("ay");
      }
      isWord = false;
      isVowel = false;
      printf("%c", input[i]);
    }
  }
  if (isWord) {
    if (!isVowel) {
      printf("%c", firstChar);
    }
    printf("ay");
  }
}

void readInput() {
  char in[1000000];
  while (fgets(in, sizeof(in), stdin) != NULL) {
    processInput(in);
  }
}

int main() {
  readInput();
  return 0;
}
