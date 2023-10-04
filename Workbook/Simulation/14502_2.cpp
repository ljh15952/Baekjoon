#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int n, m;
int ans = 0;
int board[9][9];
int free_cells = 0;


int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};

queue<pair<int, int>> virus; // 바이러스
vector<pair<int, int>> frees; // 빈칸


int bfs(){
			
	queue<pair<int, int>> Q;
	bool vis[8][8] = {};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == 2)
				Q.push({i, j});
		}
	}
	
	int ret = 0;
	while(!Q.empty()){
		auto cur = Q.front(); 
		Q.pop();
		ret++;
		for(int i = 0; i < 4; i++){
			int dx = mx[i] + cur.X;
			int dy = my[i] + cur.Y;
			
			if(dx < 0 || dy < 0 || dx >= m || dy >= n)
				continue;
			if(board[dy][dx] != 0 || vis[dy][dx])
				continue;
			vis[dy][dx] = 1;
			Q.push({dy, dx});
		}
	}
	
	return ret;
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
			
			if(board[i][j] == 0){
				free_cells++;
				frees.push_back({i, j});
			}else if(board[i][j] == 2){
				virus.push({i ,j});
			}
		}
	}
	
	for(int i = 0; i < frees.size(); i++){
		board[frees[i].Y][frees[i].X] = 1;
		for(int j = i + 1; j < frees.size(); j++){
			board[frees[j].Y][frees[j].X] = 1;
			for(int k = j + 1; k < frees.size(); k++){
				board[frees[k].Y][frees[k].X] = 1;
				
				int tmp = bfs();
				
				ans = max(free_cells - 3 - tmp + (int)virus.size(), ans);
				board[frees[k].Y][frees[k].X] = 0;
			}
			board[frees[j].Y][frees[j].X] = 0;
		}
		board[frees[i].Y][frees[i].X] = 0;
	}
	
	cout << ans << '\n';
	return 0;
}

