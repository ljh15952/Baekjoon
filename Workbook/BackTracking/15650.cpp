#include <bits/stdc++.h>

using namespace std;

int N, M;

int arr[9];
int isused[9];

void func(int c){
	
	if(c == M){
		for(int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	int st = 1; // 시작지점, k = 0일 때에는 st = 1
    if(c != 0) st = arr[c-1] + 1; // k != 0일 경우 st = arr[k-1]+1
	
	for(int i = st; i <= N; ++i){
		if(isused[i])
			continue;
		if(arr[c-1] > i)
			continue;
		arr[c] = i;
		isused[i] = 1;
		func(c+1);
		isused[i] = 0;
	}
	
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	func(0);
	
	return 0;
}

/*
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램
1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

3 1
1
2
3

4 2
1 2
1 3
1 4
2 3
2 4
3 4

4 4
1 2 3 4

*/