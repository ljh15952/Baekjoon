#include <iostream>

using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	//계단수
	//n = 1
	//1 2 3 4 5 6 7 8 9
	//n = 2
	//10 12 21 23 32 34
	//43 45 54 56 65 67
	//76 78 87 89 98
	//n = 3
	//101 121 123 210 212 232 234
	
	long long int dp[101][11];
	
	for(int i = 1; i <= 9; ++i){
		dp[1][i] = 1;
	}
	
	for(int i = 2; i <= n; ++i){
		for(int j = 0; j <= 9; ++j){
			if (j == 0) { 
				dp[i][j] = dp[i-1][1]; 
			} else if (j == 9) {
				dp[i][j] = dp[i-1][8]; 
			} else { 
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]; 
			}
			
			dp[i][j] = dp[i][j] % 1000000000;
		}
	}
	
	long long int sum = 0;
	for(int i = 0; i < 10; ++i){
		sum += dp[n][i];
	}
	
	cout << sum % 1000000000 << endl;
	
	return 0;
}