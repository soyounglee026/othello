#define N 6

extern int turn;
extern char gameboard[N][N];
extern int numofW, numofB;

int turn_pass() { //놓을 곳 없으면 턴 패스
	int l, h, k; //for문 변수
	int pass; //값이 0이면 놓을 곳이 없다는 뜻 
	
	if(turn==0) { 
	pass=0;
		for(l=0;l<N;l++)
			for(h=0;h<N;h++) {
				if(gameboard[l][h]=='O')
					for(k=1;k<5;k++){
						if(l-k>=0&&l+k<=5&&h-k>=0&&h+k<=5) {
						if(gameboard[l+k][h]=='X'&&gameboard[l+k+1][h]==' ') //8개 방향 확인 
							pass++; //놓을 곳 있으면 pass의 수를 증가시킴 
						if(gameboard[l-k][h]=='X'&&gameboard[l-k-1][h]==' ')
							pass++;
						if(gameboard[l][h+k]=='X'&&gameboard[l][h+k+1]==' ')
							pass++;
						if(gameboard[l][h-k]=='X'&&gameboard[l][h-k-1]==' ')
							pass++;
						if(gameboard[l+k][h+k]=='X'&&gameboard[l+k+1][h+k+1]==' ')
							pass++;
						if(gameboard[l-k][h-k]=='X'&&gameboard[l-k-1][h-k-1]==' ')
							pass++;
						if(gameboard[l-k][h+k]=='X'&&gameboard[l-k-1][h+k+1]==' ')
							pass++;
						if(gameboard[l+k][h-k]=='X'&&gameboard[l+k-1][h+k-1]==' ')
							pass++;
						}
				}
			}
	}
	
	else if(turn==1) { 
	pass=0;
		for(l=0;l<N;l++)
			for(h=0;h<N;h++) {
				if(gameboard[l][h]=='X')
					for(k=1;k<5;k++){
						if(l-k>=0&&l+k<=5&&h-k>=0&&h+k<=5) {
						if(gameboard[l+k][h]=='O'&&gameboard[l+k+1][h]==' ')
							pass++;
						if(gameboard[l-k][h]=='O'&&gameboard[l-k-1][h]==' ')
							pass++;
						if(gameboard[l][h+k]=='O'&&gameboard[l][h+k+1]==' ')
							pass++;
						if(gameboard[l][h-k]=='O'&&gameboard[l][h-k-1]==' ')
							pass++;
						if(gameboard[l+k][h+k]=='O'&&gameboard[l+k+1][h+k+1]==' ')
							pass++;
						if(gameboard[l-k][h-k]=='O'&&gameboard[l-k-1][h-k-1]==' ')
							pass++;
						if(gameboard[l-k][h+k]=='O'&&gameboard[l-k-1][h+k+1]==' ')
							pass++;
						if(gameboard[l+k][h-k]=='O'&&gameboard[l+k-1][h+k-1]==' ')
							pass++;
						}
				}
			}
	}
		
	return pass;
}

int isGameEnd() {
	int result;
	print_othello();
	
	if(numofW==0||numofB==0) //어느 한 오델로 색으로 통일 되었을 때 
		result=numofW*numofB;
	else
		result=numofW+numofB-36; //오델로를 놓을 자리가 없을 때 
	
		return result;
	
}
