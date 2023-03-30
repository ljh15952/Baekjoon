#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

int N, X;

int board[MAX];
int prePos[MAX];

queue<int> Q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> X;
	
	Q.push(N);
	board[N] = 1;
	prePos[N] = N;	
	
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		
		for(int nx : { cur + 1, cur - 1, cur * 2}){
			if(nx < 0 || nx >= MAX) continue;
			if(board[nx] > 0) continue;
			
			board[nx] = board[cur] + 1;
			prePos[nx] = cur;
			Q.push(nx);
		}
	}
	
	
	cout << board[X] - 1 << '\n';
	
	deque<int> track = {X};
	while(track.front() != N){
		track.push_front(prePos[track.front()]);
	}
	for(int p : track) cout << p << ' ';
	
	return 0;
}

/*
숨바꼭질4

수빈, 동생 숨바꼭질
수빈 N, 동생 K
수빈 걷거나 순간이동
수빈이가 위치가 X일 떄 걸으면 1초 후에 X-1 또는 X+1로 이동
순간이동을 하는 경우에는 1초후에 2*X의 위치로 이동하게 된다.
동생을 찾을 수 있는 가장 빠른 시간이 몇 초인지 구하는 프로그램
어떻게 이동해야 하는지 공백으로 구분해 출력


-1, +1 1초 
2 x X 1초

시작점이 0인 경우
시작점과 종료점이 같을 경우

*/