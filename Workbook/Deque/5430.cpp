#include <bits/stdc++.h>

using namespace std;

void parase(string tmp, deque<int>& dq){
	int cur = 0;
	for(int i = 1; i + 1 < tmp.size(); ++i){
		if(tmp[i] == ','){
			dq.push_back(cur);
			cur = 0;
		}else{
			cur = 10 * cur + (tmp[i] - '0');
		}
	}
	if(cur != 0)
		dq.push_back(cur);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){
		deque<int> dq;
		int n;
		bool isError = false;
		
		bool isRev = false;
		
		string func;
		string tmp;
		
		cin >> func;
		cin >> n;
		cin >> tmp;
		parase(tmp,dq);

		for(auto it : func){
			if(it == 'R'){
				isRev = !isRev;
			}else if(it == 'D'){
				if(dq.empty()){
					isError = true;
					break;
				}else{
					if(isRev){
						dq.pop_back();
					}else{
						dq.pop_front();
					}
				}
			}
		}

		if(isError){
			cout << "error" << '\n';
		}else{
			if(isRev) reverse(dq.begin(), dq.end());
			cout << '[';
			for(int i = 0; i < dq.size(); ++i){
				cout << dq[i];
				if(i != dq.size() - 1) cout << ',';
			}
			cout << "]\n";
		}
	}

	return 0;
}

/*
AC언어 
정수 배열에 연산을 하기 위해 만든 언어
두 다지 함수 R(뒤집기), D(버리기)

배열이 비어있는데 D함수를 사용하면 에러가 발생

RDD -> 배열을 뒤집고 처음 두 수를 버림

배열의 초기값과 수행할 함수가 주어지고 최종 결과를 구하는 프로그램 

에러가 발생할 경우에는 error를 출력한다.
1
DD
1
[42]
*/