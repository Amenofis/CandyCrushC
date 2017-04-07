#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <stdio.h>

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))

typedef enum {FALSE, TRUE} BOOL;
typedef enum {OK, ERR_FILE_NOT_FOUND, ERR_FILE_NOT_PERM, IMPOSSIBLE_VALID_BOARD, NOT_ENOUGH_MEMORY} CODE;

enum {EASY=1, MEDIUM=3, HARD=5} DIFFICULTY;

#endif