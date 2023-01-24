#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	
	int n;
	cin >> n;
	
	stack<int> s;
	vector<char> ans;
	vector<int> arr;
	
	int a;
	for(int i = 1; i <= n; ++i){
		cin >> a;
		arr.push_back(a);
	}
	
	int i = 0;
	int j = 1;
	while(j <= n){
		s.push(j++);
		ans.push_back('+');
		while(!s.empty() && s.top() == arr[i]){
			ans.push_back('-');
			s.pop();
			i++;
		}
	}
	
	if(s.empty()){
		for(auto it : ans){
			cout << it << '\n';
		}
	}else{
		cout << "NO" << '\n';
	}
	
	return 0;
}

/*


*/