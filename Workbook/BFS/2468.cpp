#include <bits/stdc++.h>

using namespace std;

#define Y first
#define X second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int N;
int board[102][102];
int visited[102][102];


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	int maxNum = -999;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> board[i][j];
			maxNum = max(maxNum, board[i][j]);
		}
	}
	
	
	
	queue<pair<int,int>> Q;
	vector<int> nums;
	
	
	for(int k = 0; k <= maxNum; ++k){
		int num = 0;
		
		for(int v = 0; v < N; ++v) fill(visited[v], visited[v]+N, 0);
		
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				if(visited[i][j]) continue;
				if(board[i][j] <= k) continue;

				Q.push({i,j});
				visited[i][j] = 1;
				num++;

				while(!Q.empty()){
					auto cur = Q.front(); Q.pop();

					for(int dir = 0; dir < 4; dir++){
						int nx = dx[dir] + cur.X;
						int ny = dy[dir] + cur.Y;

						if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if(visited[ny][nx]) continue;
						if(board[ny][nx] <= k) continue;

						Q.push({ny,nx});
						visited[ny][nx] = 1;
					}
				}
			}
		}
		nums.push_back(num);
	}
	
	// for(auto it : nums){
	// 	cout << it << '\n';
	// }
	
	cout << *max_element(nums.begin(), nums.end()) << '\n';
	
	return 0;
}

/*
안전 영역
많은 비가 내리는 장마철에 대비해서 다음과 같은 일을 계획하고 있다.
어떤 지역의 늪이 정보를 파악한다.(?)
그 다음 그 지역에 많은 비가 내렸을 때 물에 잠기지 않는 안전한 영역이 
최대로 몇개가 만들어 지는 지를 조사하려고 한다.
문제를 간단히 하기 위해서 장마철에 내리는 비의 양에 따라 일정한 
높이 이하의 모든 지점은 물에 잠긴다고 가정

어떤 지역의 높이 정보든 행과 열의 크기가 각각 N인 2차원 배열 형태로 주어지며
배열의 각 원소는 해당 지점의 높이를 표시하는 자연수 이다

어떤 지역의 높이 정보가 주어졌을 때,
장마철에 물에 잠기지 않는 안전한 영역의
최대 개수를 계산하는 프로그램

*/