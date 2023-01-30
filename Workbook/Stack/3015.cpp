#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N;
	cin >> N;
	
	stack<pair<int,int>> s;
	long long ans = 0;
	
	for(int i = 0; i < N; ++i){
		int n;
		cin >> n;
		
		int cnt = 1;
		while(!s.empty() && s.top().first <= n){
			ans += s.top().second;
			if(s.top().first == n) cnt += s.top().second;
			s.pop();
		}
		if(!s.empty()) ans++;
		s.push({n, cnt});
	}
	
	cout << ans << '\n';
	
	return 0;
}

/*
0 1 2 3 4 5 6
2 4 1 2 2 5 1

6 -> 1
5 -> 3
4 -> 2
3 -> 2
2 -> 1
1 -> 1
0 -> 0
-> 10명

stack
5
n 
1
ct
9

6 5 4 3 2 1




*/