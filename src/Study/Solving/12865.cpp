#include <iostream>

#define endl "\n"
#define MAX 110
#define Max(A,B) (((A)>(B)) ? (A) : (B))

using namespace std;

int n,k;
int Weight[MAX];
int Value[MAX];
int DP[MAX][100010];


void Input(){
	cin >> n >> k;
	for(int i = 1; i <= n; ++i){
		cin >> Weight[i] >> Value[i];
	}
}

void Solution(){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= k; ++j){
			if (j >= Weight[i])    
				DP[i][j] = Max(DP[i - 1][j], DP[i - 1][j - Weight[i]] + Value[i]);
            else 
				DP[i][j] = DP[i - 1][j];
		}
	}
	cout << DP[n][k] << endl;
}

void Solve(){
	Input();
	Solution();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	Solve();
	
	return 0;
}
