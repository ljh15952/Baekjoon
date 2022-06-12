#include <iostream>
#include <string>
#include <stack>

using namespace std;


// bool isVPS(string str){
// 	int pivot = 0;
// 	for(int i = str.size()-1; i >= 0; --i){
// 		if(str[i] == ')'){
// 			for(int j = i-1; j >= 0; --j){
// 				if(str[j] == '('){
// 					str[i] = '*';
// 					str[j] = '*';
// 					break;
// 				}
// 			}
// 		}
// 	}
// 	for(int i = str.size()-1; i >= 0; --i){
// 		if(str[i] != '*')
// 			return false;
// 	}
// 	return true;
// }
bool isVPS(string str){

	stack<char> s;
	
	for(int i = 0; i < str.size(); ++i){
		char c = str[i];
		
		if(c == '('){
			s.push(c);
		}else if(s.empty()){
			return false;
		}else{
			s.pop();
		}
	}
	
	return s.empty();
}

int main(){
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i){
		string str;
		cin >> str;
		
		if(isVPS(str))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
	}
	
	return 0;
}