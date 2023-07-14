#include <bits/stdc++.h>

#define Y first
#define X second

using namespace std;

int N, M;
int board[55][55];

vector<pair<int,int>> houses;
vector<pair<int,int>> chickens;
vector<pair<int,int>> selectChicken;

int ans = 9999;

template <typename T>
int getDistance(T h, T c){
	return abs(h.X - c.X) + abs(h.Y - c.Y);
}


int getChickenRoad(){
	
	int tot = 0;
	
	for(int i = 0; i < houses.size(); i++){
		
		int num = 9999;
		for(auto it : selectChicken){
			num = min(num, getDistance(it, houses[i]));
		}
		tot += num;
	}
	return tot;
}

void backTracking(int st){
	
	if(selectChicken.size() >= M){
		ans = min(ans, getChickenRoad());
		return;
	}
	
	for(int i = st; i < chickens.size(); i++){
		selectChicken.push_back(chickens[i]);
		backTracking(i+1);
		selectChicken.pop_back();
	}
	
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> board[i][j];
			
			if(board[i][j] == 1){
				houses.push_back({i, j});
			}else if(board[i][j] == 2){
				chickens.push_back({i, j});
			}
			
		}
	}
	
	backTracking(0);
	
	cout << ans << '\n';
	
	return 0;
}