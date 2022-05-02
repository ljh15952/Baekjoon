#include <iostream>
#include <string>

using namespace std;

int main(){
	
	string s;
	cin >> s;
	int index = 0;
	
	for(char s : s){
		cout << s;
		index++;
		if(index == 10){
			cout << endl;
			index = 0;
		}
	}
	
	return 0;
}