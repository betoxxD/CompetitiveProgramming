#include<bits/stdc++.h>

using namespace std;

vector<string> urls;
vector<int> relevances;
int greatest;

void clearData() {
  urls.clear();
  relevances.clear();
  greatest = 0;
}

void getPopular(){
  for(int i = 0; i < 10; i++){
    if(relevances[i] == greatest) printf("%s\n", urls[i].c_str());
  }
}

void readInput(){
  int n;
  char url[200];
  int relevance;
  scanf("%d", &n);
  int caseN = 1;
  while(n--) {
    greatest = 0;
    for(int i = 0; i < 10; i++){
      scanf("%s", url);
      scanf("%d", &relevance);
      urls.push_back(url);
      relevances.push_back(relevance);
      if(relevance > greatest) greatest = relevance;
    }
    printf("Case #%d:\n", caseN++);
    getPopular();
    clearData();
  }
}

int main() {
  readInput();
  return 0;
}
