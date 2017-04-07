#include "board.h"

#include <stdio.h>

int main(int argc, char* argv[]) {

	CODE status;
	Params p;
	p.foo = 1;
	p.bar = 2;
	BoardPtr board = createBoard(6, 6, p, &status);
	if (board) {
		initializeLevel(board, 1, &status);
		displayBoard(board, &status);
	}
	
	/*
	printf ("\033[K");//erase to end of line
	int iX = 6;
	int iY = 3;

	gotoxy(iX,iY);
	while(1) {
		char ch = getchar();
		if (ch == 'd') {
			iY+=4;
		} else if (ch == 'a') {
			iY-=4;
		}
		gotoxy(iX,iY);
	}
	*/
	
	getchar();
	destroyBoard(&board);
	if (board == NULL)
		printf("Board Destroyed\n");

	return 0;
}