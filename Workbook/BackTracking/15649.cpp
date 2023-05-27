#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[10];
bool isused[10];

void func(int k){
	if(k == M){
		for(int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	for(int i = 1; i <= N; ++i){
		if(!isused[i]){
			arr[k] = i;
			isused[i] = 1;
			func(k+1);
			isused[i] = 0;
		}
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
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인
수열을 모두 구하는 프로그램
* 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

3 1
1부터 3까지 자연수 중에서 중복 없이 1개를 고른 수열 
1, 2, 3
4 2
1부터 4까지 자연수 중에서 중복없이 2개를 고른 수열
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3

*/