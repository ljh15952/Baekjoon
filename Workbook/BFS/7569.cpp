#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int board[102][102][102];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cout << "QWE" << '\n';
	
	int b[3][2][1] = {[[0],[1]],
									 [[2],[3]],
									 [[4],[5]]};
	
	
	cout << b[0][0][0] << '\n';
	
	
	
	
	return 0;
}

/*
토마토 3차원 bfs..?
M 가로칸 수
N 세로 칸 수
H 쌓아올려지는 상자의 수
익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 영향을 받아 익게 됨
위, 아래, 왼,오,앞,뒤 6방향임
며칠이 지나면 다 익게 되는지 그 최소 일수를 알고 싶어 한다.

1 익은 토마토, 0 익지 않은 토마토, -1 토마토 들어있지 않음
토마토가 모두 익지 못하는 상황이면 -1 출력

5 3 1
for(int a = 0; a < 1; ++a)
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 5; ++j)
			cin >> board[a][i][j];
*/