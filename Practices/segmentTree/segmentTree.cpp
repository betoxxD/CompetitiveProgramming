#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

class SegmentTree {
	private:
		vector<int> st, A;
		int n;
		int left(int p) { return p << 1; } 
		int right(int p) { return (p << 1) + 1; }

		void printSt() {
			for(int i = 0; i < 10; i++) {
				printf("%d ", st[i]);
			}
			printf("\n");
		}

		void printA() {
			for(int i = 0; i < 10; i++) {
				printf("%d ", A[st[i]]);
			}
		}

		void build(int pos, int L, int R, int func) {
			if(L == R) {
				st[pos] = L;
			} else {
				build(left(pos), L, (L + R) / 2, 1);
				build(right(pos), ((L + R) / 2) + 1, R, 2);
				int pos1 = st[left(pos)]; int pos2 = st[right(pos)];
				st[pos] = (A[pos1] >= A[pos2]) ? pos1 : pos2;
			}

		}

		int rmq(int pos, int L, int R, int i, int j) {
			if( i > R || j < L ) return -1;
			if( L >= i && R <= j ) return st[pos];

			int pos1 = rmq(left(pos), L, (L + R) / 2, i, j);
			int pos2 = rmq(right(pos), ((L + R) / 2) + 1, R, i, j);
			if(pos1 == -1) return pos2;
			if(pos2 == -1) return pos1;
			return (A[pos1] <= A[pos2]) ? pos1 : pos2;
		}


	public:
		SegmentTree(const vector<int> &_A) {
			A = _A; n = (int) A.size();
			st.assign(4 * n, 0);
			build(1, 0, n - 1, 0);
		}

		int rmq(int i, int j) {return rmq(1, 0 , n - 1, i, j);}
};

int main() {
	vector<int> Arr = {-1, -1, 1, 1, 1, 1, 3, 10, 10, 10};
	SegmentTree st(Arr);
	int pos = st.rmq(1, 10);
	printf("st.rmq(1, 2) = A[%d]  = %d\n", pos, Arr[pos]);
	return 0;
}
