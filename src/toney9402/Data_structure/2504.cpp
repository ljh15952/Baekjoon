#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	
	string str;
	cin >> str;
    
    stack<char>	stack;
	stack<int> nums; // <- 왜 오류?
	char cur;
    
    for(auto it : str){
        if(stack.empty()){
			stack.push(it);
			cur = it;
		}else if(it == '('){
			stack.push(it);
			cur = it;
		}else if(it == ')'){
			if(cur == it){
				stack.pop();
				stack.pop();
				stack.push('2');
			}else{
				while(!stack.empty()){
					char c = stack.top();
					if(c == '['){
						cout << "0" << endl;
						return 0;
					}else if(c != '('){
						nums.push((stack.top() - '0') * 2);
						stack.pop();
					}else if(c == '('){
						stack.pop();
						stack.pop();
					}
					
				}
			}
		}
    }
	
	for(auto it : nums){
		cout << it << endl;
	}
	
	/*
	(())
	(2
	*/
        
    return 0;
}

/*


*/