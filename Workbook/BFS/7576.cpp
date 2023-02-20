#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int n,m;

int board[1004][1004];
int dist[1002][1002];

int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

queue<pair<int,int>> Q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> m >> n;
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> board[i][j];
			if(board[i][j] == 1) Q.push({i,j});
			if(board[i][j] == 0) dist[i][j] = -1;
		}	
	}
		
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
				
		for(int i = 0; i < 4; ++i){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
					
			if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if(dist[ny][nx] >= 0) continue;
			
			dist[ny][nx] = dist[cur.Y][cur.X] + 1;
			Q.push({ny,nx});
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(dist[i][j] == -1){
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}

/*
시작점이 애매한 BFS문제?
M행 N열 격자 모양 상자
익지 않은 토마토가 있다.
보관후 하루가 지나면 익은 토마토들의 인접한 곳에 있는
익지 않은 토마토들은 익은 토마토의 영향을 받아 익게된다.
대각선X 저절로 익지 않음
토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수를 알고싶다.

1은 익은 토마토, 0은 익지 않은 토마토, -1은 토마토가 들어있지 않은 칸

*/