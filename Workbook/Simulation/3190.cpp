#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int N, K, L;
int Map[105][105];

pair<int, char> Move[105];

int ans = 0;

int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
int d = 0;
int m = 0;
// int d = (d < 0) ? 3 : d-1;

deque<pair<int, int>> dq;

void printMap(){
	cout << '\n';
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << Map[i][j] << ' ';
		}
		cout << '\n';
	}
}

void start(){
	while(1){
		
		auto cur = dq.front();
		Map[cur.Y][cur.X] = 2;
		ans++;

		int nx = cur.X + mx[d];
		int ny = cur.Y + my[d];
		
		if(nx < 1 || nx > N || ny < 1 || ny > N)
			break;
		if(Map[ny][nx] == 2)
			break;
		
		if(Map[ny][nx] != 1){
			auto tail = dq.back();
			Map[tail.Y][tail.X] = 0;
			dq.pop_back();
		}
		
		if(ans == Move[m].Y){
			if(Move[m].X == 'D'){
				d = (d+1 > 3) ? 0 : d+1;
			}else{
				d = (d-1 < 0) ? 3 : d-1;
			}
			m++;
		}
		
		dq.push_front({ny, nx});
	}
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> K;
	
	for(int i = 0; i < K; i++){
		int y, x;
		cin >> y >> x;
		Map[y][x] = 1;
	}
	
	cin >> L;
	for(int i = 0; i < L; i++){
		int x;
		char c;
		cin >> x >> c;
		Move[i] = {x, c};
	}
	
	dq.push_front({1,1});
	start();
	
	cout << ans << '\n';
		

	return 0;
}

/*
지렁이를 저장하는 자료구죠?가 필요할 까?

지렁이 게임이 끝나는 탈출조건 먼저 생각

*/
