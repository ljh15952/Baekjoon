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
	
	/*
	풀이
	마지막 칸을 무조건 밟아야 함
	경우의 수 *마지막 칸이 n이라면
	1. 전칸을 밟고 마지막 칸을 밟는 경우
	---> n-1 + n
	2. 전전칸을 밟고 마지막 칸을 밟는 경우
	---> n-2 + n
	* 1번의 경우 연속으로 3칸을 밟을 수 없으므로 전칸을 밟고 현재칸을 밟는 경우
	  조건을 추가해주어야 한다.
	  1. 전칸을 밟는 경우 n-2번째 칸을 밟을 수 없다.(전전전칸 + 전칸 + 현재칸)
	  ---> n-3 + n-1 + n
	*/
	
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