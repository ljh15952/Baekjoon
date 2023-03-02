#include <bits/stdc++.h>

using namespace std;

int board[103][103][103];
int dist[103][103][103];

int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

queue<tuple<int,int,int>> Q;

int m,n,h;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> m >> n >> h;
	
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < m; ++k){
				cin >> board[i][j][k];
				if(board[i][j][k] == 1) Q.push({i,j,k});
				if(board[i][j][k] == 0) dist[i][j][k] = -1;
			}
		}
	}
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		int curX, curY, curZ;
		tie(curZ,curY,curX) = cur;
		for(int i = 0; i < 6; ++i){
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			int nz = curZ + dz[i];
			if(nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h) continue;
			if(dist[nz][ny][nx] >= 0) continue;
			dist[nz][ny][nx] = dist[curZ][curY][curX] + 1;
			Q.push({nz,ny,nx});
		}
	}
	
	int ans = 0;
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < m; ++k){
				if(dist[i][j][k] == -1){
					cout << -1 << '\n';
					return 0;
				}
				ans = max(ans, dist[i][j][k]);
			}
		}
	}
	
	cout << ans << '\n';
	
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