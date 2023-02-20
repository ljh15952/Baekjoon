#include <bits/stdc++.h>

using namespace std;

#define X second
#define Y first

int N, M;
string board[105];
int dist[105][105];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; ++i) cin >> board[i];
	for(int i = 0; i < N; ++i) fill(dist[i], dist[i]+M, 0);
	
	
	queue<pair<int,int>> Q;
	Q.push({0,0});
	dist[0][0] = 1;
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		
		for(int i = 0; i < 4; ++i){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			
			if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
			if(board[ny][nx] != '1' || dist[ny][nx] > 0) continue;
			
			dist[ny][nx] = dist[cur.Y][cur.X]+1;
			Q.push({ny, nx});
		}
	}
	
	cout << dist[N-1][M-1] << '\n';
	
	return 0;
}

/*
NxM 크기의 배열
미로 1은 이동할 수 있는 칸
0은 이동 X, (1,1), 출발 (N,M)의 위치로 이동할 때 지나야 하는 
최소의 칸 수
칸을 셀 때 시작 위치와 도착 위치도 포함



*/