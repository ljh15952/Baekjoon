#include <iostream>
#include <algorithm>

using namespace std;

int buf[2][100000];
int dp[2][100000];


int main(){
	
	int t;
	cin >> t;
	
	for(int k = 0; k < t; ++k){
		int n;
		cin >> n;

		int score;
		for(int i = 0; i < 2; ++i){
			for(int j = 0; j < n; ++j){
				scanf("%d",&buf[i][j]);
			}
		}

		dp[0][0] = buf[0][0];
		dp[1][0] = buf[1][0];
		dp[0][1] = buf[0][1] + dp[1][0];
		dp[1][1] = buf[1][1] + dp[0][0];

		for (int i = 2; i < n; i++) {
			dp[0][i] = buf[0][i] + max(dp[1][i-1],dp[1][i-2]);
			dp[1][i] = buf[1][i] + max(dp[0][i-1],dp[0][i-2]);
		}

		cout << max(dp[0][n-1],dp[1][n-1]) << endl;
	}
	
	return 0;
}