#include <bits/stdc++.h>

using namespace std;

string oneDigit = ".*.";
string twoOne   = "***";
string twoTwo   = "..*";
string twoThree = "***";
string twoFour  = "*..";
string twoFive  = "***";
string threeOne   = "***";
string threeTwo   = "..*";
string threeThree = "***";
string threeFour  = "..*";
string threeFive  = "***";

void readInput() {
  int n;
  scanf("%d", &n);
  char line1[1000];
  char line2[1000];
  char line3[1000];
  char line4[1000];
  char line5[1000];
  scanf("%s", line1);
  scanf("%s", line2);
  scanf("%s", line3);
  scanf("%s", line4);
  scanf("%s", line5);
  int size = strlen(line1);
  int dPos;
  bool one, two, three;
  for(int i = 0; i < size; i+=4) {
    dPos = 0;
    one = true;
    two = true;
    three = true;
    for(int j = i; j < i+3; j++) {
      if(line1[j] != oneDigit[dPos]) one = false;
      if(line2[j] != oneDigit[dPos]) one = false;
      if(line3[j] != oneDigit[dPos]) one = false;
      if(line4[j] != oneDigit[dPos]) one = false;
      if(line5[j] != oneDigit[dPos]) one = false;

      if(line1[j] != twoOne[dPos]) two = false;
      if(line2[j] != twoTwo[dPos]) two = false;
      if(line3[j] != twoThree[dPos]) two = false;
      if(line4[j] != twoFour[dPos]) two = false;
      if(line5[j] != twoFive[dPos]) two = false;

      if(line1[j] != threeOne[dPos]) three = false;
      if(line2[j] != threeTwo[dPos]) three = false;
      if(line3[j] != threeThree[dPos]) three = false;
      if(line4[j] != threeFour[dPos]) three = false;
      if(line5[j] != threeFive[dPos]) three = false;
      dPos++;
    }
    if(one) printf("1");
    if(two) printf("2");
    if(three) printf("3");
  }
  printf("\n");
}

int main() {
  readInput();
  return 0;
}
