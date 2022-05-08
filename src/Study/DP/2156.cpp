#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	int arr[n+1];
	int dp[n+1];
	for(int i = 1; i <= n; ++i){
		scanf("%d",&arr[i]);
	}
	
	dp[1] = arr[1]; 
	dp[2] = arr[1] + arr[2];
	
	for(int i = 3; i <= n; ++i){ 
		dp[i] = max(arr[i] + dp[i-2], arr[i] + arr[i-1] + dp[i-3]);
		dp[i] = max(dp[i],dp[i-1]);
	}
	
	cout << dp[n] << endl;

	
	
	
	return 0;
}