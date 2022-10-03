#include <iostream>

using namespace std;

long long int arr[1000000];
int n;

int main(){
	
	scanf("%d", &n);
	
	arr[1] = 1;
	arr[2] = 2;
	
	for(int i = 3; i <= n; ++i){
		arr[i] = arr[i-1] + arr[i-2];
		arr[i] %= 15746;
	}
	
	cout << arr[n] << "\n";
	
	return 0;
}