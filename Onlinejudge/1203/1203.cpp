#include <bits/stdc++.h>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class data{
	private:
		int id;
		int value;
		int apparition;

	public:
		data(int id, int value, int apparition){
			this->id = id;
			this->value = value;
			this-> apparition = apparition;
		}

		int getId() {
			return this->id;
		}

		int getValue() {
			return this-> value;
		}

		int getApparition() {
			return this->apparition;
		}

		void setValue(int value) {
			this->value = value;
		}
};

class Compare {

	public:
		bool operator() (data &a, data &b) {
			if(a.getValue() > b.getValue()) {
				return  true;
			} else if(a.getValue() < b.getValue()) {
				return false;
			} else {
				return a.getId() > b.getId();
			}
		}
};

vector<data> ids;
priority_queue<data, vector<data>, Compare> queuedData;

void readInput() {
	char in[100000], secondIn[100000];
	int id, period, quantity;
	int firstValue, secondValue;
	int cont = 0;
	while(fgets(in, sizeof(in), stdin) != NULL) {
		if(in[0] == '#') {
			break;
		}
		sscanf(in, "%s%d%d", secondIn, &id, &period);
		ids.push_back(data(id, period, cont++));
	}
	scanf("%d", &quantity);
	int periodAux;
	for(data id : ids) {
		periodAux = id.getValue();
		for(int i = 1; i <= quantity; i++) {
			id.setValue(i * periodAux);
			queuedData.push(id);
		}
	}
	data star(0, 0, 0);
	for(int i = 0; i < quantity; i++) {
		star = queuedData.top();
		printf("%d\n", star.getId());
		queuedData.pop();
	}
}

int main() {
	readInput();
	return 0;
}
