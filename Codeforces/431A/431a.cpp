#include <stdio.h>
#include <string.h>

// Variables
int values['9'];
char apparitions[100005];

void readValues() {
	scanf("%d%d%d%d",&values['1'],&values['2'],&values['3'],&values['4']);
	scanf("%s",apparitions);
}

int countCalories() {
	int size = strlen(apparitions);
	int calories = 0;
	for (int i = 0; i < size; i++) {
		calories+= values[apparitions[i]];
	}
	return calories;
}

int main() {
	readValues();
	printf("%d\n", countCalories());
	return 0;
}
