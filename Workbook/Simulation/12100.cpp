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
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(board[i][j] != 0){
					go(i, j, dir);
				}
			}
		}
	}else if(dir == RIGHT || dir == DOWN){
		for(int i = N - 1; i >= 0; i--){
			for(int j = N - 1; j >= 0; j--){
				if(board[i][j] != 0){
					go(i, j, dir);
				}
			}
		}
	}
		
	
		
	
	
}

/*
3
0 2 4
2 4 0
0 0 8
*/

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}
	
	mergeBloack(DOWN);
	
	printBoard();
	
	return 0;
}

/*

1. 블록 합쳐지는 알고리즘
2. 모든 방향 백트래킹
 <- <- <- <- <-
    ^ <- <- <- 
	  ^ <- <-
	  ....


*/

/*
2048
4x4 z크기의 보드에서 혼자 즐기는 재미있는 게임

한 번의 이동은 보드 위에 있는 전체 블록을
상하좌우 네 방향 중 하나로 이동시키는 것
이때, 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다.
한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다
(실제 게임에서는 이동을 한 번 할  때마다 블록이 추가되지면 이 문제에서는 X)

똑같은 수 세 개가 있는 경우에는 이동하려고 하는 쪽의 칸이 먼저 합쳐진다.
위쪽에 있는 블록이 먼저 합쳐지게 된다

NxN 보드의 크기의 보드판과
블록 상태가 주어졌을 때 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램

0
2 2 2
4 4 4
8 8 8

1

4 2 0
8 4 0
16 8 0

2

0 4 2
0 8 4
0 16 8 이 뒤로 안되넹

3

4

5
*/
