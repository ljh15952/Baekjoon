#include <iostream>

using namespace std;

int main(){
	int n;
	
	cin >> n;
	int sum = 0;
	char str[n];
	scanf("%s",str);
	for(int i = 0; i < n; i++){
		sum += str[i] - 48;
	}
	cout << sum;
	return 0;
}