#include <iostream>

using namespace std;

long long int arr[91];

int main(){
	
	int n;
	
	scanf("%d",&n);
	
	arr[1] = 1;
	arr[2] = 1;
	
	for(int i = 3; i <= n; ++i){
		arr[i] = arr[i - 2] + arr[i - 1];
	}
	
	cout << arr[n] << endl;
	
	
	return 0;
}

/*
1

10

101
100

1010
1000
1001

10100
10101
10001
10000
10010

*/