#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}

int main(){

	int n;
	cin >> n;
	
	vector<int> arr;
	for(int i = 0; i < n; i++){
		int num;
		scanf("%d",&num);
		arr.push_back(num);
	}
	
	for(int i = 1; i < n; i++){
		int gcdNum = gcd(arr[0],arr[i]);
		cout << arr[0] / gcdNum << "/" << arr[i] / gcdNum << '\n';
	}
	
	return 0;
}