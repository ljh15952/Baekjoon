#include <bits/stdc++.h>

using namespace std;

int N, L;
int board[101][101];
bool isStair[101];
int ans = 0;
bool canSetHighStair(int r, int k){
	for(int i = 0; i < L; i++){
		if(board[r][k] != board[r][k - i]){				
			return false;
		}
		if(isStair[k - i]){
			return false;
		}
		isStair[k - i] = true;
	}
	return true;
}

bool canSetLowStair(int r, int k){
	for(int i = 1; i <= L; i++){
		if(board[r][k] - 1 != board[r][k + i]){				
			return false;
		}
		if(isStair[k + i]){
			return false;
		}
		isStair[k + i] = true;
	}
	return true;
}

bool canSetHighStair2(int r, int k){
	for(int i = 0; i < L; i++){
		if(board[r][k] != board[r - i][k]){				
			return false;
		}
		if(isStair[r - i]){
			return false;
		}
		isStair[r - i] = true;
	}
	return true;
}

bool canSetLowStair2(int r, int k){
	for(int i = 1; i <= L; i++){
		if(board[r][k] - 1 != board[r + i][k]){				
			return false;
		}
		if(isStair[r + i]){
			return false;
		}
		isStair[r + i] = true;
	}
	return true;
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> L;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}
	
	for(int i = 0; i < N; i++){
		
		for(int k = 0; k < N; k++){
			isStair[k] = false;
		}
		
		for(int j = 0; j < N; j++){
			
			if(j == N-1){
				ans++;
				break;
			}
			
			if(board[i][j] + 1 == board[i][j+1]){
				if(!canSetHighStair(i, j)){
					break;
				}
			}else if(board[i][j] - 1 == board[i][j+1]){
				if(!canSetLowStair(i, j)){
					break;
				}
			}else if(board[i][j] != board[i][j+1]){
				break;
			}
		}
	}
	
	for(int j = 0; j < N; j++){
		
		for(int k = 0; k < N; k++){
			isStair[k] = false;
		}
		for(int i = 0; i < N; i++){
			
			if(i == N-1){
				ans++;
				break;
			}
			if(board[i][j] + 1 == board[i+1][j]){
				if(!canSetHighStair2(i ,j)){
					break;
				}
			}else if(board[i][j] - 1 == board[i+1][j]){
				if(!canSetLowStair2(i, j)){
					break;
				}
			}else if(board[i][j] != board[i+1][j]){
				break;
			}
		}
	}
	
	cout << ans << '\n';

	
	return 0;
}

/*

1. 가로 for문, 세로 for문 
4. 
case1 현재 i (값 v) 보다 i+1 위치한 수가 클(v+1) 경우
만약 L이 2라면 i, i-1이 v일 경우 can go
case2 현재 i 보다 i+1 위치한 수가 작을(v-1) 경우
만약 L이 2라면 i+1, i+2 가 v-1일 경우 can go

*/