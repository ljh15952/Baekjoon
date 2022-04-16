#include <iostream>

using namespace std;


bool isSosu(int n){
	if(n == 1)
		return false;
	for(int i = 2; i < n; i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

int main(){
	
	int n;
	
	cin >> n;
	
	int ct = 0;
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		
		if(isSosu(num)){
			ct++;
		}
		
	}
	
	cout << ct << endl;
	
	return 0;
}