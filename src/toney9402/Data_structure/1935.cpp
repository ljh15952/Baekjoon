#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(){
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	
	int n;
	cin >> n;
	
	string str;
	cin >> str;
	
	vector<int> v;
		
	for(int i = 0; i < n; ++i){
		int t;
		cin >> t;
		v.push_back(t);
	}
	
	stack<double> s;
	
	for(int i = 0; i < str.length(); ++i){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			s.push(v[str[i] - 'A']);
		}else{
				double temp = s.top();
				s.pop();
				if(str[i] == '+'){
					temp = s.top() + temp;
				}else if(str[i] == '-'){
					temp = s.top() - temp;
				}else if(str[i] == '*'){
					temp = s.top() * temp;;
				}else if(str[i] == '/'){
					temp = s.top() / temp;
				}
				s.pop();
				s.push(temp);
		}
	}
	
	cout << fixed;
	cout.precision(2);
	cout << s.top() << endl;
	
	return 0;
}

/*
후위 표기식과 각 피연산자에 대응하는 값들이 주어져 있을 때, 그 식을 계산하는 프로그램

첫째줄에 피연산자의 개수 (1<=N<=26)이 주어진다.
둘째줄에는 후위표기식이 주어진다(여기서 피연산자는 A~Z의 영대문자 A부터 순서대로 N개의
영대문자만이 사용되며, 길이는 100이하
셋째줄 부터 N+2번째줄에는 각 피연산자에 대응하는 값이 주어진다.
3번째 = A 4번쩨 = B 5번쩨 = C

후위 표기법의 계산
숫자를 만나면 스택에 집어 넣는다.
연산자가 나오면 스택에서 두 수를 꺼내 계산하고 다시 스택에 집어 넣는다.

1
AA+A+
-> A+A -> AA+
-> A+A+A -> AA+A+ 이런 느낌


*/
