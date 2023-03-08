#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

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
	
	queue<pair<int,int>> Q;
	int ct = 0;
	vector<int> size;
	
	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			if(board[i][j] > 0) continue;
			
			Q.push({i,j});
			board[i][j] = 2;
			ct++;
			
			int s = 0;
			while(!Q.empty()){
				auto cur = Q.front(); Q.pop();
				s++;
				for(int dir = 0; dir < 4; dir++){
					int nx = dx[dir] + cur.X;
					int ny = dy[dir] + cur.Y;
					
					if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
					if(board[ny][nx] > 0) continue;
					
					board[ny][nx] = 2;
					Q.push({ny,nx});
				}
			}
			size.push_back(s);
		}
	}

	cout << ct << '\n';
	
	sort(size.begin(), size.end());
	for(auto it : size){
		cout << it << ' ';
	}
	cout << '\n';
	
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