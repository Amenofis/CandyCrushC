#include "constants.h"

#ifndef _CANDY_H_
#define _CANDY_H_

typedef struct Candy* CandyPtr;

typedef struct Type* TypePtr;

CandyPtr createCandy(); 

char getCandy(CandyPtr c);

#endif