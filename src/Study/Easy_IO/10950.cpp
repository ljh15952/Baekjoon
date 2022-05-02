#include <iostream>

using namespace std;

int main(){
	
	int A,B;
	int n;
	cin >> n;
	
	for(int i = 0; i < n; ++i){
		cin >> A >> B;
		cout << A + B << endl;
	}
	
	return 0;
}