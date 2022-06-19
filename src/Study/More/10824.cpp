#include <iostream>
#include <string>
using namespace std;

int main(){
	
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	
	string A = a+b;
	string B = c+d;
	
	cout << stoll(A) + stoll(B); 
	
	return 0;
}