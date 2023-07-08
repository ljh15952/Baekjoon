#include <bits/stdc++.h>

using namespace std;

int N;
int board[25][25];

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

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}
	
	printBoard();
	
	return 0;
}

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
