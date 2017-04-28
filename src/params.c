
#include "params.h"
#include "candy.h"

#include <stdlib.h>

struct CandyType {
	int amount;
	TypePtr type;
}

struct Params {
	Difficulty difficulty;
	struct CandyType *candiesTypes;
}

