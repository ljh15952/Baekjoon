#include <bits/stdc++.h>

#define Y first
#define X second

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

template <typename T>
int getDistance(T h, T c){
	return abs(h.X - c.X) + abs(h.Y - c.Y);
}

/*
5 2
2 0 1 0 0
2 0 1 0 1
2 1 1 0 0
0 0 1 0 0
0 0 0 0 1
*/

vector<pair<int,int>> selectChicken;

void backTracking(int st){
	
	if(selectChicken.size() >= M){
		
		return;
	}
	
	for(int i = st; i < chickens.size(); i++){
		selectChicken.push_back(chickens[i]);
		backTracking(i+1);
		selectChicken.pop_back();
	}
	
}

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
	//cout << getDistance(h, c) << '\n';

	//printBoard();
	
	backTracking(0);
	
	return 0;
}