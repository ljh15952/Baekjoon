#include <bits/stdc++.h> 

using namespace std;

int F, S, G, U, D;

int board[1000002];

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> F >> S >> G >> U >> D;
	
	fill(board+1, board+F+1, -1);
	queue<int> Q;
	
	Q.push(S);
	board[S] = 0;
	
	int dx[2] = {U, -D};
	
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		
		for(int i = 0; i < 2; ++i){
			int nx = cur + dx[i];
			
			if(nx <= 0 || nx > F || board[nx] != -1) continue;
			
			board[nx] = board[cur] + 1;
			Q.push(nx);
		}
	}
	
	if(board[G] == -1) 	cout << "use the stairs\n";
	else cout << board[G] << '\n';
	
	
	// for(int i = 1; i <= F; ++i){
	// 	cout << i << "층 " << board[i] << '\n';
	// }
	
	return 0;
}

/*
총 F층으로 이루어진 고층 건물에 사무실
스타트링크가 있는 곳의 위치는 G층
강호가 있는 곳은 S층
이제 엘리베이터를 타고 G층으로 이동한다.

강호가 탄 엘리베이터는 버튼이 2개밖에 없다
U버튼은 위로 U층을 가는 버튼, D버튼은 아래로 D층을 가는 버튼
만약 U층 위, D층 아래에 해당하는 층이 없을 때는 엘리베이터 움직이지 않음

강호가 G층에 도착하려면 버튼을 적어도 몇 번 눌러야 하는지 구하는 프로그램
엘리베이터로 이동할 수 없을 때는 use the stairs를 출력한다.

F, S, G, U, D 
10 1 10 2 1
1 -> 3 -> 5 -> 7 -> 9 -> 8 -> 10
6번

*/