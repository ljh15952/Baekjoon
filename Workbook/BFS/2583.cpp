#include <bits/stdc++.h>

using namespace std;


int M, N, K;

int board[100][100];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> M >> N >> K;
	
	for(int i = 0; i < K; ++i){
		int x1, y1;
		int x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for(int y = y1; y < y2; ++y){
			for(int x = x1; x < x2; ++x){
				board[y][x] = 1;
			}
		}
	}
	
	/*
		0 0 0 0 1 1 0
		0 1 0 0 1 1 0
		1 1 1 1 0 0 0
		1 1 1 1 0 0 0
		0 1 0 0 0 0 0
	
	
	*/
	
	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	
	
	return 0;
}

/*
영역 구하기
MxN 크기의 모눈종이가 있다

k개의 직사각형을 그림
직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.
M세로 N가로
몇 개의 분리된 영역으로 나누어 지는지
분리된 영역의 넓이
출력




*/