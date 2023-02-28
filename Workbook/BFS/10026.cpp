#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int N;
queue<pair<int,int>> Q;
string board[101];

int vis1[101][101]; // 적록색약이 아닌 사람
int vis2[101][101]; // 적록색약 사람


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	
	for(int i = 0; i < N; ++i)
		cin >> board[i];
	
	//일단 적록색약이 아닌 사람의 그림 수 판별
	int num1 = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			
			if(vis1[i][j] == 1) continue;
			
			num1++;
			Q.push({i,j});
			
			while(!Q.empty()){
				auto cur = Q.front(); Q.pop();
				
				for(int dir = 0; dir < 4; ++dir){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					
					if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if(board[ny][nx] != board[cur.Y][cur.X] || vis1[ny][nx] == 1) continue;
						
					vis1[ny][nx] = 1;
					Q.push({ny,nx});
				}
			}
		}
	}
	cout << num1 << ' ';
	
	//적록색약 사람의 그림 수 판별
	int num2 = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			
			if(vis2[i][j] == 1) continue;
			
			num2++;
			Q.push({i,j});
			
			while(!Q.empty()){
				auto cur = Q.front(); Q.pop();
				
				for(int dir = 0; dir < 4; ++dir){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					
					if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
					if(vis2[ny][nx] == 1) continue;
					//현재 B임 옆이 B가 아니면 continue
					if(board[cur.Y][cur.X] == 'B' && board[ny][nx] != 'B') continue;
					if(board[cur.Y][cur.X] != 'B' && board[ny][nx] == 'B') continue;
					vis2[ny][nx] = 1;
					Q.push({ny,nx});
				}
			}
		}
	}
	cout << num2 << '\n';
	
	return 0;
}

/*
적록색약
빨간색과 초록색의 차이를 거의 느끼지 못한다.
NxN 그리드
R,G,B중 하나를 색칠한 그림이 있다.

RRRBB
GGBBB
BBBRR
BBRRR
RRRRR

적록색약이 아닌 사람이 봤을 때의 구역의 수와
적록색약인 사람이 봤을 때의 구역의 수를 출력


*/