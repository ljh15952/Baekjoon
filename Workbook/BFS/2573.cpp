#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N, M;

int board[300][300];
int vis[300][300];

int year = 0;


bool OOB(int y, int x){
	return (x < 0 || y < 0 || x >= M || y >= N);
}

void melting(){
	int zero[303][303] = {0,};
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			if(board[i][j] == 0) continue;
			for(int dir = 0; dir < 4; ++dir){
				int nx = j + dx[dir];
				int ny = i + dy[dir];
				if(OOB(ny,nx) || board[ny][nx] > 0) continue;
				zero[i][j]++;
			}
		}
	}
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			board[i][j] = max(0, board[i][j] - zero[i][j]);	
		}
	}
}

int BFS(){
	int ct = 0;
	queue<pair<int,int>> Q;
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			if(board[i][j] == 0 || vis[i][j]) continue;
			
			Q.push({i,j});
			ct++;
			
			while(!Q.empty()){
				auto cur = Q.front(); Q.pop();
				
				for(int dir = 0; dir < 4; dir++){
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					
					if(OOB(ny,nx) || board[ny][nx] == 0) continue;
					if(vis[ny][nx] == 1) continue;
					
					vis[ny][nx] = 1;
					Q.push({ny,nx});
				}
			}
		}
	}
	return ct;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M; // N행 M열
	
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < M; ++j)
			cin >> board[i][j];
	
	while(1){
		year++;
		melting();
		for(int i = 0; i < N; ++i) fill(vis[i], vis[i] + M, 0);
		
		int ct = BFS(); // BFS함수에서 땅 덩이의 개수 반환
		if(ct >= 2){
			cout << year << '\n';
			return 0;
		}else if(ct == 0){
			cout << "0\n";
			return 0;
		}
		
	}
	
	return 0;
}
/*
0 0 0 0 0 0 0
0 1 4 5 3 0 0
0 3 0 1 5 1 0
0 7 6 1 4 0 0
0 0 0 0 0 0 0

0 2 3
1 3 4

*/
/*
빙산
지구 온난화로 북극의 빙산이 녹고 있다.
빙산을 2차원 배열로 표시함
빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다.
빙산 이외의 바다에 해당되는 칸에는 0이 저장된다.

빙산의 높이는 바닷물에 많이 접해있는 부분에서 더 빨리 줄어듬
빙산의 칸의 높이는 일년마다 그 칸에 동서남북 네 방향으로 붙어있는
0이 저장된 칸의 개수만큼 줄어든다.
0보다 줄어들지는 않음

한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로
분리되는 최초의 시간(년)을 구하는 프로그램 작성
전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면
0을 출력


*/