#include <bits/stdc++.h>

using namespace std;

int priceMile(int time) {
  int price;
  price = (time / 30) + 1;
  return price * 10;
}

int priceJuice(int time) {
  int price;
  price = (time / 60) + 1;
  return price * 15;
}

void readInput() {
  int n;
  int calls, call;
  int totalPriceMile;
  int totalPriceJuice;
  int cont;
  scanf("%d", &n);

  cont = 1;
  while (n--) {
    totalPriceMile = 0;
    totalPriceJuice = 0;
    scanf("%d", &calls);
    while (calls--) {
      scanf("%d", &call);
      totalPriceMile += priceMile(call);
      totalPriceJuice += priceJuice(call);
    }
    if(totalPriceMile < totalPriceJuice) {
      printf("Case %d: Mile %d\n", cont, totalPriceMile);
    } else if(totalPriceMile > totalPriceJuice) {
      printf("Case %d: Juice %d\n", cont, totalPriceJuice);
    } else {
      printf("Case %d: Mile Juice %d\n", cont, totalPriceJuice);
    }
    cont++;
  }
}

int main() {
  readInput();
  return 0;
}
