#include <bits/stdc++.h>

using namespace std;

int N, K;
int w[101];
int v[101];

int knap[101][100001];

void func(){
	
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= K; j++){
			
			if(w[i] > j)
				knap[i][j] = knap[i - 1][j];
			else{
				knap[i][j] = max(knap[i-1][j], v[i] + knap[i - 1][j - w[i]]);
			}
			
		}
	}
}


int main() {
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> K;
	
	for(int i = 1; i <= N; i++){
		cin >> w[i];
		cin >> v[i];
	}
	
	func();
	
	cout << knap[N][K] << '\n';
	
    return 0;
}