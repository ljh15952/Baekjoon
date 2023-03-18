#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

char board[1001][1001];
int dist[1001][1001][2];

int N, M;

bool OOB(int y, int x){
	return (x < 0 || x >= M || y < 0 || y >= N);
}

int bfs(){
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			dist[i][j][0] = dist[i][j][1] = -1;
	
	dist[0][0][0] = 1;
	
	queue<tuple<int,int,int>> q;
	q.push({0,0,0});
	while(!q.empty()){
		int x,y,broken;
		tie(y,x,broken) = q.front();
		q.pop();
		
		if(x == M-1 && y == N-1) return dist[y][x][broken];
		
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(OOB(ny,nx)) continue;

			if(board[ny][nx] == '0' && dist[ny][nx][broken] == -1){
				dist[ny][nx][broken] = dist[y][x][broken] + 1;
				q.push({ny,nx,broken});
			}
			
			// 벽을 부수는 경우
			if(!broken && board[ny][nx] == '1' && dist[ny][nx][1] == -1){
				dist[ny][nx][1] = dist[y][x][broken] + 1;
				q.push({ny,nx,1});
			}
		}
		
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			cin >> board[i][j];

	cout << bfs() << '\n';
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cout << dist[i][j][0] << ' ';
		}	
		cout << '\n';
	}
	cout << '\n';
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cout << dist[i][j][1] << ' ';
		}	
		cout << '\n';
	}
	return 0;
}

/*
6 4
0000
0000
1000
0000
0111
0000
*/