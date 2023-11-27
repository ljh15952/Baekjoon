#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	
	int arr[10] = {3,5,1,2,4,8,7,9,6,0};
	int n = 10;
	for(int i = 0; i < n-1; i++){
		
		int Min = arr[i];
		int Min_Idx = i;
		for(int j = i+1; j < n; j++){
			if(arr[j] < Min){
				Min = arr[j];
				Min_Idx = j;
			}
			
			int temp = arr[i];
			arr[i] = arr[Min_Idx];
			arr[Min_Idx] = temp;
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << arr[i] << ' ';
	}
	cout << endl;
	
	return 0;
}