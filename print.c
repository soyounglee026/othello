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
	
	while(*ptr) { //������ �̿��ؼ� ������ ���� ���� 
		if (*ptr == 'O')
			numofW++;
		else if (*ptr == 'X')
			numofB++;
		ptr++;
	}
	
	if(numofW+numofB<N*N) //���� ���� ���� �� �� ��ġ ��Ȳ ��� 
		printf(" STATUS - WHITE : %d, BLACK : %d\n\n", numofW, numofB);
}

void flipped_othello() {
	printf("\n :: flip result ::\n");
	printf("  W:%d E:%d N:%d S:%d NW:%d NE:%d SW:%d SE:%d\n",
	fW, fE, fN, fS, fNW, fNE, fSW, fSE);
	
	if(fW+fE+fN+fS+fNW+fNE+fSW+fSE!=0) { //�� �������� ������ ���� ��� 
		if(turn==0) {
			printf("  White has flipped %d othello(s)!\n\n", fW+fE+fN+fS+fNW+fNE+fSW+fSE);
			turn+=1; //������ ������ �ٲ�  
		}
		else if(turn==1) {
			printf("  Black has flipped %d othello(s)!\n\n", fW+fE+fN+fS+fNW+fNE+fSW+fSE);
			turn+=-1; //��� ������ �ٲ�  
		}
	}
	else
		printf("invalid input! (no flip happens)\n\n"); //�߸��� ���� �ξ��� �� ���  
}

void check_result() {
	if(numofW+numofB==N*N) 
		printf("The number of white othellos is %d, The number of black othellos is %d\n", numofW, numofB);
	else if(numofW==0)
		printf("There is no white othello.\n");
	else if(numofB==0)
		printf("There is no black othello.\n");
	
	if(numofW>numofB) //��� �����ΰ� �� ���� ��  
		printf("The winner is WHITE!\n");
	else if(numofB>numofW) //������ �����ΰ� �� ���� ��  
		printf("The winner is BLACK!\n");
	else
		printf("It's a DRAW!\n");
}

