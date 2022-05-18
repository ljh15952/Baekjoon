#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001];

int main(){
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}

	
	dp[0] = arr[0];
	
	for(int i = 1; i < n; ++i){
		dp[i] = max(arr[i],arr[i] + dp[i-1]);
	}
	
	cout << *max_element(dp+0,dp+n) << endl;
	
	
	return 0;
}