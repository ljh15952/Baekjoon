#include <bits/stdc++.h>

using namespace std;

#define Y second
#define X first

int n, m;
string board[11];
pair<int, int> red, blue; // 빨간 구슬과 파란구슬의 위치

// dist[a][b][c][d]
// 빨간 구슬 (a,b) 파란 구슬 (c,d)에 위치한 상황에 도달하기 위한 동작의 횟수
int dist[11][11][11][11]; 

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};



int bfs() {
  	queue<tuple<int,int,int,int>> q;
	q.push({red.X, red.Y, blue.X, blue.Y});
	dist[red.X][red.Y][blue.X][blue.Y] = 0;
	
	while(!q.empty()){
		int rx, ry, bx, by;
		tie(rx, ry, bx, by) = q.front();
		q.pop();
		
		int cnt = dist[rx][ry][bx][by];
		
		if(cnt >= 10)
			return -1;
		// 4방향으로 기울이기
		for(int i = 0; i < 4; i++){
			int n_rx = rx, n_ry = ry, n_bx = bx, n_by = by;

			while(board[n_bx + dx[i]][n_by + dy[i]] == '.'){
				n_bx += dx[i];
				n_by += dy[i];
			}


		if(board[n_bx + dx[i]][n_by + dy[i]] == 'O') continue;

		while(board[n_rx + dx[i]][n_ry + dy[i]] == '.'){
			n_rx += dx[i];
			n_ry += dy[i];
		}

		if(board[n_rx + dx[i]][n_ry + dy[i]] == 'O') return cnt + 1;

		  // Red, Blue가 겹쳐진 경우 늦게 출발한 구슬을 한칸 뒤로 이동
		if((n_rx == n_bx) && (n_ry == n_by)){
			if(i == 0)
				ry < by ? n_ry-- : n_by--;
			else if(i == 1)
				rx < bx ? n_rx-- : n_bx--;
			else if(i == 2)
				ry > by ? n_ry++ : n_by++;
			else
				rx > bx ? n_rx++ : n_bx++;
		}
			if(dist[n_rx][n_ry][n_bx][n_by] != -1) continue;
			dist[n_rx][n_ry][n_bx][n_by] = cnt + 1;
			q.push({n_rx, n_ry, n_bx, n_by});
		}
	}
	return -1;
}


int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	// 거리 배열 초기화
	for(int i = 0; i < 10; i++)
		for(int j = 0; j < 10; j++)
			for(int k = 0; k < 10; k++)
				fill(dist[i][j][k], dist[i][j][k]+10, -1);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		cin >> board[i];
		for(int j = 0; j < m; j++){
			
			if(board[i][j] == 'R'){
				red = {i, j};
				board[i][j] = '.';
			}else if(board[i][j] == 'B'){
				blue = {i , j};
				board[i][j] = '.';
			}
		}
	}

	cout << bfs() << '\n';
	
	return 0;
}
