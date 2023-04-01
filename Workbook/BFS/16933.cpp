#include <bits/stdc++.h>

using namespace std;

string board[1002];
// y,x,부순 횟수, 낮/밤 여부(낮=0, 밤 = 1)
int dist[1002][1002][12][2]; 

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M >> K;
	for(int i = 0; i < N; ++i)
		cin >> board[i];
	
	queue<tuple<int,int,int,int>> Q;
	dist[0][0][0][0] = 1;
	
	while(!Q.empty()){
		int x,y,z,w;
		tie(y,x,z,w) = Q.front(); Q.tie();
	}
	
	return 0;
}

/*
낮과 밤ㅋㅋ..
개어렵잔아

*/