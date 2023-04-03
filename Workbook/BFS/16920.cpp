#include <bits/stdc++.h>

using namespace std;

int canExtend[1000][1000];
int step[10];
int area[10];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

queue<tuple<int,int,int>> Q[10];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N,M,P;
	cin >> N >> M >> P;
	
	for(int i = 1; i <= P; ++i)
		cin >> step[i];
	
	// 맵 입력
	char ch;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cin >> ch;
			if(ch == '.') canExtend[i][j] = 1;
			else if(ch == '#') canExtend[i][j] = 0;
			else{
				canExtend[i][j] = 0;
				Q[ch - '0'].push({i,j,0});
				area[ch - '0'] += 1;
			}
		}
	}
	
	while(1){
		bool isExtend = 0;
		
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < M; ++j){
				cout << canExtend[i][j] << ' ';	
			}
			cout << '\n';
		}
		cout << '\n';
		
		for(int i = 1; i <= P; ++i){
			queue<tuple<int,int,int>> nextQ;
			while(!Q[i].empty()){
				int curx, cury, curstep;
				tie(curx, cury, curstep) = Q[i].front();
				Q[i].pop();
				if(curstep >= step[i]){
					nextQ.push({curx,cury,0});
					continue;
				}
				for(int dir = 0; dir < 4; ++dir){
					int x = curx + dx[dir];
					int y = cury + dy[dir];
					if(x < 0 || x >= N || y < 0 || y >= M) continue;
					if(canExtend[x][y] <= 0) continue;
					Q[i].push({x,y,curstep+1});
					canExtend[x][y] = -i;
					area[i]++;
					isExtend = 1;
				}
			}
			Q[i] = nextQ;
		}
		
		
		// 아무도 영토를 확장하지 못하여 게임이 끝났는지 확인
		if(!isExtend) break;
	}
	cout << '\n';
	for(int i = 1; i <= P; ++i)
		cout << area[i] << " ";
	cout << '\n';
	return 0;
}

/*
1..1
#.##
....
...2






*/