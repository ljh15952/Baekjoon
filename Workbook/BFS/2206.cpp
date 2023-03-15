#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[1001][1001];
int dist[1001][1001][2];
// dist[y][x][0] 벽을 하나도 부수지 않고 (x,y)까지 오는데 걸리는 비용
// dist[y][x][1] 벽을 하나만 부수고 (x,y)까지 오는데 걸리는 비용, (x,y)가 벽이라
// 부수는 경우도 포함

int N, M;

bool OOB(int y, int x){
	return (x < 0 || x >= M || y < 0 || y >= N)
}

int bfs(){
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			dist[i][j][0] = dist[i][j][1] = -1;
	
	
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cin >> board[N][M];
		}
	}
	
	Q.push({0,0});
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		
		
		
	}
	
	
	// if(ny == N-1 && nx == M-1) 끝
	
	return 0;
}
//가로 30 세로 16 지뢰 99
/*
벽 부수고 이동하기
NxM 행렬로 표현되는 맵이 있다.
0은 이동할 수 있는 곳
1은 이동할 수 없는 벽
(1,1)에서 (N,M)의 위치까지 이동하려 하는데, 최단 경로로 이동하려 한다.
가장 적은 개수의 칸을 지나는 경로 시작하는 칸과 끝나는 칸도 포함해서 센다.

이동하는 도중 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면
벽을 한 개 까지 부수고 이동하여도 된다.

한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸
불가능할 때는 -1 출력
(1,1) (N,M)은 항상 0
N 행
M 열 
*/