#include <stdio.h>

int xPos, yPos;

void getValues(){
	int number;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			scanf("%d", &number); 
			if(number == 1){
				xPos = i + 1;
				yPos = j + 1;
			}
		}
	}
}

int getMovements(){
	int movements = 0;
	if(xPos < 3){
		movements+=3-xPos;
	} else {
		movements+=xPos-3;
	}
	if(yPos < 3){
		movements+=3-yPos;
	} else {
		movements+=yPos-3;
	}
	return movements;
}

int main() {
	getValues();
	printf("%d\n",getMovements());
	return 0;
}
