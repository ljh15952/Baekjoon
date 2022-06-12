#include <iostream>
#include <string>
#include <stack>

using namespace std;

int getScore(string str){
	int score = 0;
	stack<char> s;
	
	bool flag = false;
	
	for(int i = 0; i < str.size(); ++i){
		char c = str[i];
		
		if(c == '('){
			s.push(c);
			flag = true;
		}else{
			s.pop();
			if(flag){
				score += s.size();
				flag = !flag;
			}else{
				score++;
			}
		}
	}
	
	return score;
}

int main(){
	//start
	/*
	()(((()())(())()))(()) 17
	
	(((()(()()))(())()))(()()) 24
	
	알고리즘 자신의 괄호 안에 ()이게 있으면 막대 +1
	*/
	
	string str;
	cin >> str;
	
	cout << getScore(str) << endl;
	
	return 0;
}