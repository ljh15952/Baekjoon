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
n = 4 m = 3
3과 2 채워진 상태
arr[0] = 3, arr[1] = 2
isused[1] = false, isused[2] = true, isused[3] = true, isused[4] = false
*/