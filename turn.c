#define N 6

extern int turn;
extern char gameboard[N][N];
extern int numofW, numofB;

int turn_pass() { //���� �� ������ �� �н�
	int l, h, k; //for�� ����
	int pass; //���� 0�̸� ���� ���� ���ٴ� �� 
	
	if(turn==0) { 
	pass=0;
		for(l=0;l<N;l++)
			for(h=0;h<N;h++) {
				if(gameboard[l][h]=='O')
					for(k=1;k<5;k++){
						if(l-k>=0&&l+k<=5&&h-k>=0&&h+k<=5) {
						if(gameboard[l+k][h]=='X'&&gameboard[l+k+1][h]==' ') //8�� ���� Ȯ�� 
							pass++; //���� �� ������ pass�� ���� ������Ŵ 
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
	
	if(numofW==0||numofB==0) //��� �� ������ ������ ���� �Ǿ��� �� 
		result=numofW*numofB;
	else
		result=numofW+numofB-36; //�����θ� ���� �ڸ��� ���� �� 
	
		return result;
	
}
