#include <iostream>
#include <string>

using namespace std;

int main(){
	
	string s;
	
	getline(cin,s);
	
	for(int i = 0; i < s.length(); ++i){
		int n;
		if(s[i] >= 'a' && s[i] <= 'z'){
			n = (s[i] - 'a' + 13) % 26;
			cout << char('a'+ n);
		}
		else if(s[i] >= 'A' && s[i] <= 'Z'){
			n = (s[i] - 'A' + 13) % 26;
			cout << char('A'+ n);
		}else{
			cout << s[i];
		}
	}

	return 0;
}