#include <bits/stdc++.h>

using namespace std;

int N;

int queenMove[][];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin << N;
	
	return 0;
}


/*
N-Queen

NxN 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제
퀸을 놓는 방법의 수를 구해라 
(1<=N<=15)

1. board[0][0]
2. board[0][0] 퀸의 움직임 만큼 배제
3. 다음 가능한 곳 놓기 board[1][1]
4. board[1][1] 퀸의 움직임 만큼 배제
5. 다음 가능한 곳 놓기
..
다 놨으면
대충 감오는데
*/