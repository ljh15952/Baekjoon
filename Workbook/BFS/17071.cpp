#include <bits/stdc++.h>

using namespace std;

int N, M;

int speed = 1;

#define MAX 500001
int board[MAX];

queue<int> Q;

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	board[N] = 1;
	Q.push(N);
	
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		
		for(int nv : {2 * cur, cur + 1, cur - 1}){
			if(nv < 0 || nv > MAX) continue;
			if(board[nv] > 0) continue;
			
			board[nv] = board[cur] + 1;

			if(nv == M){
				cout << board[nv] - 1 << '\n';
				return 0;
			}
			
			Q.push(nv);
		}
		M += speed++;
	}
	
	// for(int i = 0; i < 20; ++i){
	// 	cout << i << ": " << board[i]-1 << '\n';
	// }
	
	//
	
	
	return 0;
}

/*
시간제한이 개 빡센데요?

숨바꼭질
또 수빈이는 동생과 숨바꼭질을 한다.
수빈 점 (0 <= N <= 500000)
동생 점 (0 <= K <= 500000)
수빈이 걷기 1초 후 x-1, x+1
순간이동 1초 후 2*x의 위치 이동
동생은 항상 걷기만 매 초마다 이동을 하며 가속(?)이 붙는다.
동생이 이동하는 거리는 이전에 이동한 거리보다 1을 더한 만큼 이동한다.
K, K+1, K+1+2, K+1+2+3
수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램
수빈이 0보다 작은 좌표, 50만보다 큰 좌표 이동 불가 -> -1출력

5 17
10 18
20 20 찾음! 2초

*/