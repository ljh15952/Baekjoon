#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int n, m;
int board[9][9];
queue<pair<int, int>> Q;

int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};

void dfs(){
	
	
	int tempBoard[9][9];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			tempBoard[i][j] = board[i][j];
		}
	}
	
	
	while(!Q.empty()){
		auto cur = Q.front(); 
		Q.pop();
		
		for(int i = 0; i < 4; i++){
			int dx = mx[i] + cur.X;
			int dy = my[i] + cur.Y;
			
			
		}
		
	}
	
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
			Q.push({i, j});
		}
	}
	
	
	
	cout << '\n';
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	
	
	//dfs();
	
	return 0;
}

/*

재귀

전에 백트래킹 부터
2를 큐에 먼저 넣자


*/

/*
바이러스 유출
연구소에 벽을 세우려고 함
NxM의 직사각형
빈 칸, 벽
바이러스 상하좌우로 인접한 빈 칸으로 모두 퍼져나감
새로 세울 수 있는 벽의 개수는 3개, 꼭 3개를 세워야 함
0 빈칸, 1 벽, 2바이러스

안전 영역의 크기의 최댓값을 구하여라

*/