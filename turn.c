#define N 6

extern int turn;
extern char gameboard[N][N];
extern int numofW, numofB;
void repeat();

int turn_pass() { //���� �� ������ �� �н�
	int pass; //���� 0�̸� ���� ���� ���ٴ� �� 
	int l, h, k; //for�� ����
	
	if(turn==0) { 
		pass=0;
		for(l=0;l<N;l++)
			for(h=0;h<N;h++) 
				if(gameboard[l][h]=='O') 
					for(k=1;k<5;k++) {
						if(l+k<5)
							if(gameboard[l+k][h]=='X'&&gameboard[l+k+1][h]==' '){ //8�� ���� Ȯ��
								pass++; //���� �� ������ pass�� ���� ������Ŵ
								continue;
							}
						if(l-k>0)
							if(gameboard[l-k][h]=='X'&&gameboard[l-k-1][h]==' '){
								pass++;
								continue;
							}
						if(h+k<5)
							if(gameboard[l][h+k]=='X'&&gameboard[l][h+k+1]==' '){
								pass++;
								continue;
							}
						if(h-k>0)
							if(gameboard[l][h-k]=='X'&&gameboard[l][h-k-1]==' '){
								pass++;
								continue;
							}
						if(l+k<5&&h+k<5)
							if(gameboard[l+k][h+k]=='X'&&gameboard[l+k+1][h+k+1]==' '){
								pass++;
								continue;
							}
						if(l-k>0&&h-k>0)
							if(gameboard[l-k][h-k]=='X'&&gameboard[l-k-1][h-k-1]==' '){
								pass++;
								continue;
							}
						if(l-k>0&&h+k<5)
							if(gameboard[l-k][h+k]=='X'&&gameboard[l-k-1][h+k+1]==' '){
								pass++;
								continue;
							}
						if(l+k<5&&h-k>0)
							if(gameboard[l+k][h-k]=='X'&&gameboard[l+k+1][h-k-1]==' '){
								pass++;
								continue;
							}
					}
	}
	
	else if(turn==1) { 
		pass=0;
		for(l=0;l<N;l++)
			for(h=0;h<N;h++) 
				if(gameboard[l][h]=='X')
					for(k=1;k<5;k++) {
						if(l+k<5) 
							if(gameboard[l+k][h]=='O'&&gameboard[l+k+1][h]==' '){
								pass++;
								continue;
							}
						if(l-k>0) 
							if(gameboard[l-k][h]=='O'&&gameboard[l-k-1][h]==' '){
								pass++;
								continue;
							}
						if(h+k<5) 
							if(gameboard[l][h+k]=='O'&&gameboard[l][h+k+1]==' '){
								pass++;
								continue;
							}
						if(h-k>0) 	
							if(gameboard[l][h-k]=='O'&&gameboard[l][h-k-1]==' '){
								pass++;
								continue;
							}
						if(l+k<5&&h+k<5) 	
							if(gameboard[l+k][h+k]=='O'&&gameboard[l+k+1][h+k+1]==' '){
								pass++;
								continue;
							}
						if(l-k>0&&h-k>0) 	
							if(gameboard[l-k][h-k]=='O'&&gameboard[l-k-1][h-k-1]==' '){
								pass++;
								continue;
							}
						if(l-k>0&&h+k<5) 	
							if(gameboard[l-k][h+k]=='O'&&gameboard[l-k-1][h+k+1]==' '){
								pass++;
								continue;
							}
						if(l+k<5&&h-k>0) 	
							if(gameboard[l+k][h-k]=='O'&&gameboard[l+k+1][h-k-1]==' '){
								pass++;
								continue;
							}
					}
								
	}
		
	return pass;
}

int isGameEnd() {
	int result;
	othello_num();
	
	if(numofW==0||numofB==0) //��� �� ������ ������ ���� �Ǿ��� �� 
		result=numofW*numofB;
	else
		result=numofW+numofB-36; //�����θ� ���� �ڸ��� ���� �� 
	
		return result;
	
}
