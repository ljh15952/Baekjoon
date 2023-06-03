#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[10];

void func(int k){
	
	if(k == M){
		for(int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	int st = 1;
	if(k != 0) st = arr[k-1];
	
	for(int i = st; i <= N; ++i){
		arr[k] = i;
		func(k+1);
	}
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	func(0);
	
	return 0;
}

/*
N과 M
1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러번 골라도 됨
고른 수열은 비내림차순
길이가 K인 수열 A
A1 < A2 < .. < Ak-1 < AK <- 오름차순 아니노?

*/