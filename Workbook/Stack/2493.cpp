#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	int n;
	cin >> n;
	
	
	stack<pair<int,int>> s;
	int ans[n] = {};
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		
		while(!s.empty() && a > s.top().first){
			s.pop();
		}
		
		if(!s.empty()){
			ans[i] = s.top().second;
		}
		pair<int, int> p;
		p.first = a;
		p.second = i + 1;
		s.push(p);
	}
	
	for(auto it : ans){
		cout << it << ' ';
	}
	
	return 0;
}