#include <iostream>
#define MODULAR 1000000000

using namespace std;

int arr[201];
int dp[201][10];

int main(){
	
	//start	
	
	int n,k;
	cin >> n >> k;
	
	//0부터 N까지 정수 K개를 더해서 합이 N이 되는 경우의 수
	
	/*
	0 0 3 0
	
	0 0 0 3
	0 0 2 1
	0 0 1 2
	
	0 4 3 x
	dp[2][4] = dp[3][4-1]
	
	dp[4][i] = 1;
	dp[3][1] += dp[4][]
	dp[1][i] = dp[2][n-i];
	*/
	
	return 0;
}