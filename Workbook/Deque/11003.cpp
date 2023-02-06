#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N, L;
	cin >> N >> L;
	
	deque<pair<int,int>> dq;
	
	for(int i = 0; i < N; ++i){
		int a;
		cin >> a;
		
		while(!dq.empty() && dq.back().second >= a){
			dq.pop_back();
		}
		
		dq.push_back({i, a});
		
		if(dq.front().first <= i - L){
			dq.pop_front();
		}

		cout << dq.front().second << ' ';
	}
	cout << '\n';
	return 0;
}

/*
N개의 수 와 L이 주어짐
Di = Ai - L+1 ~ Ai 중 최소값
D에 저장된 수를 출력하는 프로그램
i <= 0 인 Ai는 무시하고 D

1 5 2 3 6 2 3 7 3 5 2  6
0 1 2 3 4 5 6 7 8 9 10 11
1 1 1 2 2 2 2 2 3 3 2  2
L = 3

D0 = A0-L+1 ~ A11 최소값

*/