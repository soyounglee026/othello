#define N 6

extern char gameboard[N][N];
extern int ROWS, COLS;
extern int turn;
extern int fW, fE, fN, fS, fNW, fNE, fSW, fSE;

void flip_condition() { 
	
	int i, k, l; //�ݺ������� �� ���� 
	
	if(turn==0) { //��� ������ �� 
		if(ROWS<4&&gameboard[ROWS+1][COLS]=='X'){ //���� 
			for(k=1;k<N-1;k++) {  
				if(gameboard[ROWS+k][COLS]=='X'&&gameboard[ROWS+k+1][COLS]=='O')//�����θ� ���� �� �ִ��� Ȯ��
					for(i=1;i<N-1;i++){
						if(ROWS+k<N-1) { //ROWS+k>=N-1�̸� ���̻� ���ʿ� �ִ� �����θ� ������ �� ����  
							if(gameboard[ROWS+i][COLS]=='X') {
								gameboard[ROWS+i][COLS]='O'; //���ǿ� �´� ������ ������� �ٲٱ� 
								fS++; //�ٲ� ���� 
								gameboard[ROWS][COLS]='O';
								continue; //�ش�Ǵ� �� ��� �ٲٱ� 
							}
						
							else if(gameboard[ROWS+i][COLS]=='O')
								break; //����� ������ �׸� �ٲ� 
						}
					}
			}
		}
		
		if(ROWS>1&&gameboard[ROWS-1][COLS]=='X'){ //����
			for(k=1;k<N-1;k++) { 
				if(gameboard[ROWS-k][COLS]=='X'&&gameboard[ROWS-k-1][COLS]=='O')	
					for(i=1;i<N-1;i++){
						if(ROWS-k>0) {
							if(gameboard[ROWS-i][COLS]=='X'){
								gameboard[ROWS-i][COLS]='O';
								fN++;
								gameboard[ROWS][COLS]='O';
								continue;
							}
						
							else if(gameboard[ROWS-i][COLS]=='O')
								break;
						}
					}
			}
		}
		
		if(COLS>1&&gameboard[ROWS][COLS-1]=='X'){ //����  
			for(k=1;k<N-1;k++){
				if(gameboard[ROWS][COLS-k]=='X'&&gameboard[ROWS][COLS-k-1]=='O')
					for(i=1;i<N-1;i++){
						if(COLS-k>0) {
							if(gameboard[ROWS][COLS-i]=='X'){
								gameboard[ROWS][COLS-i]='O';
								fW++;
								gameboard[ROWS][COLS]='O';
								continue;
							}
							
							else if(gameboard[ROWS][COLS-i]=='O') 
								break;
						}
					}
			}
		}
		
		if(COLS<4&&gameboard[ROWS][COLS+1]=='X'){ //���� 
				for(k=1;k<N-1;k++){
					if(gameboard[ROWS][COLS+k]=='X'&&gameboard[ROWS][COLS+k+1]=='O')
						for(i=1;i<N-1;i++){
							if(COLS+k<N-1) {
								if(gameboard[ROWS][COLS+i]=='X'){
									gameboard[ROWS][COLS+i]='O';
									fE++;
									gameboard[ROWS][COLS]='O';
									continue;
								}
									
								else if(gameboard[ROWS][COLS+i]=='O') 
									break;
							}
						}
				}
		}
		
		if(ROWS>1&&COLS>1&&gameboard[ROWS-1][COLS-1]=='X'){ //�ϼ���  
			for(k=1;k<N-1;k++) {
				if(gameboard[ROWS-k][COLS-k]=='X'&&gameboard[ROWS-k-1][COLS-k-1]=='O')		
					for(i=1;i<N-1;i++) {
						if(ROWS-k>0&&COLS-k>0) {
							if(gameboard[ROWS-i][COLS-i]=='X'){
								gameboard[ROWS-i][COLS-i]='O';
								fNW++;
								gameboard[ROWS][COLS]='O';
								continue;
							}
								
							else if(gameboard[ROWS-i][COLS-i]=='O') 
								break;
						}
					}
			}
		}
		
		if(ROWS>1&&COLS<4&&gameboard[ROWS-1][COLS+1]=='X'){ //�ϵ���  
			for(k=1;k<N-1;k++) {
				if(gameboard[ROWS-k][COLS+k]=='X'&&gameboard[ROWS-k-1][COLS+k+1]=='O')		
					for(i=1;i<N-1;i++) {
						if(ROWS-k>0&&COLS+k<N-1) {
							if(gameboard[ROWS-i][COLS+i]=='X'){
								gameboard[ROWS-i][COLS+i]='O';
								fNE++;
								gameboard[ROWS][COLS]='O';
								continue;
							}
							
							else if(gameboard[ROWS-i][COLS+i]=='O') 
								break;
						}
					}
			}
		}
		
		if(ROWS<4&&COLS>1&&gameboard[ROWS+1][COLS-1]=='X'){ //������  
			for(k=1;k<N-1;k++) {
				if(gameboard[ROWS+k][COLS-k]=='X'&&gameboard[ROWS+k+1][COLS-k-1]=='O')		
					for(i=1;i<N-1;i++) {
						if(ROWS+k<N-1&&COLS-k>0) {
							if(gameboard[ROWS+i][COLS-i]=='X'){
								gameboard[ROWS+i][COLS-i]='O';
								fSW++;
								gameboard[ROWS][COLS]='O';
								continue;
							}
							
							else if(gameboard[ROWS+i][COLS-i]=='O') 
								break;
						}
					}
			}
		}
		
		if(ROWS<4&&COLS<4&&gameboard[ROWS+1][COLS+1]=='X'){ //������  
			for(k=1;k<N-1;k++) {
				if(gameboard[ROWS+k][COLS+k]=='X'&&gameboard[ROWS+k+1][COLS+k+1]=='O')		
					for(i=1;i<N-1;i++) {
						if(ROWS+k<N-1&&COLS+k<N-1) {
							if(gameboard[ROWS+i][COLS+i]=='X'){
								gameboard[ROWS+i][COLS+i]='O';
								fSE++;
								gameboard[ROWS][COLS]='O';
								continue;
							}
						
							else if(gameboard[ROWS+i][COLS+i]=='O') 
								break;
						}
					}
			}
		}
	}
	
	else if(turn==1) { //������ ������ �� 		
		if(ROWS<4&&gameboard[ROWS+1][COLS]=='O'){ //���� 
			for(k=1;k<N-1;k++) { 
				if(gameboard[ROWS+k][COLS]=='O'&&gameboard[ROWS+k+1][COLS]=='X')
					for(i=1;i<N-1;i++){
						if(ROWS+k<N-1) {
							if(gameboard[ROWS+i][COLS]=='O') {
								gameboard[ROWS+i][COLS]='X';
								fS++;
								gameboard[ROWS][COLS]='X';
								continue;
							}
							
							else if(gameboard[ROWS+i][COLS]=='X')
								break;
						}
					}
			}
		}
		
		if(ROWS>1&&gameboard[ROWS-1][COLS]=='O'){ //����
			for(k=1;k<N-1;k++) { 
				if(gameboard[ROWS-k][COLS]=='O'&&gameboard[ROWS-k-1][COLS]=='X')	
					for(i=1;i<N-1;i++){
						if(ROWS-k>0) {
							if(gameboard[ROWS-i][COLS]=='O'){
								gameboard[ROWS-i][COLS]='X';
								fN++;
								gameboard[ROWS][COLS]='X';
								continue;
							}
							
							else if(gameboard[ROWS-i][COLS]=='X')
								break;
						}
					}
			}
		}
		
		if(COLS>1&&gameboard[ROWS][COLS-1]=='O'){ //����  
			for(k=1;k<N-1;k++){
				if(gameboard[ROWS][COLS-k]=='O'&&gameboard[ROWS][COLS-k-1]=='X')
					for(i=1;i<N-1;i++){
						if(COLS-k>0) {
							if(gameboard[ROWS][COLS-i]=='O'){
								gameboard[ROWS][COLS-i]='X';
								fW++;
								gameboard[ROWS][COLS]='X';
								continue;
							}
							
							else if(gameboard[ROWS][COLS-i]=='X') 
								break;
						}
					}
			}
		}
		
		if(COLS<4&&gameboard[ROWS][COLS+1]=='O'){ //���� 
			for(k=1;k<N-1;k++){
				if(gameboard[ROWS][COLS+k]=='O'&&gameboard[ROWS][COLS+k+1]=='X')
					for(i=1;i<N-1;i++){
						if(COLS+k<N-1) {
							if(gameboard[ROWS][COLS+i]=='O'){
								gameboard[ROWS][COLS+i]='X';
								fE++;
								gameboard[ROWS][COLS]='X';
								continue;
							}
							
							else if(gameboard[ROWS][COLS+i]=='X') 
								break;
						}
					}
			}
		}
		
		if(ROWS>1&&COLS>1&&gameboard[ROWS-1][COLS-1]=='O'){ //�ϼ���  
			for(k=1;k<N-1;k++) {
				if(gameboard[ROWS-k][COLS-k]=='O'&&gameboard[ROWS-k-1][COLS-k-1]=='X')		
					for(i=1;i<N-1;i++) {
						if(ROWS-k>0&&COLS-k>0) {
							if(gameboard[ROWS-i][COLS-i]=='O'){
								gameboard[ROWS-i][COLS-i]='X';
								fNW++;
								gameboard[ROWS][COLS]='X';
								continue;
							}
							
							else if(gameboard[ROWS-i][COLS-i]=='X') 
								break;
						}
					}
			}
		}
		
		if(ROWS>1&&COLS<4&&gameboard[ROWS-1][COLS+1]=='O'){ //�ϵ���  
			for(k=1;k<N-1;k++) {
				if(gameboard[ROWS-k][COLS+k]=='O'&&gameboard[ROWS-k-1][COLS+k+1]=='X')
					for(i=1;i<N-1;i++) {
						if(ROWS-k>0&&COLS+k<N-1) {
							if(gameboard[ROWS-i][COLS+i]=='O'){
								gameboard[ROWS-i][COLS+i]='X';
								fNE++;
								gameboard[ROWS][COLS]='X';
								continue;
							}
								
							else if(gameboard[ROWS-i][COLS+i]=='X') 
								break;
						}
					}
			}
		}
		
		if(ROWS<4&&COLS>1&&gameboard[ROWS+1][COLS-1]=='O'){ //������  
			for(k=1;k<N-1;k++) {
				if(gameboard[ROWS+k][COLS-k]=='O'&&gameboard[ROWS+k+1][COLS-k-1]=='X')		
					for(i=1;i<N-1;i++) {
						if(ROWS+k<N-1&&COLS-k>0) {
							if(gameboard[ROWS+i][COLS-i]=='O'){
								gameboard[ROWS+i][COLS-i]='X';
								fSW++;
								gameboard[ROWS][COLS]='X';
								continue;
							}
									
							else if(gameboard[ROWS+i][COLS-i]=='X') 
								break;
						}
					}
			}
		}
		
		if(ROWS<4&&COLS<4&&gameboard[ROWS+1][COLS+1]=='O'){ //������  
			for(k=1;k<N-1;k++) {
				if(gameboard[ROWS+k][COLS+k]=='O'&&gameboard[ROWS+k+1][COLS+k+1]=='X')		
					for(i=1;i<N-1;i++) {
						if(ROWS+k<N-1&&COLS+k<N-1) {
							if(gameboard[ROWS+i][COLS+i]=='O'){
								gameboard[ROWS+i][COLS+i]='X';
								fSE++;
								gameboard[ROWS][COLS]='X';
								continue;
							}
									
							else if(gameboard[ROWS+i][COLS+i]=='X') 
								break;
						}
					}
			}
		}
	}
}
