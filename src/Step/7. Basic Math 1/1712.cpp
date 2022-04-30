#include<iostream>

using namespace std;

int main(){
	
	int a,b,c;
	cin >> a >> b >> c;
	
	int sum = (b > c) ? -1 : (c - b ==0) ? -1 : (a / (c - b) + 1);
	
	cout << sum << endl;
	return 0;
}