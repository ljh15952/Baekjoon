#include <bits/stdc++.h>

using namespace std;

int N, M;
int Room[10][10];

const int RIGHT = 0;
const int DOWN = 1;
const int LEFT = 2;
const int UP = 3;

int c1[4][2][8] = {
	// RIGHT 0
	{
		{1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0}
	},
	// DOWN 1
	{
		{0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1}
	},
	// LEFT 2
	{
		{-1,-1,-1,-1,-1,-1,-1,-1},
		{0,0,0,0,0,0,0,0}
	},
	// UP 3
	{
		{0,0,0,0,0,0,0,0},
		{-1,-1,-1,-1,-1,-1,-1,-1}
	}
};

bool isValid(int y, int x){
	return (x < 0 || x >= M || y < 0 || y >= N);
}
bool isWall(int y, int x){
	return (Room[y][x] == 6);
}
bool isCamera(int y, int x){
	return (Room[y][x] > 0 && Room[y][x] <= 5);
}

void setCamera(int angle, int y, int x, int n){
	for(int k = 0; k < 8; k++){
		x += c1[angle][0][k];
		y += c1[angle][1][k];
		if(isValid(y, x))
			continue;
		if(isWall(y,x))
			break;
		if(isCamera(y,x))
			continue;
		Room[y][x] = n;
	}
}

void c1Func(int angle, int y, int x, int n){
	if (angle == 0) {
		setCamera(RIGHT, y, x, n);
	} else if (angle == 1) {
		setCamera(DOWN, y, x, n);
	} else if (angle == 2) {
		setCamera(LEFT, y, x, n);
	} else if (angle == 3) {
		setCamera(UP, y, x, n);
	}
}

void c2Func(int angle, int y, int x, int n){
	if(angle == 0){
		setCamera(RIGHT,y,x, n);
		setCamera(LEFT,y,x, n);
	}else if(angle == 1){
		setCamera(DOWN,y,x, n);
		setCamera(UP,y,x, n);
	}
}

void c3Func(int angle, int y, int x, int n){
	if (angle == 0) {
		setCamera(UP, y, x, n);
		setCamera(RIGHT, y, x, n);
	} else if (angle == 1) {
		setCamera(RIGHT, y, x, n);
		setCamera(DOWN, y, x, n);
	} else if (angle == 2) {
		setCamera(DOWN, y, x, n);
		setCamera(LEFT, y, x, n);
	} else if (angle == 3) {
		setCamera(LEFT, y, x, n);
		setCamera(UP, y, x, n);
	}
}

void c4Func(int angle, int y, int x, int n){
	if (angle == 0) {
		setCamera(LEFT, y, x, n);
		setCamera(UP, y, x, n);
		setCamera(RIGHT, y, x, n);
	} else if (angle == 1) {
		setCamera(UP, y, x, n);
		setCamera(RIGHT, y, x, n);
		setCamera(DOWN, y, x, n);
	} else if (angle == 2) {
		setCamera(RIGHT, y, x, n);
		setCamera(DOWN, y, x, n);
		setCamera(LEFT, y, x, n);
	} else if (angle == 3) {
		setCamera(DOWN, y, x, n);
		setCamera(LEFT, y, x, n);
		setCamera(UP, y, x, n);
	}
}

void c5Func(int angle, int y, int x, int n){
	setCamera(LEFT,y,x, n);
	setCamera(UP,y,x, n);
	setCamera(RIGHT,y,x, n);
	setCamera(DOWN,y,x, n);
}

bool isused[10][10];
int ans = 999;

void solve1(int Y, int X){
	
	for(int i = Y; i < N; i++){
		for(int j = X; j < M; j++){
			
			if(isused[i][j])
				continue;
			
			if(Room[i][j] == 1){
				for(int a = 0; a < 4; a++){
					isused[i][j] = true;
					c1Func(a,i,j,9);
					solve1(i,j);
					c1Func(a,i,j,0);
					isused[i][j] = false;
				}
			}else if(Room[i][j] == 2){
				isused[i][j] = true;
				for(int a = 0; a < 2; a++){
					c2Func(a,i,j,9);
					solve1(i,j);
					c2Func(a,i,j,0);
				}
			}else if(Room[i][j] == 3){
				isused[i][j] = true;
				for(int a = 0; a < 4; a++){
					c3Func(a,i,j,9);
					solve1(i,j);
					c3Func(a,i,j,0);
				}
			}else if(Room[i][j] == 4){
				isused[i][j] = true;
				for(int a = 0; a < 4; a++){
					c4Func(a,i,j,9);
					solve1(i,j);
					c4Func(a,i,j,0);
				}
			}else if(Room[i][j] == 5){
				isused[i][j] = true;
				c5Func(0,i,j,9);
				solve1(i,j);
			}
			
		}
	}
	
	int tmp = 0;
	//cout << '\n';
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
		//	cout << Room[i][j] << ' ';
			if(Room[i][j] == 0)
				tmp++;
		}
		//cout << '\n';
	}
	//cout << '\n';
	
	ans = min(tmp,ans);
	
}
/*
4 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 5 0 6 0
0 0 0 0 0 0

*/
int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> Room[i][j];
		}
	}
	
	solve1(0,0);
	
	cout << ans << '\n';
	
	return 0;
}

/*
감시(삼성 SW역량테스트 A형 기출문제)
꼭 혼자서 풀어볼 것

스타트링크의 사무실은 1 x 1 크기의 정사각형으로 나누어져 있는 N x M 크기의 직사강형으로
나타낼 수 있다.
사무실에는 총 K개의 CCTV가 설치되어져 있는데, CCTV는 5가지의 종류가 있다.
각 CCTV가 감시할 수 있는 방법은 다음과 같다.
1. 오른쪽
2. 왼쪽, 오른쪽
3. 위, 오른쪽
4. 왼쪽, 위, 오른쪽
5. 왼쪽, 오른쪽, 위, 아래
CCTV는 감시할 수 있는 방향에 있는 칸 전체를 감시할 수 있다.
벽이 있는데 CCTV는 벽을 통과할 수 없다. -> 감시할 수 없는 영역은 사각지대라고 한다.

CCTV는 회전시킬 수 있는데, 회전은 항상 90도 방향으로 해야 하며, 
(감시하려고 하는 방향이 가로 또는 세로 방향이어야 한다)

지도에서 0은 빈칸 6은 벽, 1~5는 CCTV의 번호이다.
CCTV는 CCTV를 통과할 수 있다.

사무실의 크기와 상태, CCTV의 정보가 주어졌을 때, CCTV의 방향을 적절히 정해서
사각 지대의 최소 크기를 구하는 프로그램을 작성하시오.

*/