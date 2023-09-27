#include <iostream>

using namespace std;

int GCD(int a, int b){
	
	if(b == 0){
		return a;
	}else{
		return GCD(b, a%b);
	}
}

int main(){
	
	int a, b;
	
	a = 11;
	b = 10;
	
	cout << GCD(a, b) << '\n';
	
	return 0;
}