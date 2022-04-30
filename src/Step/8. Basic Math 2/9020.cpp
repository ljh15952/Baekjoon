#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
	int arr[10001] = {0,};
	arr[1] = 1;
	
	for(int i = 2; i <= 10000; ++i){
		for(int j = 2; j * i <= 10000; ++j){
			arr[i*j] = 1;
		}
	}
	
	int T;
	scanf("%d",&T);
	
	for(int x = 0; x < T; x++){
		int n;

		cin >> n;

		int pivot = n / 2;
		
		for(int i = 0; i < pivot; ++i){
			int num1 = pivot - i;
			int num2 = n - num1;
			
			if(arr[num1] == 0 && arr[num2] == 0){
				cout << num1 << ' ' << num2 << endl;
				break;
			}
		}
	}
	
	
	return 0;
}