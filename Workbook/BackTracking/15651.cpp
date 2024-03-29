#include <bits/stdc++.h>

using namespace std;

int N, M;
int isused[9];
int arr[9];

void func(int k){
	
	if(k == M){
		for(int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	for(int i = 1; i <= N; ++i){
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
N과 N 3
자연수 N과 M이 주어졌을 떄, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램
1부터 N까지 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 됨

3 1
1
2
3

4 2
1 1
1 2
1 3
1 4
2 1
2 2
2 3
2 4

*/