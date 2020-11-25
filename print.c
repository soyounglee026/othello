#include <stdio.h>
#include <stdlib.h>
#define N 6

extern char gameboard[N][N];
extern int numofW, numofB;
extern int ROWS, COLS;
extern int turn;
extern int fW, fE, fN, fS, fNW, fNE, fSW, fSE;

void init_othello() {
	
	printf("  0 1 2 3 4 5\n");
	
	for(ROWS=0;ROWS<N;ROWS++) {
		printf(" -------------\n");
		printf("%d|", ROWS);
		
		for(COLS=0;COLS<N;COLS++)
			printf("%c|", gameboard[ROWS][COLS]);
		printf("\n");
	}
	printf(" -------------\n\n");
	
}

void print_othello() {
	char *ptr;
	ptr = *gameboard;
	
	numofW=0;
	numofB=0;
	
	while(*ptr) {
		if (*ptr == 'O')
			numofW++;
		else if (*ptr == 'X')
			numofB++;
		ptr++;
	}
	
	if(numofW+numofB<N*N)
		printf(" STATUS - WHITE : %d, BLACK : %d\n\n", numofW, numofB);
}

