#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	
	string str;
	cin >> str;
	cout << str << endl;
	
	vector<char> stack;
	
	for(int i = 0; i < str.length; ++i){
		
	}
	
	return 0;
}

/*

스택 넣고 다음거 넣을 때 방금 넣은거랑 짝이면 pop 두번 -> 마지막에 남은 사이즈가 1이상이면 올바르지 못한 괄호열이다.

여는 괄호 뒤 여는 괄호가 한번 더 나오면 곱하기
닫는 괄호 뒤 여는 괄호가 더 나오면 더한다

지금 까지의 연산을 자료구조의 저장 후 순서대로 실행 한다면?

(()[[]])
(2+3x3) x 2 = 22

2 x 2 + 3 x 3 아ㅋㅋ 이거도 스택이네 뒤에서 부터 뽑아서 계산!!

*/