#include "candy.h"

#include <stdlib.h>

struct Candy {
	int symbol;
	char value;
};

CandyPtr createCandy() {
	CandyPtr mCandy = malloc(sizeof * mCandy);
	mCandy->symbol = (rand() % (68 + 1 - 65)) + 65;
	mCandy->value = mCandy->symbol;
	return mCandy;
}

char getCandy(CandyPtr c) {
	return c->value;
}