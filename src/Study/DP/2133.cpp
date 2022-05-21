#include <iostream>

using namespace std;

int dp[31];

int main(){
	//타일 채우기
	
	/*
	3xn 크기의 벽을 2x1 1x2 크기의 타일로 채우는 경우의 수
	
	3x2 = 3개의 타일로 가능
	*/
	
	int n;
	cin >> n;
	
	dp[0] = 1;
	dp[2] = 3;
	
	for(int i = 4; i <= n; ++i){
		dp[i] = dp[i-2] * 3;
		for(int j = 4; j <= i; j+=2)
		{
			dp[i] += dp[i-j] * 2;
		}
	}

	cout << dp[n] << endl;
	
	return 0;
}