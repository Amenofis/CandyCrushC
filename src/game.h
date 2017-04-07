#include "constants.h"

// Game's method declaration
#ifndef _GAME_H_
#define _GAME_H_

typedef struct *Game GamePtr;

void saveBoard(BoardPtr board, int *id, CODE status);

#endif