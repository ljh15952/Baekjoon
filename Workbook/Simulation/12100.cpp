#include <bits/stdc++.h>

using namespace std;

int N;
int board[25][25];

const int LEFT = 0;
const int UP = 1;
const int RIGHT = 2;
const int DOWN = 3;

int mx[4] = {-1,0,1,0};
int my[4] = {0,-1,0,1};

void printBoard(){
	cout << '\n';
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= N || x >= N);
}

void go(int y, int x, int dir){
	
	int dx = x;
	int dy = y;
	while(1){
		dx += mx[dir];
		dy += my[dir];
		
		if(OOB(dy, dx)){
			break;
		}
		
		if(board[dy][dx] == 0){
			swap(board[dy][dx], board[y][x]);
			x = dx;
			y = dy;
		}else if(board[dy][dx] == board[y][x]){
			board[dy][dx] *= 2;
			board[y][x] = 0;
			break;
		}else if(board[dy][dx] != board[y][x]){
			break;
		}
		
		//printBoard();
		
	}
	
}

void mergeBloack(int dir){
	
	if(dir == LEFT || dir == UP){
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				if(board[i][j] != 0)
					go(i, j, dir);
	}else if(dir == RIGHT || dir == DOWN){
		for(int i = N - 1; i >= 0; i--)
			for(int j = N - 1; j >= 0; j--)
				if(board[i][j] != 0)
					go(i, j, dir);
	}
	
}

/*

// 배열 바꿔치기
// 막 복사해야 함
*/

void backTracking(int dir, int ct){
	
	if(ct == 5){
		// 끝
		return;
	}
	
	for(int i = 0; i < 4; i++){
		backTracking(i, ct+1);
	}
	
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}
	
	backTracking(LEFT, 0);
	
	//mergeBloack(DOWN);
	
	//printBoard();
	
	return 0;
}

/*
최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록을 출력한다.


*/

/*

*/
