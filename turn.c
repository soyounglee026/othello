#define N 6

extern int turn;
extern char gameboard[N][N];
extern int numofW, numofB;
void repeat();
int passW, passB; //���� 0�̸� ���� ���� ���ٴ� �� 

int turn_pass() { //���� �� ������ �� �н�
	int l, h, k; //for�� ����
	
	if(turn==0) { 
		passW=0;
		for(l=0;l<N;l++)
			for(h=0;h<N;h++) 
				if(gameboard[l][h]=='O') 
					for(k=1;k<N-1;k++) {
						if(l+k<N-1)
							if(gameboard[l+k][h]=='X'&&gameboard[l+k+1][h]==' '){ //8�� ���� Ȯ��
								passW++; //���� �� ������ pass�� ���� ������Ŵ
								continue;
							}
						if(l-k>0)
							if(gameboard[l-k][h]=='X'&&gameboard[l-k-1][h]==' '){
								passW++;
								continue;
							}
						if(h+k<N-1)
							if(gameboard[l][h+k]=='X'&&gameboard[l][h+k+1]==' '){
								passW++;
								continue;
							}
						if(h-k>0)
							if(gameboard[l][h-k]=='X'&&gameboard[l][h-k-1]==' '){
								passW++;
								continue;
							}
						if(l+k<N-1&&h+k<N-1)
							if(gameboard[l+k][h+k]=='X'&&gameboard[l+k+1][h+k+1]==' '){
								passW++;
								continue;
							}
						if(l-k>0&&h-k>0)
							if(gameboard[l-k][h-k]=='X'&&gameboard[l-k-1][h-k-1]==' '){
								passW++;
								continue;
							}
						if(l-k>0&&h+k<N-1)
							if(gameboard[l-k][h+k]=='X'&&gameboard[l-k-1][h+k+1]==' '){
								passW++;
								continue;
							}
						if(l+k<N-1&&h-k>0)
							if(gameboard[l+k][h-k]=='X'&&gameboard[l+k+1][h-k-1]==' '){
								passW++;
								continue;
							}
					}
	}
	
	else if(turn==1) { 
		passB=0;
		for(l=0;l<N;l++)
			for(h=0;h<N;h++) 
				if(gameboard[l][h]=='X')
					for(k=1;k<N-1;k++) {
						if(l+k<N-1) 
							if(gameboard[l+k][h]=='O'&&gameboard[l+k+1][h]==' '){
								passB++;
								continue;
							}
						if(l-k>0) 
							if(gameboard[l-k][h]=='O'&&gameboard[l-k-1][h]==' '){
								passB++;
								continue;
							}
						if(h+k<N-1) 
							if(gameboard[l][h+k]=='O'&&gameboard[l][h+k+1]==' '){
								passB++;
								continue;
							}
						if(h-k>0) 	
							if(gameboard[l][h-k]=='O'&&gameboard[l][h-k-1]==' '){
								passB++;
								continue;
							}
						if(l+k<N-1&&h+k<N-1) 	
							if(gameboard[l+k][h+k]=='O'&&gameboard[l+k+1][h+k+1]==' '){
								passB++;
								continue;
							}
						if(l-k>0&&h-k>0) 	
							if(gameboard[l-k][h-k]=='O'&&gameboard[l-k-1][h-k-1]==' '){
								passB++;
								continue;
							}
						if(l-k>0&&h+k<N-1) 	
							if(gameboard[l-k][h+k]=='O'&&gameboard[l-k-1][h+k+1]==' '){
								passB++;
								continue;
							}
						if(l+k<N-1&&h-k>0) 	
							if(gameboard[l+k][h-k]=='O'&&gameboard[l+k+1][h-k-1]==' '){
								passB++;
								continue;
							}
					}
								
	}
		
	return passW, passB;
}

int isGameEnd() {
	int result;
	othello_num();
	turn_pass();
	
	if(numofW==0||numofB==0) //��� �� ������ ������ ���� �Ǿ��� �� 
		result=numofW*numofB;
	else if(passW==0&&passB==0)
		result=passW+passB;
	else
		result=numofW+numofB-36; //�����θ� ���� �ڸ��� ���� �� 
	
		return result;
	
}
