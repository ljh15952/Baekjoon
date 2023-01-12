#include <bits/stdc++.h>

using namespace std;

int func(int a, int b){
	if(a < 0){
		return 0;
	}
	return func(a - b, b) + 1;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N; 
	cin >> N;
	
	int y = 0,m = 0;
	int a;
	for(int i = 0; i < N; ++i){
		cin >> a;
		y += func(a,30) * 10;
		m += func(a,60) * 15;
	}

	if(y == m){
		cout << "Y M " << y; 
	}else if(y > m){
		cout << "M " << m;
	}else{
		cout << "Y " << y;
	}

	return 0;
}