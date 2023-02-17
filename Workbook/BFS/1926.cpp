#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502];
bool vis[502][502];

int n, m; //n세로 크기 m가로 크기
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	
	cin >> n >> m; // 행 열
	
	for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> board[i][j];
  cout << board[0][0];
	
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		cin >> board[i][j];
	// 	}
	// }
	// cout << board[0][0];
	// queue<int> Q;
	// int maxSize = 0;
	// for(int i = 0; i < n; ++i){
	// 	for(int j = 0; j < m; ++j){
	// 		if(vis[i][j] != 1){
	// 			int size = 0;
				
				
				
	// 			maxSize = max(maxSize,size);
	// 		}
	// 	}
	// }
	
	
	
	return 0;
}