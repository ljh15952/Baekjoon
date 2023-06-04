#include <bits/stdc++.h>

using namespace std;

int N, M;
int num[10];
int arr[10];

void func(int k){
	
	if(k == M){
		for(int i = 0; i < M; ++i)
			cout << num[arr[i]] << ' ';
		cout << '\n';
		return;
	}
	
	for(int i = 0; i < N; ++i){
		arr[k] = i;
		func(k + 1);
	}
	
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; ++i)
		cin >> num[i];
	
	sort(num, num + N);
	
	func(0);
	
	return 0;
}

/*
주어진 수 N과 M
같은 수 여러번 OK

*/