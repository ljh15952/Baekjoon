#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	
	string s;
	cin >> s;
	
	map<char,int> arr;
	
	for(char c = 'a'; c <= 'z'; ++c){
		arr.insert({c,0});
	}
	

	for(int i = 0; i < s.length(); ++i){
		arr[s[i]]++;
	}
	
	for(auto it : arr){
		cout << it.second << " ";
	}
	
	return 0;
}