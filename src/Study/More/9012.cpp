#include <iostream>
#include <string>

using namespace std;


bool isVPS(string str){
	int pivot = 0;
	for(int i = str.size()-1; i >= 0; --i){
		if(str[i] == ')'){
			for(int j = i-1; j >= 0; --j){
				if(str[j] == '('){
					str[i] = '*';
					str[j] = '*';
					break;
				}
			}
		}
	}
	for(int i = str.size()-1; i >= 0; --i){
		if(str[i] != '*')
			return false;
	}
	return true;
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