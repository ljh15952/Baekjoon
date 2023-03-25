#include <bits/stdc++.h>

using namespace std;

int board[100001];
int N, K; // 수빈, 동생

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
    
	cin >> N >> K;
	
	fill(board, board + K + 1, -1); 
	// 마지막값에서 -1로 이동하여 찾는 수밖에 없으니
	// 필요한 배열의 크기는 K + 1 이다.
	
	board[N] = 0;
	
	queue<int> Q;
	Q.push(N);
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		
		if(board[cur + 1] != -1 || cur + 1 < K + 1){
			Q.push(cur + 1);
			board[cur + 1] = board[cur] + 1;
		} 
		if(cur > 0board[cur - 1] != -1 || ){
			Q.push(cur - 1);
			board[cur - 1] = board[cur] + 1;
		}
		if(board[cur * 2] != -1 || cur * 2 < K + 1){
			Q.push(cur * 2);
			board[cur * 2] = 0;
		}
	}
	
	for(int i = 0; i < K + 1; ++i){
		cout << board[i] << ' ';
	}
		
		
		    
  return 0;
}

/*
N 큐에 넣고
10만보다 작은 N*2의 값 0초니깐 다 큐에 넣음


*/

/*
숨바꼭질

수빈이의 점 N 
동생의 점 K

수빈이는 걷거나 순간이동? 을 할 수 있다?
수빈이의 위치가 X일 때 걸으면 1초 후에 X-1 또는 X+1로 이동하게 된다.
순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램

5 17

5 (0초) 10 (1초) 9 (0초) 18 (1초) 17
총 2초..
어려운데
순간이동은 무조건 앞으로만 가네

*/
