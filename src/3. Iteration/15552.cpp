#include<iostream>

using namespace std;


int main(){
	cin.tie(NULL);
	int n;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int a,b;
		cin >> a >> b;
		cout << a + b;
		printf("\n");
	}	
	return 0;
}