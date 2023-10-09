#include <bits/stdc++.h>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Phrase {
	string content;
	struct Phrase *next;
};

struct Phrase *head;
string input;

void clearData() {
}

void printResult() {
	struct Phrase *aux = head;
	while(aux != NULL) {
		printf("%s",aux->content.c_str());
		getchar();
		aux = aux->next;
	}
	printf("\n");
}

void makePhrase() {
	struct Phrase *initHead = NULL; 
	struct Phrase *p = NULL; 
	initHead->content = "";
	initHead->next = NULL;
	head = initHead;
	string nextWord = "";
	for(int i = 0; i < input.size(); i++) {
		p = new Phrase;
		if(input[i] == '[') {
			p->content = nextWord;
			p->next = head;
			head = p;
			nextWord = "";
		}else if(input[i] == ']') {

		} else {
			nextWord+=input[i];
		}
	}
}

void readInput() {
	char in[100000];
	while(scanf("%s", in) != EOF) {
		input = in;
		makePhrase();
		printResult();
	}
}

int main() {
	readInput();
	return 0;
}
