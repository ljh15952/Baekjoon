#include <bits/stdc++.h>
using namespace std;

#define Y first
#define X second

int T;
int M, N, K;

int board[51][51];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

queue<pair<int,int>> Q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> T;
	
	while(T--){
		
		cin >> M >> N >> K;
	
		int x, y;
		for(int i = 0; i < K; ++i){
			cin >> x >> y;
			board[y][x] = 1;
		}

		int ans = 0;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < M; ++j){
				if(board[i][j] == 0) continue;

				board[i][j] = 0;
				Q.push({i,j});
				ans++;

				while(!Q.empty()){
					auto cur = Q.front(); Q.pop();

					for(int dir = 0; dir < 4; dir++){
						int nx = dx[dir] + cur.X;
						int ny = dy[dir] + cur.Y;

						if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
						if(board[ny][nx] == 0) continue;

						Q.push({ny,nx});
						board[ny][nx] = 0;
					}
					
				}

			}
		}

		cout << ans << '\n';
		
		for(int i = 0; i < N; ++i){
			fill(board[i], board[i]+M, 0);
		}
	}
	
	return 0;
}
