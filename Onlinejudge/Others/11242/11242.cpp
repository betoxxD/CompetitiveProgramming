#include <bits/stdc++.h>

using namespace std;

vector<int> front;
vector<int> rear;
priority_queue<double> dRatio;

void readInput() {
	int f,r;
	int in;
	double d1,d2;
	double maxi;
	while (scanf("%d", &f) != EOF && f != 0) {
		maxi = 0;
		scanf("%d", &r);
		for(int i = 0; i < f; i++) {
			scanf("%d", &in);
			front.push_back(in);
		}
		for(int i = 0; i < r; i++) {
			scanf("%d", &in);
			rear.push_back(in);
		}
		for(int i = 0; i < f; i++) {
			for(int j = 0; j < r; j++) {
				dRatio.push(rear[j] * 1.0 / front[i] * 1.0);
			}
		}
		d2 = dRatio.top();
		dRatio.pop();
		while (!dRatio.empty()) {
			d1 = dRatio.top();
			dRatio.pop();
			maxi = max(maxi, d2 / d1);
			d2 = d1;
		}
		printf("%0.2lf\n", maxi);
		front.clear();
		rear.clear();
	}

}

int main() {
	readInput();
	return 0;
}
