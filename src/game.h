#include "board.h"

// Game's method declaration
#ifndef _GAME_H_
#define _GAME_H_

typedef struct Game* GamePtr;

void showMainMenu(code *status);

void startNewGame(code *status);

void saveBoard(BoardPtr board, int *id, code *status);

void printTitle();

#endif