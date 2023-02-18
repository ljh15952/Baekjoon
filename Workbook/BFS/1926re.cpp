#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int n, m; //n행 m열
int board[502][502];
bool visited[502][502];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};



int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> board[i][j];
	
	
	int area = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(visited[i][j] == 1 || board[i][j] == 0) continue;
			queue<pair<int,int>> Q;
			Q.push({i,j});
			visited[i][j] = 1;
			area++;
			
			while(!Q.empty()){
				pair<int,int> cur = Q.front(); Q.pop();
				
				for(int dir = 0; dir < 4; ++dir){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					
					if(nx < 0 || nx >= m || ny < 0 || ny > n) continue;
					if(board[ny][nx] == 0 || 
						 visited[ny][nx] == 1) continue;
					
					visited[ny][nx] = 1;
					Q.push({ny, nx});
					
				}
				
			}
		}
	}
	
	cout << area << '\n';
	
	return 0;
}