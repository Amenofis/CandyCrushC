#include "game.h"
#include <stdio.h>
#include <stdlib.h>

struct {
	BoardPtr board;
	unsigned int score;
	unsigned short level;
} Game;

void showMainMenu(code *status) {

	int opt;
	do {
		clear();
		printTitle();
		gotoxy(10,24);
		printf("1. Continuar\n");
		gotoxy(11,24);
		printf("2. Nuevo Juego\n");
		gotoxy(12,24);
		printf("3. Cargar Partida\n");
		gotoxy(13,24);
		printf("4. Salir\n");
		gotoxy(14,24);
		printf("Ingrese una opción: ");
		scanf("%d", &opt);
		getchar();
		switch(opt) {
			case 1:
				// TODO
			break;
			case 2:
				startNewGame(status);
			break;
			case 3:
				
			break;
			case 4:
				printf("Adiós\n");
			break;
			default: 
			break;
		}


	} while(opt != 4);

}

void startNewGame(code *status){
	GamePtr newGame = malloc(sizeof * newGame);
	if (newGame) {
		newGame->score = 0;
		newGame->level = 1;

		Params p;
		p.foo = 1;
		p.bar = 2;
		BoardPtr board = createBoard(6, 6, p, status);
		board->turns = 10;
		board->turnsLeft = 10;

		if (board) {
			initializeLevel(board, 1, status);
			displayBoard(board, status);
		}
	}

	
	
	printf("Press Any Key to Continue");
	getchar();
}

void saveBoard(BoardPtr board, int *id, code *status) {
	printf("Guardar Board\n");


}



void printTitle(){
		printf(" _____                 _         _____                _     \n");
		printf("/  __ \\               | |       /  __ \\              | |    \n");
		printf("| /  \\/ __ _ _ __   __| |_   _  | /  \\/_ __ _   _ ___| |__  \n");
		printf("| |    / _` | '_ \\ / _` | | | | | |   | '__| | | / __| '_ \\ \n");
		printf("| \\__/\\ (_| | | | | (_| | |_| | | \\__/\\ |  | |_| \\__ \\ | | |\n");
		printf("\\____/\\__,_|_| |_|\\__,_|\\__,  |  \\____/_|   \\__,_|___/_| |_|\n");
		printf("                          __/ |                             \n");
		printf("                         |___/                              \n");
}