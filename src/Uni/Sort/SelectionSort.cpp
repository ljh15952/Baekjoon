#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int arr[10] = {3,5,1,2,4,8,7,9,6,0};
	int n = 10;
	for(int i = 0; i < n-1; i++){
		
		int Min = i;
		for(int j = i+1; j < n; j++){
			if(arr[j] < arr[Min]){
				Min = j;
			}
			
			int temp = arr[i];
			arr[i] = arr[Min];
			arr[Min] = temp;
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << ' ';
	}
	cout << endl;
	
	return 0;
}