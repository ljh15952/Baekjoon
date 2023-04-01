#include <bits/stdc++.h>

using namespace std;

#define first Y
#define second X

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N, M, K;

char board[1001][1001];

int dist[2][1001][1001];

queue<tuple<int,int,int>> Q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M >> K;
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cin >> board[i][j];
		}
	}
	
	Q.push({0,0,0});
	dist[0][0][0] = 1;
	dist[1][0][0] = 1;
	
	while(!Q.empty()){
		int x,y,z;
		tie(z,y,x) = Q.front(); Q.pop();
		
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			if(dist[z][ny][nx] > 0) continue;
			if(board[ny][nx] == '1') continue;
			
			dist[z][ny][nx] = dist[z][y][x] + 1;
			Q.push({z,ny,nx});
		}
	}
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cout << dist[0][i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}


/*
6 4 1
0000
1110
1000
0000
0111
0000

*/

/*
NxM의 행렬로 표현되는 맵
0은 이동할 수 있는 곳, 1은 이동할 수 없는 벽
(1,1)에서 (N,M)의 위치까지 이동하려 함(최단경로)
시작하는 칸, 끝나는 칸도 포함해서 센다.

만약 이동하는 도중 벽을 부수고 이동하는 것이 좀 더 경로가 짧다면
벽을 K개 까지 부수고 이동하여도 된다.

N, M, K
1,1과 N,M은 항상 0이다

*/