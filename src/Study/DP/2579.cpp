#include <iostream>
#include <algorithm>
using namespace std;

int arr[301];
int dp[301];

int main(){
	
	//계단 오르기
	
	int n;
	cin >> n;
	
	//못풀겠어요 초등부 문제인데;;
	
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	
	dp[0] = arr[0];
	dp[1] = max(arr[0]+arr[1],arr[1]);
	dp[2] = max(arr[0]+arr[2],arr[1]+arr[2]);
	
	for(int i = 3; i < n; ++i){
		dp[i] = max(dp[i-2]+arr[i],arr[i-1]+arr[i]+dp[i-3]);
	}
	
	cout << dp[n-1] << endl;
	
	return 0;
}