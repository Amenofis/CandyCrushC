#include "candy.h"

#include <stdlib.h>
#include <stdio.h>

typedef enum {NORMAL=0, ROWS_EXPLODE=1, COLS_EXPLODE=2} CandyEffect;

struct Type {
	int multiplier;
	CandyEffect effect;
};

struct Candy {
	int value;
	char symbol;
	TypePtr type;
};

CandyPtr generateCandy() {
	CandyPtr mCandy = malloc(sizeof * mCandy);
	mCandy->symbol = (rand()%3) + 65;
	return mCandy;
}

CandyPtr createCandy(int s, TypePtr t, int v) {
	CandyPtr mCandy = malloc(sizeof * mCandy);
	mCandy->value = v;
	mCandy->symbol = s;
	mCandy->type = t;
	return mCandy;
}

TypePtr createType(int m, CandyEffect e) {
	TypePtr mType = malloc(sizeof * mType);
	mType->multiplier = m;
	mType->effect = e;
	return mType;
}

char getCandy(CandyPtr c) {
	return c->symbol;
}