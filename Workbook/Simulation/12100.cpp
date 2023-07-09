#include <bits/stdc++.h>

using namespace std;

const int LEFT = 0;
const int UP = 1;
const int RIGHT = 2;
const int DOWN = 3;

int N;
int board[25][25];
int mx[4] = {-1,0,1,0};
int my[4] = {0,-1,0,1};
int ans = 0;
bool isMerge[25][25];

bool OOB(int y, int x){
	return (y < 0 || x < 0 || y >= N || x >= N);
}

void go(int y, int x, int dir, int arr[][25]){
	
	int dx = x;
	int dy = y;
	
	while(1){
		dx += mx[dir];
		dy += my[dir];
		
		if(OOB(dy, dx)){
			break;
		}
		
		if(arr[dy][dx] == 0){
			swap(arr[dy][dx], arr[y][x]);
			x = dx;
			y = dy;
		}else if(arr[dy][dx] == arr[y][x]){
			if(isMerge[dy][dx])
				break;
			arr[dy][dx] *= 2;
			arr[y][x] = 0;
			isMerge[dy][dx] = true;
			break;
		}else if(arr[dy][dx] != arr[y][x]){
			break;
		}
	}
}

void mergeBloack(int dir, int arr[][25]){
	
	if(dir == LEFT || dir == UP){
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				if(arr[i][j] != 0)
					go(i, j, dir, arr);
	}else if(dir == RIGHT || dir == DOWN){
		for(int i = N - 1; i >= 0; i--)
			for(int j = N - 1; j >= 0; j--)
				if(arr[i][j] != 0)
					go(i, j, dir, arr);
	}
}

void backTracking(int dir, int ct, int arr[][25]){
	
	if(ct == 5){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				ans = max(ans, arr[i][j]);
			}
		}
		return;
	}
	
	for(int i = 0; i < 4; i++){
		int tempArr[25][25];
	
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				tempArr[i][j] = arr[i][j];	
			}
		}
		
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				isMerge[i][j] = false;
			}
		}
		mergeBloack(i, tempArr);
		backTracking(i, ct+1, tempArr);
	}
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}
	
	backTracking(LEFT, 0, board);
	
	cout << ans << '\n';
	
	return 0;
}