#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

bool ladder[32][12];
int idxs[3];

vector<pair<int, int>> coords;

int n, m, h;

bool check(){
	
	for(int j = 1; j <= n; j++){
		int cur = j;
		for(int i = 1; i <= h; i++){
			if(ladder[i][cur - 1]) cur--;
			else if(ladder[i][cur]) cur++;
		}
		if(cur != j) return false;
	}
	return true;
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> h;
	
	while(m--){
		int a, b;
		cin >> a >> b;
		ladder[a][b] = true;
	}
	
	for(int i = 1; i <= h; i++){
		for(int j = 1; j < n; j++){
			if(ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1]) continue;
			coords.push_back({i, j});
		}
	}
	
	if(check()){
		cout << 0;
		return 0;
	}
	
	int ans = 0x7f7f7f7f;
	int sz = coords.size();
	
	for(int i = 0; i < sz; i++){
		ladder[coords[i].X][coords[i].Y] = true;
		if(check()) ans = min(ans, 1);
		for(int j = i+1; j < sz; j++){
			ladder[coords[j].X][coords[j].Y] = true;
			if(check()) ans = min(ans, 2);
		  	for(int k = j+1; k < sz; k++){
				ladder[coords[k].X][coords[k].Y] = true;
				if(check()) ans = min(ans, 3);
				ladder[coords[k].X][coords[k].Y] = false;
		  	}
			ladder[coords[j].X][coords[j].Y] = false;
		}
		ladder[coords[i].X][coords[i].Y] = false;
	}
	if(ans == 0x7f7f7f7f) ans = -1;
	cout << ans;
	
	return 0;
}

/*
사다리 조작

N개의 세로선
M개의 가로선으로 이루어진 사다리 게임

인접한 세로선 사이에 가로선을 놓을 수 있다.
각각의 세로선마다 가로선을 놓을 수 있는 위치의 개수는 H
모든 세로선이 같은 위치를 갖는다.
두 가로선이 연속하거나 서로 접하면 안된다.

사다리 게임은 각각의 세로선마다 게임을 진행
세로선의 가장 위에서부터 아래 방향으로 내려가야한다.
이때 가로선을 만나면 가로선을 이용해 옆 세로선으로 이동한 다음
이동한 세로선에서 아래 방향으로 이동해야 한다.

사다리에 가로선을 추가해서 사다리 게임의 결과를 조작하려고 한다.
이때 i번 세로선의 결과가 i번이 나와야 한다.
그렇게 하기 위해서 추가해야 하는 가로선 개수의 최솟값을 구하는 프로그램을 작성

입력
N, M, H
세로선 개수 N, 
가로선 개수 M, 
세로선마다 가로선을 놓을 수 있는 위치의 개수 H

둘째 줄부터 M개의 줄 가로선의 정보가 한 줄에 하나씩
가로선의 정보는 두 정수 a와 b로 나타낸다
b번 세로선과 b+1번 세로선을 a번 점선 위치에서 연결했다는의미

가장 위에 있는 점선의 번호는 1, 아래로 내려갈 때마다 1이 증가한다
세로선은 가장 왼쪽에 있는 것의 번호가 1번이고, 오른쪽으로 갈 때마다 1이 증가

출력
정답이 3보다 큰 값이면 -1을 출력한다.
불가능한 경우에도 -1을 출력한다.

*/