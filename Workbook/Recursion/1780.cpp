#include <bits/stdc++.h>

using namespace std;

int N;
int board[2200][2200];


int cnt[3];

bool cheak(int x, int y, int n){
	for(int i = x; i < x + n; ++i){
		for(int j = y; j < y + n; ++j){
			if(board[x][y] != board[i][j])
				return false;
		}
	}
	return true;
}

void func(int x, int y, int z){
	
	if(cheak(x, y, z)){
		cnt[board[x][y]] += 1;
		return;
	}
	
	int n = z / 3;
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			func(x + i * n, y + j * n, n);
		}
	}
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> board[i][j];
			board[i][j]++;
		}
	}
	
	func(0, 0, N);

	for(int i = 0; i < 3; ++i) 
		cout << cnt[i] << '\n';
	
	return 0;
} 

/*
NxN 크기의 행렬로 표현되는 종이가 있다.
종이의 각 칸에는 -1,0,1 중 하나가 저장되어 있다.
우리는이 행렬을 다음과 같은 규칙에 따라 적절한 크기로 자르려고한다.

1. 만약 종이가 모두 같은 수로 되어있다면 이 종이를 그대로 사용한다.
2. (1)이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복. 

이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를
구하는 프로그램 작성

N입력
다음 N개의 줄 N개의 정수로 행렬이 주어진다

0 0 0  1 1 1  -1 -1 -1
0 0 0  1 1 1  -1 -1 -1
0 0 0  1 1 1  -1 -1 -1

1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0

0  1  -1  0  1  -1  0  1  -1

0  -1  1  0  1  -1  0  1  -1

0  1  -1  1  0  -1  0  1  -1

10 <- -1로만 채워진 종이의 개수
12 <- 0으로만 채워진 종이의 개수
11 <- 1로만 채워진 종이의 개수

*/