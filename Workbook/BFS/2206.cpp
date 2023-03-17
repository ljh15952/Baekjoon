#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

char board[1001][1001];
int dist[1001][1001];

int N, M;

bool OOB(int y, int x){
	return (x < 0 || x >= M || y < 0 || y >= N);
}

int bfs(){
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			dist[i][j] = -1;
	
	dist[0][0] = 1;
	
	queue<pair<int,int>> q;
	q.push({0,0});
	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		
		for(int i = 0; i < 4; ++i){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			
			if(OOB(ny,nx)) continue;
			if(dist[ny][nx] > 0) continue;
			if(board[ny][nx] == '1') continue;

			dist[ny][nx] = dist[cur.Y][cur.X] + 1;
			q.push({ny,nx});
		}
		
	}
	return 1;
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
			cout << dist[i][j] << ' ';
		}	
		cout << '\n';
	}
	
	return 0;
}

/*

*/