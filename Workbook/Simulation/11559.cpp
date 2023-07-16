#include <bits/stdc++.h>
#define Y first
#define X second

using namespace std;

const int ROW = 12;
const int COL = 6;

char board[ROW][COL];

char tempBoard[ROW][COL];

bool isvisited[ROW][COL];

int mx[4] = {0,1,0,-1};
int my[4] = {1,0,-1,0};

queue<pair<int,int>> Q;

bool isChain = false;


void bfs(int y, int x){
	
	int ct = 0;
	
	Q.push({y,x});
	isvisited[y][x] = true;
	
	vector<pair<int,int>> vec;
	
	while(!Q.empty()){
		
		auto cur = Q.front(); Q.pop();
		vec.push_back({cur.Y, cur.X});
		
		for(int i = 0; i < 4; i++){
			int dx = mx[i] + cur.X;
			int dy = my[i] + cur.Y;
			
			if(dx < 0 || dy < 0 || dx >= COL || dy >= ROW)
				continue;
			if(board[cur.Y][cur.X] != board[dy][dx])
				continue;
			if(isvisited[dy][dx])
				continue;
			
			Q.push({dy,dx});
			isvisited[dy][dx] = true;
			ct++;
		}
		
	}
	
	if(ct >= 3){
		// 연쇄 성공
		isChain = true;
		
		for(auto it : vec){
			tempBoard[it.Y][it.X] = '.';
		}
		
		for(int i = ROW-1; i >= 0; i--){
			for(int j = COL-1; j >= 0; j--){
				if(tempBoard[i][j] != '.'){
					int dy = i;
					int dx = j;
					while(1){
						if(dy == ROW-1)
							break;
						if(tempBoard[dy+1][dx] != '.')
							break;

						swap(tempBoard[dy][dx], tempBoard[dy+1][dx]);
						dy = dy+1;
					}
				}
			}
		}
		
		
	}
	
}

bool checkPuyo(){
	
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			tempBoard[i][j] = board[i][j];
			isvisited[i][j] = false;
		}
	}
	
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			if(board[i][j] != '.'){
				if(!isvisited[i][j]){
					bfs(i,j);
				}
			}
		}
	}
	
	return isChain;
}

int main(){
	
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			cin >> board[i][j];
		}
	}
	
	int ans = 0;
	
	while(checkPuyo()){
		
		for(int i = 0; i < ROW; i++){
			for(int j = 0; j < COL; j++){
				board[i][j] = tempBoard[i][j];
			}
		}	
		ans++;
		isChain = false;
	}
	
	cout << ans << '\n';
	
	
	
	return 0;
}

/*
푸는 법
1. 뿌요만 일단 저장 <- 이건 좀 아닐듯 내려오는 뿌요 좌표가 바뀌니깐
2. 뿌요 재귀 돌면서 4개 이상 연결되어 있으면 저장해놨다가 삭제(모든 뿌요)
3. 내리기
4. 터지는게 없을 때 까지 반복
5. 몇번 반복 했는지 출력


*/

/*
뿌요뿌요 문제

룰

1. 필드에 여러 가지 색깔의 뿌요를 놓는다.
2. 뿌요는 중력의 영향을 받아 아래에 바닥이나 다른 뿌요가 나올 때 까지 아래로
3. 뿌요를 놓고 난 후, 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면
	연결된 같은 색 뿌요들이 한꺼번에 없어진다. 이때 1연쇄가 시작된다.
4. 뿌요들이 없어지고 나서 위에 다른 뿌요들이 있다면, 역시 중력의 영향을 받아
	차례대로 아래로 떨어지게 된다.
5. 아래로 떨어지고 나서 다시 같은 색의 뿌요들이 4개 이상 모이게 되면 또 터지게 되는데,
	터진 후 뿌요들이 내려오고 다시 터짐을 반복 할 때마다 1연쇄씩 늘어난다.
6. 터질 수 있는 뿌요가 여러 그룹이 있다면 동시에 터져야 하고
	여러 그룹이 터지더라도 한번의 연쇄가 추가된다.
	
상대방의 필드가 주여졌을 때, 연쇄가 몇 번 연속으로 일어날지 계산하자

12개의 줄에 필드의 정보가 주어진다.
각 줄에는 6개의 문자가 있다.
.은 빈공간 R, G, B, P, Y 5가지의 색
입력으로 주어지는 필드는 뿌요들이 전부 아래로 떨어진 뒤의 상태이다.

몇 연쇄가 되는지 출력한다. 하나도 터지지 않는다면 0을 출력한다.


*/