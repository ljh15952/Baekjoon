#include <bits/stdc++.h>

using namespace std;

int N, M;
int num[10];
int arr[10];
int isused[10];


void func(int k){
	
	if(k == M){
		for(int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	
	int tmp = 0;
	for(int i = 0; i < N; ++i){
		if(!isused[i] && tmp != num[i])
		{
			arr[k] = num[i];
			isused[i] = 1;
			tmp = arr[k];
			func(k+1);
			isused[i] = 0;
		}		
		
	}
	
	
}
/*

4 2
9 7 2 1

*/

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; ++i)
		cin >> num[i];
	
	sort(num, num+N);
	
	func(0);
	
	return 0;
}

/*
입력을 중복되게 받는데 중복되는 수열을 여러 번 출력하면 안된다.

*/