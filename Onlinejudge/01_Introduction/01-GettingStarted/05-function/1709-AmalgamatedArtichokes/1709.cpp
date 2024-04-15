#include <bits/stdc++.h>

using namespace std;

double p, a, b, c, d;
int n;

double price(int k) {
  return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

void readInput() {
  double maxi;
  double biggest;
  double current;
  double difference;
  while (scanf("%lf", &p) != EOF) {
    maxi = 0;
    biggest = 0;
    current = 0;
    difference = 0;
    scanf("%lf%lf%lf%lf%d", &a, &b, &c, &d, &n);
    for(int i = 1; i <= n; i++) {
      current = price(i);
      if(current > biggest) biggest = current;
      else{
        difference = biggest - current;
        if(difference > maxi) maxi = difference;
      }
    }
    printf("%lf\n", maxi);
  }
}

int main() {
  readInput();
  return 0;
}
