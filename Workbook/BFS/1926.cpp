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
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> n; // 행 열
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> board[i][j];
		}
	}
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	
	
	
	return 0;
}