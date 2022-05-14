#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main(){
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; ++i){
		cin >> arr[i]; 
	}

	for(int i = N-1; i >= 0; --i){
		for(int j = i-1; j >= 0; --j){
			if(arr[i] < arr[j]){
				dp[j] = max(dp[i] + 1,dp[j]);
			}
		}
	}
	
	cout << *max_element(dp+0,dp+N-1) + 1 << endl;
	
	return 0;
}