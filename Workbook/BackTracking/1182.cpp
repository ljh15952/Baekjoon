#include <bits/stdc++.h>

using namespace std;

int N, S;
int arr[20];

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> S;
	
	for(int i = 0; i < N; ++i){
		cin >> arr[i];
	}
	
	
	return 0;
}

/*
부분 수열의 합

N개의 정수로 이루어진 수열
크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이
S가 되는 경우의 수를 구하는 프로그램

*/