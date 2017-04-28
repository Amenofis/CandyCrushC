#include "board.h"
#include "candy.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Board {
	int id, r, c;
	unsigned short turns, turnsLeft;
	boolean rdy;
	CandyPtr **m;
};

struct Position {
	int x, y;
}


BoardPtr createBoard(int n, int m, Params params, code *status) {
	clear();
	if (n>0 && m>0) {
		BoardPtr mBoard = malloc(sizeof * mBoard);
		if (mBoard) {
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
						*status = NOT_ENOUGH_MEMORY;
						return NULL;
					}
				}
				printf("Board OK!\n");
				*status = OK;
				return mBoard;
			} else {
				*status = NOT_ENOUGH_MEMORY;
			}
		} else {
			*status = NOT_ENOUGH_MEMORY;
		}
	} else {
		*status = IMPOSSIBLE_VALID_BOARD;
	}
	return NULL;
}

void initializeLevel(BoardPtr board, int level, code *status) {
	printf("Preparing Board... ");
	srand(time(NULL));
	int x, y;
	for (x = 0; x < board->r; x++) {
		for (y = 0; y < board->c ; y++) {
			CandyPtr c;
			do {
				c = createCandy();
			} while(checkInitializedCandies(board, c, x, y) == FALSE);
			board->m[x][y] = c;
		}
	}
	board->rdy = TRUE;
}

void displayBoard(BoardPtr board, code *status) {
	if (board) {
		printf("All ready, level start... \n\n");
		int x,y;

		// ┌───┬───┬───┐
		// │ C │ C │ C │
		// ├───┼───┼───┤
		// │ C │ C │ C │
		// ├───┼───┼───┤
		// │ C │ C │ C │ 
		// └───┴───┴───┘ 

		// ┌─────────┐
		printf("┌");
		for (x = 0; x < board->r; x++)
			printf("────");
		printf("┐\n");

		for (x = 0; x < board->r; x++) {
			for (y = 0; y < board->c; y++) {
				printf("│ %c ", getCandy(board->m[x][y]));
			}
			// │ C │ C │ C │

			printf(" │\n");
			if ( (x+1) < board->r ) {

				printf("├");
				for (y = 0; y < board->c; y++) {
					printf("────");
				}
				printf("┤\n");
				// ├────────────┤
			}
		}
		
		printf("└");
		for (x = 0; x < board->r; x++)
			printf("────");
		printf("┘\n");
		// └─────────┘ 

		*status = OK;
	}
	*status = IMPOSSIBLE_VALID_BOARD;
}

boolean checkInitializedCandies(BoardPtr board, CandyPtr candy, int x, int y) {
	if (x < 2 && y < 2) {
		return TRUE;
	} else {
		int i, COL, ROW, hCheck, rCheck;
		COL = y >= 2 ? y - 2 : y; // COLS TO CHECK
		ROW = x >= 2 ? x - 2 : x; // ROWS TO CHECK

		if (y >= 2 ) { // HORIZONTAL CHECK
			hCheck = 0;
			for (i = y-1; i >= COL; i--) {
				if (getCandy(candy) == getCandy(board->m[x][i])) hCheck++;
			}
			if (hCheck == 2) return FALSE;
		}
		if (x >= 2) { // VERTICAL CHECK
			rCheck = 0;
			for (i = x-1; i >= ROW; i--) {
				if (getCandy(candy) == getCandy(board->m[i][y])) rCheck++;
			}
			if (rCheck == 2) return FALSE;
		}
		return TRUE;
	}
}


void destroyBoard(BoardPtr *board) {
	BoardPtr temp;
	temp = *board;
	int i;
	for (i = 0; i < temp->r; i++)
		free(temp->m[i]);
	free(temp->m);
	free(temp);

	*board = NULL;
}