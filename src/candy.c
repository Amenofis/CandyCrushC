#include "candy.h"

#include <stdlib.h>
#include <stdio.h>


struct Candy {
	int symbol;
	char value;
};

CandyPtr createCandy() {
	CandyPtr mCandy = malloc(sizeof * mCandy);
	mCandy->symbol = (rand()%3) + 65;
	mCandy->value = mCandy->symbol;
	return mCandy;
}

char getCandy(CandyPtr c) {
	return c->value;
}