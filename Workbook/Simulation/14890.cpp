#include <bits/stdc++.h>

using namespace std;

int N, L;
int board[101][101];

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> L;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
		}
	}
	
	

	
	return 0;
}

/*

1. 가로 for문, 세로 for문 
2. 시작할 때 원본배열 복사하여 새로운 배열 생성
3. 선형적으로 진행
4. 
case1 현재 i (값 v) 보다 i+1 위치한 수가 클(v+1) 경우
만약 L이 2라면 i, i-1이 v일 경우 can go
case2 현재 i 보다 i+1 위치한 수가 작을(v-1) 경우
만약 L이 2라면 i+1, i+2 가 v-1일 경우 can go

*/