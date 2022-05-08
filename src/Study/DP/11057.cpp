#include <iostream>

using namespace std;

long long int dp[1001][10];

int main(){
	
	int n;
	cin >> n;
	
	//오르막수
	//1자리수
	//0 1 2 3 4 5 6 7 8 9 -> 10개
	//2자리수
	//00 01 02 03 04 05 06 07 08 09 -> 10개
	//11 12 13 14 15 16 17 18 19 -> 9개
	//22 23 24 25 26 27 28 29 -> 8개
	//33 34 35 36 37 38 39 -> 7개
	//44 45 46 47 48 49 -> 6개
	//55 56 57 58 59 -> 5개
	//66 67 68 69 -> 4개
	//77 78 79 -> 3개
	//88 89 -> 2개
	//99 -> 1개
	//55개
	//3자리수
	//000 001 002 003 ... 011 012 013 ..022 023
	//점화식 
	//dp[2][0] += dp[1][0:9]
	//dp[2][1] += dp[1][1:9];
	//dp[2][2] += dp[1][2:9];
	
	//dp[i][j] += dp[i-1][j:9];

	
	for(int i = 0; i < 10; ++i){
		//1자리 수 일때 숫자 i가 가질수 있는 오르막수의 개수
		dp[1][i] = 1;
	}
	
	for(int i = 2; i <= n; ++i){
		for(int j = 0; j < 10; ++j){
			for(int k = j; k <= 9; ++k){
				dp[i][j] += dp[i-1][k];
				dp[i][j] = dp[i][j] % 10007;
			}
		}
	}
	
	long long int sum = 0;
	for(int i = 0; i < 10; ++i){
		sum += dp[n][i];
	}
	
	cout << sum % 10007 << endl;
	
	return 0;
}