#include <bits/stdc++.h>

using namespace std;

int T;
int w, h; // 너비와 높이

string board[1001];

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> w >> h;
	
	for(int i = 0; i < h; ++i){
		cin >> board[i];
	}
	
	
	return 0;
}

/*
불이 옮겨진 칸, 불이 붙으려는 칸으로 이동할 수 없다.
얼마나 빨리 빌딩을 탈출할 수 있는지

. 빈공간
# 벽
@ 상근이의 시작 위치
* 불

불이 여러개..
불 bfs 먼저 돌리고
돌리면서 지금 값이 더 적으면 넣고

사람 bfs돌리고 
지금 값보다 적으면 움직이고
벽에 닿았으면 탈출


*/