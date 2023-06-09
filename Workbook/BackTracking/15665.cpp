#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[10];
int num[10];
int isused[10];

void func(int k){
	
	if(k == m){
		for(int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	
	
	
	for(int i = 0; i < n; ++i){
		
		if(isused[i])
			continue;
		
		
		
		
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
N과 M이 주어진다.
같은 수를 여러 번 골라도 된다.

*/