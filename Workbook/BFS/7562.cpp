#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int dx[8] = {-2,-1,1,2,2,1,-1,-2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int board[300][300];

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int I;
		cin >> I;
	
		for(int i = 0; i < I; ++i) fill(board[i], board[i] + I, -1);
		
		int kx, ky;
		cin >> ky >> kx;

		int tx, ty;
		cin >> ty >> tx;

		queue<pair<int,int>> Q;
		Q.push({ky, kx});
		board[ky][kx] = 0;
		while(!Q.empty()){
			auto cur = Q.front(); Q.pop();

			for(int i = 0; i < 8; ++i){
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];

				if(ny < 0 || nx < 0 || nx >= I || ny >= I) continue;
				if(board[ny][nx] >= 0) continue;
				board[ny][nx] = board[cur.Y][cur.X] + 1;
				Q.push({ny,nx});
			}
		}
		cout << board[ty][tx] << '\n';
	}
	
	return 0;
}

/*
나이트의 이동

나이트가 이동하려고 하는 칸이 주어진다.
나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까

테스트 케이스의 개수가 주어짐
각 케이스는 세 줄로 이루어져 있다.
체스판의 한 변의 길이 4<=I<=300
크기는 IxI 
둘째 줄과 셋째줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어짐

K * * * * * * *
* * * * * * * *
* 1 * * * * * *
* * * * * * * *
* * 2 * * * * *
* 4 * * * * * *
* * * 3 * * * *
5 * * * * * * *

*/