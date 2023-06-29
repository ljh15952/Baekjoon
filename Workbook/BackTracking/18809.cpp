#include <bits/stdc++.h>

#define TYPE first
#define TIME second

using namespace std;

int board[52][52];
int N, M;
int G, R;

int ans = 0;

pair<int,int> arr[52][52]; // TYPE, TIME
stack<pair<int,int>> st;

int mx[4] = {1,0,-1,0};
int my[4] = {0,-1,0,1};

const int WATER = -1;
const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

vector<int> maxAns;

void dfs(){
	if(st.empty())
		return;
	
	auto cur = st.top();
	st.pop();
	
	for(int i = 0; i < 4; i++){
		int dx = cur.second + mx[i];
		int dy = cur.first + my[i];
		
		if(dx < 0 || dy < 0 || dy >= N || dx >= M)
			continue;
		
		if(arr[dy][dx].TYPE == WATER)
			continue;
		else if(arr[dy][dx].TYPE == EMPTY){
			arr[dy][dx].TYPE = arr[cur.first][cur.second].TYPE;
			arr[dy][dx].TIME = arr[cur.first][cur.second].TIME + 1;
			st.push({dy,dx});
		}else if(arr[dy][dx].TYPE + arr[cur.first][cur.second].TYPE == 3 && 
				 arr[dy][dx].TIME == arr[cur.first][cur.second].TIME+1){
			arr[dy][dx].TYPE = FLOWER;
			ans++;
		}
	}
	
	dfs();
}

void func(int k, int g, int r){
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			
			if(board[i][j] == 2){
				if(arr[i][j].TYPE == GREEN || arr[i][j].TYPE == RED)
					continue;
				if(g < G){
					arr[i][j] = {GREEN,0};
					func(k+1, g+1, r);
				}
				if(r < R){
					arr[i][j] = {RED, 0};
					func(k+1, g, r+1);
				}
				arr[i][j] = {EMPTY,0};
				
			}else if(board[i][j] == 0){
				arr[i][j] = {WATER, 0};
			}else{
				arr[i][j] = {EMPTY, 0};
			}
			
		}
	}
	
	if(k == G+R){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(arr[i][j].TYPE > 0){
					st.push({i,j});
				}
			}
		}
		dfs();
		maxAns.push_back(ans);
		ans = 0;
	}
	
}
/*
2 2 1 1
2 1
2 0

*/

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M >> G >> R;
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cin >> board[i][j];
		}
	}
	
	func(0, 0, 0);
	
	cout << *max_element(maxAns.begin(), maxAns.end()) << '\n';
	
	return 0;
}

/*
꽃을 마을 소유의 정원에 피우려고 한다.
정원은 땅과 호수로 이루어져 있고 2차원 격자판 모양

사람이 직접 씨앗을 심는 대신
초록색 배양액과 빨간색 배양액을 땅에 적절하게
뿌려서 꽃을 피울 것이다. 이 때 배양액을 뿌릴 수 있는 땅은 미리 정해져있다.

배양액은 매 초마다 이전에 배양액이 도달한 적 없는 인접한 땅으로 퍼져간다.

배양액을 뿌릴 수 있는 땅에 백트래킹..
*/