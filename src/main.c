#include "board.h"

#include <stdio.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

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
	//destroyBoard(&board);

	return 0;
}