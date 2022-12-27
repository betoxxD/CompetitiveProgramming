#include <bits/stdc++.h>

using namespace std;

string tree;
map<string, double> trees;
int cont;

void clearData() {
	tree = "";
	trees.clear();
	cont = 0;
}

void printResult() {
	for(pair<string, double> treeName: trees) {
		printf("%s %0.4lf\n", treeName.first.c_str(), (treeName.second * 100) / cont);
	}
}

void readInput() {
	int n; scanf("%d",&n);
	getchar();
	getchar();
	char in[50] = "";
	while (n--) {
		in[0] = 0;
		while(fgets(in, sizeof(in), stdin) != NULL) {
			if(in[0] == '\n') {
				break;
			}
			in[strlen(in) - 1] = 0;
			tree = in;
			trees[tree]++;
			cont++;
		}
		printResult();
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
