#include <iostream>

using namespace std;

int gcd(long long int a, long long int b){
	if(b == 0)
		return a;
	else
		return gcd(b , a%b);
}

int main(){
	
	long long int a,b;
	cin >> a >> b;
	
	for(int i = 0; i < gcd(a,b); ++i){
		cout << "1";
	}

	cout << endl;
	
	return 0;
}