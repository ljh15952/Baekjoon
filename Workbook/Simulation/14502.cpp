#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int n, m;
int board[9][9];

int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};


int ans = 0;

void dfs(){
			
	int tempBoard[9][9];
	queue<pair<int, int>> Q;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			tempBoard[i][j] = board[i][j];
			if(board[i][j] == 2)
				Q.push({i, j});
		}
	}
	
	while(!Q.empty()){
		auto cur = Q.front(); 
		Q.pop();
		
		for(int i = 0; i < 4; i++){
			int dx = mx[i] + cur.X;
			int dy = my[i] + cur.Y;
			
			if(dx < 0 || dy < 0 || dx >= m || dy >= n)
				continue;
			if(tempBoard[dy][dx] == 1 || tempBoard[dy][dx] == 2)
				continue;
			tempBoard[dy][dx] = 2;
			Q.push({dy, dx});
		}
	}
	
	int ct = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(tempBoard[i][j] == 0)
				ct++;
		}
	}
	ans = max(ans, ct);
}

void backTracking(int k){
	
	if(k == 3){
		dfs();
		return;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == 0){
				
				board[i][j] = 1;
				backTracking(k+1);
				board[i][j] = 0;
				
				
			}
		}
	}
	
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}
	
	backTracking(0);
	cout << ans << '\n';
	return 0;
}

