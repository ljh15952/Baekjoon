#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[10];
int num[10];

void func(int k){
	
	
	if(k == m){
		for(int i = 0; i < m; ++i){
			cout << num[arr[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	
	
	int tmp = -1;
	
	int st = 0;
	if(k != 0) st = arr[k-1];
	
	for(int i = st; i < n; ++i){
		
		if(num[i] != tmp){
			arr[k] = i;
			tmp = num[i];
			func(k+1);
		}
		
	}
	
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i)
		cin >> num[i];
	
	sort(num, num+n);
	
	func(0);
		
	return 0;
}

/*
n과 m마지막
같은 수 여러번
고른 수열 비내림차순
중복 수열 여러번 X


*/