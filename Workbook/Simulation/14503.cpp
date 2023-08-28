#include <bits/stdc++.h>

using namespace std;

int N, M;
int r, c, d; // d 0북 1 동 2 남 3 서
int Map[55][55]; // 0 청소X 1 벽  2 청소 O

int mx[4] = {0, 1, 0, -1};
int my[4] = {-1, 0, 1, 0};

int ans = 0;

void Cleaning(){
	
	while(1){
		
		if(Map[r][c] == 0){
			Map[r][c] = 2; 
			ans++;
		}
		
		bool isAllClean = true;
		
		for(int i = 0; i < 4; i++){
			int dx = c + mx[i];
			int dy = r + my[i];
			
			if(Map[dy][dx] == 0)
				isAllClean = false;
		}
		
		if(isAllClean){
			
			int tmp = d;
			
			int dx = c - mx[tmp];
			int dy = r - my[tmp];
			
			if(Map[dy][dx] == 1)
				return;
			else{
				r = dy;
				c = dx;
			}
			
		}else{
			
			for(int i = 0; i < 4; i++){
				
				d = (d-1 < 0) ? 3 : d-1;
				
				int dx = c + mx[d];
				int dy = r + my[d];
				
				if(Map[dy][dx] == 0){
					r = dy;
					c = dx;
					break;
				}
				
			}
			
		}
		
	}
	
	
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	cin >> r >> c >> d;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> Map[i][j];
		}
	}
	
	Cleaning();
	
	cout << ans << '\n';
	
	return 0;
}

/*
1. r,c 청소를 함
2. 현재 칸 주변 4칸 청소 되있는 지 확인
	2-1 전부 되있으면 바라보는 방향 유지한 채 한칸 후진
		3-1 후진 할 수 없다면 작동 중지
	2-2 전부 되있지 않다면
		3-1 반시계 방향 90도 회전
			4-1 앞쪽 칸 청소 되있는지 확인
				5-1 되있을 경우 3-1로
				5-2 되있지 않을 경우 한 칸 전진
					1로

*/

/*
로봇 청소기

로봇 청소기와 방의 상태가 주어졌을 때, 청소하는 영역으 개수를 구하는 프로그램

NxM 크기의 직사각형
각각의 칸은 벽 또는 빈칸
청소기의 바라보는 방향 (동, 서, 남, 북)
각 칸은 좌표 (r,c)

로봇청소기 작동
1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
	바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
	바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있을 경우
	1. 반시계 방향으로 90도 회전한다.
	2. 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
	3. 1번으로 돌아간다.



*/