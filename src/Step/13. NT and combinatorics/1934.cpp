#include <iostream>

using namespace std;

int gcd(int a,int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}

int lcm(int a,int b){
	return (a * b) / gcd(a,b);
}

int main(){
	
	int n;
	
	cin >> n;
	
	int a,b;
	for(int i = 0; i < n; ++i){
		cin >> a >> b;
		cout << lcm(a,b) << '\n';
	}
	
	return 0;
}