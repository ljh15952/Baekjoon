#include <bits/stdc++.h>

using namespace std;

int N, M;
int input[10];
int arr[10];
int isused[10000];

void func(int k){
	
	if(k == M){
		for(int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	for(int i = 0; i < N; ++i){
		if(isused[input[i]])
			continue;
		arr[k] = input[i];
		isused[input[i]] = 1;
		func(k+1);
		isused[input[i]] = 0;
	}
	
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;

	for(int i = 0; i < N; ++i){
		cin >> input[i];
	}
	sort(input, input+N);
	func(0);
	
	return 0;
	
}

/*
N개의 자연수 중에서 M개를 고른 수열
수열은 사전 순으로 증가하는 순서대로 출력
3 1
4 5 2
2 4 5

4 2
9 8 7 1
1 7
1 8
1 9
7 1 
7 8
7 9
...

*/