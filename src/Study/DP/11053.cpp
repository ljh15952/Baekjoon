#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000];
int arr[1000];

int main(){
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; ++i){
		cin >> arr[i];
	}
	
	/*
	10 20 10 30 20 50
	0 1 
	1
	*/
	int num = 0;
	for(int i = 1; i <= N; ++i){
		dp[i] = 1;
		for(int j = i - 1; j >= 1; --j){
			if(arr[i] > arr[j]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		num = max(dp[i],num);
	}
	
	cout << num << endl;
	
	return 0;
}