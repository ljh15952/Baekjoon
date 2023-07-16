#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

const int ROW = 12;
const int COL = 6;

char board[ROW][COL];
bool isvisited[ROW][COL];

int mx[4] = {0,1,0,-1};
int my[4] = {1,0,-1,0};

queue<pair<int,int>> Q;

bool isChain = false;

void gravity(){
	for(int i = ROW-1; i >= 0; i--){
		for(int j = COL-1; j >= 0; j--){
			if(board[i][j] == '.'){
				for(int k = 1; k <= i; k++){
					if(board[i - k][j] != '.'){
						swap(board[i][j], board[i - k][j]);
						break;
					}
				}
			}
		}
	}
}

void bfs(int y, int x){
	
	int ct = 0;
	
	Q.push({y,x});
	isvisited[y][x] = true;
	
	vector<pair<int,int>> vec;
	
	while(!Q.empty()){
		
		auto cur = Q.front(); Q.pop();
		vec.push_back({cur.Y, cur.X});
		
		for(int i = 0; i < 4; i++){
			int dx = mx[i] + cur.X;
			int dy = my[i] + cur.Y;
			
			if(dx < 0 || dy < 0 || dx >= COL || dy >= ROW)
				continue;
			if(board[cur.Y][cur.X] != board[dy][dx])
				continue;
			if(isvisited[dy][dx])
				continue;
			
			Q.push({dy,dx});
			isvisited[dy][dx] = true;
			ct++;
		}
		
	}
	
	if(ct >= 3){
		isChain = true;
		
		for(auto it : vec){
			board[it.Y][it.X] = '.';
		}
	}
	
}

bool checkPuyo(){
	
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			isvisited[i][j] = false;
		}
	}
	
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			if(board[i][j] != '.'){
				if(!isvisited[i][j]){
					bfs(i,j);
				}
			}
		}
	}
	
	return isChain;
}

int main(){
	
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			cin >> board[i][j];
		}
	}
	
	int ans = 0;
	while(checkPuyo()){
		ans++;
		gravity();
		isChain = false;
	}
	
	cout << ans << '\n';
	
	return 0;
}
