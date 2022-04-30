#include<iostream>

using namespace std;

int fac(int n){
	if(n == 1 || n == 0){
		return 1;
	}else{
		return fac(n - 1) * n;
	}
}

int main(){
	
	int n,k;
	
	cin >> n >> k;
	
	cout << fac(n) / (fac(k) * fac(n-k)) << endl;
	
	return 0;
}