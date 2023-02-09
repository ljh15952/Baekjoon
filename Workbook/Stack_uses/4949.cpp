#include <bits/stdc++.h>

using namespace std;


/*
So when I die (the [first] I will see in (heaven) is a score list).

*/
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	
	
	while(1){
		string s;
		getline(cin, s);
		if(s == ".") break;
		
		stack<char> st;
		bool isStr = true;
		
		for(auto it : s){
			if(it == '(' || it == '[') st.push(it);
			else if(it == ')'){
				if(st.size() > 0 && st.top() == '('){
					st.pop();
				}else{
					isStr = false;
					break;
				}
				// Short-circuit evaluation
				
			}else if(it == ']'){
				if(st.size() > 0 && st.top() == '['){
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