#include <iostream>

using namespace std;

int main(){
	int n,t;
	
	cin >> n >> t;
	
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a < t)
			cout << a << " ";
	}
	
	return 0;
}