#include <bits/stdc++.h>

using namespace std;

int N, M, x, y, K;
int command;
int board[21][21];
int dice[7];
/*
	[1]
 [5][2][6]
	[3]
	[4]
*/

int idx[5][4] = {
	{}, // dummy
	{2,6,4,5}, // 동쪽 5->2, 2->6, 6->4, 4->5
	{2,5,4,6},
	{3,2,1,4},
	{2,3,1,4},
};

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M >> x >> y >> K;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> board[i][j];
		}
	}
	
	for(int i = 0; i < K; i++){
		cin >> cmd[i];
	}
	
	cout << '\n';
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';

	for(int i = 0; i < K; i++){
		cout << cmd[i] << ' ';
	}
	
	
	return 0;
}
