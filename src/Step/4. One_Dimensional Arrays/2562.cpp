#include <iostream>

using namespace std;

int main(){
	int arr[9];
	
	for(int i = 0; i < 9; i++){
		scanf("%d",&arr[i]);
	}
	
	int max = arr[0];
	int num = 1;
	
	for(int i = 1; i < 9; i++){
		if(arr[i] > max){
			max = arr[i];
			num = i+1;
		}
	}
	
	cout << max << endl;
	cout << num << endl;
	
	//배열을 안씀
	// int max = -99999;
	// int num = 0;
	// for(int i = 0; i < 9; i++)
	// {
	// 	int n;
	// 	cin >> n;
	// 	if(n > max){
	// 		max = n;
	// 		num = i+1;
	// 	}
	// }
	
	// cout << max << endl;
	// cout << num << endl;

	return 0;
}