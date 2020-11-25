#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 6 //ũ�� 6 

char gameboard[N][N];
int ROWS, COLS;
int numofW, numofB; //����� ������ ������ ���� ��Ÿ���� ���� 
extern void init_othello(); //������ �� ��� 
extern void print_othello(); //��ġ ��Ȳ ���
extern void flipped_othello(); //������ �������� ���� �� ���� �� ��� 
extern void flip_condition(); //������ ���� �� 
extern int turn_pass(); //�� �н� ����Ȯ�� 
extern int isGameEnd(); //������ ������ ���� 
extern void check_result(); //��� ���
 
int turn=0; //0�� ��� ��, 1�� ������ ��  
int fW, fE, fN, fS, fNW, fNE, fSW, fSE; //�� �������� ������ ���� ��Ÿ���� ���� 

int main(int argc, char *argv[]) {
	
	for(ROWS=0;ROWS<N;ROWS++)
		for(COLS=0;COLS<N;COLS++)
			gameboard[ROWS][COLS]=' '; //�����ΰ� ���� �� ���� 
		
	gameboard[2][2]='O';
	gameboard[3][3]='O';
	gameboard[2][3]='X';
	gameboard[3][2]='X'; //ó�� ������ ��ġ 

	do {
		fW=0, fE=0, fN=0, fS=0, fNW=0, fNE=0, fSW=0, fSE=0; //���� �ʱ�ȭ 
		
		do {
			init_othello();
			print_othello();

			if(turn==0&&turn_pass()==0) { //�� ���ϱ�
				turn+=1;
				printf("put a new black othello : ");
			}
			else if(turn==0&&turn_pass()!=0)
				printf("put a new white othello : ");
				
			if(turn==1&&turn_pass()==0) {
				turn+=-1;
				printf("put a new white othello : ");
			}
			else if(turn==1&&turn_pass()!=0)
				printf("put a new black othello : ");
			
			scanf("%d %d", &ROWS, &COLS); //������ ���� �� �Է¹ޱ� 
			printf("\n");
		
			if(gameboard[ROWS][COLS]!=' ') //�̹� �ִ� ���� �� �� ���� 
				flipped_othello();
		} while(gameboard[ROWS][COLS]!=' ');
		flip_condition(); //������ ����Ȯ�� �� ������ 
		flipped_othello();
	
	} while(isGameEnd()!=0); //���� ���� Ȯ�� 
	
	init_othello(); //������ �� ���� ��� 
	
	check_result();
	
	return 0;
}
