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
		dp[i] = arr[i];
	}
	
	//10 20 15 25 10 20
	//10 65 15 45 10 20
	//75
	for(int i = n-1; i >= 2; --i){
		if(arr[i-1] > arr[i-2]){
			dp[i-1] += dp[i];
		}else{
			dp[i-2] += dp[i];
			if(i==3){
				dp[0] += dp[1];
			}
			i--;
		}
	}
	
	cout << *max_element(dp+0,dp+n) << endl;
	
	return 0;
}