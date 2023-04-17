#include <bits/stdc++.h>

using namespace std;

int N;
int R, C; // row행 col열

int func(int n, int r, int c){
	if(n == 0) return 0;
	
	int half = 1 << (n-1);
	
	if(r < half && c < half) return func(n-1, r, c);
	if(r < half && c >= half) return half*half + func(n-1, r, c-half);
	if(r >= half && c < half) return 2*half*half + func(n-1, r-half, c);
	return 3*half*half + func(n-1, r-half, c-half);
}

int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> R >> C;
	
	cout << func(N, R, C) << '\n';
	
	return 0;
}
// z자 탐색 2차원 배열