#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int T;
int w, h; // 너비와 높이

char board[1002][1002];

int fire[1002][1002];
int hito[1002][1002];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	while(T--){
		int flag = false;
		
		cin >> w >> h;
	
		queue<pair<int,int>> Q1;
		queue<pair<int,int>> Q2;
		
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				cin >> board[i][j];
				
				fire[i][j] = -1;
				hito[i][j] = -1;
				
				if(board[i][j] == '*'){
					Q1.push({i,j});
					fire[i][j] = 0;
				}else if(board[i][j] == '@'){
					Q2.push({i,j});
					hito[i][j] = 0;
				} 
			}
		}

		while(!Q1.empty()){
			auto cur = Q1.front(); Q1.pop();
			for(int i = 0; i < 4; ++i){
				int nx = dx[i] + cur.X;
				int ny = dy[i] + cur.Y;

				if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
				if(board[ny][nx] == '#' || fire[ny][nx] >= 0) continue;

				fire[ny][nx] = fire[cur.Y][cur.X] + 1;
				Q1.push({ny,nx});
			}
		}

		while(!Q2.empty() && !flag){
			auto cur = Q2.front(); Q2.pop();

			for(int i = 0; i < 4; ++i){
				int nx = dx[i] + cur.X;
				int ny = dy[i] + cur.Y;

				if(nx < 0 || ny < 0 || nx >= w || ny >= h){
					cout << hito[cur.Y][cur.X] + 1 << '\n';
					flag = true;
					break;
				}
				if(board[ny][nx] == '#' || hito[ny][nx] >= 0) continue;
				if(fire[ny][nx] != -1 &&
					 fire[ny][nx] <= hito[cur.Y][cur.X] + 1) continue;

				hito[ny][nx] = hito[cur.Y][cur.X] + 1;
				Q2.push({ny,nx});
			}
		}
		if(!flag) cout << "IMPOSSIBLE\n";
	}
	return 0;
}

/*
불이 옮겨진 칸, 불이 붙으려는 칸으로 이동할 수 없다.
얼마나 빨리 빌딩을 탈출할 수 있는지

. 빈공간
# 벽
@ 상근이의 시작 위치
* 불

불이 여러개..
불 bfs 먼저 돌리고
돌리면서 지금 값이 더 적으면 넣고

사람 bfs돌리고 
지금 값보다 적으면 움직이고
벽에 닿았으면 탈출


*/