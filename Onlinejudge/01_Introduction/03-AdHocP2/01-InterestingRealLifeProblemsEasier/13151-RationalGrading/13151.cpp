#include <bits/stdc++.h>

using namespace std;

int iGValue;

int convertToInt(string iValue) {
  if (iValue[0] == '0') {
    if (iValue[1] == 'x') {
      return stoi(iValue, 0, 16);
    } else {
      return stoi(iValue, 0, 8);
    }
  }
  return stoi(iValue);
}

void printDebug(string expression, int outputValue) {
  printf("Value: %d\n", iGValue);
  printf("Expression: %s\n", expression.c_str());
  printf("Output: %d\n", outputValue);
  printf("Desired value: ");
  if (expression == "++i") {
    printf("%d\n", iGValue + 1);
    if (iGValue + 1 == outputValue) {
      printf("Result: true\n");
    } else {
      printf("Result: false\n");
    }
  } else if (expression == "i++") {
    printf("%d\n", iGValue);
    if (iGValue == outputValue) {
      printf("Result: true\n");
    } else {
      printf("Result: false\n");
    }
  } else if (expression == "--i") {
    printf("%d\n", iGValue - 1);
    if (iGValue - 1 == outputValue) {
      printf("Result: true\n");
    } else {
      printf("Result: false\n");
    }
  } else if (expression == "i--") {
    printf("%d\n", iGValue);
    if (iGValue == outputValue) {
      printf("Result: true\n");
    } else {
      printf("Result: false\n");
    }
  } else {
    printf("%d\n", iGValue);
    if (iGValue == outputValue) {
      printf("Result: true\n");
    } else {
      printf("Result: false\n");
    }
  }
}

bool evaluateResult(string expression, int outputValue) {
  if (expression == "++i") {
    if (iGValue + 1 == outputValue) {
      iGValue++;
      return true;
    } else {
      iGValue = outputValue;
      return false;
    }
  } else if (expression == "i++") {
    if (iGValue == outputValue) {
      iGValue++;
      return true;
    } else {
      iGValue = outputValue;
      iGValue++;
      return false;
    }
  } else if (expression == "--i") {
    if (iGValue - 1 == outputValue) {
      iGValue--;
      return true;
    } else {
      iGValue = outputValue;
      return false;
    }
  } else if (expression == "i--") {
    if (iGValue == outputValue) {
      iGValue--;
      return true;
    } else {
      iGValue = outputValue;
      iGValue--;
      return false;
    }
  } else {
    if (iGValue == outputValue) {
      return true;
    } else {
      iGValue = outputValue;
      return false;
    }
  }
  return false;
}

void readInput() {
  char iValue[100000];
  int nEval;
  char expressionIn[10];
  int outputValue;
  int cont;
  bool isCorrect;
  int contar = 1;
  while (scanf("%s%d", iValue, &nEval) != EOF && strcmp(iValue, "0") != 0 &&
         nEval != 0) {
    cont = 0;
    iGValue = convertToInt(iValue);
    while (nEval--) {
      scanf("%s%d", expressionIn, &outputValue);
      /*printDebug(expressionIn, outputValue);*/
      isCorrect = evaluateResult(expressionIn, outputValue);
      if (isCorrect) {
        cont++;
      }
      /*printf("New registered value: %d\n", iGValue);*/
      /*printf("Flags: %d\n", cont);*/
      /*printf("-----------------------------------\n");*/
    }
    printf("%d\n", cont);
  }
}

int main() {
  readInput();
  return 0;
}
