#include <iostream>

using namespace std;

int dp[30][30];

int main(){
	
	//조합 공식 이용
	//혼자 못풀겠음ㅠ
	
	for(int i = 0; i < 30; ++i){
		dp[i][i] = 1;
		dp[i][0] = 1;
	}
	
	for(int i = 2; i < 30; ++i){
		for(int j = 1; j < 30; ++j){
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	
	int n,m,t;
	
	cin >> t;
	
	for(int i = 0; i < t; ++i){
		cin >> n >> m;
		
		cout << dp[m][n] << endl;
	}
	

	return 0;
}