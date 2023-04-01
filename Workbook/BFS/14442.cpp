#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N, M, K;

string board[1002];

int dist[12][1002][1002];

queue<tuple<int,int,int>> Q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M >> K;
	
	for(int i = 0; i < N; ++i){
		cin >> board[i];
	}
	
	Q.push({0,0,0});
	dist[0][0][0] = 1;
	
	while(!Q.empty()){
		int x,y,z;
		tie(z,y,x) = Q.front(); Q.pop();
		
		if(x == M - 1 && y == N - 1){
			cout << dist[z][y][x] << '\n';
			return 0;
		}
		
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
			
			int nz = z;
			if(board[ny][nx] == '1') nz++;
			
			if(nz > K || dist[nz][ny][nx] > 0) continue;
			
			dist[nz][ny][nx] = dist[z][y][x] + 1;
			Q.push({nz,ny,nx});
		}
	}
	cout << -1;
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