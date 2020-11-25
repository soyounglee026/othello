#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define N 6 //크기 6 

char gameboard[N][N];
int ROWS, COLS;
int numofW, numofB; //흰색과 검은색 오델로 개수 나타내는 변수 
extern void init_othello(); //오델로 판 출력 
extern void print_othello(); //배치 상황 출력
extern void flipped_othello(); //뒤집힌 오델로의 방향 및 개수 등 출력 
extern void flip_condition(); //뒤집는 조건 등 
extern int turn_pass(); //턴 패스 여부확인 
extern int isGameEnd(); //게임이 끝나는 조건 
extern void check_result(); //결과 출력
 
int turn=0; //0은 흰색 턴, 1은 검은색 턴  
int fW, fE, fN, fS, fNW, fNE, fSW, fSE; //각 방향으로 뒤집힌 개수 나타내는 변수 

int main(int argc, char *argv[]) {
	
	for(ROWS=0;ROWS<N;ROWS++)
		for(COLS=0;COLS<N;COLS++)
			gameboard[ROWS][COLS]=' '; //오델로가 없는 빈 공간 
		
	gameboard[2][2]='O';
	gameboard[3][3]='O';
	gameboard[2][3]='X';
	gameboard[3][2]='X'; //처음 오델로 배치 

	do {
		fW=0, fE=0, fN=0, fS=0, fNW=0, fNE=0, fSW=0, fSE=0; //개수 초기화 
		
		do {
			init_othello();
			print_othello();

			if(turn==0&&turn_pass()==0) { //턴 정하기
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
			
			scanf("%d %d", &ROWS, &COLS); //오델로 놓을 곳 입력받기 
			printf("\n");
		
			if(gameboard[ROWS][COLS]!=' ') //이미 있는 곳에 둘 수 없음 
				flipped_othello();
		} while(gameboard[ROWS][COLS]!=' ');
		flip_condition(); //뒤집을 조건확인 후 뒤집기 
		flipped_othello();
	
	} while(isGameEnd()!=0); //종료 조건 확인 
	
	init_othello(); //마지막 판 상태 출력 
	
	check_result();
	
	return 0;
}
