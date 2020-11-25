#define N 6

extern char gameboard[N][N];
extern int ROWS, COLS;
extern int turn;
extern int fW, fE, fN, fS, fNW, fNE, fSW, fSE;

void flip_condition() { 
	
	int i, k, l; //반복문에서 쓸 변수 
	
	if(turn==0) { //흰색 차례일 때 
		if(ROWS<4&&gameboard[ROWS+1][COLS]=='X'){ //남쪽 
			for(k=1;k<N-1;k++) {  
				if(gameboard[ROWS+k][COLS]=='X'&&gameboard[ROWS+k+1][COLS]=='O')//오델로를 놓을 수 있는지 확인
					for(i=1;i<N-1;i++){
						if(ROWS+k<N-1) { //ROWS+k>=N-1이면 더이상 남쪽에 있는 오델로를 뒤집을 수 없음  
							if(gameboard[ROWS+i][COLS]=='X') {
								gameboard[ROWS+i][COLS]='O'; //조건에 맞는 검은색 흰색으로 바꾸기 
								fS++; //바꾼 개수 
								gameboard[ROWS][COLS]='O';
								continue; //해당되는 것 계속 바꾸기 
							}
						
							else if(gameboard[ROWS+i][COLS]=='O')
								break; //흰색과 만나면 그만 바꿈 
						}
					}
			}
		}
		
		if(ROWS>1&&gameboard[ROWS-1][COLS]=='X'){ //북쪽
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
		
		if(COLS>1&&gameboard[ROWS][COLS-1]=='X'){ //서쪽  
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
		
		if(COLS<4&&gameboard[ROWS][COLS+1]=='X'){ //동쪽 
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
		
		if(ROWS>1&&COLS>1&&gameboard[ROWS-1][COLS-1]=='X'){ //북서쪽  
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
		
		if(ROWS>1&&COLS<4&&gameboard[ROWS-1][COLS+1]=='X'){ //북동쪽  
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
		
		if(ROWS<4&&COLS>1&&gameboard[ROWS+1][COLS-1]=='X'){ //남서쪽  
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
		
		if(ROWS<4&&COLS<4&&gameboard[ROWS+1][COLS+1]=='X'){ //남동쪽  
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
	
	else if(turn==1) { //검은색 차례일 때 		
		if(ROWS<4&&gameboard[ROWS+1][COLS]=='O'){ //남쪽 
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
		
		if(ROWS>1&&gameboard[ROWS-1][COLS]=='O'){ //북쪽
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
		
		if(COLS>1&&gameboard[ROWS][COLS-1]=='O'){ //서쪽  
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
		
		if(COLS<4&&gameboard[ROWS][COLS+1]=='O'){ //동쪽 
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
		
		if(ROWS>1&&COLS>1&&gameboard[ROWS-1][COLS-1]=='O'){ //북서쪽  
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
		
		if(ROWS>1&&COLS<4&&gameboard[ROWS-1][COLS+1]=='O'){ //북동쪽  
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
		
		if(ROWS<4&&COLS>1&&gameboard[ROWS+1][COLS-1]=='O'){ //남서쪽  
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
		
		if(ROWS<4&&COLS<4&&gameboard[ROWS+1][COLS+1]=='O'){ //남동쪽  
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
