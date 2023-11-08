#include <bits/stdc++.h>

using namespace std;

int N, L;
int board[101][101];

bool canSetHighStair(int k){
	for(int i = 0; i < L; i++){
		if(board[k] != board[k - i]){				
			return false;
		}
	}
	return true;
}

bool canSetLowStair(int k){
	for(int i = 1; i <= L; i++){
		if(board[k] != board[k + i]){				
			return false;
		}
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
		for(int j = 0; j < N; j++){
			
			if(j == N-1){
				cout << "Can go" << '\n';
				break;
			}

			if(board[j] == board[j+1] + 1){
				if(!canSetHighStair(j)){
					break;
				}
			}else if(board[j] == board[j+1] - 1){
				if(!canSetLowStair(j)){
					break;
				}
			}else if(board[j] != board[j+1]){
				break;
			}
		}
	}
	

	
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