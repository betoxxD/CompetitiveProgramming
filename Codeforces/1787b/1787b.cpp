#include <bits/stdc++.h>
#include <bitset>
#include <cmath>
#include <vector>

using namespace std;

long long _sieve_size;
bitset<10000010> bs;
vector<long long> primes;

void sieve(long long upperbound) {
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (long long i = 2; i <= _sieve_size; i++) {
    if (bs[i]) {
      for (long long j = i * i; j <= _sieve_size; j += i) {
        bs[j] = 0;
      }
      primes.push_back(i);
    }
  }
}

void readInput() {
  int n;
  scanf("%d", &n);
  long long in;
  long long mult;
  long long truncDiv;
  double div;
  long long sum;
  long long last;
  while (n--) {
    sum = 0;
    last = 0;
    scanf("%lld", &in);
    for (int i = 0; i < primes.size(); i++) {
      if (primes[i] > in) {
        break;
      }
      if (primes[i] * primes[i + 1] > in) {
        break;
      }
      for (int j = i + 1; j < primes.size(); j++) {
        mult = primes[i] * primes[j];
        if(pow(mult, last + 1) > in){
          break;
        }
        if (mult > in) {
          break;
        }
        truncDiv = log(in) / log(mult);
        div = log(in) / log(mult);
        if(pow(mult, truncDiv) > in) {
          break;
        }
        if (truncDiv * 1.0 == div) {
          last = truncDiv;
          sum += mult * truncDiv;
        }
      }
    }
    printf("%lld\n", sum);
  }
}

int main() {
  sieve(10000010);
  readInput();
  return 0;
}
