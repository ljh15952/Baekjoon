#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int R, C;

string board[1002];
int dist1[1002][1002]; // 불의 전파 시간
int dist2[1002][1002]; // 지훈이의 이동 시간

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> R >> C;
	
	for(int i = 0; i < C; ++i){
		fill(dist1[i], dist1[i] + R, -1);
		fill(dist2[i], dist2[i] + R, -1);
	}
	
	for(int i = 0; i < C; ++i)
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
			
			if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if(dist1[ny][nx] >= 0 || board[ny][nx] == '#') continue;
			Q1.push({ny,nx});
			dist1[ny][nx] = dist1[cur.Y][cur.X] + 1;
		}
	}
	
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			cout << dist1[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}

/*
미로, 탈출
지훈이 위치, 불이 붙은 위치
불에 타기전에 탈출, 할 수 있는지의 여부, 얼마나 빨리 탈출할 수 있는지

불은 매 분바다 한칸씩 수평또는 수직으로 이동
R행, C는 열
#벽 .지나갈 수 있는 공간 J지훈이의 미로에서의 초기위치 F불이 난 공간

미로 탈출 할 수 없으면 IMPOOSSIBLE 출력
탈출하면 가장 빠른 탈출 시간 출력

####
#JF#
#..#
#..# 

####
#FF#
#JF#
#..#

####
#FF#
#FF#
#JF#

####
#FF#
#FF#
#FF#  탈출
 J
*/