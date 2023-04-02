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
		
		for(int i = 1; i <= P; ++i){
			queue<tuple<int,int,int>> nextQ;
			while(!Q[i].empty()){
				// 아 너무 어렵다 
				//https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x09/solutions/16920.cpp
				//https://www.acmicpc.net/problem/16920
			}
		}
	}
	
	return 0;
}


/*
확장게임
라운드로 이루어짐
자기 턴이 돌아올 때마다 성을 확장해야 한다.
플레이어1확장->플레이어2확장

각 턴이 돌아왔을 때, 플레이어는 자신이 가지고 있는 성을 비어있는 칸으로 확장한다.
플레이어 i는 자신의 성이 있는 곳에서 Si칸 만큼 이동할 수 있는 모든 칸에 성을 동시에 만든다.

벽이나 다른 플레이어의 성이 있는 곳으로는 이동할 수 없다.
성을 다 건설한 이후엔 다음 플레이어가 턴을 갖는다

모든 플레이어가 더 이상 확장을 할 수 없을 때 게임이 끝난다.

게임판의 초기 상태가 주어졌을 때, 최종 상태를 구해보자

격자판의 크기 N,M 플레이어 수 P가 주어진다.

N개의 줄 게임판의 상태 .은 빈칸 #은 벽 1,2,3,...9는 각 플레이어의 성

플레이어 1이 가진 성의 수, 2가 가진 성의 수, P가 가진 성의 수를 공백으로 구분해 출력


3 3 2
1 1 <- ?뭘까

1..
...
..2

11.
1.2
.22

111
112
122

4 4 2
2 1

1..1
....
....
...2





*/