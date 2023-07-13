#include <bits/stdc++.h>

// #define Y first
// #define X second

using namespace std;

int N, M;
int board[55][55];

vector<pair<int,int>> houses;
vector<pair<int,int>> chickens;

void printBoard(){
	
	cout << '\n';
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	
}

int getDistance(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}

int getDistance(pair<int,int> h, vector<int,int> c){
	return abs(h.X - c.X) + abs(h.Y - c.Y);
}
/*
5 3
1 0 1 0 0
0 0 0 0 1
0 1 2 0 0
0 0 1 0 0
0 0 0 0 2
*/

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
			
			if(board[i][j] == 1){
				// 집
				houses.push_back({i, j});
			}else if(board[i][j] == 2){
				// 치킨집
				chickens.push_back({i, j});
			}
			
		}
	}
	
	auto h = houses[0];
	auto c = chickens[0];
	cout << h.first << '\n';
	//cout << getDistance(h, c) << '\n';

	//printBoard();
	
	return 0;
}

/*
M개 만큼 for문을 돈다면?
M개 치킨집 경우의 수 몇가지 나올라나 
하고 bfs 최소거리 구하는게 뭐더라 생각해보니깐 필요 없음

*/

/*
치킨 배달

크기가 NxN인 도시가 있다. 1x1 크기의 칸으로 나누어져 있다
도시의 각 칸은 빈 칸, 치킨집, 집 중 하나이다.

도시의 칸은 (r,c)와 같은 형태로 나타내고, r행 c열 또는 위에서부터
r번째 칸, 왼쪽에서부터 c번째 칸을 의미한다.
r과 c는 1부터 시작한다.

이 도시에 사는 사람들은 치킨을 매우 좋아한다.
따라서, 사람들은 "치킨 거리" 라는 말을 주로 사용한다.
치킨 거리는 집과 가장 가까운 치킨집 사이의 거리이다.

즉 치킨거리는 집을 기준으로 정해지며, 각각의 집은 치킨거리를 가지고 있다.
도시의 치킨 거리는 모든 집의 치킨 거리의 합이다

r1 c1과 r2 c2 사이의 거리는 |r2-r1| + |c2-c1| (두 점 사이의 거리)

일부 치킨집을 폐업시키려고 한다.
이 도시에서 가장 수익을 많이 낼 수 있는 치킨집의 개수는 최대 M개
수익을 가장 많이 낼 수 있는 치킨집의 개수는 최대 M개
어떻게 고르면 도시의 치킨 거리가 가장 될지 구하는 프로그램

*/