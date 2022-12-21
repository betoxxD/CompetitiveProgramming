#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

int main() {
	// a = 5(00000101), b = 9(00001001)
	unsigned char a = 5, b = 9;

	// And
	// 00000101
	// 00001001
	// ------------
	// 00000001
	// El resultado es 00000001
	printf("a = %d, b = %d\n", a, b);
	printf("a&b = %d\n", a & b);

	// Or
	// 00000101
	// 00001001
	// ------------
	// 00001101
	// El resultado es 00001101
	printf("a|b = %d\n", a|b);

	// Xor
	// 00000101
	// 00001001
	// ------------
	// 00001100
	// El resultado es 00001100
	printf("a^b = %d\n", a^b);

	// Not
	// 00000101
	// ------------
	// 11111010
	// El resultado es 11111010
	printf("~a = %d\n",a = ~a);

	// Los siguientes comandos no deben ser utilizados para números negativos:

	// Left shift
	// 00001001
	// 00000001
	// ------------
	// 00010010
	// El resultado es 00010010
	printf("b<<1 = %d\n",b<<1);

	// Right shift
	// 00001001
	// 00000001
	// ------------
	// 00000100
	// El resultado es 00000100
	printf("b>>1 = %d\n",b>>1);

	return 0;
}
