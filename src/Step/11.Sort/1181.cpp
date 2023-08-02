#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
	if(a.length() == b.length()){
		return a < b;
	}
	return a.length() < b.length();
}

int main(){
	
	int n;
	
	cin >> n;
	
	vector<string> arr;
	string str;	
	for(int i = 0; i < n; i++){
		cin >> str;
		arr.push_back(str);
	}
	
	sort(arr.begin(),arr.end(),compare);
	arr.erase(unique(arr.begin(),arr.end()),arr.end());
	
	for(string s : arr){
		cout << s << '\n';
	}
	
	
	return 0;
}