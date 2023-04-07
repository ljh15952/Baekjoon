#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int board[7][7] = {
	{0,0,0,1,0,0,0},
	{1,0,0,1,0,0,0},
	{1,0,0,1,0,0,1},
	{1,1,1,1,1,1,1},
	{1,0,0,1,0,1,0},
	{0,0,0,1,0,0,0},
	{0,0,0,1,0,0,0}
};
bool vis[7][7];

stack<pair<int,int>> S;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	S.push({3,3});
	vis[3][3] = true;
	
	int num = 1;
	
	while(!S.empty()){
		auto cur = S.top(); S.pop();
		
		board[cur.Y][cur.X] = num++;
		
		for(int i = 0; i < 4; ++i){
			int nx = dx[i] + cur.X;
			int ny = dy[i] + cur.Y;
			
			if(nx < 0 || ny < 0 || nx >= 7 || ny >= 7) continue;
			if(board[ny][nx] == 0) continue;
			if(vis[ny][nx] == true) continue;
			
			vis[ny][nx] = true;
			S.push({ny,nx});
		}
	}
	
	for(int i = 0; i < 7; ++i){
		for(int j = 0; j < 7; ++j){
			printf("%d\t",board[i][j]);
		}
		printf("\n");
	}
	
		
	
	return 0;
}