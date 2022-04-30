#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	
	int arr[1000000];
	
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	
	int max = arr[0];
	int min = arr[0];
	for(int i = 1; i < n; i++){
		if(arr[i] > max){
			max = arr[i];
		}
		if(arr[i] < min){
			min = arr[i];
		}
	}
	
	cout << min << " " << max << endl;
	
	// cin.tie(NULL);
	// int n;
	
	// cin >> n;
	
	// int min = 9999999;
	// int max = -9999999;
	// for(int i = 0; i < n; i++){
	// 	int num;
		
	// 	cin >> num;
		
	// 	if(num > max)
	// 		max = num;
	// 	if(num < min)
	// 		min = num;
	// }
	
	// cout << min << " " << max << endl;
	
	return 0;
}