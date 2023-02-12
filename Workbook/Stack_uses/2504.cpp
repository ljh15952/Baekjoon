#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	stack<char> s;
	string str;
	
	cin >> str;
	int sum = 0; // 누적해서 더해질 값
	int num = 1; // 곱해질 값
	
	for(int i = 0; i < str.size(); ++i){
		if(str[i] == '('){
			num *= 2; // 소괄호가 나오면 곱해질 값 2배 증가
			s.push(str[i]);
		}else if(str[i] == '['){
			num *= 3;
			s.push(str[i]);
		}else if(str[i] == ')'){
			if(s.empty() || s.top() != '('){
				cout << 0;
				return 0;
			}
			if(str[i-1] == '(') sum += num; // 직전 괄호가 여는 괄호였다면 sum에 값 추가
			s.pop();
			num /= 2;
		}else if(str[i] == ']'){
			if(s.empty() || s.top() != '['){
				cout << 0;
				return 0;
			}
			if(str[i - 1] == '[') sum += num;
			s.pop();
			num /= 3;
		}
		cout << num << ' ';
	}
	cout << '\n';
	if(s.empty()) cout << sum << '\n';
	else cout << 0;
	
	return 0;
}
