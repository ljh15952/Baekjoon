#include <bits/stdc++.h>

using namespace std;

int dmx[4] = {1,0,-1,0};
int dmy[4] = {0,1,0,-1};

int dkx[8] = {-2,-2,-1,-1,1,1,2,2};
int dky[8] = {1,-1,2,-2,2,-2,1,-1};

int board[201][201];
int vis[31][201][201];

queue<tuple<int,int,int>> Q;

int K, W, H;

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> K >> W >> H;
	
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			cin >> board[i][j];
		}
	}
	
	Q.push({0,0,0});
	vis[0][0][0] = 1;
	
	while(!Q.empty()){
		int vk,vx,vy;
		tie(vk,vy,vx) = Q.front(); Q.pop();
		
		if(vk < K){ // 점프할 수 있을 때
			for(int i = 0; i < 8; ++i){
				int nx = vx + dkx[i];
				int ny = vy + dky[i];
				
				if(nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
				if(board[ny][nx] == 1) continue;
				if(vis[vk + 1][ny][nx] > 0) continue; //이게 뭔지 잘 모르겠네
				
				vis[vk + 1][ny][nx] = vis[vk][vy][vx] + 1;
				Q.push({vk + 1, ny, nx});
			}
		}
		
		for(int i = 0; i < 4; ++i){
			int nx = vx + dmx[i];
			int ny = vy + dmy[i];
			
			if(nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
			if(board[ny][nx] == 1) continue;
			if(vis[vk][ny][nx] > 0) continue;
			
			vis[vk][ny][nx] = vis[vk][vy][vx] + 1;
			Q.push({vk, ny, nx});
		}
	}
	
	cout << '\n';
	for(int i = 0; i < H; ++i){
		for(int j = 0; j < W; ++j){
			cout << vis[0][i][j] << ' ';	
		}
		cout << '\n';
	}
			
	int ans = 0x7f7f7f7f;
  for (int i = 0; i < K + 1; i++){
    if(vis[i][H - 1][W - 1]) ans = min(ans, vis[i][H - 1][W - 1]);
	}
  if (ans != 0x7f7f7f7f) cout << ans - 1;
  else cout << -1;			
	
	return 0;
}

/*
말이 되고픈 원숭이

동물원에서 막 탈출한 원숭이 한 마리가 세상구경을 하고 있다.
말 같은 움직임을 함(나이트), 장애물을 뛰어넘을 수 있다.
원숭이는 능력이 부족해서 총 K번만 위와 같이 움직을 수 있다.
그 외에는 그냥 인접한 칸으로만 움직일 수 있다.(대각선X)

격자판 맨 왼족 위에서 시작해서 맨 오른쪽 아래까지 가야한다.
원숭이가 최소한의 동작으로 시작지점에서 도착지점까지 갈 수 있는 방법을
알아내는 프로그램

K 점프할 수 있는 횟수 
격자판의 가로길이 W, 세로길이 H가 주어진다.
0은 아무것도 없는 평지, 1은 장애물을 뜻한다.

1
4 4
0 0 0 0
1 0 0 0
0 0 1 0
0 1 0 0

-> 4



이것도 점프한 배열
안한 배열 이렇게 따로 해야될거같은데

*/