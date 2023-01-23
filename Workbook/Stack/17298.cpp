#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	int N;
	cin >> N;
	
	stack<int> s1;
	stack<int> s2;
	
	int a;
	for(int i = 0; i < N; ++i){
		cin >> a;
		s1.push(a);
	}
	
	stack<int> ans;
	
	while(!s1.empty()){
		while(!s2.empty() && s1.top() >= s2.top()) s2.pop();
		if(s2.empty()) ans.push(-1);
		else ans.push(s2.top());
		s2.push(s1.top());
		s1.pop();
	}
	
	while(!ans.empty()){
		cout << ans.top() << ' ';
		ans.pop();
	}	
	return 0;
}