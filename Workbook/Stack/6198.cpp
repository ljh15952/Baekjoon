#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int N;
	cin >> N;
	
	
	stack<int> s;
	long long int ans = 0;
	int a;
	for(int i = 0; i < N; ++i){
		cin >> a;
		while(!s.empty() && s.top() <= a){
			s.pop();
		}
		ans += s.size();
		s.push(a);
	}
	
	cout << ans << '\n';
	
	return 0;
}
