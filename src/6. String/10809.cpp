#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	int alpha[26];
	for(int i = 0; i < 26; ++i){
		alpha[i] = -1;
	}
	cin >> str;
	for(int i = str.length(); i >= 0 ; --i){
		alpha[str[i] - 97] = i;
		
	}
	for(int i = 0; i < 26; ++i){
		cout << alpha[i] << " ";
	}
	return 0;
}