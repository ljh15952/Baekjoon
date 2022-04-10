#include <iostream>

using namespace std;

int main(){
	
	long long int n;
	
	cin >> n;
	
	int line = 0;
	int end = 0;
	while(n > end){
		line += 1;
		end += line;
	}
	
	int diff = end - n;
	int top, bottom;
	if(line % 2 == 0){
		top = line - diff;
		bottom = diff + 1;
	}else{
		top = diff + 1;
		bottom = line - diff;
	}
	
	cout << top << "/" << bottom << endl;
	
	return 0;
}