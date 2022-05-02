#include <iostream>

using namespace std;

int main(){
	
	int n;
	cin >> n;
	//4 3 2 1 0
	for(int i = 1; i <= n; i++){
		for(int j = n - i; j > 0; j--){
			cout << " ";
		}
		for(int j = 0; j < i*2-1; j++){
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;
}