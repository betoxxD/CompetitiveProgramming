#include<bits/stdc++.h>

using namespace std;

int calculateScore(string result){
  int increment = 1;
  int sum = 0;
  for(int i = 0; i < result.size(); i++){
    if(result[i] == 'O') {
     sum+= increment;
     increment++;
    } else {
      increment = 1;
    }
  }
  return sum;
}

void readInput(){
  int t;
  char result[100];
  scanf("%d", &t);
  while(t--){
    scanf("%s", result);
    printf("%d\n", calculateScore(result));
  }
}

int main() {
  readInput();
  return 0;
}
