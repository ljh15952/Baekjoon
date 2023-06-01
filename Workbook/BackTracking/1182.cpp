#include <bits/stdc++.h>

using namespace std;

int N, S;
int arr[20];

int cnt = 0;

void func(int cur, int tot){
	if(cur == N){
		if(tot == S) cnt++;
		return;
	}		
	func(cur+1, tot);
	func(cur+1, tot+arr[cur]);
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> S;
	
	for(int i = 0; i < N; ++i){
		cin >> arr[i];
	}
	
	func(0,0);
	
	if(S == 0) cnt--;
	
	cout << cnt << '\n';
	
	return 0;
}

/*
부분 수열의 합

N개의 정수로 이루어진 수열
크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이
S가 되는 경우의 수를 구하는 프로그램

5 0
-7 -3 -2 5 7
*/