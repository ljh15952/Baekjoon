#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

vector<pair<int,int>> v;
bool cheak[25];

char arr[5][5];

int ans = 0;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool dfs(){
	// Cheak is near
	bool flag[7] = {false, };
	
	queue<pair<int,int>> q;
	q.push({v[0].X, v[0].Y});
	flag[0] = true;
	
	int cnt = 1;
	
	while(!q.empty()){
		int cx = q.front().X;
		int cy = q.front().Y;
		q.pop();
		
		for(int k = 1; k < 7; k++){
			if(flag[k]) continue;
			for(int i = 0; i < 4; i++){
				int nx = cx + dx[i];
				int ny = cy + dy[i];
				if(nx == v[k].X && ny == v[k].Y){
					q.push({nx,ny});
					flag[k] = true;
					cnt++;
				}
			}
		}
		
	}
	
	return (cnt == 7);
}

void func(int k, int Y, int S){
	
	if(v.size() == 7){
		if(Y > S) return;
		if(dfs())
			ans++;
		return;
	}
	
	for(int i = k; i < 25; i++){
		if(cheak[i])
			continue;
		
		int y = i / 5;
		int x = i % 5;
		
		v.push_back({x,y});
		cheak[i] = true;
		
		if(arr[y][x] == 'Y')
			func(i+1,Y+1,S);
		else
			func(i+1,Y,S+1);

		
		v.pop_back();
		cheak[i] = false;
	}
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cin >> arr[i][j];
		}
	}
	
	func(0,0,0);
	
	cout << ans << '\n';
	
	return 0;
	
}