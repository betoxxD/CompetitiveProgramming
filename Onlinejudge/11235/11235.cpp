#include <bits/stdc++.h>
#include <bitset>
#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

class SegmentTree{
	private:
		int n;
		vector<int> A, st;

		int p1, p2;
		int left(int p) {return p << 1;}
		int right(int p) {return (p << 1) + 1;}

		void build(int p, int L, int R) {
			if(L == R) {
				st[p] = L;
			} else {
				build(left(p), L, (L + R) / 2);
				build(right(p), ((L + R) / 2) + 1, R);
				p1 = st[left(p)];
				p2 = st[right(p)];
				st[p] = (A[p1] >= A[p2]) ? p1 : p2;
			}
		}

		int RMQ(int p, int L, int R, int i, int j) {
			if(i > R || j < L) return -1;
			if(L>= i && R <= j) return st[p];
			p1 = RMQ(left(p), L, (L + R) / 2, i, j);
			p2 = RMQ(right(p), ((L + R) / 2) + 1, R, i, j);
			if(p1 == -1) return p2;
			if(p2 == -1) return p1;
			return A[p1] >= A[p2] ? p1 : p2;
		}

	public:
		int RMQ(int i, int j) {return RMQ(1, 0, n - 1, i, j);}

		void assignValues( vector<int> &_A ) {
			A = _A; n = (int) A.size();
			st.assign(4*n, 0);
			build(1, 0, n - 1);
		}
};

vector<int> positions;
vector<int> cantNumber;

int main() {
	int n, m, in, a, b, posA, posB, ca, cb, index, last = -100005, posicionAparicion = 0;

	SegmentTree sg;
	while (scanf("%d", &n) != EOF && n != 0) {
		if(n == 0) {
			break;
		}
		scanf("%d", &m);
		while (n--) {
			scanf("%d", &in);
			if(in != last) {
				last = in;
				positions.push_back(posicionAparicion);
			}
			posicionAparicion++;
		}
		while (m--) {
			scanf("%d%d", &a, &b);
			posA = 0;
			posB = 0;
			cantNumber.clear();
			ca = 0;
			cb = 0;
			a--;
			b--;
			if(a == b) {
				printf("1\n");
				continue;
			}
			while (a > positions[posA]) {
				posA++;
			}
			while (b < positions[posB]) {
				posB++;
			}
			posB--;
			posA--;
			cantNumber.push_back(positions[posA] - a); 
			for(int i = posA; i < posB; i++ ) {
				cantNumber.push_back(positions[posB] - positions[posA]);
			}
			cantNumber.push_back(b - positions[posB]);
			for(int pos : cantNumber) {
				printf("%d ", pos);
			}
			printf("\n");
			getchar();
			sg.assignValues(cantNumber);
			index = sg.RMQ(0, cantNumber.size());
			printf("%d\n", cantNumber[index]);
		}
	}
	return 0;
}
