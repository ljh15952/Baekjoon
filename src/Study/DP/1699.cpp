#include <iostream>
#include <algorithm>
using namespace std;

int dp[100000];

int main(){
	
	//start
	/*
	7 = 4(2) + 1 + 1 + 1
	1 = 1
	4 = 4(2)
	11 = 9(3) + 1 + 1
	13 = 9(3) + 4(2)
	*/
	int n;
	cin >> n;
	
	//3이하일 경우 1의 제곱으로 표현해야함
	//num <= 3; -> break; count += 3;
	
	//1 2 3 4 5 6 7 8
	//1 5 14 30 55...
	
	for(int i = 1; i <= n; ++i){
		dp[i] = i;
		for(int j = 1; j * j <= i; ++j){
			dp[i] = min(dp[i],dp[i - j * j] + 1);
		}
	}
	
	cout << dp[n];
	
	return 0;
}