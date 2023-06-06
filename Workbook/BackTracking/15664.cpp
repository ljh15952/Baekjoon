#include <bits/stdc++.h>

using namespace std;

int N,M;
int num[10];
int arr[10];
int isused[10];

void func(int k){
	
	if(k == M){
		for(int i = 0; i < M; ++i)
			cout << num[arr[i]] << ' ';
		cout << '\n';
		return;
	}
	
	int tmp = 0;
	int st = 0;
	if(k != 0) st = arr[k-1];
	for(int i = st; i < N; ++i){
		if(!isused[i] && tmp != num[i]){
			arr[k] = i;
			isused[i] = 1;
			tmp = num[i];
			func(k+1);
			isused[i] = 0;
		}
		
	}
	
}


int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; ++i){
		cin >> num[i];
	}
	
	sort(num, num+N);
	
	func(0);
	
	return 0;
}

/*
N과 M
비내림차순 중복X


*/