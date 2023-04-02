#include <bits/stdc++.h>

using namespace std;

string board[1002];
// y,x,부순 횟수, 낮/밤 여부(낮=0, 밤 = 1)
int dist[1002][1002][12][2]; 

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N, M, K;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M >> K;
	for(int i = 0; i < N; ++i)
		cin >> board[i];
	
	queue<tuple<int,int,int,int>> Q;
	Q.push({0,0,0,0});
	dist[0][0][0][0] = 1;
	
	while(!Q.empty()){
		int x,y,w,t;
		tie(y,x,w,t) = Q.front(); Q.pop();
		
		if(x == M - 1 && y == N - 1){
			cout << dist[y][x][w][t] << '\n';
			return 0;
		}
		
		for(int i = 0; i < 4; ++i){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= M || ny >= N)
				continue;
			
			// nx,ny가 빈곳이면 편하게 간다!
			if(board[ny][nx] == '0'){
				int nw = w;
				int nt = 1-t;
				if(dist[ny][nx][nw][nt] > 0) continue;
				dist[ny][nx][nw][nt] = dist[y][x][w][t] + 1;
				Q.push({ny,nx,nw,nt});
			}
			// 비어있지 않다면
			else{
				// 이미 k번 깼으면 더 깰 수 없음
				if(w == K) continue;
				// 낮이라면 깨고 넘어간다.
				if(t == 0){
					int nw = w+1;
					int nt = 1-t;
					if(dist[ny][nx][nw][nt] > 0) continue;
					dist[ny][nx][nw][nt] = dist[y][x][w][t] + 1;
					Q.push({ny,nx,nw,nt});
				}
				// 밤이라면 낮이 올 때 까지 기다린다.
				// 다음 좌표가 x,y,z,nw인 점을 주의한다.
				else{
					int nt = 1-t;
					if(dist[y][x][w][nt] > 0) continue;
					dist[y][x][w][nt] = dist[y][x][w][t] + 1;
					Q.push({y,x,w,nt});
				}
			}
			
		}
	}
	
	cout << "-1\n";
	
	return 0;
}

/*
낮과 밤ㅋㅋ..
개어렵잔아

*/