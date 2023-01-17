#include <bits/stdc++.h>

using namespace std;

class Provider{
  private:
    string name;
    int lower;
    int upper;
  
  public:
    Provider(string name, int lower, int upper){
      this->name = name;
      this->lower = lower;
      this->upper = upper;
    }

    string getName() {
      return this->name;
    }

    int getLower() {
      return this->lower;
    }

    int getUpper() {
      return this->upper;
    }
};

vector<Provider> database;
string prov;

void clearData() {
  prov = "";
  database.clear();
}

int checkMakers(int query) {
  int makers = 0;
  for(Provider pv : database) {
    if(query >= pv.getLower() && query <= pv.getUpper()) {
      prov = pv.getName();
      makers++;
    }
  }
  return makers;
}

void readInput() {
  int n; scanf("%d", &n);
  int m;
  char name[100];
  int lower, upper;
  int query;
  while (n--)
  {
    scanf("%d", &m);
    while (m--)
    {
      scanf("%s%d%d",name, &lower, &upper);
      Provider pv(name, lower, upper);
      database.push_back(pv);
    }
    scanf("%d", &m);
    while (m--)
    {
      scanf("%d", &query);
      if(checkMakers(query) == 1) {
        printf("%s\n", prov.c_str());
      } else {
        printf("UNDETERMINED\n");
      }
    }
    if(n >= 1) {
      printf("\n");
    }
    clearData();
  }
}

int main() {
  readInput();
  return 0;
}
