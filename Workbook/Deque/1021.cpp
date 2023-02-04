#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N, M;
	cin >> N >> M;
	
	deque<int> dq;
	for(int i = 1; i <= N; ++i){
		dq.push_back(i);
	}
	
	
	int ans = 0;
	for(int i = 0; i < M; ++i){
		int n;
		cin >> n;
		
		int idx = find(dq.begin(), dq.end(), n) - dq.begin();
		
		if(idx < dq.size() - idx){
			while(dq[0] != n){
				dq.push_back(dq.front());
				dq.pop_front();
				ans++;
			}
		}else{
			while(dq[0] != n){
				dq.push_front(dq.back());
				dq.pop_back();
				ans++;
			}
		}
		dq.pop_front();
	}
	
	
	cout << ans << '\n';
	
	
	return 0;
}

/*
1 2 3 4 5 6 7 8 9 10
6 3 2 7 9 8 4 10 5
P
2 3 4 5 6 7 8 9 10
*/