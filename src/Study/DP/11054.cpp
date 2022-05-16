#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1001];
int dp2[1001];

int main(){
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; ++i){
		cin >> arr[i];
	}
	//왜 틀렸는지 모르겠어요 다음에 또 풀게요 
	//hihi
	int maxDp1 = 0;
	int maxDp1_index = 0;
	int maxDp2 = 0;
	int maxDp2_index = 0;
	
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= i; ++j){
			if(arr[i] > arr[j]){
				dp[i] = max(dp[i],dp[j] + 1);
			}
		}
		
		if(maxDp1 < dp[i]){
			maxDp1 = dp[i];
			maxDp1_index = i;
		}
		
	}
	
	for(int i = N; i >= 1; --i){
		for(int j = N; j >= i; --j){
			if(arr[i] > arr[j]){
				dp2[i] = max(dp2[i],dp2[j] + 1);
			}
		}
		
		if(maxDp2 < dp2[i]){
			maxDp2 = dp2[i];
			maxDp2_index = i;
		}
	}
	
	// for(int i = 0; i < N; ++i){
	// 	cout << arr[i] << " " << dp[i] << endl;
	// }
	// cout << endl;
	// for(int i = 0; i < N; ++i){
	// 	cout << arr[i] << " " << dp2[i] << endl;
	// }
	// cout << endl;
	// cout << maxDp1 << " " << maxDp1_index << endl;
	// cout << maxDp2 << " " << maxDp2_index << endl;

	cout << max(dp[maxDp1_index]+dp2[maxDp1_index],dp[maxDp2_index]+dp2[maxDp2_index]) + 1 << endl;
	
	//cout << *max_element(dp+0,dp+N-1) + *max_element(dp2+0,dp2+N-1) - 1 << endl;
	
	return 0;
}