#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	int n;
	cin >> n;
	
	stack<pair<int,int>> s;
	s.push({100000001, 0});
	for(int i = 1; i <= n; ++i){
		int a;
		cin >> a;
		
		while(a > s.top().first){
			s.pop();
		}
		cout << s.top().second << ' ';
		s.push({a, i});
	}

	return 0;
}