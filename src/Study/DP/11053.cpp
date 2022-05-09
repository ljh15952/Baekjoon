#include <iostream>

using namespace std;

int dp[1000];

int main(){
	
	int N;
	cin >> N;
	
	int arr[1000];
	
	for(int i = 0; i < N; ++i){
		cin >> arr[i];
	}
	
	/*
	10 20 10 30 20 50
	0 1 
	1
	*/
	dp[0] = 0;
	int max = -1;
	for(int i = 1; i < N; ++i){
		for(int j = i-1; j >= 0; --j){
			if(dp[i] > dp[j]){
				if(max < dp[j]){
					dp[i] = dp[j] + 1;
					max = dp[i];
				}
			}
		}
	}
		
	cout << dp[N-1] + 1 << endl;
	
	return 0;
}