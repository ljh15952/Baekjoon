#include <iostream>

using namespace std;


int pac(int n){
	if(n <= 1)
		return 1;
	return n * pac(n-1);	
}

int main(){
	
	int n;
	
	cin >> n;
	
	cout << pac(n) << endl;
	
	return 0;
}