#include <bits/stdc++.h>

using namespace std;

string sumDigits(string number) {
  int sum = 0;
  for(int i = 0; i < number.size(); i++) {
    sum+=number[i] - '0';
  }
  return to_string(sum);
}
 
void readInput() {
  string sIn;
  char in[100];
  while (scanf("%s", in) != EOF && in[0] != '0') {
    sIn = in;
    while (sIn.size() > 1) {
      sIn = sumDigits(sIn);
    }
    printf("%s\n", sIn.c_str());
  }
}

int main() {
  readInput();
  return 0;
}
