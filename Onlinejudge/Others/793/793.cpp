#include <bits/stdc++.h>
#include <cstddef>
#include <cstdio>
#include <vector>

using namespace std;

class UnionFind{
	private:
		vector<int> parent, rank;

	public:
		UnionFind(int N) {
			N++;
			rank.assign(N, 0);
			parent.assign(N, 0);
			for(int i = 0; i < N; i++) {
				parent[i] = i;
			}
		}

		int findSet(int i) {
			return (parent[i] == i) ? i : parent[i] = findSet(parent[i]);
		}

		bool isSameSet(int i, int j) {
			return findSet(i) == findSet(j);
		}

		int childOf(int i) {
			return parent[i];
		}

		void joinSet(int i, int j) {
			if(!isSameSet(i, j)) {
				int x = findSet(i), y = findSet(j);
				if(rank[x] > rank[y]) {
					parent[y] = x;
				} else if(rank[x] < rank[y]) {
					parent[x] = y;
				} else {
					parent[y] = x;
					rank[x]++;
				}
			}
		}
};

int correct, incorrect;

void readInput() {
	int n; scanf("%d", &n);
	getchar();
	int nComputers;
	char input[1000];
	char action;
	int c1, c2;
	while (n--) {
		scanf("%d", &nComputers);
		UnionFind uf(nComputers);
		getchar();
		while (fgets(input, sizeof(input), stdin) != NULL) {
			if(input[0] == '\n') {
				break;
			}
			sscanf(input, " %c%d%d", &action, &c1, &c2);
			if(action == 'c') {
				uf.joinSet(c1, c2);
			} else {
				if(uf.isSameSet(c1, c2)){
					correct++;
				} else {
					incorrect++;
				}
			}
		}
		printf("%d,%d\n", correct, incorrect);
		if(n > 0) {
			printf("\n");
		}
		correct = 0;
		incorrect = 0;
	}
}

int main() {
	readInput();
	return 0;
}
