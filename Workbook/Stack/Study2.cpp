#include <bits/stdc++.h>
using namespace std;

int main(){
	
	stack<int> s;
	s.push(10); // 10
	s.push(20); // 10 20
	s.push(30); // 10 20 30
	
	cout << s.size() << '\n'; // 3
	if(s.empty()) cout << "stack is empty\n";
	else cout << "s in not empty\n";
	
	s.pop(); // 10 20
	cout << s.top() << '\n'; // 20
	s.pop(); // 10
	cout << s.top() << '\n'; // 10
	s.pop(); // empty
	if(s.empty()) cout << "stack is empty\n";
	cout << s.top() << '\n'; // runtime error 발생
	// 비어있는데 값을 호출했기 때문 top()이나 pop()함수에서 오류가 날 수 있음
	
	
	
	return 0;
}