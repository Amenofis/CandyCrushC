#include "constants.h"
#include "models.h"

#include "candy.h"

// Board's method declaration
#ifndef _BOARD_H_
#define _BOARD_H_

typedef struct Board* BoardPtr;

BoardPtr createBoard(int n, int m, Params params, code *status);

void initializeLevel(BoardPtr board, int level, code *status);

void displayBoard(BoardPtr b, code *status);

boolean checkInitializedCandies(BoardPtr board, CandyPtr candy, int x, int y);

void destroyBoard(BoardPtr *b);

#endif