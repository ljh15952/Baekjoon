#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int n;
	
	scanf("%d",&n);
	
	int arr[1000];
	
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d",&a);
		arr[i] = a;
	}
	int MAX = *max_element(arr,arr+n);
	float sum = 0;
	for(int i = 0; i < n; i++){
		sum += (float)arr[i] / MAX * 100;
	}
	
	cout << sum / n << endl;
	
	return 0;
}