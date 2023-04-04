#include <bits/stdc++.h>

using namespace std;

#define Y first 
#define X second 

int N, M;

int board[101][101];
bool vis[101][101];
vector<pair<int,int>> adj[101][101];

queue<pair<int,int>> Q;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool is_conn(pair<int,int> nxt){
	for(int i = 0; i < 4; ++i){
		int nx = nxt.X + dx[i];
		int ny = nxt.Y + dy[i];
		if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
		if(vis[ny][nx]) return 1;
	}
	return 0;
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < M; ++i){
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		adj[y][x].push_back({b,a});
	}
	
	Q.push({1,1});
	board[1][1] = 1;	
	vis[1][1] = true;
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		
		for(auto it : adj[cur.Y][cur.X]){
			if(vis[it.Y][it.X]) continue;
			if(is_conn(it)){
				vis[it.Y][it.X] = 1;
				Q.push({it.Y,it.X});
			}
			board[it.Y][it.X] = 1;
		}
		
		for(int i = 0; i < 4; ++i){
			int nx = dx[i] + cur.X;
			int ny = dy[i] + cur.Y;
			
			if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
			if(vis[ny][nx]) continue;
			if(board[ny][nx] == 0) continue;
			vis[ny][nx] = true;
			Q.push({ny,nx});
		}
	}
	int ans = 0;
 	for (int i = 1; i <= N; i++)
    	for (int j = 1; j <= N; j++) ans += board[i][j];
	cout << ans << '\n';
		
	return 0;
}

/*
3 6
1 1 1 2
2 1 2 2
1 1 1 3
2 3 3 1
1 3 1 2
1 3 2 1

x x x x
x 1 1 0
x 1 1 0
x 1 0 0


*/


/*
불 켜기
농부 존
NxN개의 방이 있는 거대한 헛간을 새로 지음
(1,1)부터 (N,N)까지 번호가 매겨져있음 (2 <= N <= 100)
어둠을 무서워하는 암소 베시는 최대한 많은 방에 불을 밝히고 싶어함

베시는 유일하게 불이 켜져있는 방인 (1,1)방에서 출발
어떤 방에는 다른 방의 불을 끄고 켤 수 있는 스위치가 달려있다(?)
(1,1)방에 있는 스위치로 (1,2)방의 불을 쓰고 켤 수 있다.
베시는 불이 켜져있는 방으로만 들어갈 수 있고, 각 방에서는 상하좌우에 인접한 방으로 움직일 수 있다.
베시가 불을 켤 수 있는 방의 최대 개수를 구하시오

*/