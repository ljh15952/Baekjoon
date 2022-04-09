#include <iostream>
#include <string>
using namespace std;

bool isGroupNum(string str){
	for(int i = 0; i < str.length(); ++i){
		for(int j = i+1; j < str.length(); ++j){
			if(str[i] == str[j] && str[i] != '!' && str[j] != '!'){
				return false;
			}
		}
	}
	return true;
}

int main(){
	
	int n;
	cin >> n;
	
	int num = 0;

	for(int i = 0; i < n; i++){
		string str;
	
		cin >> str;

		// 1. 인접한 연속된 숫자 제거
		for(int i = 0; i < str.length()-1; ++i){
			if(str[i] == str[i+1]){
				str[i] = '!';
			}
		}

		// 2. 첫 문자부터 끝까지 체크해서 중복되면 그룹 단어 X
		num += isGroupNum(str);
	}

	
	cout << num << endl;
	
	return 0;
}