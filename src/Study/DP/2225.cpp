#include <iostream>
#define MODULAR 1000000000

using namespace std;

long long int dp[201][201];

int main(){
	
	//start	
	
	int n,k;
	cin >> n >> k;

	//0부터 N까지 정수 K개를 더해서 합이 N이 되는 경우의 수
	
	/*
	dp[k][n] = k개를 더해서 합이 n일 경우
	dp[k][n] = dp[k-1][n-l]
	*/
	
	for(int i = 0; i <= n; ++i){
		dp[1][i] = 1;
	}
	
	for(int i = 1; i <= k; ++i){
		for(int j = 0; j <= n; ++j){
			for(int l = 0; l <= j; ++l){
				dp[i][j] += dp[i-1][j-l];
				dp[i][j] %= MODULAR;
			}
		}
	}
	
	cout << dp[k][n] << endl;
	
	return 0;
}