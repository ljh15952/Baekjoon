#include <bits/stdc++.h>

using namespace std;

int n, m;
char board[13][13];

void print(){
	cout << '\n';
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

int ry, rx; // 빨간 구슬
int by, bx; // 파란 구슬
int hy, hx; // 구멍


void backTracking(){
	
}


int main(){
	
	ios::sync_with_stdio(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
		}
	}

	print();
	
	backTracking();
	
	return 0;
}

/*
계획

백트래킹을 해야함
현재 R이 움직일 수 있는 위치 판별
움직여 보고->R이 구멍빠지면 끝(바로 끝내면 안됨 B움직여보고), B가 구멍 빠지면 안되는 것
R이 지나간 길에 표시


*/

/*
구슬 탈출

직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 빼내는 게임

보드의 세로크기 N, 가로 크기 M
보드에는 구멍이 하나 있다.

빨간 구슬과 파란 구슬은 각각 하나씩 들어가 있다. 
파란 구슬이 구멍에 들어가면 안된다.

기울이기를 통해 구슬을 움직인다.
빨간 구슬과 파란 구슬 동시에 구멍에 빠져도 실패

기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지 

보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하라

. 빈칸
# 벽
O 구멍
R 빨간 구슬
B 파란 구슬

*/