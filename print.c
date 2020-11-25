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
	
	while(*ptr) { //포인터 이용해서 오델로 개수 세기 
		if (*ptr == 'O')
			numofW++;
		else if (*ptr == 'X')
			numofB++;
		ptr++;
	}
	
	if(numofW+numofB<N*N) //게임 진행 중일 때 총 배치 상황 출력 
		printf(" STATUS - WHITE : %d, BLACK : %d\n\n", numofW, numofB);
}

void flipped_othello() {
	printf("\n :: flip result ::\n");
	printf("  W:%d E:%d N:%d S:%d NW:%d NE:%d SW:%d SE:%d\n",
	fW, fE, fN, fS, fNW, fNE, fSW, fSE);
	
	if(fW+fE+fN+fS+fNW+fNE+fSW+fSE!=0) { //총 뒤집어진 오델로 개수 출력 
		if(turn==0) {
			printf("  White has flipped %d othello(s)!\n\n", fW+fE+fN+fS+fNW+fNE+fSW+fSE);
			turn+=1; //검은색 턴으로 바꿈  
		}
		else if(turn==1) {
			printf("  Black has flipped %d othello(s)!\n\n", fW+fE+fN+fS+fNW+fNE+fSW+fSE);
			turn+=-1; //흰색 턴으로 바꿈  
		}
	}
	else
		printf("invalid input! (no flip happens)\n\n"); //잘못된 곳에 두었을 때 출력  
}

void check_result() {
	if(numofW+numofB==N*N) 
		printf("The number of white othellos is %d, The number of black othellos is %d\n", numofW, numofB);
	else if(numofW==0)
		printf("There is no white othello.\n");
	else if(numofB==0)
		printf("There is no black othello.\n");
	
	if(numofW>numofB) //흰색 오델로가 더 많을 때  
		printf("The winner is WHITE!\n");
	else if(numofB>numofW) //검은색 오델로가 더 많을 때  
		printf("The winner is BLACK!\n");
	else
		printf("It's a DRAW!\n");
}

