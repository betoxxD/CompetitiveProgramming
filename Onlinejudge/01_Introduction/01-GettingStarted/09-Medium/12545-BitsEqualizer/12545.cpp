#include <bits/stdc++.h>

using namespace std;

bool canConvert(string S, string T){
  if(S.length() != T.length()) return false;
  int s0 = 0, s1 = 0, sQ = 0 ;
  int t0 = 0, t1 = 0;
  for(int i = 0; i < S.length(); i++) {
    if(S[i] == '0') s0++;
    else if(S[i] == '1') s1++;
    else sQ++;

    if(T[i] == '0') t0++;
    else t1++;
  }

  if(t1 - s1 < 0) return false;

  return true;
}

int convertString(string S, string T) {
  int steps = 0;

  int aux;

  int s0 = 0, s1 = 0, sQ = 0 ;
  int t0 = 0, t1 = 0;
  for(int i = 0; i < S.length(); i++) {
    if(S[i] == '0') s0++;
    else if(S[i] == '1') s1++;
    else sQ++;

    if(T[i] == '0') t0++;
    else t1++;
  }
  int neededS0 = t0 - s0;
  int neededS1 = t1 - s1;
  int stringSize = S.length();
  for(int i = 0; i < stringSize; i++) {
    if(S[i] == '?') {
      if(T[i] == '0') {
        if(neededS0 > 0) {
          S[i] = '0';
          neededS0--;
        } else {
          S[i] = '1';
          neededS1--;
        }
      } else {
        if(neededS1 > 0) {
          S[i] = '1';
          neededS1--;
        } else {
          S[i] = '0';
          neededS0--;
        }
      }
      steps++;
    } else {

    }
  }
  for(int i = 0; i < stringSize; i++) {
    if(S[i] != T[i]) {
      for(int j = i + 1; j < stringSize; j++) {
        if(S[j] != T[j]) {
          if(S[i] == T[j]) {
            aux = S[i];
            S[i] = S[j];
            S[j] = aux;
            steps++;
            break;
          }
        }
      }
    }
  }
  for(int i = 0; i < stringSize; i++) {
    if(S[i] != T[i]) {
      if(S[i] == '0') {
        S[i] = '1';
        steps++;
      } else {
        steps = -1;
        break;
      }
    }
  }
  return steps;
}

void readInput() {
  int n;
  scanf("%d", &n);
  char S[105], T[105];
  for(int i = 1; i <= n; i++) {
    scanf("%s%s", S, T);
    if(canConvert(S, T)) {
      printf("Case %d: %d\n", i, convertString(S, T));
    } else {
      printf("Case %d: -1\n", i);
    }
  }
}

int main() {
  readInput();
  return 0;
}
