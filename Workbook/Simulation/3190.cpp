#include <bits/stdc++.h>

using namespace std;

int N, K, L;
int Map[105][105];

pair<int, char> Move[105];

int ans = 0;

int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
// int d = (d < 0) ? 3 : d-1;


bool canGo(int y, int x){
	return (y < N && x < N && y > 0 && x > 0);
}

void start(){
	
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
	
	
	start();
	
		
	cout << '\n';
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << Map[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}

/*
지렁이를 저장하는 자료구죠?가 필요할 까?

지렁이 게임이 끝나는 탈출조건 먼저 생각

*/
