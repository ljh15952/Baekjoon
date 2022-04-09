#include <iostream>
#include <string>
using namespace std;

int main(){
	int num = 1;
	
	char c = ' ';
	string str;
	while(1){
		scanf("%c",&c);
		if(c == '\n'){
			break;
		}
		str += c;
	}
	
	str.erase(0,str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ') + 1);
	if(str.length() == 0)
		num = 0;
	for(int i = 0; i < str.length(); ++i){
		if(str[i] == ' ')
			num++;
	}
	
	cout << num << endl;
	
	return 0;
}