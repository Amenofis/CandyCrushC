#include "board.h"

typedef struct {
	BoardPtr board;
	unsigned int score;
	unsigned short level;
	unsigned short turns;
	unsigned short turnsLeft;
} Game;


void saveBoard(BoardPtr board, int *id, CODE status) {
	printf("Guardar Board\n");


}