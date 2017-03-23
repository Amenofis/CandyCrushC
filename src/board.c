#include "board.h"
#include "Candy.h"

#include <stdlib.h>
#include <stdio.h>

struct Board {
	CandyPtr **m;
	int r, c;
	BOOL rdy;
};

BoardPtr createBoard(int n, int m, Params params, CODE *status) {
	system("clear");
	if (n>0 && m>0) {
		BoardPtr mBoard = malloc(sizeof * mBoard);
		if (mBoard) { // Succesfully initialized BoardPtr
			mBoard->r = n;
			mBoard->c = m;
			mBoard->m = (CandyPtr**)malloc(sizeof(CandyPtr)*n);
			mBoard->rdy = FALSE;
			if (mBoard->m) {
				int i;
				printf("Creating Board...\n");
				for (i = 0; i < n; i++) {
					mBoard->m[i] = (CandyPtr*)calloc(m, sizeof(CandyPtr));
					if (!mBoard->m[i]) {
						printf("Returning null...\n");
						*status = NOT_ENOUGH_MINERALS;
						return NULL;
					}
				}
				printf("Board OK...\n");
				*status = OK;
				return mBoard;
			} else {
				*status = IMPOSSIBLE_VALID_BOARD;
			}
		} else {
			*status = IMPOSSIBLE_VALID_BOARD;
		}
	} else {
		*status = IMPOSSIBLE_VALID_BOARD;
	}
	return NULL;
}

void initializeLevel(BoardPtr board, int level, CODE *status) {
	printf("Preparing Board... ");
	int x, y;
	for (x = 0; x < board->r; x++) {
		for (y = 0; y < board->c ; y++) {
			board->m[x][y] = createCandy();
		}
	}
	board->rdy = TRUE;
}

void displayBoard(BoardPtr board, CODE *status) {
	printf("All ready, level start... \n\n");
	if (board) {
		int x,y;

		// ┌─────────┐ //
		printf("┌");
		for (x = 0; x < board->r; x++)
			printf("────");
		printf("┐\n");


		for (x = 0; x < board->r; x++) {
			for (y = 0; y < board->c; y++) {
				printf("│ %c ", getCandy(board->m[x][y]));
			}
			printf(" │\n");
			if ( (x+1) < board->r ) {
				printf("├");
				for (y = 0; y < board->c; y++) {
					printf("────");
				}
				printf("┤\n");
			}
		}
		
		printf("└");
		for (x = 0; x < board->r; x++)
			printf("────");
		printf("┘\n");
		// └─────────┘ //

		*status = OK;
	}
	*status = IMPOSSIBLE_VALID_BOARD;
}



/*
void destroyBoard(BoardPtr *board) {
	BoardPtr *temp;
	temp = *board;
	int i;
	for (i = 0; i < temp->r; i++)
		free(temp->m[i]);
	free(temp->m);
	free(temp);

	*board = NULL;
}
*/