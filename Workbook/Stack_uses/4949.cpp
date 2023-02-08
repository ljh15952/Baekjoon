#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	string s;
	
	while(1){
		getline(cin, s);
		if(s == ".") break;
		
		stack<char> st;
		bool isStr = true;
		
		for(auto it : s){
			if(it == '(' || it == '['){
				st.push(it);
			}else if(it == ')'){
				if(st.top() == '('){
					st.pop();
					st.pop();
				}else{
					isStr = false;
					break;
				}
			}else if(it == ']'){
				if(st.top() == '['){
					st.pop();
					st.pop();
				}else{
					isStr= false;
					break;
				}
			}
		}
		
		if(st.size() != 0){
			isStr = false;
		}
		
		if(isStr) cout << "yes\n";
		else cout << "no\n";
	}
	
	
	return 0;
}