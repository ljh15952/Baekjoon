#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];
int dp1[1001];
int dp2[1001];

int main(){
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; ++i){
		cin >> arr[i];
	}
	
	for(int i = 1; i <= N; ++i){
		dp1[i] = 1;
		dp2[N-i+1] = 1;
		for(int j = 1; j < i; ++j){
			if(arr[i] > arr[j] && dp1[j] + 1 > dp1[i]){
				dp1[i] = dp1[j] + 1;
			}
			if(arr[N-i+1] > arr[N-j+1] && dp2[N-j+1] +1 > dp2[N-i+1]){
				dp2[N-i+1] = dp2[N-j+1] + 1;
			}
		}
	}
	
	int maxArr[N+1];
	int Max = 0;
	for(int i = 1; i <= N; ++i){
		maxArr[i] = dp1[i] + dp2[i];
		Max = max(Max,maxArr[i]);
	}
	
	cout << Max - 1 << endl;
	
	return 0;
}