#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
	
	string s;
	cin >> s;
	
	vector<string> arr;
	
	for(int i = 0; i < s.length(); ++i){
		arr.push_back(s.substr(i,s.length()));
	}
	
	sort(arr.begin(),arr.end());
	
	for(auto it : arr){
		cout << it << endl;
	}
	
	return 0;
}