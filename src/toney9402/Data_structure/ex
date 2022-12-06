#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	
	string str;
	cin >> str;
    
    stack<char>	arr;
    stack<char> math;
    
    for(auto it : str){
        
        if(arr.empty() == true){
            arr.push(it);
        }else{
            if((it == '(' || it == '[') && (arr.top() == '(' || arr.top() == '[')){
                math.push('x');
            }else if((arr.top() == ')' || arr.top() == ']') && (it == '(' || it == '[')){
                math.push('+');
            }
            if((arr.top() == '(' || it == ')') && (arr.top() == '[' && it == ']')){
                arr.pop();
            }else{
                arr.push(it);
            }   
        }
        if(it == '('){
            math.push('2');
        }else if(it == '['){
            math.push('3');
        }
    }
    if(arr.empty() == false){
        cout << "0" << endl;
        
        while(!arr.empty()){
            cout << arr.top() << " ";
            arr.pop();
        }
        cout << endl;   
        //return 0;
    }
    
    while(!math.empty()){
        cout << math.top() << " ";
        math.pop();
    }
        
        
    return 0;
}
