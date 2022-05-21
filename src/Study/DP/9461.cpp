#include <iostream>

using namespace std;

long long int dp[101];

int main(){
	
	int T;
	cin >> T;

	
	dp[1] = 1;
	dp[2] = 1;	
	dp[3] = 1;	
	
	dp[4] = 2;
	dp[5] = 2;
	
	int N;
	for(int j = 0; j < T; ++j){
		cin >> N;
		for(int i = 6; i <= N; ++i){
			dp[i] = dp[i-1] + dp[i-5];
		}
		cout << dp[N] << endl;
	}
	
	/*
	풀이
	수열 10까지
	0 : 1
	1 : 1
	2 : 1
	3 : p[1] + p[2] = 2
	4 : 2
	5 : p[2] + p[4] = 3
	6 : p[5] + p[1] = 4
	7 : p[6] + p[2] = 5
	8 : p[7] + p[3] = 7
	9 : p[8] + p[4] = 9
	10 : p[9] + p[5] = 12
	11 : p[10] + p[6] = 16
	규칙?
	6이상부터
	p[n] = p[n-1] + p[n-5];
	*/

	return 0;
}