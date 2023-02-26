#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int R, C; // row행 column열

string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> R >> C;
	
	for(int i = 0; i < R; ++i){
		fill(dist1[i], dist1[i] + C, -1);
		fill(dist2[i], dist2[i] + C, -1);
	}
	
	for(int i = 0; i < R; ++i)
		cin >> board[i];	
	
	queue<pair<int,int>> Q1;
	queue<pair<int,int>> Q2;
	
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			if(board[i][j] == 'F'){
				Q1.push({i,j});
				dist1[i][j] = 0;
			}else if(board[i][j] == 'J'){
				Q2.push({i,j});
				dist2[i][j] = 0;
			}
		}
	}
	
	
	// 불 BFS
	while(!Q1.empty()){
		auto cur = Q1.front(); Q1.pop();
		
		for(int i = 0; i < 4; ++i){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			
			if(nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
			if(dist1[ny][nx] >= 0 || board[ny][nx] == '#') continue;
			Q1.push({ny,nx});
			dist1[ny][nx] = dist1[cur.Y][cur.X] + 1;
		}
	}
	
	while(!Q2.empty()){
		auto cur = Q2.front(); Q2.pop();
		
		for(int i = 0; i < 4; ++i){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			
			if(nx < 0 || nx >= C || ny < 0 || ny >= R){
				cout << dist2[cur.Y][cur.X]+1 << '\n';
				return 0;
			}
			if(dist2[ny][nx] >= 0 || board[ny][nx] == '#') continue;
			if(dist1[ny][nx] != -1 && dist1[ny][nx] <= dist2[cur.Y][cur.X]+1) continue;
			dist2[ny][nx] = dist2[cur.Y][cur.X] + 1;
			Q2.push({ny,nx});
		}
	}
	
	cout << "IMPOSSIBLE\n";
	return 0;
}

/*
5 6
#####
#J.F#
#...#
#...#
#...#
#...#
*/