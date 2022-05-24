#include <iostream>

using namespace std;

long long int arr[1001];
long long int dp[1001];

int main(){
	
	int N;
	cin >> N;
	
	for(int i = 1; i <= N; ++i){
		cin >> arr[i];
	}
	
	
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= i; ++j){
			dp[i] = max(dp[i],arr[j]+dp[i-j]);
		}
	}
	
	cout << dp[N] << endl;
	
	
	/*
	arr[i] = j 카드 i개는 j원
	카드 N개를 갖기 위해 지불해야 하는 금액의 "최댓값"
	
	dp[i] = j 카드 i개의 최댓값 j
	dp[i] = arr[i]
	*카드 1개의 최댓값
 	dp[1] = arr[1]
	*카드 2개의 최댓값
	dp[2] = max(dp[2], dp[1]+dp[1]) 1
	*카드 3개의 최댓값
	dp[3] = max(dp[3], dp[1]+dp[2]) 1
	*카드 4개의 최댓값
	dp[4] = max(dp[4], dp[1]+dp[3]) 1
	dp[4] = max(dp[4], dp[2]+dp[2]) 2
	*카드 5개의 최댓값
	dp[5] = max(dp[5],dp[1]+dp[4]) 1
	dp[5] = max(dp[5],dp[2]+dp[3]) 2
	*카드 6개의 최댓값
	dp[5] = max(dp[6],dp[1]+dp[5]) 1
	dp[5] = max(dp[6],dp[2]+dp[4]) 2
	dp[5] = max(dp[6],dp[3]+dp[3]) 3
	
	dp[i] = max(dp[i],d[j=1->n/2]+dp[n-j])
	
	문신 시간대 언제?
	6월7일 오후 쯤?	
	6월7일 화 점심먹고 서울 출발 저녁 동완이네 집에서 취침
	6월8일 수 아침 동완이랑 먹고 점심 저녁 태환이 민형이형이랑 같이?
	6월9일 목 용인 애들 한번 봐야지
	6월10일 금 논산 출발 부모님이랑 밥 먹고 부대 복귀맨	
	*/
	
	
	
	return 0;
}