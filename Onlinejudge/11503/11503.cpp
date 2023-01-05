#include <bits/stdc++.h>
#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

class Network {
	private:
		unordered_map<string, int> rank, size;
		unordered_map<string, string> parent;
	public:
		string findParent(string i) {
			if(size[i] == 0) {
				size[i] = 1;
				parent[i] = i;
				rank[i] = 0;
			}
			return parent[i] == i ? i : parent[i] = findParent(parent[i]);
		}

		bool sameParent(string i, string j) {
			return findParent(i) == findParent(j);
		}

		int putPeople(string i, string j) {
			if(!sameParent(i, j)){
				string x = findParent(i); string y = findParent(j); 	
				if(rank[x] > rank[y]) {
					parent[y] = x;
					size[x] += size[y];
					return size[x];
				} else if(rank[y] > rank[x]) {
					parent[x] = y;
					size[y] += size[x];
					return size[y];
				} else {
					parent[y] = x;
					size[x] += size[y];
					rank[x]++;
					return size[x];
				}
			}
			string x = findParent(i);
			return size[x];
		}
};

void readInput() {
	int n; scanf("%d", &n);
	int m;
	char p1[100], p2[100];
	while (n--) {
		Network nt;
		scanf("%d", &m);
		while (m--) {
			scanf("%s%s",p1, p2);
			printf("%d\n", nt.putPeople(p1, p2));
		}
	}
}

int main() {
	readInput();
	return 0;
}
