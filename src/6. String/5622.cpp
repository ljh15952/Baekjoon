#include <iostream>
#include <string>
using namespace std;

string str;

bool isAlphaIn(char start,char end,char c){
	return (c >= start && c <= end);
}

int main(){
	
	cin >> str;
	int time = 0;
	for(int i = 0; i < str.length(); ++i){
		if(isAlphaIn('A','C',str[i]))
			time += 3;
		else if(isAlphaIn('D','F',str[i]))
			time += 4;
		else if(isAlphaIn('G','I',str[i]))
			time += 5;
		else if(isAlphaIn('J','L',str[i]))
			time += 6;
		else if(isAlphaIn('M','O',str[i]))
			time += 7;
		else if(isAlphaIn('P','S',str[i]))
			time += 8;
		else if(isAlphaIn('T','V',str[i]))
			time += 9;
		else if(isAlphaIn('W','Z',str[i]))
			time += 10;
	}
	cout << time << endl;
	
	return 0;
}