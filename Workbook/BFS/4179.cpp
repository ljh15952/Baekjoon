#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int R, C;

char board[1001][1001];
int dist[1001][1001]

queue<pair<int,int>> Q;

int minute = 0;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> R >> C;
	
	int curY, curX;
	
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			cin >> board[i][j];
			if(board[i][j] == 'J') Q.push({i,j});
		}
	}
	
	while(!Q.empty()){
		auto cur = Q.front(); q.pop();
		
		for(int i = 0; i < 4; ++i){
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
		}
		
		
		
		
		
	}
	
	int ans = 0;
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			ans = min(dist[i][j], ans);
	
	if(ans == 0) cout << "IMPOSSIBLE\n";
	else cout << ans << '\n';
	
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