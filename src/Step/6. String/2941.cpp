#include <iostream>
#include <string>
using namespace std;

int main(){
	
	string str;
	
	cin >> str;
	
	int num = str.length();
	if(str.length() < 2){
		cout << "1" << endl;
		return 0;
	}
	for(int i = 0; i < str.length() - 1; ++i){
		string s;
		s += str[i];
		s += str[i + 1];
		if(s == "c=")
			num -= 1;
		if(s == "c-")
			num -= 1;
		if(s == "d-")
			num -= 1;
		if(s == "s=")
			num -= 1;
		if(s == "z=")
			num -= 1;
		if(s == "lj")
			num -= 1;
		if(s == "nj")
			num -= 1;
	}
	
	for(int i = 0; i < str.length() - 2; ++i){
		string s;
		s += str[i];
		s += str[i + 1];
		s += str[i + 2];

		if(s == "dz=")
			num -= 1;
	}
	
	cout << num << endl;
	
	return 0;
}