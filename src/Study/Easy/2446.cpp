#include <iostream>

using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	//9 7 5 3 1
	//3 5 7 9
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			cout << " ";
		}
		for(int j = 0; j < (n*2-1) - (2*i); ++j){
			cout << "*";
		}
		cout << endl;
	}
	
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < n - i - 1; ++j){
			cout << " ";
		}
		for(int j = 0; j < 1 + (i*2); ++j){
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;
}