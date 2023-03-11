#include <bits/stdc++.h>

using namespace std;

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,-1,1};



int L,R,C;


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	while(1){
		cin >> L >> R >> C;
		if(L == 0 && R == 0 && C == 0) break;
		queue<tuple<int,int,int>> Q;
		char board[31][31][31];
		int dist[31][31][31];
		
		for(int i = 0; i < L; ++i)
			for(int j = 0; j < R; ++j) fill(dist[i][j], dist[i][j] + C, 0);
		
		for(int i = 0; i < L; ++i){
			for(int j = 0; j < R; ++j){
				for(int k = 0; k < C; ++k){
					cin >> board[i][j][k];
					if(board[i][j][k] == 'S'){
						Q.push({i,j,k});
						dist[i][j][k] = 0;
					}else if(board[i][j][k] == '.') dist[i][j][k] = -1;
				}
			}
		}
		
		bool isEscape = false;
		
		while(!Q.empty()){
			if(isEscape) break;
			auto cur = Q.front(); Q.pop();
			int curX, curY, curZ;

			tie(curZ,curY,curX) = cur;

			for(int i = 0; i < 6; ++i){
				int nx = curX + dx[i];
				int ny = curY + dy[i];
				int nz = curZ + dz[i];

				if(nx < 0 || ny < 0 || nz < 0||
					 nx >= C || ny >= R || nz >= L) continue;
				if(dist[nz][ny][nx] > 0) continue;
				if(board[nz][ny][nx] == '#') continue;

				dist[nz][ny][nx] = dist[curZ][curY][curX] + 1;

				if(board[nz][ny][nx] == 'E'){
					cout << "Escaped in " << dist[nz][ny][nx] << " minute(s).\n";
					isEscape = true;
					break;
				}
				Q.push({nz,ny,nx});
			}
		}
		while(!Q.empty()) Q.pop();
    if(!isEscape) cout << "Trapped!" << "\n";
	}
	return 0;
}

/*
상범? 빌딩에 갇혔다.?
각 변의 길이가 1인 정육면체로 이루어져있다.
각 칸에서 인접한 6개의 칸(동,서,남,북,상,하) 1분의 시간을 들여 이동
L 빌딩의 층 수
R 빌딩 행
C 빌딩 열

막힌 칸 #
비어있는 칸 . 
시작지점 S
탈출구 E 

0 0 0 입력되면 끝

*/