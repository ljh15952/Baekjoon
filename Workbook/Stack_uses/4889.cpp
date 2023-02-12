#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int ord = 0;
	
	while(1){
		ord++;
		string s;
		getline(cin, s);
		if(s[0] == '-') break;
		
		stack<char> st;
		int cnt = 0;

		for(auto it : s){
			if(st.empty()) st.push(it);
			else{
				if(it == '}' && st.top() == '{'){
					st.pop();
				}else{
					st.push(it);
				}
			}
		}	
		
		while(!st.empty()){
			char c1 = st.top();
			st.pop();
			char c2 = st.top();
			st.pop();
			
			if(c1 == c2) cnt++;
			else cnt+=2;
		}
		cout << ord << ". " << cnt << '\n';
	}
	
	
	return 0;
}

/*
여는 괄호와 닫는 괄호만으로 이루어진 문자열
여기서 안정적인 문자열을 만들기 위한 최소 연산의 수

안정적인 문자열이란
1. 빈 문자열은 안정적
2. S가 안정적이라면 {S}도 안정적인 문자열이다.
3. S와 T가 안정적이라면 ST(두 문자열의 연결)도 안정적이다.

{}, {}{}, {{}{}} <- 안정적, }{, {{}{ {}{ <- 안정X

문자열에 행할 수 있는 연산은 여는 괄호를 닫는 괄호로 바꾸거나
닫는 괄호를 여는 괄호로 바꾸는 것 2가지이다.

입력의 마지막 줄은 -가 한개 이상 주어짐

}{ -> 2
{}{}{} -> 0
{{{} => 1



*/